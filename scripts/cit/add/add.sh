#!/usr/bin/env bash
category=$1
object=$2

cit_dir="$(dirname -- "$BASH_SOURCE")"

case $category in
    "h" | "header")
        ${cit_dir}/header.sh ${object}
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
        echo "Creating Module"
        ${cit_dir}/module.sh ${object}
    ;;
    *)
        echo "illegal category: ${category}"
    ;;
esac