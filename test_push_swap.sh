#!/bin/bash

minimum=-20000
max=100000
size=500
ARG=$(seq $minimum  $max | shuf -n $size)

./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG > output.txt
