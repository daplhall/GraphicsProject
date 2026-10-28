#!/usr/bin/env bash
mode=$1
args=${@:2}

cdir="$(dirname -- "$BASH_SOURCE")"

case $mode in 
    "m" | "module")
        "$cdir/module.sh" $args
    ;;
    "h" | "header")
        "$cdir/header.sh" $args
    ;;
    "s" | "source")
        "$cdir/source.sh" $args
    ;;
    "t" | "tests")
        "$cdir/tests.sh" $args
    ;;
    "")
        echo "Cit - C Helper"
        echo "--------------"
        echo "Current modes:"
        echo "  module | m - manages modules"
        echo "  header | h - manages headers"
    ;;
    *)
        echo "Ohhh Cit! - mode is not a supported mode"
        exit 1
    ;;
esac
