folders="$(dirname -- "$BASH_SOURCE")"

grant(){
    for file in "$@"; do
        if [[ "$file" == "$0" ]]; then
            continue
        elif [[ ! -x "$file" ]]; then
            echo "Granting execute on ${file}"
            chmod +x "$file"
        fi
    done
}

grant ${folders}/cit/*.sh
grant ${folders}/*.sh