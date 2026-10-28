#!/usr/bin/env bash

# cit source add module/file.h
#
#
mode=$1
module_and_file=$2

create_file(){
    echo "" > $1
}


case "$mode" in
    "add")
        command="create_file"
        message="Creating"
    ;;
    "rm")
        command="rm"
        message="Removing"
    ;;
    *)
        echo "unkown source command"
        exit 1
    ;;
esac

echo "${message} ${module_and_file}"
$command src/${module_and_file}