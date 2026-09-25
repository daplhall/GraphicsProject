#!/bin/sh
if declare -F deactivate >/dev/null; then
    deactivate
fi

OLD_PS1="$PS1"
cit="$PWD/scripts/cit/cit.sh"
alias cit=${cit}

deactivate(){
    unalias cit
    export PS1="$OLD_PS1" # Akin to .venv
    unset deactivate
}

grant(){
    for file in $1; do
        if [[ "$file" == "$0" ]]; then
            continue
        elif [[ ! -x "$file" ]]; then
            echo "Granting execute on ${file}"
            chmod +x "$file"
        fi
    done
}

grant $PWD/scripts/cit/*.sh
grant $PWD/scripts/*.sh
unset -f grant

export PS1="(Scipted) $PS1" # Akin to .venv
