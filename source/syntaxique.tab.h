
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 13 "syntaxique.y"

        #include"tv.h"



/* Line 1676 of yacc.c  */
#line 46 "syntaxique.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_if = 258,
     mc_else = 259,
     mc_for = 260,
     mc_while = 261,
     mc_in = 262,
     mc_range = 263,
     mc_and = 264,
     mc_or = 265,
     mc_not = 266,
     newLine = 267,
     ident = 268,
     mc_int = 269,
     mc_float = 270,
     mc_char = 271,
     mc_bool = 272,
     colon = 273,
     comma = 274,
     assign = 275,
     openParenthesis = 276,
     closeParenthesis = 277,
     openBracket = 278,
     closeBracket = 279,
     idf = 280,
     lessOrEqual = 281,
     greatOrEqual = 282,
     less = 283,
     great = 284,
     equal = 285,
     notEqual = 286,
     pls = 287,
     min = 288,
     divs = 289,
     mul = 290,
     integer = 291,
     real = 292,
     character = 293,
     booleen = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 17 "syntaxique.y"

        char type;
        char *str;
        struct vt valtype;   



/* Line 1676 of yacc.c  */
#line 110 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


