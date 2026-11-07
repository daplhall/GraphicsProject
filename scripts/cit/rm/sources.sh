#!/usr/bin/env bash
destination=$1
base_destination="${destination%/*}"
module="${base_destination##*/}"

if [[ -f $destination ]]; then
    echo "Header file $file exists in module $module"
    exit 1
fi

echo "Removing src/${destination}"
rm "src/${destination}"
