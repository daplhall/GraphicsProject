#!/bin/sh
mode=$1
module=$2

case "$mode" in
    "add")
        command="mkdir"
        message="Creating"
    ;;
    "rm")
        command="rm -r"
        message="Removing"
    ;;
    *)
    echo "Unknown module command"
    exit 1
    ;;
esac

module_print(){
    echo "${message} $1"
}

module_print "source"
$command src/$module
module_print "tests"
$command tests/$module
module_print "include"
$command include/$module
