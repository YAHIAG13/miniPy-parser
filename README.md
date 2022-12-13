# miniPy-parser

a flex/bison parser for mini python (python like with only the basic instructions in mind).

## Compilataion:

`flex lexical.l`

`bison syntaxique.y -d`

`gcc lex.yy.c syntaxique.tab.c -o parser.exe -lfl`

## Execution: (use command prompt)

`parser.exe<test.txt`