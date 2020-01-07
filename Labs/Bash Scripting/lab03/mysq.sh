#!/bin/bash

function square {
	typeset -i square
	square=$1*$1
        return $square

}


if [[ $* -eq 0 ]]
then
	echo "nothing entered, please enter an argument"
else
	square $1
	echo $?
fi
