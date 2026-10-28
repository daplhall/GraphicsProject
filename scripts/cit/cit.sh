#!/usr/bin/env bash
mode=$1
args=${@:2}

cit_dir="$(dirname -- "$BASH_SOURCE")"

case $mode in
    "add")
        ${cit_dir}/add/add.sh $args
    ;;
    "rm")
        echo "rm"
        ${cit_dir}/rm/rm.sh $args
    ;;
    *)
        echo "illegal command: ${mode}"
    ;;
esac