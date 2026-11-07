#!/usr/bin/env bash
mode=$1
category=$2
object=$3

cit_dir="$(dirname -- "$BASH_SOURCE")"
action=${cit_dir}/${mode}
case $category in
    "h" | "header")
       ${action}/header.sh ${object}
    ;;
    "s" | "source")
       ${action}/sources.sh ${object}
    ;;
    "t" | "test")
        echo "create test"
    ;;
    "i" | "interface")
        echo "create interface"
    ;;
    "m" | "module" )
       ${action}/module.sh ${object}
    ;;
    *)
        echo "illegal category: ${category}"
    ;;
esac
