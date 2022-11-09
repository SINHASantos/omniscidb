#!/usr/bin/env bash

# Copyright 2022 HEAVY.AI, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# NOTE: This will perform a full system update via the command yay -Suy.
# See https://wiki.archlinux.org/title/System_maintenance#Partial_upgrades_are_unsupported
# for more information.

# Must be run from the scripts/ directory as the non-root user.
# Since we use an older version of Apache Arrow, automatic updates to arrow can be avoided by
# adding it to the uncommented IgnorePkg line in /etc/pacman.conf. Example:
# IgnorePkg   = arrow

set -e
set -x

cd "$( dirname "${BASH_SOURCE[0]}" )"

hash yay || { echo >&2 "yay is required but is not installed. Aborting."; exit 1; }

unset CMAKE_GENERATOR

# Install all normal dependencies
yay -Suy \
    aws-sdk-cpp \
    blosc \
    boost \
    c-ares \
    clang \
    cmake \
    cuda \
    doxygen \
    flex \
    fmt \
    gcc \
    gdal \
    geos \
    git \
    glm \
    glslang \
    go \
    google-glog \
    intel-tbb \
    jdk-openjdk \
    libiodbc \
    librdkafka \
    libuv \
    llvm \
    lz4 \
    maven \
    ninja \
    pdal \
    python-numpy \
    snappy \
    spirv-cross \
    thrift \
    vulkan-headers \
    wget \
    zlib

# Install Arrow
pushd arch/arrow
makepkg -cis
popd

# Install Bison++ from source
wget --continue https://dependencies.mapd.com/thirdparty/bisonpp-1.21-45.tar.gz
tar xvf bisonpp-1.21-45.tar.gz
pushd bison++-1.21
./configure
make -j $(nproc)
sudo make install
popd
