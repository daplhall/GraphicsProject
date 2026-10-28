#!/usr/bin/env bash
mode=$1
args=${@:2}

cit_dir="$(dirname -- "$BASH_SOURCE")"

case $mode in
    "add")
        command=add
    ;;
    "rm")
        command=rm
    ;;
    *)
        echo "illegal command: ${mode}"
        exit 1
    ;;
esac

${cit_dir}/route.sh ${command} $args