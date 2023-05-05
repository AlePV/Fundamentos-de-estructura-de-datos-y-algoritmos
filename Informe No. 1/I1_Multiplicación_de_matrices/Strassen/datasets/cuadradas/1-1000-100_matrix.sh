#!/bin/bash

for i in {1..1000..100}
do 
	python3 create_matrix.py -n $i
done
