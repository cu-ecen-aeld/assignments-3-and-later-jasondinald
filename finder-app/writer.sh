#!/bin/sh
writefile=$1
writestr=$2
if [ -z $writefile ] & [ -z $writestr ]
then
	echo "writefile or writestr is not defined"
	exit 1
fi
if ! [ -d $( dirname $writefile ) ]
then	
	mkdir -p $( dirname $writefile )
fi	
touch $writefile
echo $writestr>$writefile
