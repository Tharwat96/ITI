#!/bin/bash

if (($# == 0))
then 
	echo "Please enter an argument"
elif [[ -f $1 ]]
then
	echo "$1 is a file"
elif [[ -d $1 ]]
then 
	echo "$1 is a directory"
fi
if (($# >0))
then
	echo "Permissions are: "
	if [[ -r $1 ]]
	then
		echo "R"
	fi
	if [[ -w $1 ]]
        then
                echo "W"
	fi
        if [[ -x $1 ]]
        then
                echo "X"
	fi
fi


	
