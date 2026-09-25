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
        echo "Cit - C Helper"
        echo "--------------"
        echo "Current modes:"
        echo "  module - manages modules"
        echo "  header - manages headers"
    ;;
    *)
        echo "$mode is not a supported mode"
        exit 1
    ;;
esac
