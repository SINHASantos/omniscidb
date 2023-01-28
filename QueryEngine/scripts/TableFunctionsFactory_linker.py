import os
import abc
import sys
import math
import textwrap


def get_existing_file_content(filepath):
    if not os.path.exists(filepath):
        return ""

    with open(filepath, "r") as f:
        return "".join(f.readlines())


class BaseGenerateFiles(object):

    CHUNK_SIZE = 200
    _generated_header_files = []

    def __init__(self, dirname, kind):
        self.dirname = dirname
        self.kind = kind

    @classmethod
    def file_counter(cls):
        return cls._file_counter

    @classmethod
    def generated_header_files(self):
        return self._generated_header_files

    @classmethod
    def increment_file_counter(cls):
        cls._file_counter += 1

    @abc.abstractmethod
    def should_generate_files(self):
        raise NotImplementedError()

    @abc.abstractmethod
    def get_filename(self, prefix, kind, fileno, ext):
        raise NotImplementedError()

    @classmethod
    def get_num_generated_files(cls):
        return cls.file_counter()

    def _get_filename(self, ext):
        fileno = self.file_counter()
        filename = self.get_filename(self.filename_prefix, self.kind, fileno, ext)
        return os.path.join(self.dirname, filename)

    def _generate_files(self, chunk):
        self.increment_file_counter()
        fileno = self.file_counter()
        cpp_filename = self._get_filename(ext="cpp")
        hpp_filename = self._get_filename(ext="h")

        BaseGenerateFiles._generated_header_files.append(hpp_filename)

        cpp_content = self._generate_cpp_content(chunk, hpp_filename, fileno)
        hpp_content = self._generate_hpp_content(chunk, fileno)

        cpp_ec = get_existing_file_content(cpp_filename)
        hpp_ec = get_existing_file_content(hpp_filename)

        if cpp_content == cpp_ec and hpp_content == hpp_ec:
            return

        with open(cpp_filename, "w") as f:
            f.write(cpp_content)

        with open(hpp_filename, "w") as f:
            f.write(hpp_content)

    def _split_stmts_into_chunks(self):
        stmts = self.stmts
        L = len(stmts)
        chunks = []
        for i in range(0, L, self.CHUNK_SIZE):
            chunks.append(stmts[i : i + self.CHUNK_SIZE])
        return chunks

    def generate_files(self):
        chunks = self._split_stmts_into_chunks()
        for chunk in chunks:
            self._generate_files(chunk)


class GenerateTemplateFiles(BaseGenerateFiles):

    _file_counter = -1

    def __init__(self, dirname, stmts, header_file, kind):
        assert kind in ("cpu", "gpu")
        self.stmts = stmts
        self.header_file = header_file
        super(
            GenerateTemplateFiles,
            self,
        ).__init__(dirname=dirname, kind=kind)

    @property
    def filename_prefix(self):
        return "TableFunctionsFactory_init"

    def get_filename(self, prefix, kind, fileno, ext):
        return "%s_%s_%s.%s" % (prefix, kind, fileno, ext)

    def _get_decl_from_cpp_functions(self, cpp_functions):
        decls = []
        for func in cpp_functions:
            header = func.split("{", 1)[0].rstrip() + ";"
            decls.append(header)
        return decls

    def _generate_cpp_content(self, stmts, hpp_filename, fileno):
        content = '''
        /*
        This file is generated by %s. Do no edit!

        */
        #include "%s"

        %s
        '''
        content = textwrap.dedent(content)
        funcs_formatted = '\n'.join(stmts)
        return content % (sys.argv[0], hpp_filename, funcs_formatted)

    def _generate_hpp_content(self, funcs, fileno):
        content = '''
        /*
        This file is generated by %s. Do no edit!
        */
        #include "%s"

        %s
        '''
        content = textwrap.dedent(content)

        decls = '\n\n'.join(self._get_decl_from_cpp_functions(funcs))

        return content % (sys.argv[0], self.header_file, decls)



class GenerateAddTableFunctionsFiles(BaseGenerateFiles):

    _file_counter = -1

    def __init__(self, dirname, stmts, header_file):
        self.stmts = stmts
        self.header_file = header_file
        super(GenerateAddTableFunctionsFiles, self).__init__(dirname=dirname, kind="")

    @property
    def filename_prefix(self):
        return "TableFunctionsFactory_add"

    def get_filename(self, prefix, kind, fileno, ext):
        return "%s_%s.%s" % (prefix, fileno, ext)

    def should_generate_files(self):
        return len(self.stmts) > 0

    def _generate_cpp_content(self, chunk, hpp_filename, fileno):
        content = """
        /*
        This file is generated by %s. Do no edit!
        */

        #include "QueryEngine/TableFunctions/TableFunctionsFactory.h"
        #include "%s"

        namespace table_functions {

        NO_OPT_ATTRIBUTE void add_table_functions_%d() {
            %s
        }
        };

        """
        content = textwrap.dedent(content)
        chunk = '\n    '.join(chunk)
        return content % (sys.argv[0], hpp_filename, fileno, chunk)

    def _generate_hpp_content(self, funcs, fileno):
        content = """
        /*
        This file is generated by %s. Do no edit!
        */

        #include "QueryEngine/TableFunctions/TableFunctionsFactory.h"
        #include "%s"

        #if defined(__clang__)
        #define NO_OPT_ATTRIBUTE __attribute__((optnone))

        #elif defined(__GNUC__) || defined(__GNUG__)
        #define NO_OPT_ATTRIBUTE __attribute((optimize("O0")))

        #elif defined(_MSC_VER)
        #define NO_OPT_ATTRIBUTE

        #endif

        namespace table_functions {
            NO_OPT_ATTRIBUTE void add_table_functions_%s();
        };
        """

        content = textwrap.dedent(content)
        return content % (sys.argv[0], self.header_file, fileno)
