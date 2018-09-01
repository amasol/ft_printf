#!/bin/bash

make re

gcc  -Wall -Wextra -Werror main2.c libftprintf.a -I includes
./a.out |cat -e
