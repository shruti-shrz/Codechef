#!/bin/bash

echo "Let's test recurrence"

C=`ls -1 | wc -l`

((C=C-1))

echo $C

for var in $(ls -1)
do
	./r $var
done

echo "Automated check completed"
