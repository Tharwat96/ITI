#!/bin/bash

echo "Please enter size of array"
read arrsize
let i=1
while (($arrsize > 0))
do
	let arr[$i]=i+10
	let i=$i+1
	let arrsize=$arrsize-1
done
echo ${arr[*]}
