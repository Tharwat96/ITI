#!/bin/bash

dir='./test'

for file in `ls $dir`
do 
	chmod u+x $dir"/"$file
done
