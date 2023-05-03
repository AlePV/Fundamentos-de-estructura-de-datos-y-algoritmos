#!/bin/bash

directorio="datasets/semiordenados"

rm *.csv

for archivo in $(find $directorio -name "*.txt")
do 
	./sorting.out $archivo
done
