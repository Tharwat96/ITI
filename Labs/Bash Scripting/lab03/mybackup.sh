#!/bin/bash

dir=~
backupdir='./backuptest'

for file in `ls -p $dir | grep -v /`
do 
	cp $dir"/"$file $backupdir
done
