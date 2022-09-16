SCRIPT_DIR=$(dirname "$0")
cd "$SCRIPT_DIR"

function configure_output_directory {
    CMAKE_BUILD_DIR="_build/$(printf %s-%s $CMAKE_BUILD_TYPE $PROJECT | tr [:upper:] [:lower:])"
    if [[ -n ${CLEAR} ]]; then
        rm -rf ${CMAKE_BUILD_DIR}
    fi

    mkdir -p "$CMAKE_BUILD_DIR"
    if [[ -n ${CMAKE_INSTALL_PREFIX} ]]; then
        mkdir -p ${CMAKE_INSTALL_PREFIX}
    fi
    cd "$CMAKE_BUILD_DIR"
}

function adjust_threads_count {
    if [[ -z "$MAKE_THREADS" ]]; then
        if [[ -f "/proc/cpuinfo" ]]; then
            MAKE_THREADS=$(grep -c '^processor' /proc/cpuinfo)
        elif [[ $(uname) == "Darwin" ]]; then
            MAKE_THREADS=$(sysctl -n hw.logicalcpu)
        else
            MAKE_THREADS="1"
        fi
    fi
}

CMAKE_INSTALL_PREFIX="$(pwd)/${UTILITIES_INSTALL_PATH}"
export PATH="${PATH}:${CMAKE_INSTALL_PREFIX}/bin"
INITCACHE_FILE="../../CMakeInit.cmake"