#!/bin/bash

echo "Please enter your username"
read username
if [[ `ls /home | grep $username`  ]]
then
	ls -l /home/$username
	ps -aux | grep $username
	cp -r /home/$username /tmp
fi
