# miniPy-parser

a flex/bison parser for miniPy.

## Compilataion:

`flex lexical.l`

`bison syntaxique.y -d`

`gcc lex.yy.c syntaxique.tab.c tv.c -o parser.exe -lfl`

## Execution: (use command prompt)

`parser.exe<test.txt`
