#!/bin/bash

minimum=0
max=200
size=500
ARG=$(seq $minimum  $max | shuf -n $size)

./push_swap $ARG
