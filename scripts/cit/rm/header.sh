#!/usr/bin/env bash
destination=$1
base_destination="${destination%/*}"
module="${base_destination##*/}"

echo ${base_destination}
if [[ ! -d "${base_destination}" ]]; then
    echo "Module $base_destination does not exits"
    exit 1
elif [[ ! -f $destination ]]; then
    echo "Header file $file does not exists in module $module"
    exit 1
fi

echo "Removing header :: ${destination}"

rm ${destination}
