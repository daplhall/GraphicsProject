#!/usr/bin/env bash

if declare -F deactivate; then
    deactivate
fi

folders="$(dirname -- "$BASH_SOURCE")"

OLD_PS1="$PS1"
cit (){
    "${folders}/cit/cit.sh" "$@"  
}
vroom (){
    "${folders}/vroom.sh" "$@"
}

deactivate(){
    unset -f cit
    unset -f vroom
    export PS1="$OLD_PS1" # Akin to .venv
    unset -f deactivate
}

export PS1="(Scripted) $PS1" # Akin to .venv
