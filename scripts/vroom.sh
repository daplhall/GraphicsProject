#!/usr/bin/env bash
if [[ "$#" -eq 0 ]] ; then
    build_type=release
else
    build_type=$1
fi

cmake --preset ci-linux-${build_type} && cmake --build --preset linux-${build_type} && ctest --preset linux-${build_type}
