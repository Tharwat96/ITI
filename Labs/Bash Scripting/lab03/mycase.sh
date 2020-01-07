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
	@([a-z]) ) 
		echo "lowercase";;
	@([A-Z]) )
		echo "uppercase";;
	@([0-9]) )
		echo "number";;

esac
