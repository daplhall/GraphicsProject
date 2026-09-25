#!/bin/sh
mode=$1
args=${@:2}

cdir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

case $mode in 
    "module")
        "$cdir/cit_module.sh" $args
    ;;
    "header")
        "$cdir/cit_header.sh" $args
    ;;
    "")
        echo "You have not chosen a mode"
    ;;
    *)
        echo "$mode is not a supported mode"
        exit 1
    ;;
esac
