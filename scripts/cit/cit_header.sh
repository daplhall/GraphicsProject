#!/bin/sh
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

identity=${file%.*}
identity=${identity^^}
module=${module^^}
identity="GUARD_${module}_${identity}_H"
extension="${file##*.}"

push(){
    echo "$1" >> $destination
}

push "#ifndef $identity"
push "#define $identity"
push ""
if [[ "$extension" = "h" ]]; then
    push "#ifdef __cplusplus"
    push "extern "C" {"
    push "#endif"
    push ""
    push "#ifdef __cplusplus"
    push "}"
    push "#endif"
fi
push "#endif //$identity"
