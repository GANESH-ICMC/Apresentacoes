#!/bin/bash

name="Ganesh"

if ["$name" == "Ganesh"]
then
	echo "Ganesh!"
else
	echo "Not Ganesh!!"
fi

for output in $(ls)
do
	echo "$output"
done
