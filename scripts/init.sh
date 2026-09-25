#!/bin/sh
cit="$PWD/scripts/cit/cit.sh"
alias cit=${cit}

for file in $PWD/scripts/cit/*.sh; do
    if [[ ! -x "$file" ]]; then
        echo "Granting execute on ${file}"
        chmod +x "$file"
    fi
done

export PS1="(Scipted) $PS1" # Akin to .venv