#!/usr/bin/env bash
mode=$1
category=$2
object=$3

cit_dir="$(dirname -- "$BASH_SOURCE")"

case $category in
    "h" | "header")
        echo "create header"
    ;;
    "s" | "source")
        echo "create source"
    ;;
    "t" | "test")
        echo "create test"
    ;;
    "i" | "interface")
        echo "create interface"
    ;;
    "m" | "module" )
        ${cit_dir}/${mode}/module.sh ${object}
    ;;
    *)
        echo "illegal category: ${category}"
    ;;
esac