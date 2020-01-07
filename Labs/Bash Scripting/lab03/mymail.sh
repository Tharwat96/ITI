#!/bin/bash

for user in `awk -F: '{print $1}' /etc/passwd`
do
	mail -s "mymail test" $user < mtemplate
done
