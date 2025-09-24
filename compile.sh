#!/bin/bash

rm -f *.o
rm -f *exe
lex Parser.l
g++ -g -c lex.yy.c -o lex.yy.o
g++ -g lex.yy.o  -o exe -ll