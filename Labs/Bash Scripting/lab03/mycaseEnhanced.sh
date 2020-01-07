#!/bin/bash
LC_ALL=C
shopt -s extglob

echo "Please enter a character to check if it is uppercase, lowercase, number: "
read var
if [[ $var = '' ]]
then 
	echo "Nothing entered"
fi
case $var in
	*([a-z]) ) 
		echo "lowercase";;
	*([A-Z]) )
		echo "uppercase";;
	*([0-9]) )
		echo "number";;
	*([a-z-A-Z]) )
		echo "mixed lower and upper cases";;
	*([a-z-0-9]) )
                echo "mixed lowercase and numbers";;
        *([0-9-A-Z]) )
                echo "mixed uppercase and numbers";;

        *([a-z-A-Z-0-9]) )
                echo "mixed lowercase, uppercase, and numbers";;


	
	*	)
		echo "Not categorized";;

esac
