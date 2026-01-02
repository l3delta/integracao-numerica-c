#!/bin/bash

clear

gcc -Wall -Wextra -Wpedantic \
    -Iinclude \
    src/*.c \
    -o a.out -lm

./a.out

