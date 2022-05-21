#!/usr/bin/env bash -e

ARCH=$(uname -s)

TOOLS_DIR="${PWD}/.tools"
GCC_DIR="${TOOLS_DIR}/arm_none_eabi_gcc"
DOWNLOAD_DIR="${TOOLS_DIR}/archives"

# Get all submodules
git submodule update --init --recursive

download_gcc() {
    echo "Installing arm-none-eabi-gcc"

    if [ "${ARCH}" == "Darwin" ]; then
        GCC_ARCHIVE="gcc-arm-none-eabi-10.3-2021.10-mac"
    elif [ "${ARCH}" == "Linux" ]; then
        GCC_ARCHIVE="gcc-arm-none-eabi-10.3-2021.10-x86_64-linux"
    fi
    GCC_URL="https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/${GCC_ARCHIVE}.tar.bz2"

    mkdir -p ${DOWNLOAD_DIR}

    pushd ${DOWNLOAD_DIR}
    if [ -f "${GCC_ARCHIVE}.tar.bz2" ]; then
        echo "skipping gcc download, already downloaded"
    else
        wget ${GCC_URL}
    fi
    popd

    tar -xf "${DOWNLOAD_DIR}/${GCC_ARCHIVE}.tar.bz2"
    mv gcc-arm-none-eabi-10.3-2021.10 ${GCC_DIR}
}

ensure_gcc() {
    if [ -d "${GCC_DIR}" ]; then
        echo "gcc already installed"
    else
        download_gcc
    fi

    GCC_PATH="${GCC_DIR}/bin"

    if [ -n "${GITHUB_PATH}" ]; then
        echo "${GCC_PATH}" >> ${GITHUB_PATH}
    fi

    export PATH="${GCC_PATH}:${PATH}"
}

ensure_gcc
