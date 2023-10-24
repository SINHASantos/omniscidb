/*
 * Copyright 2022 HEAVY.AI, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <set>
#include <string>

static std::set<std::string> reserved_keywords{

    // OmniSci reserved keywords

    "ACCESS",
    "ADD",  // legacy
    "AMMSC",
    "ARCHIVE",
    "ASC",
    "CONTINUE",
    "COPY",
    "DASHBOARD",
    "DATABASE",
    "DATAFRAME",
    "DATETIME",
    "DATE_TRUNC",
    "DESC",
    "DUMP",
    "EDIT",
    "EDITOR",
    "FIRST",
    "FOUND",
    "GEOGRAPHY",  // geo type
    "GEOMETRY",   // geo type
    "IF",
    "ILIKE",
    "LAST",
    "LENGTH",
    "LINESTRING",       // geo type
    "MULTILINESTRING",  // geo type
    "MULTIPOINT",       // geo type
    "MULTIPOLYGON",     // geo type
    "NOW",
    "NULLX",
    "OPTION",
    "POINT",    // geo type
    "POLYGON",  // geo type
    "PRIVILEGES",
    "PUBLIC",
    "RENAME",
    "RESTORE",
    "ROLE",   // permissions
    "ROWID",  // hidden column name
    "SCHEMA",
    "SQL",
    "TEMPORARY",  // in-memory tables
    "TEXT",
    "VIEW",
    "WORK",

    // Calcite reserved keywords
    // https://calcite.apache.org/docs/reference.html#keywords
    // As of apache/calcite@9085b601081689b5b7f1e9f57deb20e2229910cb

    "ABS",
    "ALL",
    "ALLOCATE",
    "ALLOW",
    "ALTER",
    "AND",
    "ANY",
    "ARE",
    "ARRAY",
    "ARRAY_MAX_CARDINALITY",
    "AS",
    "ASENSITIVE",
    "ASYMMETRIC",
    "AT",
    "ATOMIC",
    "AUTHORIZATION",
    "AVG",
    "BEGIN",
    "BEGIN_FRAME",
    "BEGIN_PARTITION",
    "BETWEEN",
    "BIGINT",
    "BINARY",
    "BIT",
    "BLOB",
    "BOOLEAN",
    "BOTH",
    "BY",
    "CALL",
    "CALLED",
    "CARDINALITY",
    "CASCADED",
    "CASE",
    "CAST",
    "CEIL",
    "CEILING",
    "CHAR",
    "CHARACTER",
    "CHARACTER_LENGTH",
    "CHAR_LENGTH",
    "CHECK",
    "CLASSIFIER",
    "CLOB",
    "CLOSE",
    "COALESCE",
    "COLLATE",
    "COLLECT",
    "COLUMN",
    "COMMIT",
    "CONDITION",
    "CONNECT",
    "CONSTRAINT",
    "CONTAINS",
    "CONVERT",
    "CORR",
    "CORRESPONDING",
    "COUNT",
    "COVAR_POP",
    "COVAR_SAMP",
    "CREATE",
    "CROSS",
    "CUBE",
    "CUME_DIST",
    "CURRENT",
    "CURRENT_CATALOG",
    "CURRENT_DATE",
    "CURRENT_DEFAULT_TRANSFORM_GROUP",
    "CURRENT_PATH",
    "CURRENT_ROLE",
    "CURRENT_ROW",
    "CURRENT_SCHEMA",
    "CURRENT_TIME",
    "CURRENT_TIMESTAMP",
    "CURRENT_TRANSFORM_GROUP_FOR_TYPE",
    "CURRENT_USER",
    "CURSOR",
    "CYCLE",
    "DATE",
    "DAY",
    "DEALLOCATE",
    "DEC",
    "DECIMAL",
    "DECLARE",
    "DEFAULT",
    "DEFINE",
    "DELETE",
    "DENSE_RANK",
    "DEREF",
    "DESCRIBE",
    "DETERMINISTIC",
    "DISALLOW",
    "DISCONNECT",
    "DISTINCT",
    "DOUBLE",
    "DROP",
    "DYNAMIC",
    "EACH",
    "ELEMENT",
    "ELSE",
    "EMPTY",
    "END",
    "END-EXEC",
    "END_FRAME",
    "END_PARTITION",
    "EQUALS",
    "ESCAPE",
    "EVERY",
    "EXCEPT",
    "EXEC",
    "EXECUTE",
    "EXISTS",
    "EXP",
    "EXPLAIN",
    "EXTEND",
    "EXTERNAL",
    "EXTRACT",
    "FALSE",
    "FETCH",
    "FILTER",
    "FIRST_VALUE",
    "FLOAT",
    "FLOOR",
    "FOR",
    "FOREIGN",
    "FRAME_ROW",
    "FREE",
    "FROM",
    "FULL",
    "FUNCTION",
    "FUSION",
    "GET",
    "GLOBAL",
    "GRANT",
    "GROUP",
    "GROUPING",
    "GROUPS",
    "HAVING",
    "HOLD",
    "HOUR",
    "IDENTITY",
    "IMPORT",
    "IN",
    "INDICATOR",
    "INITIAL",
    "INNER",
    "INOUT",
    "INSENSITIVE",
    "INSERT",
    "INT",
    "INTEGER",
    "INTERSECT",
    "INTERSECTION",
    "INTERVAL",
    "INTO",
    "IS",
    "JAROWINKLER_SIMILARITY"
    "JOIN",
    "LAG",
    "LANGUAGE",
    "LARGE",
    "LAST_VALUE",
    "LATERAL",
    "LEAD",
    "LEADING",
    "LEFT",
    "LEVENSHTEIN_DISTANCE"
    "LIKE",
    "LIKE_REGEX",
    "LIMIT",
    "LN",
    "LOCAL",
    "LOCALTIME",
    "LOCALTIMESTAMP",
    "LOWER",
    "LPAD",
    "LTRIM",
    "MATCH",
    "MATCHES",
    "MATCH_NUMBER",
    "MATCH_RECOGNIZE",
    "MAX",
    "MEASURES",
    "MEMBER",
    "MERGE",
    "METHOD",
    "MIN",
    "MINUS",
    "MINUTE",
    "MOD",
    "MODIFIES",
    "MODULE",
    "MONTH",
    "MULTISET",
    "NATIONAL",
    "NATURAL",
    "NCHAR",
    "NCLOB",
    "NEW",
    "NEXT",
    "NO",
    "NONE",
    "NORMALIZE",
    "NOT",
    "NTH_VALUE",
    "NTILE",
    "NULL",
    "NULLIF",
    "NUMERIC",
    "OCCURRENCES_REGEX",
    "OCTET_LENGTH",
    "OF",
    "OFFSET",
    "OLD",
    "OMIT",
    "ON",
    "ONE",
    "ONLY",
    "OPEN",
    "OPTIMIZE",
    "OR",
    "ORDER",
    "OUT",
    "OUTER",
    "OVER",
    "OVERLAPS",
    "OVERLAY",
    "PARAMETER",
    "PARTITION",
    "PATTERN",
    "PER",
    "PERCENT",
    "PERCENTILE_CONT",
    "PERCENTILE_DISC",
    "PERCENT_RANK",
    "PERIOD",
    "PERMUTE",
    "PORTION",
    "POSITION",
    "POSITION_REGEX",
    "POWER",
    "PRECEDES",
    "PRECISION",
    "PREPARE",
    "PREV",
    "PRIMARY",
    "PROCEDURE",
    "RANGE",
    "RANK",
    "READS",
    "REAL",
    "RECURSIVE",
    "REF",
    "REFERENCES",
    "REFERENCING",
    "REGEXP_COUNT",
    "REGEXP_REPLACE",
    "REGEXP_SUBSTR",
    "REGEXP_MATCH"
    "REGR_AVGX",
    "REGR_AVGY",
    "REGR_COUNT",
    "REGR_INTERCEPT",
    "REGR_R2",
    "REGR_SLOPE",
    "REGR_SXX",
    "REGR_SXY",
    "REGR_SYY",
    "RELEASE",
    "REPEAT",
    "REPLACE",
    "RESET",
    "RESULT",
    "RETURN",
    "RETURNS",
    "REVERSE",
    "REVOKE",
    "RIGHT",
    "ROLLBACK",
    "ROLLUP",
    "ROW",
    "ROWS",
    "ROW_NUMBER",
    "RPAD",
    "RUNNING",
    "RTRIM",
    "SAVEPOINT",
    "SCOPE",
    "SCROLL",
    "SEARCH",
    "SECOND",
    "SEEK",
    "SELECT",
    "SENSITIVE",
    "SESSION_USER",
    "SET",
    "SHOW",
    "SIMILAR",
    "SKIP",
    "SMALLINT",
    "SOME",
    "SPECIFIC",
    "SPECIFICTYPE",
    "SPLIT_PART",
    "SQL",
    "SQLEXCEPTION",
    "SQLSTATE",
    "SQLWARNING",
    "SQRT",
    "START",
    "STATIC",
    "STDDEV_POP",
    "STDDEV_SAMP",
    "STREAM",
    "SUBMULTISET",
    "SUBSET",
    "SUBSTRING",
    "SUCCEEDS",
    "SUM",
    "SYMMETRIC",
    "SYSTEM",
    "SYSTEM_TIME",
    "SYSTEM_USER",
    "TABLE",
    "TABLESAMPLE",
    "THEN",
    "TIME",
    "TIMESTAMP",
    "TIMEZONE_HOUR",
    "TIMEZONE_MINUTE",
    "TINYINT",
    "TO",
    "TRAILING",
    "TRANSLATE",
    "TRANSLATE_REGEX",
    "TRANSLATION",
    "TREAT",
    "TRIGGER",
    "TRIM",
    "TRIM_ARRAY",
    "TRUE",
    "TRUNCATE",
    "TRY_CAST",
    "UESCAPE",
    "UNION",
    "UNIQUE",
    "UNKNOWN",
    "UNNEST",
    "UPDATE",
    "UPPER",
    "UPSERT",
    "USER",
    "USING",
    "VALUE",
    "VALUES",
    "VALUE_OF",
    "VARBINARY",
    "VARCHAR",
    "VARYING",
    "VAR_POP",
    "VAR_SAMP",
    "VERSIONING",
    "WHEN",
    "WHENEVER",
    "WHERE",
    "WIDTH_BUCKET",
    "WINDOW",
    "WITH",
    "WITHIN",
    "WITHOUT",
    "YEAR",
};
