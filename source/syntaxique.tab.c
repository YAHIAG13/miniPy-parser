
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntaxique.y"

    int nb_ligne = 1;
    int nb_colone = 1;
    int qc = 0;
    char tmp[20];
    int yyerror();

    int sauv_debut_while = 0;
    int sauv_debut_if = 0;
    int sauv_fin_if = 0;
    int sauve_debut_for = 0;


/* Line 189 of yacc.c  */
#line 87 "syntaxique.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 13 "syntaxique.y"

        #include"tv.h"



/* Line 209 of yacc.c  */
#line 117 "syntaxique.tab.c"

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

/* Line 214 of yacc.c  */
#line 17 "syntaxique.y"

        char type;
        char *str;
        struct vt valtype;   



/* Line 214 of yacc.c  */
#line 181 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "syntaxique.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    16,    18,    21,
      24,    26,    28,    30,    33,    34,    39,    40,    45,    46,
      53,    55,    59,    63,    70,    72,    74,    76,    78,    80,
      82,    84,    86,    90,    93,    95,    98,   105,   110,   113,
     120,   125,   128,   131,   138,   142,   147,   151,   156,   160,
     164,   168,   171,   175,   179,   183,   187,   191,   195,   199,
     203,   207,   211,   213,   215,   217,   219,   221,   223,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    43,    -1,    43,    -1,    12,    42,
      -1,    12,    -1,    44,    43,    -1,    44,    -1,    45,    42,
      -1,    50,    42,    -1,    59,    -1,    55,    -1,    61,    -1,
      53,    47,    -1,    -1,    53,    25,    46,    54,    -1,    -1,
      25,    19,    48,    47,    -1,    -1,    25,    20,    51,    19,
      49,    47,    -1,    25,    -1,    25,    20,    51,    -1,    25,
      20,    51,    -1,    25,    23,    52,    24,    20,    51,    -1,
      69,    -1,    38,    -1,    36,    -1,    25,    -1,    14,    -1,
      15,    -1,    16,    -1,    17,    -1,    23,    36,    24,    -1,
      56,    58,    -1,    56,    -1,    57,    65,    -1,     3,    21,
      69,    22,    18,    12,    -1,     4,    18,    12,    65,    -1,
      60,    65,    -1,     6,    21,    69,    22,    18,    12,    -1,
      62,    18,    12,    65,    -1,    64,    63,    -1,    64,    25,
      -1,     8,    21,    36,    19,    36,    22,    -1,     5,    25,
       7,    -1,    13,    45,    42,    65,    -1,    13,    45,    42,
      -1,    13,    50,    42,    65,    -1,    13,    50,    42,    -1,
      69,     9,    69,    -1,    69,    10,    69,    -1,    11,    69,
      -1,    69,    30,    69,    -1,    69,    31,    69,    -1,    69,
      26,    69,    -1,    69,    27,    69,    -1,    69,    28,    69,
      -1,    69,    29,    69,    -1,    69,    35,    69,    -1,    69,
      34,    69,    -1,    69,    32,    69,    -1,    69,    33,    69,
      -1,    25,    -1,    36,    -1,    37,    -1,    39,    -1,    68,
      -1,    67,    -1,    66,    -1,    21,    69,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    43,    46,    47,    50,    51,    53,    54,
      55,    56,    57,    59,    76,    75,    91,    90,   102,   101,
     116,   127,   142,   162,   177,   181,   184,   189,   194,   195,
     196,   197,   199,   213,   217,   222,   231,   242,   245,   253,
     261,   268,   269,   277,   292,   305,   306,   307,   308,   311,
     341,   370,   397,   453,   508,   563,   618,   673,   730,   772,
     838,   880,   924,   954,   958,   962,   966,   970,   974,   978
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_if", "mc_else", "mc_for", "mc_while",
  "mc_in", "mc_range", "mc_and", "mc_or", "mc_not", "newLine", "ident",
  "mc_int", "mc_float", "mc_char", "mc_bool", "colon", "comma", "assign",
  "openParenthesis", "closeParenthesis", "openBracket", "closeBracket",
  "idf", "lessOrEqual", "greatOrEqual", "less", "great", "equal",
  "notEqual", "pls", "min", "divs", "mul", "integer", "real", "character",
  "booleen", "$accept", "Prog", "newLines", "prog_Instructions",
  "Instruction", "Declaration", "$@1", "ListDeclaration", "$@2", "$@3",
  "Assignment", "Val", "intOridf", "type", "tab", "IF", "IF_STAT",
  "IF_COND", "ELSE", "WHILE", "WC", "FOR", "forType", "range", "for_idf",
  "block_Instructions", "logicExpression", "comparisonExpression",
  "arithmeticExpression", "Operand", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      44,    44,    44,    45,    46,    45,    48,    47,    49,    47,
      47,    47,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    54,    55,    55,    56,    57,    58,    59,    60,
      61,    62,    62,    63,    64,    65,    65,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     1,     2,     2,
       1,     1,     1,     2,     0,     4,     0,     4,     0,     6,
       1,     3,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     2,     6,     4,     2,     6,
       4,     2,     2,     6,     3,     4,     3,     4,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     5,    28,    29,    30,    31,     0,
       0,     0,     3,     7,     0,     0,     0,    11,    34,     0,
      10,     0,    12,     0,     0,     0,     0,     0,     4,     0,
       0,     1,     2,     6,     8,     9,    14,    13,     0,    33,
       0,    35,    38,     0,     0,    42,    41,     0,     0,    62,
      63,    64,    65,    68,    67,    66,     0,    44,     0,    25,
      22,    24,    27,    26,     0,    16,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,    15,     0,    46,    48,    40,     0,    69,
      49,    50,     0,    54,    55,    56,    57,    52,    53,    60,
      61,    59,    58,     0,     0,    20,    17,    18,     0,    37,
      45,    47,     0,    36,    39,    23,     0,    32,     0,    19,
      43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    67,    37,    90,   126,
      15,    60,    64,    16,    93,    17,    18,    19,    39,    20,
      21,    22,    23,    46,    24,    41,    53,    54,    55,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int16 yypact[] =
{
      23,    -8,     5,    15,    30,   -86,   -86,   -86,   -86,    -6,
      47,   150,   -86,   150,    30,    30,    24,   -86,    61,    63,
     -86,    63,   -86,    59,     2,    57,    74,    57,   -86,    -5,
     -18,   -86,   -86,   -86,   -86,   -86,     3,   -86,    65,   -86,
      29,   -86,   -86,    76,    66,   -86,   -86,    57,    57,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,    75,   -86,    89,   -86,
     -86,   117,   -86,   -86,    62,   -86,    -5,    67,    77,    30,
      30,    63,    55,   117,   103,    57,    57,    82,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    96,    72,
      70,   109,   104,   -86,    63,    63,    63,   -86,   120,   -86,
     151,   151,   129,    37,    37,    37,    37,    37,    37,   -26,
     -26,   -86,   -86,   130,    -5,    60,   -86,   -86,   133,   -86,
     -86,   -86,   118,   -86,   -86,   -86,    70,   -86,   136,   -86,
     -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,    -3,     8,   -86,   119,   -86,   -85,   -86,   -86,
     121,   -63,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -21,   -86,   -86,   -86,   -23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      42,    28,    56,    91,    58,   116,    47,    62,    86,    87,
      44,    34,    35,    25,    29,   -20,    48,    30,    63,    32,
      49,    33,    65,    66,    73,    74,     1,    45,     2,     3,
      26,    50,    51,    59,    52,     4,    27,     5,     6,     7,
       8,   129,     4,     5,     6,     7,     8,    31,     9,    36,
      97,   125,   100,   101,     9,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    38,    95,    96,    47,    84,
      85,    86,    87,   119,   120,   121,    40,    43,    48,    65,
      66,    57,    49,    68,    75,    76,    89,    72,    71,    94,
      92,    98,   114,    50,    51,   115,    52,    77,    75,    76,
     102,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    75,    76,   113,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    99,    75,    76,   117,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   122,
     118,   123,   124,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     1,   128,     2,     3,   127,   130,    69,
       0,    70,     0,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87
};

static const yytype_int8 yycheck[] =
{
      21,     4,    25,    66,    27,    90,    11,    25,    34,    35,
       8,    14,    15,    21,    20,    12,    21,    23,    36,    11,
      25,    13,    19,    20,    47,    48,     3,    25,     5,     6,
      25,    36,    37,    38,    39,    12,    21,    14,    15,    16,
      17,   126,    12,    14,    15,    16,    17,     0,    25,    25,
      71,   114,    75,    76,    25,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     4,    69,    70,    11,    32,
      33,    34,    35,    94,    95,    96,    13,    18,    21,    19,
      20,     7,    25,    18,     9,    10,    24,    21,    12,    12,
      23,    36,    20,    36,    37,    25,    39,    22,     9,    10,
      18,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    22,     9,    10,    18,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    22,     9,    10,    19,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    19,
      36,    12,    12,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     3,    36,     5,     6,    24,    22,    40,
      -1,    40,    -1,    -1,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,    12,    14,    15,    16,    17,    25,
      41,    42,    43,    44,    45,    50,    53,    55,    56,    57,
      59,    60,    61,    62,    64,    21,    25,    21,    42,    20,
      23,     0,    43,    43,    42,    42,    25,    47,     4,    58,
      13,    65,    65,    18,     8,    25,    63,    11,    21,    25,
      36,    37,    39,    66,    67,    68,    69,     7,    69,    38,
      51,    69,    25,    36,    52,    19,    20,    46,    18,    45,
      50,    12,    21,    69,    69,     9,    10,    22,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    22,    24,
      48,    51,    23,    54,    12,    42,    42,    65,    36,    22,
      69,    69,    18,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    18,    20,    25,    47,    19,    36,    65,
      65,    65,    19,    12,    12,    51,    49,    24,    36,    47,
      22
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 42 "syntaxique.y"
    {printf("End Prog\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 43 "syntaxique.y"
    {printf("End Prog\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 60 "syntaxique.y"
    {       
                        int i;
                        for(i=return_top(); i>=0; i--)
                        {
                                char * tempstr = (char *)pop();
                                
                                if(get_sym(tempstr)->type == NOTYPE){
                                        install_type(tempstr, (yyvsp[(1) - (2)].type));
                                }
                                if(get_sym(tempstr)->type != (yyvsp[(1) - (2)].type)){
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d, declaration type dont match constant type.\n", nb_ligne, nb_colone);YYABORT;
                                }

                        }
                ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 76 "syntaxique.y"
    {
                        if(get_sym((yyvsp[(2) - (2)].str))==NULL)
                        {
                                put_sym((yyvsp[(2) - (2)].str));
                                install_type((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].type));
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        } 
                ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 84 "syntaxique.y"
    {
                        
                        quadr("ADEC", (yyvsp[(2) - (4)].str), "vide", "vide");
                ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 91 "syntaxique.y"
    {
                        if(get_sym((yyvsp[(1) - (2)].str))==NULL)
                        {
                                put_sym((yyvsp[(1) - (2)].str));
                                push((yyvsp[(1) - (2)].str));
                                quadr("=","temp", "vide", (yyvsp[(1) - (2)].str) );
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }
                ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 102 "syntaxique.y"
    {
                        if(get_sym((yyvsp[(1) - (4)].str))==NULL)
                        {
                                put_sym((yyvsp[(1) - (4)].str));
                                install_type((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].valtype).type);
                                install_value((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].valtype));
                                printf("val=%d, type = %c\n", (yyvsp[(3) - (4)].valtype).val.I, (yyvsp[(3) - (4)].valtype).type);
                                push((yyvsp[(1) - (4)].str));
                                quadr("=","temp", "vide", (yyvsp[(1) - (4)].str) );

                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }
                ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 117 "syntaxique.y"
    {
                        if(get_sym((yyvsp[(1) - (1)].str))==NULL)
                        {
                                put_sym((yyvsp[(1) - (1)].str));
                                push((yyvsp[(1) - (1)].str));
                                quadr("=","temp", "vide", (yyvsp[(1) - (1)].str) );
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }
                ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 128 "syntaxique.y"
    {
                        if(get_sym((yyvsp[(1) - (3)].str))==NULL)
                        {
                                put_sym((yyvsp[(1) - (3)].str));
                                install_type((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].valtype).type);
                                install_value((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].valtype));
                                push((yyvsp[(1) - (3)].str));
                                quadr("=","temp", "vide", (yyvsp[(1) - (3)].str) );

                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }
                ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 143 "syntaxique.y"
    {
                        if(get_sym((yyvsp[(1) - (3)].str))==NULL)
                        {
                                put_sym((yyvsp[(1) - (3)].str));
                                install_type((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].valtype).type);
                                install_value((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].valtype));

                                quadr("=","temp", "vide", (yyvsp[(1) - (3)].str) );
                        }else{
                                if(get_sym((yyvsp[(1) - (3)].str))->type==(yyvsp[(3) - (3)].valtype).type)
                                {
                                        install_value((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].valtype));

                                        quadr("=","temp", "vide", (yyvsp[(1) - (3)].str) );
                                }else{
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d type incompatibe\n", nb_ligne, nb_colone);YYABORT;
                                }
                        }
                ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 162 "syntaxique.y"
    {
                        if(get_sym((yyvsp[(1) - (6)].str))==NULL)
                        {
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }

                        if(get_sym((yyvsp[(1) - (6)].str))->type==(yyvsp[(6) - (6)].valtype).type)
                        {
                                sprintf(tmp, "%s[%s]", (yyvsp[(1) - (6)].str), (yyvsp[(3) - (6)].str));
                                quadr("=","temp", "vide", tmp);
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, type incompatibe.\n", nb_ligne, nb_colone);YYABORT;
                        }
                ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 178 "syntaxique.y"
    {
                (yyval.valtype)=(yyvsp[(1) - (1)].valtype);
        ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 181 "syntaxique.y"
    {(yyval.valtype)=(yyvsp[(1) - (1)].valtype);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 185 "syntaxique.y"
    {
                        sprintf(tmp, "%d", (yyvsp[(1) - (1)].valtype).val.I);
                        (yyval.str) = strdup(tmp);
                ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 190 "syntaxique.y"
    {
                        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
                ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 194 "syntaxique.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 195 "syntaxique.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 196 "syntaxique.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 197 "syntaxique.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 200 "syntaxique.y"
    {
                int max = (yyvsp[(2) - (3)].valtype).val.I;
                int i;
                
                for(i = 0; i<max; i++)
                {
                        sprintf(tmp, "%d", i);
                        quadr("BOUNDS", tmp, "vide", "vide");
                }
                        
        ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 213 "syntaxique.y"
    {
                sprintf(tmp, "%d", qc);
                ajour_quad(sauv_fin_if, 1, tmp);
        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 217 "syntaxique.y"
    {
                sprintf(tmp, "%d", qc);
                ajour_quad(sauv_fin_if, 1, tmp);
        ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 223 "syntaxique.y"
    {
                sauv_fin_if = qc;
                quadr("BR", "fin", "vide", "vide");

                sprintf(tmp, "%d", qc);
                ajour_quad(sauv_debut_if, 1, tmp);
        ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 232 "syntaxique.y"
    {
                sauv_debut_if = qc;
                quadr("BZ", "fin", "condition.temp", "vide");

                if((yyvsp[(3) - (6)].valtype).type != BOOL)
                {
                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d type incompatibe\n", nb_ligne, nb_colone);YYABORT;
                }
        ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 246 "syntaxique.y"
    {
                sprintf(tmp, "%d", sauv_debut_while);
                quadr("BR", tmp, "vide", "vide");
                sprintf(tmp, "%d", qc);
                ajour_quad(sauv_debut_while, 1, tmp);
        ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 254 "syntaxique.y"
    {
                sauv_debut_while = qc; 
                quadr("BZ", "fin", "condition.temp", "vide");
        ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 261 "syntaxique.y"
    {
        sprintf(tmp, "%d", sauve_debut_for);
        quadr("BR", tmp, "vide", "vide");
        sprintf(tmp, "%d", qc);
        ajour_quad(sauve_debut_for, 1, tmp);
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 270 "syntaxique.y"
    {
                if(get_sym((yyvsp[(2) - (2)].str))==NULL)
                {
                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, identificateur non declarer.\n", nb_ligne, nb_colone);YYABORT; 
                }
        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 277 "syntaxique.y"
    {
        if((yyvsp[(3) - (6)].valtype).type != INT || (yyvsp[(5) - (6)].valtype).type != INT)
        {
                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, range must be of type int.\n", nb_ligne, nb_colone);YYABORT;
        }
        if((yyvsp[(3) - (6)].valtype).val.I > (yyvsp[(5) - (6)].valtype).val.I)
        {
                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, negative range not allowed.\n", nb_ligne, nb_colone);YYABORT;
        }

        quadr("=", "rangeMin" ,"vide", "idf");
        sauve_debut_for = qc;
        quadr("BG" ,"fin", "idf", "rangeMax");
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 292 "syntaxique.y"
    {
        if(get_sym((yyvsp[(2) - (3)].str))==NULL)
        {
               printf("ERROR SEMENTIQUE: ligne %d, colonne %d, identificateur non declarer.\n", nb_ligne, nb_colone);YYABORT; 
        }else{
                if(get_sym((yyvsp[(2) - (3)].str))->type != INT)
                {
                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d, invalid type in for loop.\n", nb_ligne, nb_colone);YYABORT; 
                }
        }
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 312 "syntaxique.y"
    {
                        (yyval.valtype).type = BOOL;
                        if((yyvsp[(1) - (3)].valtype).type==BOOL && (yyvsp[(3) - (3)].valtype).type==BOOL)
                        {
                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.B && (yyvsp[(3) - (3)].valtype).val.B;

                                int sauv_bz1 = qc;
                                quadr("BZ", "vide", "opd1", "vide"); 

                                int sauv_bz2 = qc;
                                quadr("BZ", "vide", "opd2", "vide"); 

                                quadr("=", "1", "vide", "temp");

                                int sauv_br = qc;
                                quadr("BR", "vide", "vide", "vide"); 
                                
                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz1, 1, tmp);
                                ajour_quad(sauv_bz2, 1, tmp);
                                quadr("=", "0", "vide", "temp");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                                
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                        }
                ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 342 "syntaxique.y"
    {
                        (yyval.valtype).type = BOOL;
                        if((yyvsp[(1) - (3)].valtype).type==BOOL && (yyvsp[(3) - (3)].valtype).type==BOOL)
                        {
                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.B || (yyvsp[(3) - (3)].valtype).val.B;

                                int sauv_bnz1 = qc;
                                quadr("BNZ", "vide", "opd1", "vide"); 

                                int sauv_bnz2 = qc;
                                quadr("BNZ", "vide", "opd2", "vide"); 

                                quadr("=", "0", "vide", "temp");

                                int sauv_br = qc;
                                quadr("BR", "vide", "vide", "vide"); 
                                
                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bnz1, 1, tmp);
                                ajour_quad(sauv_bnz2, 1, tmp);
                                quadr("=", "1", "vide", "temp");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                        }
                ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 371 "syntaxique.y"
    {
                        (yyval.valtype).type = BOOL;
                        if((yyvsp[(2) - (2)].valtype).type==BOOL)
                        {
                                (yyval.valtype).val.B = !(yyvsp[(2) - (2)].valtype).val.B;

                                int sauv_bz = qc;
                                quadr("BZ", "vide", "opd", "vide"); 

                                quadr("=", "0", "vide", "temp");

                                int sauv_br = qc;
                                quadr("BR", "vide", "vide", "vide"); 
                                
                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=", "1", "vide", "temp");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                        }
                ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 398 "syntaxique.y"
    {
                                (yyval.valtype).type = BOOL;

                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I == (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I == (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F == (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F == (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BZ", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);

                        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 454 "syntaxique.y"
    {
                                (yyval.valtype).type = BOOL;

                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I != (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I != (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F != (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F != (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BZ", "faux", "T0", "vide");

                                quadr("=", "1", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","0","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 509 "syntaxique.y"
    {
                                (yyval.valtype).type = BOOL;

                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I <= (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I <= (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F <= (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F <= (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BMZ", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 564 "syntaxique.y"
    {
                                (yyval.valtype).type = BOOL;

                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I >= (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I >= (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F >= (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F >= (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BPZ", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                        ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 619 "syntaxique.y"
    {
                                (yyval.valtype).type = BOOL;

                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I < (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I < (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F < (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F < (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BM", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 674 "syntaxique.y"
    {
                                (yyval.valtype).type = BOOL;

                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I > (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.I > (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F > (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).val.B = (yyvsp[(1) - (3)].valtype).val.F > (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BP", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 731 "syntaxique.y"
    {
                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).type = INT;
                                                (yyval.valtype).val.I = (yyvsp[(1) - (3)].valtype).val.I * (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.I * (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.F * (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.F * (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                                
                                quadr("*","opd1","opd2","temp");
                        ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 773 "syntaxique.y"
    {
                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                if((yyvsp[(3) - (3)].valtype).val.I == 0){
                                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d division par 0.", nb_ligne, nb_colone);
                                                        YYABORT;
                                                        break;
                                                }else{
                                                        (yyval.valtype).type = FLOAT;
                                                        (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.I / (yyvsp[(3) - (3)].valtype).val.I;
                                                        break;
                                                }
                                        case FLOAT:
                                                if((yyvsp[(3) - (3)].valtype).val.F == 0){
                                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d division par 0.", nb_ligne, nb_colone);
                                                        YYABORT;
                                                        break;
                                                }else{
                                                        (yyval.valtype).type = FLOAT;
                                                        (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.I / (yyvsp[(3) - (3)].valtype).val.F;
                                                        break;
                                                }
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                if((yyvsp[(3) - (3)].valtype).val.I == 0){
                                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d division par 0.", nb_ligne, nb_colone);
                                                        YYABORT;
                                                        break;
                                                }else{
                                                        (yyval.valtype).type = FLOAT;
                                                        (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.F / (yyvsp[(3) - (3)].valtype).val.I;                                
                                                        break;
                                                }
                                        case FLOAT:
                                                if((yyvsp[(3) - (3)].valtype).val.F == 0){

                                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d division par 0.", nb_ligne, nb_colone);
                                                        YYABORT;
                                                        break;
                                                }else{
                                                        (yyval.valtype).type = FLOAT;
                                                        (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.F / (yyvsp[(3) - (3)].valtype).val.F;
                                                        break;
                                                }
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                                quadr("/","opd1","opd2","temp");
                        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 839 "syntaxique.y"
    {
                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).type = INT;
                                                (yyval.valtype).val.I = (yyvsp[(1) - (3)].valtype).val.I + (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.I + (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.F + (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.F + (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }

                                quadr("+","opd1","opd2","temp");
                        ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 881 "syntaxique.y"
    {
                                switch((yyvsp[(1) - (3)].valtype).type){
                                case INT :
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).type = INT;
                                                (yyval.valtype).val.I = (yyvsp[(1) - (3)].valtype).val.I - (yyvsp[(3) - (3)].valtype).val.I;
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.I - (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch((yyvsp[(3) - (3)].valtype).type){
                                        case INT :
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.F - (yyvsp[(3) - (3)].valtype).val.I;                                
                                                break;
                                        case FLOAT:
                                                (yyval.valtype).type = FLOAT;
                                                (yyval.valtype).val.F = (yyvsp[(1) - (3)].valtype).val.F - (yyvsp[(3) - (3)].valtype).val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }

                                quadr("-","opd1","opd2","temp");
                        ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 925 "syntaxique.y"
    {
                symrec *elem = get_sym((yyvsp[(1) - (1)].str));
                if(elem == NULL)
                {
                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d variable (%s) not declared.\n", nb_ligne, nb_colone, (yyvsp[(1) - (1)].str));YYABORT;
                }else{
                        (yyval.valtype).type = elem->type;
                        switch (elem->type)
                        {
                        case INT :
                        (yyval.valtype).val.I = elem->value.I;
                        break;
                        case FLOAT :
                        (yyval.valtype).val.F = elem->value.F;
                        break;
                        case CHAR :
                        (yyval.valtype).val.C = elem->value.C;
                        break;
                        case BOOL :
                        (yyval.valtype).val.B = elem->value.B;
                        break;
                
                        default:
                        printf("ERROR: UNKNOWN TYPE\n");
                        break;
                        }
                }
                
        ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 955 "syntaxique.y"
    {       
                (yyval.valtype) = (yyvsp[(1) - (1)].valtype);
        ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 959 "syntaxique.y"
    {
                (yyval.valtype) = (yyvsp[(1) - (1)].valtype);
        ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 963 "syntaxique.y"
    {
                (yyval.valtype) = (yyvsp[(1) - (1)].valtype);
        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 967 "syntaxique.y"
    {
                (yyval.valtype) = (yyvsp[(1) - (1)].valtype);
        ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 971 "syntaxique.y"
    {
                (yyval.valtype) = (yyvsp[(1) - (1)].valtype);
        ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 975 "syntaxique.y"
    {
                (yyval.valtype) = (yyvsp[(1) - (1)].valtype);
        ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 979 "syntaxique.y"
    {
                (yyval.valtype) = (yyvsp[(2) - (3)].valtype);
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2669 "syntaxique.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 985 "syntaxique.y"


main()
{
        Init_TS();
        yyparse();
        print_table();
        Print_TS();
        afficher_qdr();
}
yywrap()
{

}
int yyerror (char *msg)
{
        printf ("ERREUR SYNTAXIQUE: ligne %d, colonne %d \n",nb_ligne,nb_colone); 
        exit(0);
}

