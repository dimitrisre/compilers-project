/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTCONST = 258,
     FLOATCONST = 259,
     STRING = 260,
     ID = 261,
     IF_KEYWORD = 262,
     FOR_KEYWORD = 263,
     ELSE_KEYWORD = 264,
     FUNCTION_KEYWORD = 265,
     WHILE_KEYWORD = 266,
     RETURN_KEYWORD = 267,
     BREAK_KEYWORD = 268,
     CONTINUE_KEYWORD = 269,
     LOCAL_KEYWORD = 270,
     TRUE_KEYWORD = 271,
     FALSE_KEYWORD = 272,
     NIL_KEYWORD = 273,
     AND_KEYWORD = 274,
     OR_KEYWORD = 275,
     NOT_KEYWORD = 276,
     GLOBAL_KEYWORD = 277,
     PLUSPLUS_OP = 278,
     SUBSUB_OP = 279,
     MULL_OP = 280,
     DIV_OP = 281,
     EQ_OP = 282,
     PLUS_OP = 283,
     SUB_OP = 284,
     ASS_OP = 285,
     NEQ_OP = 286,
     MOD_OP = 287,
     GEQ_OP = 288,
     LEQ_OP = 289,
     GRE_OP = 290,
     LESS_OP = 291,
     L_PAR = 292,
     R_PAR = 293,
     L_AG = 294,
     R_AG = 295,
     L_BR = 296,
     R_BR = 297,
     COMMA = 298,
     SEMICOL = 299,
     FULLST = 300,
     D_FULLST = 301,
     ILLEGAL = 302,
     UMINUS = 303
   };
#endif
#define INTCONST 258
#define FLOATCONST 259
#define STRING 260
#define ID 261
#define IF_KEYWORD 262
#define FOR_KEYWORD 263
#define ELSE_KEYWORD 264
#define FUNCTION_KEYWORD 265
#define WHILE_KEYWORD 266
#define RETURN_KEYWORD 267
#define BREAK_KEYWORD 268
#define CONTINUE_KEYWORD 269
#define LOCAL_KEYWORD 270
#define TRUE_KEYWORD 271
#define FALSE_KEYWORD 272
#define NIL_KEYWORD 273
#define AND_KEYWORD 274
#define OR_KEYWORD 275
#define NOT_KEYWORD 276
#define GLOBAL_KEYWORD 277
#define PLUSPLUS_OP 278
#define SUBSUB_OP 279
#define MULL_OP 280
#define DIV_OP 281
#define EQ_OP 282
#define PLUS_OP 283
#define SUB_OP 284
#define ASS_OP 285
#define NEQ_OP 286
#define MOD_OP 287
#define GEQ_OP 288
#define LEQ_OP 289
#define GRE_OP 290
#define LESS_OP 291
#define L_PAR 292
#define R_PAR 293
#define L_AG 294
#define R_AG 295
#define L_BR 296
#define R_BR 297
#define COMMA 298
#define SEMICOL 299
#define FULLST 300
#define D_FULLST 301
#define ILLEGAL 302
#define UMINUS 303




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<math.h>
	#include"scanner.h"
	#include"token.h"
	#include"symboltable.h"
	#include"scopes.h"
	#include <time.h>

	extern int   yylineno;
	extern char *yytext;
	extern FILE *yyin,*yyout;
	extern int MaxScope;
	int yyerror(char *);
	struct alpha_token_t *new;
	int Scope = 0,upScope=0,upScope2=0;
	FILE *sym_file;
	char * func_name, *id_tmp;
	
	


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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 24 "parser.y"
typedef union token_A{

	  int ival;
	  float fval;
	  char *sval;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 203 "parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 215 "parser.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   659

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  37
/* YYNRULES -- Number of rules. */
#define YYNRULES  97
/* YYNRULES -- Number of states. */
#define YYNSTATES  177

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    17,    19,
      21,    23,    25,    28,    31,    33,    35,    37,    39,    43,
      47,    51,    55,    59,    63,    67,    71,    75,    79,    83,
      87,    91,    93,    97,   100,   103,   106,   109,   112,   115,
     117,   121,   123,   125,   127,   131,   133,   135,   138,   141,
     143,   145,   148,   152,   157,   161,   166,   171,   176,   183,
     186,   187,   190,   191,   194,   197,   200,   201,   204,   210,
     214,   216,   218,   219,   224,   225,   226,   235,   237,   238,
     240,   242,   244,   246,   248,   250,   253,   254,   257,   260,
     261,   268,   271,   272,   278,   288,   292,   294
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      50,     0,    -1,    51,    -1,    52,    51,    -1,    -1,     1,
      52,    -1,    47,    -1,    53,    44,    -1,    80,    -1,    82,
      -1,    83,    -1,    84,    -1,    13,    44,    -1,    14,    44,
      -1,    70,    -1,    72,    -1,    44,    -1,    55,    -1,    53,
      28,    53,    -1,    53,    29,    53,    -1,    53,    25,    53,
      -1,    53,    26,    53,    -1,    53,    27,    53,    -1,    53,
      31,    53,    -1,    53,    32,    53,    -1,    53,    33,    53,
      -1,    53,    34,    53,    -1,    53,    35,    53,    -1,    53,
      36,    53,    -1,    53,    19,    53,    -1,    53,    20,    53,
      -1,    54,    -1,    37,    53,    38,    -1,    29,    53,    -1,
      21,    53,    -1,    23,    57,    -1,    57,    23,    -1,    24,
      57,    -1,    57,    24,    -1,    56,    -1,    57,    30,    53,
      -1,    57,    -1,    60,    -1,    68,    -1,    37,    72,    38,
      -1,    76,    -1,     6,    -1,    15,     6,    -1,    58,     6,
      -1,    59,    -1,    22,    -1,    46,    46,    -1,    57,    45,
       6,    -1,    57,    41,    53,    42,    -1,    60,    45,     6,
      -1,    60,    41,    53,    42,    -1,    60,    37,    61,    38,
      -1,    57,    37,    61,    38,    -1,    37,    72,    38,    37,
      61,    38,    -1,    53,    62,    -1,    -1,    63,    62,    -1,
      -1,    43,    53,    -1,    67,    65,    -1,    66,    65,    -1,
      -1,    43,    67,    -1,    39,    53,    46,    53,    40,    -1,
      41,    69,    42,    -1,    61,    -1,    64,    -1,    -1,    39,
      71,    51,    40,    -1,    -1,    -1,    10,    75,    37,    73,
      77,    38,    74,    70,    -1,     6,    -1,    -1,     3,    -1,
       4,    -1,     5,    -1,    18,    -1,    16,    -1,    17,    -1,
       6,    79,    -1,    -1,    43,     6,    -1,    78,    79,    -1,
      -1,     7,    37,    53,    38,    52,    81,    -1,     9,    52,
      -1,    -1,    11,    37,    53,    38,    52,    -1,     8,    37,
      61,    44,    53,    44,    61,    38,    52,    -1,    12,    85,
      44,    -1,    53,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    64,    64,    67,    68,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   104,   105,   106,   107,   108,   109,   110,   111,
     114,   117,   118,   119,   120,   121,   124,   128,   132,   136,
     141,   142,   144,   148,   150,   156,   159,   160,   161,   164,
     165,   168,   169,   172,   175,   178,   179,   181,   185,   188,
     191,   192,   195,   195,   201,   201,   201,   206,   214,   222,
     223,   224,   225,   226,   227,   230,   240,   244,   253,   254,
     257,   260,   261,   264,   267,   270,   273,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONST", "FLOATCONST", "STRING", "ID",
  "IF_KEYWORD", "FOR_KEYWORD", "ELSE_KEYWORD", "FUNCTION_KEYWORD",
  "WHILE_KEYWORD", "RETURN_KEYWORD", "BREAK_KEYWORD", "CONTINUE_KEYWORD",
  "LOCAL_KEYWORD", "TRUE_KEYWORD", "FALSE_KEYWORD", "NIL_KEYWORD",
  "AND_KEYWORD", "OR_KEYWORD", "NOT_KEYWORD", "GLOBAL_KEYWORD",
  "PLUSPLUS_OP", "SUBSUB_OP", "MULL_OP", "DIV_OP", "EQ_OP", "PLUS_OP",
  "SUB_OP", "ASS_OP", "NEQ_OP", "MOD_OP", "GEQ_OP", "LEQ_OP", "GRE_OP",
  "LESS_OP", "L_PAR", "R_PAR", "L_AG", "R_AG", "L_BR", "R_BR", "COMMA",
  "SEMICOL", "FULLST", "D_FULLST", "ILLEGAL", "UMINUS", "$accept",
  "programm", "stmts", "stmt", "expr", "term", "assignexpr", "primary",
  "lvalue", "glbl", "tableitem", "call", "elist", "elist1s", "elist1",
  "indexed", "ind1s", "ind1", "indexedelem", "tablemake", "tsize", "block",
  "@1", "funcdef", "@2", "@3", "fid", "const", "idlist", "id1", "id1s",
  "ifstmt", "elsestmt", "whilestmt", "forstmt", "returnstmt", "prexpr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    56,    56,    56,    56,    56,    57,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    60,    60,    60,    61,
      61,    62,    62,    63,    64,    65,    65,    66,    67,    68,
      69,    69,    71,    70,    73,    74,    72,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    78,    79,    79,
      80,    81,    81,    82,    83,    84,    85,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       1,     2,     3,     4,     3,     4,     4,     4,     6,     2,
       0,     2,     0,     2,     2,     2,     0,     2,     5,     3,
       1,     1,     0,     4,     0,     0,     8,     1,     0,     1,
       1,     1,     1,     1,     1,     2,     0,     2,     2,     0,
       6,     2,     0,     5,     9,     3,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,    79,    80,    81,    46,     0,     0,    78,     0,
      97,     0,     0,     0,    83,    84,    82,     0,    50,     0,
       0,     0,     0,    72,    60,    16,     0,     6,     0,     2,
       0,     0,    31,    17,    39,    41,     0,    49,    42,    43,
      14,    15,    45,     8,     9,    10,    11,     5,     0,    60,
      77,     0,     0,    96,     0,    12,    13,    47,    34,     0,
      35,     0,    37,    33,     0,     0,     0,     0,    62,    70,
      71,    66,     0,    51,     1,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
      36,    38,     0,    60,     0,     0,    48,    60,     0,     0,
       0,     0,    74,     0,    95,     0,    32,    44,     0,     0,
       0,    59,    62,     0,    64,    66,    69,    29,    30,    20,
      21,    22,    18,    19,    23,    24,    25,    26,    27,    28,
      40,     0,     0,    52,     0,     0,    54,     0,     0,    86,
       0,     0,    60,    73,     0,    63,    61,    67,    65,    57,
      53,    56,    55,    92,     0,    89,     0,    93,     0,     0,
       0,    90,    60,     0,    89,    85,    75,    58,    68,    91,
       0,    87,    88,     0,     0,    76,    94
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    69,   111,   112,    70,   114,   115,    71,    39,
      72,    40,    66,    41,   139,   173,    51,    42,   156,   164,
     165,    43,   161,    44,    45,    46,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const short int yypact[] =
{
     212,   306,   -48,   -48,   -48,   -48,   -34,   -27,    15,   -23,
     351,   -13,    -7,    38,   -48,   -48,   -48,   351,   -48,    14,
      14,   351,     1,   -48,   101,   -48,    16,   -48,    59,   -48,
     164,   396,   -48,   -48,   -48,    11,    58,   -48,    12,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   351,   351,
     -48,    28,   351,   569,    22,   -48,   -48,   -48,   -48,    70,
      45,    12,    45,   -48,   509,    43,   259,   351,   436,   -48,
     -48,    44,    49,   -48,   -48,   -48,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   -48,
     -48,   -48,   351,   351,   351,    86,   -48,   351,   351,    87,
     529,    50,   -48,   549,   -48,    60,   -48,    62,    56,   374,
     351,   -48,    54,    61,   -48,    44,   -48,   599,   587,   -48,
     -48,   611,    29,    29,   611,   -48,   623,   623,   623,   623,
     -48,    64,   455,   -48,    65,   473,   -48,   306,   351,   102,
     306,    62,   351,   -48,   351,   569,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   100,   416,    67,    73,   -48,    74,   491,
     306,   -48,   351,   107,    67,   -48,   -48,   -48,   -48,   -48,
      76,   -48,   -48,    81,   306,   -48,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -48,   -48,   -21,    -1,    -9,   -48,   -48,   -48,     8,   -48,
     -48,    13,   -47,     9,   -48,   -48,    17,   -48,    18,   -48,
     -48,   -46,   -48,     4,   -48,   -48,   -48,   -48,   -48,   -48,
     -38,   -48,   -48,   -48,   -48,   -48,   -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const short int yytable[] =
{
      47,    53,   101,    48,     2,     3,     4,     5,    58,    75,
      49,     8,    63,    64,    52,    68,    13,    14,    15,    16,
       5,    50,    17,    18,    19,    20,    65,    60,    62,    13,
      21,    55,    61,    61,    90,    91,    18,    56,    22,   100,
      68,    92,    24,   103,    57,   108,   131,    26,    93,    97,
     134,    59,    94,    98,    78,    79,    95,    99,   109,    74,
      26,    84,    73,   105,    96,   102,   104,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       8,   107,    93,   130,    68,   132,    94,   113,    68,   135,
      95,   116,   133,   136,   138,   158,   143,   110,   141,   142,
      67,   145,   149,   151,     2,     3,     4,     5,   155,   160,
     163,   166,   167,   171,   174,   170,    13,    14,    15,    16,
      23,   146,    17,    18,    19,    20,   172,   175,     0,   154,
      21,   147,   148,    68,     0,   159,   153,     0,    22,   157,
      67,     0,    24,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,   169,
       0,     0,     0,     0,    -4,     1,     0,     2,     3,     4,
       5,     6,     7,   176,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,    17,    18,    19,    20,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,    22,     0,    23,    -4,    24,     0,     0,    25,     0,
      26,    27,    -4,     1,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,    17,    18,    19,    20,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    23,     0,    24,     0,     0,    25,     0,    26,    27,
       1,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
      17,    18,    19,    20,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,    22,     0,    23,    -4,
      24,     0,     0,    25,     0,    26,    27,     1,     0,     2,
       3,     4,     5,     6,     7,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,    17,    18,    19,
      20,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,    22,     0,    23,     0,    24,     0,     0,
      25,     0,    26,    27,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,    16,
       0,     0,    17,    18,    19,    20,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,    24,    76,    77,     0,     0,    26,     0,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,    76,    77,     0,     0,     0,
     144,    78,    79,    80,    81,    82,     0,    83,    84,    85,
      86,    87,    88,     0,     0,    76,    77,     0,     0,     0,
      89,    78,    79,    80,    81,    82,     0,    83,    84,    85,
      86,    87,    88,     0,     0,    76,    77,     0,     0,     0,
     162,    78,    79,    80,    81,    82,     0,    83,    84,    85,
      86,    87,    88,     0,    76,    77,     0,     0,     0,   110,
      78,    79,    80,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    76,    77,     0,     0,     0,   150,    78,    79,
      80,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      76,    77,     0,     0,     0,   152,    78,    79,    80,    81,
      82,     0,    83,    84,    85,    86,    87,    88,    76,    77,
       0,   168,     0,     0,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87,    88,     0,   106,    76,    77,
       0,     0,     0,     0,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87,    88,     0,   137,    76,    77,
       0,     0,     0,     0,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87,    88,     0,   140,    76,    77,
       0,     0,     0,     0,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    76,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,     0,    83,    84,
      85,    86,    87,    88,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    78,    79,    -5,    81,
      82,     0,    -5,    84,    85,    86,    87,    88,    78,    79,
       0,    81,    82,     0,     0,    84,    -5,    -5,    -5,    -5
};

static const short int yycheck[] =
{
       1,    10,    49,    37,     3,     4,     5,     6,    17,    30,
      37,    10,    21,    22,    37,    24,    15,    16,    17,    18,
       6,     6,    21,    22,    23,    24,    22,    19,    20,    15,
      29,    44,    19,    20,    23,    24,    22,    44,    37,    48,
      49,    30,    41,    52,     6,    66,    93,    46,    37,    37,
      97,    37,    41,    41,    25,    26,    45,    45,    67,     0,
      46,    32,    46,    59,     6,    37,    44,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      10,    38,    37,    92,    93,    94,    41,    43,    97,    98,
      45,    42,     6,     6,    44,   142,    40,    43,    38,    37,
      39,   110,    38,    38,     3,     4,     5,     6,     6,     9,
      43,    38,    38,     6,    38,   162,    15,    16,    17,    18,
      39,   112,    21,    22,    23,    24,   164,   173,    -1,   138,
      29,   113,   115,   142,    -1,   144,   137,    -1,    37,   140,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,   174,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    40,    41,    -1,    -1,    44,    -1,
      46,    47,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    -1,    41,    -1,    -1,    44,    -1,    46,    47,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,
      41,    -1,    -1,    44,    -1,    46,    47,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,
      44,    -1,    46,    47,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    41,    19,    20,    -1,    -1,    46,    -1,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      46,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    -1,    -1,    19,    20,    -1,    -1,    -1,
      44,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    -1,    -1,    19,    20,    -1,    -1,    -1,
      44,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    -1,    19,    20,    -1,    -1,    -1,    43,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    19,    20,    -1,    -1,    -1,    42,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      19,    20,    -1,    -1,    -1,    42,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    19,    20,
      -1,    40,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    25,    26,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    21,    22,    23,
      24,    29,    37,    39,    41,    44,    46,    47,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    68,
      70,    72,    76,    80,    82,    83,    84,    52,    37,    37,
       6,    75,    37,    53,    85,    44,    44,     6,    53,    37,
      57,    60,    57,    53,    53,    72,    71,    39,    53,    61,
      64,    67,    69,    46,     0,    51,    19,    20,    25,    26,
      27,    28,    29,    31,    32,    33,    34,    35,    36,    44,
      23,    24,    30,    37,    41,    45,     6,    37,    41,    45,
      53,    61,    37,    53,    44,    72,    38,    38,    51,    53,
      43,    62,    63,    43,    65,    66,    42,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    61,    53,     6,    61,    53,     6,    38,    44,    73,
      38,    38,    37,    40,    46,    53,    62,    67,    65,    38,
      42,    38,    42,    52,    53,     6,    77,    52,    61,    53,
       9,    81,    44,    43,    78,    79,    38,    38,    40,    52,
      61,     6,    79,    74,    38,    70,    52
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 64 "parser.y"
    {fprintf(yyout,"rule:programm->stmts\n");  ;}
    break;

  case 3:
#line 67 "parser.y"
    {fprintf(yyout,"rule:stmts->stmt stmts\n");;}
    break;

  case 4:
#line 68 "parser.y"
    {fprintf(yyout,"rule:stmts->empty\n");	   ;}
    break;

  case 5:
#line 72 "parser.y"
    {yyerrok;;}
    break;

  case 6:
#line 73 "parser.y"
    {yyerror("Parse error invalid character ");;}
    break;

  case 7:
#line 74 "parser.y"
    {fprintf(yyout,"rule:stmt->expr ;\n");	   ;}
    break;

  case 8:
#line 75 "parser.y"
    {fprintf(yyout,"rule:stmt->ifstmt\n");     ;}
    break;

  case 9:
#line 76 "parser.y"
    {fprintf(yyout,"rule:stmt->whilestmt\n");  ;}
    break;

  case 10:
#line 77 "parser.y"
    {fprintf(yyout,"rule:stmt->forstmt\n");	   ;}
    break;

  case 11:
#line 78 "parser.y"
    {fprintf(yyout,"rule:stmt->returnstmt\n"); ;}
    break;

  case 12:
#line 79 "parser.y"
    {fprintf(yyout,"rule:stmt->break;\n");     ;}
    break;

  case 13:
#line 80 "parser.y"
    {fprintf(yyout,"rule:stmt->continue;\n");  ;}
    break;

  case 14:
#line 81 "parser.y"
    {fprintf(yyout,"rule:stmt->block\n");      ;}
    break;

  case 15:
#line 82 "parser.y"
    {fprintf(yyout,"rule:stmt->funcdef\n");	   ;}
    break;

  case 16:
#line 83 "parser.y"
    {fprintf(yyout,"rule:stmt->;\n");		   ;}
    break;

  case 17:
#line 86 "parser.y"
    {fprintf(yyout,"rule:expr->assignexpr\n");   ;}
    break;

  case 18:
#line 87 "parser.y"
    {fprintf(yyout,"rule:expr->expr + expr\n");  ;}
    break;

  case 19:
#line 88 "parser.y"
    {fprintf(yyout,"rule:expr->expr - expr\n");  ;}
    break;

  case 20:
#line 89 "parser.y"
    {fprintf(yyout,"rule:expr->expr * expr\n");  ;}
    break;

  case 21:
#line 90 "parser.y"
    {fprintf(yyout,"rule:expr->expr / expr\n");  ;}
    break;

  case 22:
#line 91 "parser.y"
    {fprintf(yyout,"rule:expr->expr == expr\n"); ;}
    break;

  case 23:
#line 92 "parser.y"
    {fprintf(yyout,"rule:expr->expr != expr\n"); ;}
    break;

  case 24:
#line 93 "parser.y"
    {fprintf(yyout,"rule:expr->expr \% expr\n"); ;}
    break;

  case 25:
#line 94 "parser.y"
    {fprintf(yyout,"rule:expr->expr >= expr\n"); ;}
    break;

  case 26:
#line 95 "parser.y"
    {fprintf(yyout,"rule:expr->expr <= expr\n"); ;}
    break;

  case 27:
#line 96 "parser.y"
    {fprintf(yyout,"rule:expr->expr > expr\n");  ;}
    break;

  case 28:
#line 97 "parser.y"
    {fprintf(yyout,"rule:expr->expr < expr\n");  ;}
    break;

  case 29:
#line 98 "parser.y"
    {fprintf(yyout,"rule:expr->expr and expr\n");;}
    break;

  case 30:
#line 99 "parser.y"
    {fprintf(yyout,"rule:expr->expr or expr\n"); ;}
    break;

  case 31:
#line 100 "parser.y"
    {fprintf(yyout,"rule:expr->term\n");		 ;}
    break;

  case 32:
#line 104 "parser.y"
    {fprintf(yyout,"rule:term -> ( expr )\n"); ;}
    break;

  case 33:
#line 105 "parser.y"
    {fprintf(yyout,"rule:term -> - expr\n");   ;}
    break;

  case 34:
#line 106 "parser.y"
    {fprintf(yyout,"rule:term -> not expr\n"); ;}
    break;

  case 35:
#line 107 "parser.y"
    {fprintf(yyout,"rule:term -> ++ lvalue\n");;}
    break;

  case 36:
#line 108 "parser.y"
    {fprintf(yyout,"rule:term -> lvalue ++\n");;}
    break;

  case 37:
#line 109 "parser.y"
    {fprintf(yyout,"rule:term -> -- lvalue\n");;}
    break;

  case 38:
#line 110 "parser.y"
    {fprintf(yyout,"rule:term -> lvalue --\n");;}
    break;

  case 39:
#line 111 "parser.y"
    {fprintf(yyout,"rule:term -> primary\n");  ;}
    break;

  case 40:
#line 114 "parser.y"
    {fprintf(yyout,"rule:assignexpr -> lvalue = expr\n");;}
    break;

  case 41:
#line 117 "parser.y"
    {fprintf(yyout,"rule:primary -> lvalue\n");		;}
    break;

  case 42:
#line 118 "parser.y"
    {fprintf(yyout,"rule:primary -> call\n");		;}
    break;

  case 43:
#line 119 "parser.y"
    {fprintf(yyout,"rule:primary -> tablemake\n");	;}
    break;

  case 44:
#line 120 "parser.y"
    {fprintf(yyout,"rule:primary -> ( funcdef )\n");;}
    break;

  case 45:
#line 121 "parser.y"
    {fprintf(yyout,"rule:primary -> const\n");		;}
    break;

  case 46:
#line 124 "parser.y"
    { id_scope(yyvsp[0].sval,Scope,upScope,upScope2);
									  fprintf(yyout,"rule:lvalue -> ID\n"); 
									;}
    break;

  case 47:
#line 128 "parser.y"
    { local_id_scope(yyvsp[0].sval,Scope);
									  fprintf(yyout,"rule:lvalue -> local ID\n");
									;}
    break;

  case 48:
#line 132 "parser.y"
    { global_id_scope(yyvsp[0].sval,Scope);
	   								  fprintf(yyout,"rule:lvalue -> global ID\n");
									;}
    break;

  case 49:
#line 136 "parser.y"
    {fprintf(yyout,"rule:lvalue -> tableitem\n");;}
    break;

  case 52:
#line 144 "parser.y"
    { upScope=search_actFunc(Scope);
									  fprintf(yyout,"rule:tableitem -> lvalue . ID\n");
									;}
    break;

  case 53:
#line 148 "parser.y"
    {fprintf(yyout,"rule:tableitem -> lvalue ( expr )\n");;}
    break;

  case 54:
#line 150 "parser.y"
    { 
	   								  	upScope=search_actFunc(Scope);
										tableitem_scope(yyvsp[0].sval,Scope,upScope);
										fprintf(yyout,"rule:tableitem -> call . ID\n");
									;}
    break;

  case 55:
#line 156 "parser.y"
    {fprintf(yyout,"rule:tableitem -> call ( expr )\n");;}
    break;

  case 56:
#line 159 "parser.y"
    {fprintf(yyout,"rule:call -> call ( elist )\n");;}
    break;

  case 57:
#line 160 "parser.y"
    {fprintf(yyout,"rule:call -> lvalue ( elist)\n");;}
    break;

  case 58:
#line 161 "parser.y"
    {fprintf(yyout,"rule:call -> ( funcdef ) ( elist )\n");;}
    break;

  case 59:
#line 164 "parser.y"
    {fprintf(yyout,"rule:elist -> expr elist1s\n");;}
    break;

  case 60:
#line 165 "parser.y"
    {fprintf(yyout,"rule:elist -> empty\n");	   ;}
    break;

  case 61:
#line 168 "parser.y"
    {fprintf(yyout,"rule:elist1s -> elist1 elist1s\n");;}
    break;

  case 62:
#line 169 "parser.y"
    {fprintf(yyout,"rule:elist1s -> empty\n");		   ;}
    break;

  case 63:
#line 172 "parser.y"
    {fprintf(yyout,"rule:elist1 -> COMMA expr\n");;}
    break;

  case 64:
#line 175 "parser.y"
    {fprintf(yyout,"rule:indexed -> indexedelem ind1s\n");;}
    break;

  case 65:
#line 178 "parser.y"
    {fprintf(yyout,"rule:ind1s -> ind1 ind1s\n");;}
    break;

  case 66:
#line 179 "parser.y"
    {fprintf(yyout,"rule:ind1s -> empty");		 ;}
    break;

  case 67:
#line 181 "parser.y"
    {fprintf(yyout,"rule:ind1 -> COMMA indexedelem\n");;}
    break;

  case 68:
#line 185 "parser.y"
    {fprintf(yyout,"rule:indexedelem -> { expr : expr }\n");;}
    break;

  case 69:
#line 188 "parser.y"
    {fprintf(yyout,"rule:tablemake -> [ tsize ]\n");;}
    break;

  case 70:
#line 191 "parser.y"
    {fprintf(yyout,"rule:tsize ->  elist \n");;}
    break;

  case 71:
#line 192 "parser.y"
    {fprintf(yyout,"rule:tsize -> indexed\n");;}
    break;

  case 72:
#line 195 "parser.y"
    {++MaxScope; Scope++; ;}
    break;

  case 73:
#line 195 "parser.y"
    {	 Hide(Scope);
													 Scope--;
										 			fprintf(yyout,"rule:block -> { stmts }\n");
												;}
    break;

  case 74:
#line 201 "parser.y"
    {++MaxScope; Scope++;;}
    break;

  case 75:
#line 201 "parser.y"
    {insert_arguments(Scope);;}
    break;

  case 76:
#line 201 "parser.y"
    {
												Hide(Scope--);
												fprintf(yyout,"rule:funcdef -> function fid ( idlist ) block\n");
											;}
    break;

  case 77:
#line 206 "parser.y"
    {	 	
						func_name = strdup(yyvsp[0].sval);
						upScope=search_actFunc(Scope);
						fid_scope( func_name, Scope , upScope );
						fprintf(yyout,"rule:fid -> ID\n");
				
				;}
    break;

  case 78:
#line 214 "parser.y"
    {	   
	  					func_name = create_funcName(func_name);
	  					if (!lookup(func_name,Scope,2) )
						insert(Scope,func_name,yylineno,2);	
						fprintf(yyout,"rule:fid -> empty\n");
				;}
    break;

  case 79:
#line 222 "parser.y"
    {fprintf(yyout,"rule:const -> INTCONST\n");  ;}
    break;

  case 80:
#line 223 "parser.y"
    {fprintf(yyout,"rule:const -> FLOATCONST\n");;}
    break;

  case 81:
#line 224 "parser.y"
    {fprintf(yyout,"rule:const -> STRING\n");    ;}
    break;

  case 82:
#line 225 "parser.y"
    {fprintf(yyout,"rule:const -> nil\n");		 ;}
    break;

  case 83:
#line 226 "parser.y"
    {fprintf(yyout,"rule:const -> true\n");		 ;}
    break;

  case 84:
#line 227 "parser.y"
    {fprintf(yyout,"rule:const -> false\n");	 ;}
    break;

  case 85:
#line 230 "parser.y"
    {  
									if(!lookup(yyvsp[-1].sval,Scope,1) &&
									!lookup(yyvsp[-1].sval,Scope-1,2))
										insert(Scope,yyvsp[-1].sval,yylineno,1);
									else
										fprintf(stderr,"Redifine id:%s at line:%d\n",yyvsp[-1].sval,yylineno);
										
									fprintf(yyout,"rule:idlist -> ID id1s\n");
								;}
    break;

  case 86:
#line 240 "parser.y"
    {fprintf(yyout,"rule:idlist -> empty\n");;}
    break;

  case 87:
#line 244 "parser.y"
    {   if(!lookup(yyvsp[0].sval,Scope,1) && !lookup(yyvsp[0].sval,Scope-1,2))
								insert(Scope,yyvsp[0].sval,yylineno,1);
							else
								fprintf(stderr,"Redifine id:%s at line:%d\n",yyvsp[0].sval,yylineno);
								
							fprintf(yyout,"rule:id1 -> , ID\n");
						;}
    break;

  case 88:
#line 253 "parser.y"
    {fprintf(yyout,"rule:id1s -> id1 id1s\n");;}
    break;

  case 89:
#line 254 "parser.y"
    {fprintf(yyout,"rule:id1s -> empty\n");	  ;}
    break;

  case 90:
#line 257 "parser.y"
    {fprintf(yyout,"rule:ifstmt -> if ( expr ) stmt elsestmt\n");;}
    break;

  case 91:
#line 260 "parser.y"
    {fprintf(yyout,"rule:elsestmt -> else stmt\n");;}
    break;

  case 92:
#line 261 "parser.y"
    {fprintf(yyout,"rule:elsestmt -> empty");	   ;}
    break;

  case 93:
#line 264 "parser.y"
    {fprintf(yyout,"rule:whilestmt -> while ( expr ) stmt\n");;}
    break;

  case 94:
#line 267 "parser.y"
    {fprintf(yyout,"rule:forstmt -> for ( elist ; expr ; elist ) stmt\n");;}
    break;

  case 95:
#line 270 "parser.y"
    {fprintf(yyout,"rule:returnstmt -> return prexpr ;\n");;}
    break;

  case 96:
#line 273 "parser.y"
    {fprintf(yyout,"rule:prexpr -> expr\n"); ;}
    break;

  case 97:
#line 274 "parser.y"
    {fprintf(yyout,"rule:prexpr -> empty\n");;}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 1870 "parser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
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

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 278 "parser.y"


int main(int argc,char **argv){

	srand(time(NULL));

	new =(struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));
	
 
	new->s_value=(char *)malloc((MAX_LEXEME)*sizeof(char));

	ayylval = (void *) new;

	
	if( argc<2 ){
		printf("Error.No input file\n");
		return 1;
	}
	else{
		if(argc==2){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				printf("Error while opening the file\n");
				return 1;
			}
			yyout=stdout;
			sym_file=stdout;
		}
		if(argc==3){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				printf("Error while opening the input file\n");
				return 1;
			}
			if((yyout=fopen(argv[2],"w+"))==NULL){
				printf("Error while opening the output file\n");
				return 1;
			}
			sym_file=stdout;

		}
		if(argc==4){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				printf("Error while opening the input file\n");
				return 1;
			}
			if((yyout=fopen(argv[2],"w+"))==NULL){
				printf("Error while opening the output file\n");
				return 1;
			}
			if((sym_file=fopen(argv[3],"w+"))==NULL){
				printf("Error while opening the sym file file\n");
				return 1;
			}

		}

	}


	Init_symbolTable();
	
	yyparse();
	
	print();
	
    destroy_symboltable();
	
	free(new->s_value);
	
	free(new);
	
	fclose(yyin);
	
	fclose(yyout);
	
	fclose(sym_file);
	
	return 0;
}


int yyerror(char *yaccProvideMessage){
	fprintf(stderr,"%s at line %d ,before token:%s\n",yaccProvideMessage,yylineno,yytext);
	return 0;
}

