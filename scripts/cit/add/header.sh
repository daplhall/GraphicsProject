#!/usr/bin/env bash
destination=$1
base_destination="${destination%/*}"
module="${base_destination##*/}"

if [[ ! -d "${base_destination}" ]]; then
    echo "Module $base_destination does not exits"
    exit 1
elif [[ -f $destination ]]; then
    echo "Header file $file exists in module $module"
    exit 1
fi

filename=${destination##*/}
filename=${filename%.*}
extension="${destination##*.}"
identity="GUARD_${module^^}_${filename^^}_H"

echo "Creating header : ${destination}"

push(){
    echo "$1" >> $destination
}

push "#ifndef $identity"
push "#define $identity"
if [[ "$extension" = "h" ]]; then
    push "#ifdef __cplusplus"
    push "extern \"C\" {"
    push "#endif"
    push ""
    push "#ifdef __cplusplus"
    push "}"
    push "#endif"
else
    push ""
fi
push "#endif //$identity"

