module=$1

extension="${module##*.}"

if [[ ${module} != ${extension} ]] ; then
    echo "You included af filename"
    exit 1
fi

paths=("src/${module}" "tests/${module}" "include/${module}")

for i in "${paths[@]}" 
do 
    echo "Removing ${i} recursively"
    rm -r ${i}
done