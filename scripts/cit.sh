#!/bin/sh
mode=$1
args=${@:2}

cdir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

case $mode in 
    "add" | "rm")
        "$cdir/cit_module.sh" $mode $args
    ;;
    "header")
        "$cdir/cit_header.sh" $args
    ;;
    *)
        echo "$mode is not a supported mode"
        exit 1
    ;;
esac
