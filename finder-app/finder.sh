#!/bin/sh
filesdir=$1
searchstr=$2
if [ -z $filesdir ] & [ -z $searchstr ]
then
	echo "searchstr or filesdir is not defined"
	exit 1
fi
if [ -d $filesdir ] 
then
	echo "The number of files are $(find $filesdir -type f |wc -l) and the number of matching lines are $(grep -r $searchstr $filesdir|wc -l )"
else
	echo "filesdir is not exists"
	exit 1
fi
