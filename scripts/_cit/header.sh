#!/usr/bin/env bash
module=$1
file=$2

destination=include/$module/$file

if [[ ! -d "include/${module}" ]]; then
    echo "Module $module does not exits"
    exit 1
elif [[ -f $destination ]]; then
    echo "Header file $file exists in module $module"
    exit 1
fi

filename=${file%.*}
extension="${file##*.}"
identity="GUARD_${module^^}_${filename^^}_H"

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
