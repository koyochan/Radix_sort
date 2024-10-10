#!/bin/bash

minimum=0
max=1000
size=500
ARG=$(seq $minimum  $max | shuf -n $size)

# ./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG > output.txt
