#!/bin/sh
mode=$1
module=$2

case "$mode" in
    "add")
        command="mkdir"
    ;;
    "rm")
        command="rm -r"
    ;;
    *)
    echo "Unknown command"
    exit 1
    ;;
esac
echo "Removing source"
$command src/$module
echo "Removing test"
$command tests/$module
echo "Removing headers"
$command include/$module