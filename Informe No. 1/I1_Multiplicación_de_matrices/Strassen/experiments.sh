#!/bin/bash

#directorio="datasets/cuadradas"
directorio="datasets/no_cuadradas"

rm *.csv

for archivo in $(find $directorio -name "*.in")
do 
	./strassen.out $archivo
done
