#!/bin/bash

echo "Please enter size of array"
read arrsize
let i=$arrsize

echo "please enter the values of the array"
while ((i > 0))
do 
	read arr[$i]
	echo ${arr[$i]}
	let i=$i-1
done
for value in ${arr[*]}
do
let sum=$sum+$value
done
echo $sum
let avg=$(( sum/arrsize ))
echo "avg is $avg"
