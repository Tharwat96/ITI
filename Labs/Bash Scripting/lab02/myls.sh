#!/bin/bash

if (($# == 0))
then
	ls -l
else 
	ls $1
fi

