#!/bin/bash

make re

gcc main2.c libftprintf.a -I includes
./a.out |cat -e
