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
	#include <time.h>

	#include "scanner.h"
	#include "token.h"
	#include "symboltable.h"
	#include "scopes.h"
	#include "icode.h"

	extern int   yylineno , ScopeSpaceCounter;
	extern char *yytext;
	extern FILE *yyin,*yyout;
	extern int MaxScope;
	struct expr *elist_head=NULL;
	struct expr *index_head=NULL;
	extern void Loading(void);
	int loop = 0 , cont_loop = 0;
	int        yyerror(char *);
	struct     alpha_token_t *new;
	int    Scope = 0,upScope=0,upScope2=0,fn_i=0;
	FILE * sym_file, *quad_ofile;
	char * func_name, *id_tmp;
	char * fun_names[100]={"_?_"};
	char * file_name;
	int func_flag = 0;
	

	


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
#line 35 "parser.y"
typedef union token_A{

	  struct expr eval;
	  int ival;
	  float fval;
	  char *sval;
	
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 215 "parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 227 "parser.c"

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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   657

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  44
/* YYNRULES -- Number of rules. */
#define YYNRULES  107
/* YYNRULES -- Number of states. */
#define YYNSTATES  193

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
     143,   145,   148,   152,   157,   161,   166,   171,   176,   182,
     188,   193,   200,   203,   204,   207,   208,   211,   214,   217,
     218,   221,   227,   231,   233,   235,   236,   241,   242,   243,
     244,   254,   256,   257,   259,   261,   263,   265,   267,   269,
     272,   273,   276,   279,   280,   281,   288,   290,   291,   299,
     300,   304,   305,   306,   317,   319,   323,   325
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      50,     0,    -1,    51,    -1,    52,    51,    -1,    -1,     1,
      52,    -1,    47,    -1,    53,    44,    -1,    84,    -1,    81,
      -1,    88,    -1,    91,    -1,    13,    44,    -1,    14,    44,
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
      -1,    77,    -1,     6,    -1,    15,     6,    -1,    58,     6,
      -1,    59,    -1,    22,    -1,    46,    46,    -1,    57,    45,
       6,    -1,    57,    41,    53,    42,    -1,    60,    45,     6,
      -1,    60,    41,    53,    42,    -1,    60,    37,    61,    38,
      -1,     6,    37,    61,    38,    -1,    58,     6,    37,    61,
      38,    -1,    15,     6,    37,    61,    38,    -1,    59,    37,
      61,    38,    -1,    37,    72,    38,    37,    61,    38,    -1,
      53,    62,    -1,    -1,    63,    62,    -1,    -1,    43,    53,
      -1,    67,    65,    -1,    66,    65,    -1,    -1,    43,    67,
      -1,    39,    53,    46,    53,    40,    -1,    41,    69,    42,
      -1,    61,    -1,    64,    -1,    -1,    39,    71,    51,    40,
      -1,    -1,    -1,    -1,    10,    76,    73,    37,    74,    78,
      38,    75,    70,    -1,     6,    -1,    -1,     3,    -1,     4,
      -1,     5,    -1,    18,    -1,    16,    -1,    17,    -1,     6,
      80,    -1,    -1,    43,     6,    -1,    79,    80,    -1,    -1,
      -1,    11,    83,    53,    38,    82,    52,    -1,    37,    -1,
      -1,     7,    37,    53,    38,    85,    52,    86,    -1,    -1,
       9,    87,    52,    -1,    -1,    -1,     8,    37,    61,    90,
      53,    44,    61,    38,    89,    52,    -1,    44,    -1,    12,
      92,    44,    -1,    53,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    80,    80,    83,    84,    88,    89,    90,    91,    92,
      93,    94,    95,   105,   116,   122,   123,   127,   136,   144,
     153,   162,   171,   180,   189,   198,   208,   218,   228,   238,
     249,   258,   265,   266,   275,   283,   294,   323,   335,   361,
     366,   386,   390,   391,   392,   393,   399,   425,   448,   471,
     476,   477,   480,   517,   548,   578,   608,   643,   668,   696,
     721,   740,   748,   757,   760,   772,   775,   781,   793,   804,
     806,   811,   816,   819,   841,   868,   868,   873,   884,   885,
     873,   914,   953,   973,   974,   975,   976,   977,   978,   981,
     992,   996,  1005,  1006,  1010,  1010,  1022,  1026,  1026,  1031,
    1031,  1032,  1037,  1037,  1050,  1054,  1066,  1067
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
  "alpha_source_code", "stmts", "stmt", "expr", "term", "assignexpr",
  "primary", "lvalue", "glbl", "tableitem", "call", "elist", "elist1s",
  "elist1", "indexed", "ind1s", "ind1", "indexedelem", "tablemake",
  "tsize", "block", "@1", "funcdef", "@2", "@3", "@4", "fid", "const",
  "idlist", "id1", "id1s", "whilestmt", "@5", "a", "ifstmt", "@6",
  "elsestmt", "@7", "forstmt", "@8", "b", "returnstmt", "prexpr", 0
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
      58,    58,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    64,    65,    65,
      66,    67,    68,    69,    69,    71,    70,    73,    74,    75,
      72,    76,    76,    77,    77,    77,    77,    77,    77,    78,
      78,    79,    80,    80,    82,    81,    83,    85,    84,    87,
      86,    86,    89,    88,    90,    91,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       1,     2,     3,     4,     3,     4,     4,     4,     5,     5,
       4,     6,     2,     0,     2,     0,     2,     2,     2,     0,
       2,     5,     3,     1,     1,     0,     4,     0,     0,     0,
       9,     1,     0,     1,     1,     1,     1,     1,     1,     2,
       0,     2,     2,     0,     0,     6,     1,     0,     7,     0,
       3,     0,     0,    10,     1,     3,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,    83,    84,    85,    46,     0,     0,    82,     0,
     107,     0,     0,     0,    87,    88,    86,     0,    50,     0,
       0,     0,     0,    75,    63,    16,     0,     6,     0,     2,
       0,     0,    31,    17,    39,    41,     0,    49,    42,    43,
      14,    15,    45,     9,     8,    10,    11,     5,    63,     0,
      63,    81,    77,    96,     0,   106,     0,    12,    13,    47,
      34,     0,    35,     0,    37,    33,     0,     0,     0,     0,
      65,    73,    74,    69,     0,    51,     1,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,    36,    38,     0,     0,     0,    48,    63,    63,
       0,     0,     0,     0,     0,     0,     0,   105,    63,     0,
      32,    44,     0,     0,     0,    62,    65,     0,    67,    69,
      72,    29,    30,    20,    21,    22,    18,    19,    23,    24,
      25,    26,    27,    28,    40,     0,    52,    63,     0,     0,
       0,    54,    57,    97,   104,     0,    78,    94,     0,     0,
      63,    76,     0,    66,    64,    70,    68,    53,     0,    60,
      56,    55,     0,     0,    90,     0,    59,     0,     0,    58,
     101,    63,    93,     0,    95,    61,    71,    99,    98,     0,
       0,    93,    89,    79,     0,   102,    91,    92,     0,   100,
       0,    80,   103
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    28,    29,    30,    70,    32,    33,    34,    35,    36,
      37,    38,    71,   115,   116,    72,   118,   119,    73,    39,
      74,    40,    68,    41,   105,   164,   188,    52,    42,   173,
     181,   182,    43,   165,    54,    44,   162,   178,   184,    45,
     190,   145,    46,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -54
static const short int yypact[] =
{
     240,   334,   -54,   -54,   -54,   -31,   -26,   -13,    12,    -8,
     379,     4,     6,    47,   -54,   -54,   -54,   379,   -54,    55,
      55,   379,    10,   -54,   100,   -54,    17,   -54,    60,   -54,
     192,   424,   -54,   -54,   -54,    14,    56,    27,   -33,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   379,   379,
     379,   -54,   -54,   -54,   379,   597,    22,   -54,   -54,    28,
     -54,    61,   -22,   -33,   -22,   -54,   537,    34,   287,   379,
     464,   -54,   -54,    30,    32,   -54,   -54,   -54,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   -54,   -54,   -54,   379,   379,    69,    39,   379,   379,
     379,    85,    59,   557,    49,    62,   577,   -54,   379,    64,
     -54,    70,    58,   402,   379,   -54,    65,    71,   -54,    30,
     -54,   122,   142,   -54,   -54,   609,    20,    20,   609,   -54,
     621,   621,   621,   621,   597,   483,   -54,   379,    73,    74,
     501,   -54,   -54,   -54,   -54,   379,   -54,   -54,    75,    70,
     379,   -54,   379,   597,   -54,   -54,   -54,   -54,    81,   -54,
     -54,   -54,   334,   444,   114,   334,   -54,    87,   519,   -54,
     117,   379,    84,    90,   -54,   -54,   -54,   -54,   -54,    93,
     126,    84,   -54,   -54,   334,   -54,   -54,   -54,    94,   -54,
     334,   -54,   -54
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -54,   -54,   -25,     1,     0,   -54,   -54,   -54,    16,   -54,
     -54,    21,   -41,    18,   -54,   -54,    19,   -54,    23,   -54,
     -54,   -53,   -54,   -19,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -45,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const short int yytable[] =
{
      31,    31,    47,    67,    99,    77,    48,   102,   100,   104,
      55,    49,   101,     2,     3,     4,     5,    60,    51,    95,
       8,    65,    66,    96,    50,    13,    14,    15,    16,    53,
      31,    17,    18,    19,    20,    62,    64,    92,    93,    21,
      63,    63,   109,   112,    94,    80,    81,    22,    57,   103,
      58,    24,    86,    59,   106,    95,    26,   138,   139,    96,
      76,     5,    97,    75,    98,   108,   107,   148,    31,   113,
      13,     8,   111,   117,   120,   136,   137,    18,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   141,    61,   144,   134,   135,   158,   142,   151,   146,
     140,    26,   149,     2,     3,     4,     5,   150,   114,   167,
      69,   159,   160,   166,   153,    13,    14,    15,    16,   169,
     172,    17,    18,    19,    20,   175,   177,   180,   183,    21,
     179,   185,   186,    23,   154,   191,   187,    22,   156,    69,
     155,    24,     0,     0,     0,   163,    26,    80,    81,    82,
      83,    84,   168,    85,    86,    87,    88,    89,    90,     0,
       0,    78,    31,   170,     0,    31,   174,    80,    81,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    31,   189,     0,     0,     0,     0,
      31,   192,    -4,     1,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,    17,    18,    19,    20,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    23,    -4,    24,     0,     0,    25,     0,    26,    27,
      -4,     1,     0,     2,     3,     4,     5,     6,     7,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,    17,    18,    19,    20,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,    22,     0,    23,
       0,    24,     0,     0,    25,     0,    26,    27,     1,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,    17,    18,
      19,    20,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,    22,     0,    23,    -4,    24,     0,
       0,    25,     0,    26,    27,     1,     0,     2,     3,     4,
       5,     6,     7,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,    17,    18,    19,    20,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,    22,     0,    23,     0,    24,     0,     0,    25,     0,
      26,    27,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,    16,     0,     0,
      17,    18,    19,    20,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
      24,    78,    79,     0,     0,    26,     0,    80,    81,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,    78,    79,     0,     0,     0,   152,    80,
      81,    82,    83,    84,     0,    85,    86,    87,    88,    89,
      90,     0,     0,    78,    79,     0,     0,     0,    91,    80,
      81,    82,    83,    84,     0,    85,    86,    87,    88,    89,
      90,     0,     0,    78,    79,     0,     0,     0,   171,    80,
      81,    82,    83,    84,     0,    85,    86,    87,    88,    89,
      90,     0,    78,    79,     0,     0,     0,   114,    80,    81,
      82,    83,    84,     0,    85,    86,    87,    88,    89,    90,
      78,    79,     0,     0,     0,   157,    80,    81,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,    78,    79,
       0,     0,     0,   161,    80,    81,    82,    83,    84,     0,
      85,    86,    87,    88,    89,    90,    78,    79,     0,   176,
       0,     0,    80,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,     0,   110,    78,    79,     0,     0,
       0,     0,    80,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,     0,   143,    78,    79,     0,     0,
       0,     0,    80,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,     0,   147,    78,    79,     0,     0,
       0,     0,    80,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,    80,    81,    -5,    83,    84,     0,
      -5,    86,    87,    88,    89,    90,    80,    81,     0,    83,
      84,     0,     0,    86,    -5,    -5,    -5,    -5
};

static const short int yycheck[] =
{
       0,     1,     1,    22,    37,    30,    37,    48,    41,    50,
      10,    37,    45,     3,     4,     5,     6,    17,     6,    41,
      10,    21,    22,    45,    37,    15,    16,    17,    18,    37,
      30,    21,    22,    23,    24,    19,    20,    23,    24,    29,
      19,    20,    61,    68,    30,    25,    26,    37,    44,    49,
      44,    41,    32,     6,    54,    41,    46,    98,    99,    45,
       0,     6,     6,    46,    37,    37,    44,   108,    68,    69,
      15,    10,    38,    43,    42,     6,    37,    22,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     6,    37,    44,    94,    95,   137,    38,    40,    37,
     100,    46,    38,     3,     4,     5,     6,    37,    43,   150,
      39,    38,    38,    38,   114,    15,    16,    17,    18,    38,
       6,    21,    22,    23,    24,    38,     9,    43,    38,    29,
     171,    38,     6,    39,   116,   188,   181,    37,   119,    39,
     117,    41,    -1,    -1,    -1,   145,    46,    25,    26,    27,
      28,    29,   152,    31,    32,    33,    34,    35,    36,    -1,
      -1,    19,   162,   162,    -1,   165,   165,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,   184,   184,    -1,    -1,    -1,    -1,
     190,   190,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    40,    41,    -1,    -1,    44,    -1,    46,    47,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,
      -1,    41,    -1,    -1,    44,    -1,    46,    47,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,
      -1,    44,    -1,    46,    47,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    -1,    41,    -1,    -1,    44,    -1,
      46,    47,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    19,    20,    -1,    -1,    46,    -1,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    46,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    -1,    -1,    19,    20,    -1,    -1,    -1,    44,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    -1,    -1,    19,    20,    -1,    -1,    -1,    44,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    -1,    19,    20,    -1,    -1,    -1,    43,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      19,    20,    -1,    -1,    -1,    42,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    19,    20,
      -1,    -1,    -1,    42,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    19,    20,    -1,    40,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    -1,    38,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    -1,    38,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    -1,    38,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    25,    26,    -1,    28,
      29,    -1,    -1,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    21,    22,    23,
      24,    29,    37,    39,    41,    44,    46,    47,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    68,
      70,    72,    77,    81,    84,    88,    91,    52,    37,    37,
      37,     6,    76,    37,    83,    53,    92,    44,    44,     6,
      53,    37,    57,    60,    57,    53,    53,    72,    71,    39,
      53,    61,    64,    67,    69,    46,     0,    51,    19,    20,
      25,    26,    27,    28,    29,    31,    32,    33,    34,    35,
      36,    44,    23,    24,    30,    41,    45,     6,    37,    37,
      41,    45,    61,    53,    61,    73,    53,    44,    37,    72,
      38,    38,    51,    53,    43,    62,    63,    43,    65,    66,
      42,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,     6,    37,    61,    61,
      53,     6,    38,    38,    44,    90,    37,    38,    61,    38,
      37,    40,    46,    53,    62,    67,    65,    42,    61,    38,
      38,    42,    85,    53,    74,    82,    38,    61,    53,    38,
      52,    44,     6,    78,    52,    38,    40,     9,    86,    61,
      43,    79,    80,    38,    87,    38,     6,    80,    75,    52,
      89,    70,    52
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
#line 80 "parser.y"
    {fprintf(yyout,"rule:programm->stmts\n");  ;}
    break;

  case 3:
#line 83 "parser.y"
    { fprintf(yyout,"rule:stmts->stmt stmts\n");;}
    break;

  case 4:
#line 84 "parser.y"
    {fprintf(yyout,"rule:stmts->empty\n");	   ;}
    break;

  case 5:
#line 88 "parser.y"
    {yyerrok;;}
    break;

  case 6:
#line 89 "parser.y"
    {yyerror("Parse error invalid character ");;}
    break;

  case 7:
#line 90 "parser.y"
    {fprintf(yyout,"rule:stmt->expr ;\n");;}
    break;

  case 8:
#line 91 "parser.y"
    {fprintf(yyout,"rule:stmt->ifstmt\n");;}
    break;

  case 9:
#line 92 "parser.y"
    {fprintf(yyout,"rule:stmt->whilestmt\n");  ;}
    break;

  case 10:
#line 93 "parser.y"
    {fprintf(yyout,"rule:stmt->forstmt\n");	   ;}
    break;

  case 11:
#line 94 "parser.y"
    {fprintf(yyout,"rule:stmt->returnstmt\n"); ;}
    break;

  case 12:
#line 95 "parser.y"
    {
	 								 if( Num_of_StackEls(break_s) == 0 ){
									 	emit(nop,NULL,NULL,NULL,0,yylineno);
									 	fprintf(stderr,"%s: line %d: ---> Warning : break statement out of loop (no operation produced)\n",file_name,yylineno);
	
									 }else{
									 	emit(jump_break,NULL,NULL,NULL,0,yylineno);
	 								 	insert_jump_point(0,break_s);
									 }
	 								 fprintf(yyout,"rule:stmt->break;\n");     ;}
    break;

  case 13:
#line 105 "parser.y"
    {
	 								 if(Num_of_StackEls(continue_s) == 0){
									 	emit(nop,NULL,NULL,NULL,0,yylineno);
									 	fprintf(stderr,"%s: line %d: ---> Warning : continue statement out of loop (no operation produced)\n",file_name,yylineno);
										
									 }
									 else{
									 	cont_loop = get_cont_point(0);
	 								  emit(jump_cont,NULL,NULL,NULL,cont_loop,yylineno);
									  }
	 								  fprintf(yyout,"rule:stmt->continue;\n");  ;}
    break;

  case 14:
#line 116 "parser.y"
    {
	 								  Hide(Scope);Scope--;
   									  resetTemp();
	 								  reset_fun_cnt();
	 								  fprintf(yyout,"rule:stmt->block\n");     
									;}
    break;

  case 15:
#line 122 "parser.y"
    {fprintf(yyout,"rule:stmt->funcdef\n");	   ;}
    break;

  case 16:
#line 123 "parser.y"
    {fprintf(yyout,"rule:stmt->;\n");		   ;}
    break;

  case 17:
#line 127 "parser.y"
    {	if(yyvsp[0].eval.sym != NULL){
											yyval.eval = yyvsp[0].eval; 
											free(&yyvsp[0].eval); 
										}
										else{
											yyval.eval.sym = NULL;
										}
										fprintf(yyout,"rule:expr->assignexpr\n");   ;}
    break;

  case 18:
#line 136 "parser.y"
    {   if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  								  		yyval.eval = op_expr(add,&yyvsp[-2].eval,&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;

									  fprintf(yyout,"rule:expr->expr + expr\n");  ;}
    break;

  case 19:
#line 144 "parser.y"
    {  if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  								 	yyval.eval = op_expr(sub,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 	free(&yyvsp[-2].eval);
									 	free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	  								 fprintf(yyout,"rule:expr->expr - expr\n");  ;}
    break;

  case 20:
#line 153 "parser.y"
    {  if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  								 		yyval.eval = op_expr(mul,&yyvsp[-2].eval,&yyvsp[0].eval);
									 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	  								 fprintf(yyout,"rule:expr->expr * expr\n");  ;}
    break;

  case 21:
#line 162 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  										yyval.eval = op_expr(div_a,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	  								 fprintf(yyout,"rule:expr->expr / expr\n");  ;}
    break;

  case 22:
#line 171 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  										yyval.eval = eq_neq_oper(if_eq,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr == expr\n"); ;}
    break;

  case 23:
#line 180 "parser.y"
    {  if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  										yyval.eval = eq_neq_oper(if_noteq,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval); 
										}
										else
											yyval.eval.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr != expr\n"); ;}
    break;

  case 24:
#line 189 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  										yyval.eval = op_expr(mod,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	  								 fprintf(yyout,"rule:expr->expr \% expr\n"); ;}
    break;

  case 25:
#line 198 "parser.y"
    {
	  									if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  										yyval.eval=bool_oper(if_greatereq,&yyvsp[-2].eval,&yyvsp[0].eval);
	                                 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	                                fprintf(yyout,"rule:expr->expr >= expr\n"); ;}
    break;

  case 26:
#line 208 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  
	  										yyval.eval=bool_oper(if_lesseq,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	                                fprintf(yyout,"rule:expr->expr <= expr\n"); ;}
    break;

  case 27:
#line 218 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  
	  										yyval.eval=bool_oper(if_greater,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 		free(&yyvsp[-2].eval);
											free(&yyvsp[0].eval);
											}
										else
											yyval.eval.sym = NULL;
	                                fprintf(yyout,"rule:expr->expr > expr\n");  ;}
    break;

  case 28:
#line 228 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  
	 	 									 yyval.eval=bool_oper(if_less,&yyvsp[-2].eval,&yyvsp[0].eval);
	  										 free(&yyvsp[-2].eval);
											 free(&yyvsp[0].eval);
											}
										else
											yyval.eval.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr < expr\n");  ;}
    break;

  case 29:
#line 238 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  
	  										 yyval.eval=andor_oper(and,&yyvsp[-2].eval,&yyvsp[0].eval);
	  										 free(&yyvsp[-2].eval);
											 free(&yyvsp[0].eval);

										}
										else
											yyval.eval.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr and expr\n");;}
    break;

  case 30:
#line 249 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  										yyval.eval=andor_oper(or,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr or expr\n"); ;}
    break;

  case 31:
#line 258 "parser.y"
    {yyval.eval = yyvsp[0].eval;fprintf(yyout,"rule:expr->term\n");
	  								 free(&yyvsp[0].eval);
									 ;}
    break;

  case 32:
#line 265 "parser.y"
    { yyval.eval = yyvsp[-1].eval; free(&yyvsp[-1].eval);fprintf(yyout,"rule:term -> ( expr )\n"); ;}
    break;

  case 33:
#line 266 "parser.y"
    { 
	   								  if ( yyvsp[0].eval.sym != NULL ){
	   								  	yyval.eval = term_expr(uminus,&yyvsp[0].eval);
	  									free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
									  fprintf(yyout,"rule:term -> - expr\n");   
									;}
    break;

  case 34:
#line 275 "parser.y"
    {	if ( yyvsp[0].eval.sym != NULL){
	   										yyval.eval=andor_oper(not,&yyvsp[0].eval,NULL);
	   									    free(&yyvsp[0].eval);
									 	}
										else
											yyval.eval.sym = NULL;
	   								fprintf(yyout,"rule:term -> not expr\n"); ;}
    break;

  case 35:
#line 283 "parser.y"
    {struct expr *const_new = new_IntExpr(1);
	                                 
									 if ( yyvsp[0].eval.sym != NULL ){
									 		yyval.eval = lvalue_prefix(add,&yyvsp[0].eval,const_new);
									 	 free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
										 free(const_new);
	                                 fprintf(yyout,"rule:term -> ++ lvalue\n");;}
    break;

  case 36:
#line 294 "parser.y"
    { 
	   								  char * tmp_var = new_tmp_var();
									  struct expr * new_tmp;
									  S_entry sym;
									  

                                      if ( yyvsp[-1].eval.sym != NULL ){
									     if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									      }
									      sym = find_rec( tmp_var , Scope, 1);

									  	 if(sym != NULL)
									  	     new_tmp = new_VarE( sym );
									  
									      emit(assign, &yyvsp[-1].eval, NULL, new_tmp, 0, yylineno);
									  
									      yyval.eval = *new_tmp;
									  
									      free(new_tmp);
									      free(tmp_var);

									      lvalue_prefix(add,&yyvsp[-1].eval,new_IntExpr(1));
									  
									      free(&yyvsp[-1].eval);
									  }
										else
											yyval.eval.sym = NULL;
	   								  fprintf(yyout,"rule:term -> lvalue ++\n");;}
    break;

  case 37:
#line 323 "parser.y"
    {
	   									struct expr *const_new = new_IntExpr(1);
	                                if ( yyvsp[0].eval.sym != NULL ){	
	   								    yyval.eval = lvalue_prefix(sub,&yyvsp[0].eval,const_new);
										
										 free(const_new);
										 free(&yyvsp[0].eval);
									 }
										else
											yyval.eval.sym = NULL;
	   								  fprintf(yyout,"rule:term -> -- lvalue\n");;}
    break;

  case 38:
#line 335 "parser.y"
    { 
	   								  char * tmp_var = new_tmp_var();
									  struct expr * new_tmp;
 									  S_entry sym;

                                    if ( yyvsp[-1].eval.sym != NULL ){
									     if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									     }
									     sym = find_rec( tmp_var , Scope, 1);

									     if(sym != NULL)
									   		new_tmp = new_VarE( sym );
									  
									  	 emit(assign, &yyvsp[-1].eval, NULL, new_tmp, 0, yylineno);
									  
									     yyval.eval = *new_tmp;
									  	 free(new_tmp);
									  	 lvalue_prefix(sub,&yyvsp[-1].eval,new_IntExpr(1));
										 free(&yyvsp[-1].eval);
	   									 free(tmp_var);
									 }
										else
											yyval.eval.sym = NULL;
	   
	   									fprintf(yyout,"rule:term -> lvalue --\n");;}
    break;

  case 39:
#line 361 "parser.y"
    { yyval.eval = yyvsp[0].eval; fprintf(yyout,"rule:term -> primary\n");  
	   									free(&yyvsp[0].eval);
									;}
    break;

  case 40:
#line 366 "parser.y"
    { 	if(yyvsp[-2].eval.sym!=NULL && yyvsp[0].eval.sym!=NULL){

		  									if ( yyvsp[-2].eval.e_type == tableitem_e ){
		  										emit(tablesetelem,&yyvsp[0].eval,NULL,&yyvsp[-2].eval,0,yylineno);
											}
											else{
												
												emit(assign,&yyvsp[0].eval,NULL,&yyvsp[-2].eval,0,yylineno);
																						
											}
											yyval.eval = yyvsp[-2].eval;											
											free(&yyvsp[-2].eval);
											free(&yyvsp[0].eval);
										}
										else 
										   yyval.eval.sym=NULL;
											
										fprintf(yyout,"rule:assignexpr -> lvalue = expr\n");;}
    break;

  case 41:
#line 386 "parser.y"
    {yyval.eval = yyvsp[0].eval;
	   								 free(&yyvsp[0].eval);
									 fprintf(yyout,"rule:primary -> lvalue\n");;}
    break;

  case 42:
#line 390 "parser.y"
    {yyval.eval = yyvsp[0].eval; fprintf(yyout,"rule:primary -> call\n");		;}
    break;

  case 43:
#line 391 "parser.y"
    {yyval.eval = yyvsp[0].eval; fprintf(yyout,"rule:primary -> tablemake\n");	;}
    break;

  case 44:
#line 392 "parser.y"
    {yyval.eval = yyvsp[-1].eval; fprintf(yyout,"rule:primary -> ( funcdef )\n");;}
    break;

  case 45:
#line 393 "parser.y"
    {yyval.eval = const_expr(assign,&yyvsp[0].eval);
	   									fprintf(yyout,"rule:primary -> const\n");		
										free(&yyvsp[0].eval);
									;}
    break;

  case 46:
#line 399 "parser.y"
    { int i;
	  								  struct expr *new_lval;
									  S_entry sym;
									  i = id_scope(yyvsp[0].sval,Scope,upScope,upScope2);

									  if ( i == 1 ){

									  		sym = find_rec(yyvsp[0].sval,Scope,1);
									  		if(sym == NULL){
									  			sym = find_rec(yyvsp[0].sval,Scope,2);
									  		}
									  		if( sym != NULL ){
									  	   		 new_lval = new_VarE(sym);
										 		yyval.eval = *new_lval;
										 		free(new_lval);
									  	 		free(&yyvsp[0].sval);

									  	  	}
									   }
									   else
										  yyval.eval.sym = NULL;
									 
									  
									  fprintf(yyout,"rule:lvalue -> ID\n"); 
									;}
    break;

  case 47:
#line 425 "parser.y"
    { int res;
	                                  struct expr *new_lval;
									  S_entry sym;
	                                  res=local_id_scope(yyvsp[0].sval,Scope);
	   								  if(res==1){
									    
									  							 
									 	sym = find_rec(yyvsp[0].sval,Scope,1);
									  
									  	if(sym != NULL){

									  		 new_lval = new_VarE(sym);
									     	yyval.eval = *new_lval;
									  	}
										free(new_lval);
										free(&yyvsp[0].sval);
									}
									else 
									   yyval.eval.sym=NULL;

									 fprintf(yyout,"rule:lvalue -> local ID\n");
									;}
    break;

  case 48:
#line 448 "parser.y"
    {int res; 
	   								 S_entry sym; 

									  struct expr *new_lval;
	                                 res=global_id_scope(yyvsp[0].sval,Scope);

									  if(res!=0){							 
									  	sym = find_rec(yyvsp[0].sval,0,1);
									  
									  	if(sym != NULL){
									  	 	new_lval = new_VarE(sym);
  										 	yyval.eval = *new_lval;
									  	}

										free(&yyvsp[0].sval);
										free(new_lval);
									 }
									 else
									    yyval.eval.sym=NULL;
	   								  
									  fprintf(yyout,"rule:lvalue -> global ID\n");
									;}
    break;

  case 49:
#line 471 "parser.y"
    {yyval.eval = yyvsp[0].eval;fprintf(yyout,"rule:lvalue -> tableitem\n");;}
    break;

  case 50:
#line 476 "parser.y"
    {fprintf(yyout,"rule:glbl -> global\n");;}
    break;

  case 51:
#line 477 "parser.y"
    {fprintf(yyout,"rule:glbl -> ::\n");;}
    break;

  case 52:
#line 480 "parser.y"
    { if( yyvsp[-2].eval.sym != NULL){

		 								struct expr * table = new_expr(tableitem_e);
 										char  * tmp_var;
										struct expr * index ;
										struct expr * res;
  								  	  	struct expr *up;
 										S_entry sym; 
		 							  	table->sym = yyvsp[-2].eval.sym;
									  
										index = new_StrExpr(yyvsp[0].sval);
									  	table->index = index;
									  
										up = new_expr(tableitem_e);
 									
										
									  
										tmp_var = new_tmp_var();
									  									   
									  	if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									  	}
									  	sym = find_rec( tmp_var , Scope, 1);
									  	
										if(sym != NULL){
									  		res = new_VarE( sym );
																			  
									  		up->sym = res->sym;
											up->index = res->index;
									  	}
									  	emit(tablegetelem,table,index,res,0,yylineno);
									  	yyval.eval = *up;
									  }
									  else
									  	yyval.eval.sym = NULL;
		 							 fprintf(yyout,"rule:tableitem -> lvalue . ID\n");;}
    break;

  case 53:
#line 517 "parser.y"
    { 
	   								  if( yyvsp[-3].eval.sym != NULL && yyvsp[-1].eval.sym != NULL){
	   								  	struct expr * table = new_expr(tableitem_e);
		 							  
									  	struct expr * res;
  								  	  	struct expr *up = new_expr(tableitem_e);
										S_entry sym;
										
										char  * tmp_var = new_tmp_var();
									  	
										table->sym = yyvsp[-3].eval.sym;
									  	table->index = Expr_cpy(table->index,&yyvsp[-1].eval) ;	

									  	if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									  	}
									   	sym= find_rec( tmp_var , Scope, 1);
									  	if(sym != NULL){
									  		res = new_VarE( sym );
																			  
									  		up->sym = res->sym;
											up->index = res->index;
									  	}
									  	emit(tablegetelem,table,&yyvsp[-1].eval,res,0,yylineno);
									  	yyval.eval = *up;
									 }
									 else
									 	yyval.eval.sym = NULL;
	   			
	   									fprintf(yyout,"rule:tableitem -> lvalue ( expr )\n");;}
    break;

  case 54:
#line 548 "parser.y"
    { if( yyvsp[-2].eval.sym != NULL){
	   								  	struct expr * table = new_expr(tableitem_e);
									  	struct expr * index ;
									  	struct expr * res;
  								  	 	struct expr *up = new_expr(tableitem_e);
										S_entry sym;
										
									  	char  * tmp_var = new_tmp_var();
	                                    table->index = index;
									  	index = new_StrExpr(yyvsp[0].sval);
										table->sym = yyvsp[-2].eval.sym;
									  	
										if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									  	}
									   	sym= find_rec( tmp_var , Scope, 1);
									  	if(sym != NULL){
									 	 	res = new_VarE( sym );
																			  
									  		up->sym = res->sym;
											up->index = res->index;
									  	}
									  	emit(tablegetelem,table,index,res,0,yylineno);
									  	yyval.eval = *up;
									  }
									  else
									  	yyval.eval.sym = NULL;
									  fprintf(yyout,"rule:tableitem -> call . ID\n");
									;}
    break;

  case 55:
#line 578 "parser.y"
    { if( yyvsp[-3].eval.sym != NULL){

	   								  	struct expr * table = new_expr(tableitem_e);
		 							    struct expr * res;
  								  	 	struct expr *up = new_expr(tableitem_e);
										S_entry sym; 	
										char  * tmp_var = new_tmp_var();

                                    	table->sym = yyvsp[-3].eval.sym;
									  	table->index = Expr_cpy(table->index,&yyvsp[-1].eval) ;
									  									   
									  	if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									  	}
									  	sym= find_rec( tmp_var , Scope, 1);
									  	if(sym != NULL){
									  		res = new_VarE( sym );
																			  
									  		up->sym = res->sym;
											up->index = res->index;
									  	}
									  	emit(tablegetelem,table,&yyvsp[-1].eval,res,0,yylineno);
									  	yyval.eval = *up;
	   
	   								 }
									 else
									 	yyval.eval.sym = NULL;
	   								  fprintf(yyout,"rule:tableitem -> call ( expr )\n");;}
    break;

  case 56:
#line 608 "parser.y"
    { 	int i=0;
										int search = 0;
										S_entry sym;
										struct expr * new_lval;
										struct expr * tmp;
										
										if(yyvsp[-3].eval.sym != NULL){
									    	while( i <= Scope ){
												if (lookup(find_name(yyvsp[-3].eval.sym,1),i,1)){
													search = 1;
													break;
												}
												i++;

											}
										}
										if ( search == 1 ){
										
										  	new_lval = new_VarE(yyvsp[-3].eval.sym);
									    	new_lval = Expr_cpy( new_lval , &yyvsp[-3].eval );

										    yyval.eval =  * call_expr( new_lval , elist_head);
																									
											free(new_lval);
											elist_head = NULL;
											free(&yyvsp[-3].eval);
										}
										else{

											printf("Undifined call of Function at line:%d\n",yylineno);
										}
										fprintf(yyout,"rule:call -> call ( elist )\n");
										
										;}
    break;

  case 57:
#line 643 "parser.y"
    {  	    int i=0;
										int search = 0;
										S_entry sym;
										struct expr * new_lval;
										
									    while( i <= Scope ){
											if (lookup(yyvsp[-3].sval,i,2)){
												search = 1;
												break;
											}
											i++;
										}
										if ( search == 1 ){
											sym = find_rec(yyvsp[-3].sval,Scope,2);
									  		new_lval = new_FuncE(sym);
									    	yyval.eval = *call_expr(new_lval,elist_head);
											elist_head = NULL;
										}
										else{
											yyval.eval.sym = NULL;
											printf("Undifined call of Function at line:%d\n",yylineno);
										}
	   									fprintf(yyout,"rule:call -> lvalue ( elist)\n");;}
    break;

  case 58:
#line 668 "parser.y"
    {  	int i=0;
										int search = 0;
                                     	S_entry sym;
										struct expr * new_lval;
										
									    
										if (lookup(yyvsp[-3].sval,0,2)){
												search = 1;
												
										}
										if ( search == 1 ){
											sym = find_rec(yyvsp[-3].sval,Scope,2);
									  		new_lval = new_FuncE(sym);
									    	yyval.eval = *call_expr(new_lval,elist_head);
											elist_head = NULL;


										}
										else{

											printf("Undifined call of Function at line:%d\n",yylineno );
										}


										
									    fprintf(yyout,"rule:call -> lvalue ( elist)\n");;}
    break;

  case 59:
#line 696 "parser.y"
    {  	int i=0;
												int search = 0;
												S_entry sym;
												struct expr * new_lval;
										
										if (lookup(yyvsp[-3].sval,Scope,2)){
												search = 1;
											
										}
											
										if ( search == 1 ){
											sym = find_rec(yyvsp[-3].sval,Scope,2);
									  		new_lval = new_FuncE(sym);
									    	yyval.eval = *call_expr(new_lval,elist_head);
											elist_head = NULL;

										}
										else{

											printf("Undifined call of Function at line:%d\n",yylineno );
										}

                                       	fprintf(yyout,"rule:call -> lvalue ( elist)\n");;}
    break;

  case 60:
#line 721 "parser.y"
    {  	int i=0;
										int search = 0;
										S_entry sym;
										struct expr * new_lval;
										
										if(yyvsp[-3].eval.sym!=NULL){
									       yyval.eval = *call_expr(&yyvsp[-3].eval,elist_head);
										   elist_head = NULL;
										}
										else{

											printf("Undifined call of Function at line:%d\n",yylineno );
										}

										fprintf(yyout,"rule:call -> lvalue ( elist)\n");;}
    break;

  case 61:
#line 742 "parser.y"
    {  yyval.eval = *call_expr(&yyvsp[-4].eval,elist_head);
										elist_head = NULL;
	   								fprintf(yyout,"rule:call -> ( funcdef ) ( elist )\n");;}
    break;

  case 62:
#line 748 "parser.y"
    { if( elist_head == NULL ){
								  	elist_head = Expr_cpy(elist_head,&yyvsp[-1].eval);
								  }
								  else{
								  	yyvsp[-1].eval.next = elist_head;
									elist_head = Expr_cpy(elist_head,&yyvsp[-1].eval);
								  }
								  
	                              fprintf(yyout,"rule:elist -> expr elist1s\n");;}
    break;

  case 63:
#line 757 "parser.y"
    {elist_head = NULL;fprintf(yyout,"rule:elist -> empty\n");	   ;}
    break;

  case 64:
#line 760 "parser.y"
    {
								  
	   							  if(elist_head == NULL){
								  	elist_head = Expr_cpy(elist_head,&yyvsp[-1].eval);
								  	
								  }
								  else{
								  	yyvsp[-1].eval.next = elist_head;
								  	elist_head = Expr_cpy(elist_head,&yyvsp[-1].eval);

								  }
	   							fprintf(yyout,"rule:elist1s -> elist1 elist1s\n");;}
    break;

  case 65:
#line 772 "parser.y"
    {elist_head = (struct expr *)0;fprintf(yyout,"rule:elist1s -> empty\n");		   ;}
    break;

  case 66:
#line 775 "parser.y"
    {	
								 
	  								yyval.eval = yyvsp[0].eval;
	  								fprintf(yyout,"rule:elist1 -> COMMA expr\n");;}
    break;

  case 67:
#line 781 "parser.y"
    { 
	   							  if( index_head == NULL ){
								  	index_head = Expr_cpy(index_head,&yyvsp[-1].eval);
								  }
								  else{
								  	yyvsp[-1].eval.next = index_head;
									index_head = Expr_cpy(index_head,&yyvsp[-1].eval);
								  }

	   							 fprintf(yyout,"rule:indexed -> indexedelem ind1s\n");;}
    break;

  case 68:
#line 793 "parser.y"
    { if(index_head == NULL){
								  	index_head = Expr_cpy(index_head,&yyvsp[-1].eval);
								  	
								  }
								  else{
								  	yyvsp[-1].eval.next = index_head;
								  	index_head = Expr_cpy(index_head,&yyvsp[-1].eval);

								  }

	 							 fprintf(yyout,"rule:ind1s -> ind1 ind1s\n");;}
    break;

  case 69:
#line 804 "parser.y"
    {index_head = NULL;fprintf(yyout,"rule:ind1s -> empty");		 ;}
    break;

  case 70:
#line 806 "parser.y"
    {	yyval.eval = yyvsp[0].eval;
									fprintf(yyout,"rule:ind1 -> COMMA indexedelem\n");;}
    break;

  case 71:
#line 811 "parser.y"
    { yyvsp[-3].eval.index = Expr_cpy(yyvsp[-3].eval.index,&yyvsp[-1].eval);
		   									yyval.eval = yyvsp[-3].eval;
		   									fprintf(yyout,"rule:indexedelem -> { expr : expr }\n");
										  ;}
    break;

  case 72:
#line 816 "parser.y"
    { yyval.eval = yyvsp[-1].eval; fprintf(yyout,"rule:tablemake -> [ tsize ]\n");;}
    break;

  case 73:
#line 819 "parser.y"
    { struct expr * table = new_expr(newtable_e);
	 						  struct expr * new_tmp;
		 					  S_entry sym;	
		 					  char  * tmp_var =  new_tmp_var();
                              struct expr * tmp;
							  int i = 0;
							  
							  if( !lookup( tmp_var , Scope, 1 ) ){
									  	insert( Scope, tmp_var , yylineno, 1 );
							  }
							  sym = find_rec( tmp_var ,Scope, 1);
							  table->sym = sym;
						
							  emit(tablecreate,NULL,NULL,table,0,yylineno);
							  
							 
							  for(tmp = elist_head; tmp!=NULL; tmp=tmp->next)
									emit(tablesetelem,new_IntExpr(i++),tmp,table,0,yylineno);

							  yyval.eval = *table;
							  fprintf(yyout,"rule:tsize ->  elist \n"); ;}
    break;

  case 74:
#line 841 "parser.y"
    { 
	   						  struct expr * table = new_expr(newtable_e);
	 						  struct expr * new_tmp;
	  						  S_entry sym; 
                              struct expr * tmp;
							  int i = 0;
                              char  * tmp_var =  new_tmp_var();
							  
							  if( !lookup( tmp_var , Scope, 1 ) ){
									  	insert( Scope, tmp_var , yylineno, 1 );
							  }
						      sym= find_rec( tmp_var ,Scope, 1);
							  table->sym = sym;
						
							  emit(tablecreate,NULL,NULL,table,0,yylineno);
							  
							
							  for(tmp = index_head; tmp!=NULL; tmp=tmp->next){
									emit(tablesetelem,tmp,tmp->index,table,0,yylineno);
                              }
							  yyval.eval = *table;
	   						  fprintf(yyout,"rule:tsize -> indexed\n"); 

							  ;}
    break;

  case 75:
#line 868 "parser.y"
    {++MaxScope; Scope++; ;}
    break;

  case 76:
#line 868 "parser.y"
    {	
													fprintf(yyout,"rule:block -> { stmts }\n");
												;}
    break;

  case 77:
#line 873 "parser.y"
    { func_flag += 1; 

	   							if( yyvsp[0].eval.sym != NULL){
	   								emit(funcstart,&yyvsp[0].eval,NULL,NULL,0,yylineno);
									yyval.eval = yyvsp[0].eval;
								}
								else
									yyval.eval.sym = NULL;
								
								
							  ;}
    break;

  case 78:
#line 884 "parser.y"
    { ++MaxScope; Scope++; ScopeSpaceCounter++;;}
    break;

  case 79:
#line 885 "parser.y"
    { insert_arguments(Scope); ScopeSpaceCounter++;;}
    break;

  case 80:
#line 886 "parser.y"
    {
								func_name = fun_names[--fn_i];

								//count_funcVars(Scope);

								Hide(Scope);
								Scope--;
								Hide(Scope--);
								ScopeSpaceCounter -= 2;
								
								if( yyvsp[-7].eval.sym != NULL ){
									emit(funcend,&yyvsp[-7].eval,NULL,NULL,0,yylineno);
									
									yyval.eval = yyvsp[-7].eval;
									free(&yyvsp[-7].eval);
									free(func_name);
									free(fun_names[fn_i]);
								}
								else
									yyval.eval.sym = NULL;

								
								reset_fun_cnt();
								func_flag -= 1;
								fprintf(yyout,"rule:funcdef -> function fid ( idlist ) block\n");
							;}
    break;

  case 81:
#line 914 "parser.y"
    {	 	int result,cmp_res;
						func_name = strdup(yyvsp[0].sval);
						
						if(fn_i==0)
						   fn_i=1;
						
						if(strcmp(func_name,fun_names[fn_i-1])!=0){
							
						
							fun_names[fn_i++]= strdup(func_name);
							upScope=search_actFunc(Scope);
							result = fid_scope( func_name, Scope , upScope );
						
							if ( result == 1 ){
						
							struct expr *new_lval;
							S_entry sym = find_rec(yyvsp[0].sval,Scope,2);
									  
							if(sym != NULL){
								new_lval = new_FuncE(sym);
																
							}
							yyval.eval = *new_lval;
							free(new_lval);
							free(&yyvsp[0].sval);

							}
							else{
								yyval.eval.sym = NULL;
					      	}
						}
						else{
						   
							  fprintf(stderr,"Redifine symbol:%s at line:%d\n",func_name,yylineno);
						}
						fprintf(yyout,"rule:fid -> ID\n");
						
				;}
    break;

  case 82:
#line 953 "parser.y"
    {	  	struct expr *new_lval;
						S_entry sym ; 
	  					func_name = create_funcName();
						fun_names[fn_i++]= strdup(func_name);
	  					if (!lookup(func_name,Scope,2) )
							insert(Scope,func_name,yylineno,2);	

					    sym = find_rec(func_name,Scope,2); 
									  
						if(sym != NULL){
							new_lval = new_FuncE(sym);
							
						}
						yyval.eval = *new_lval;
						

						fprintf(yyout,"rule:fid -> empty\n");
				;}
    break;

  case 83:
#line 973 "parser.y"
    {struct expr *const_new = new_IntExpr(yyvsp[0].ival);  yyval.eval = *const_new; free(&yyvsp[0].ival); free(const_new); fprintf(yyout,"rule:const -> INTCONST\n");  ;}
    break;

  case 84:
#line 974 "parser.y"
    {struct expr *const_new = new_FltExpr(yyvsp[0].fval);  yyval.eval = *const_new; free(&yyvsp[0].fval); free(const_new);fprintf(yyout,"rule:const -> FLOATCONST\n");;}
    break;

  case 85:
#line 975 "parser.y"
    {struct expr *const_new = new_StrExpr(yyvsp[0].sval);  yyval.eval = *const_new; free(&yyvsp[0].sval); free(const_new);fprintf(yyout,"rule:const -> STRING\n");    ;}
    break;

  case 86:
#line 976 "parser.y"
    {struct expr *const_new = new_NillExpr(yyvsp[0].sval); yyval.eval = *const_new; free(&yyvsp[0].sval); fprintf(yyout,"rule:const -> nil\n");						 							 ;}
    break;

  case 87:
#line 977 "parser.y"
    {struct expr *const_new = new_BoolExpr(1u); yyval.eval = *const_new; free(const_new); fprintf(yyout,"rule:const -> true\n");	 	 ;}
    break;

  case 88:
#line 978 "parser.y"
    {struct expr *const_new = new_BoolExpr(0u); yyval.eval = *const_new; free(const_new);fprintf(yyout,"rule:const -> false\n");	 ;}
    break;

  case 89:
#line 981 "parser.y"
    {  		
	  						if( !lookup(yyvsp[-1].sval,Scope,1) && !lookup(yyvsp[-1].sval,Scope-1,2) )
								
								insert(Scope,yyvsp[-1].sval,yylineno,1);
							
							else
								fprintf(stderr,"Redifine id:%s at line:%d\n",yyvsp[-1].sval,yylineno);
							
							fprintf(yyout,"rule:idlist -> ID id1s\n");
						;}
    break;

  case 90:
#line 992 "parser.y"
    {fprintf(yyout,"rule:idlist -> empty\n");;}
    break;

  case 91:
#line 996 "parser.y"
    {   if (!lookup(yyvsp[0].sval,Scope,1) && !lookup(yyvsp[0].sval,Scope-1,2))
								insert(Scope,yyvsp[0].sval,yylineno,1);
							else
								fprintf(stderr,"Redifine id:%s at line:%d\n",yyvsp[0].sval,yylineno);
								
							fprintf(yyout,"rule:id1 -> , ID\n");
						;}
    break;

  case 92:
#line 1005 "parser.y"
    {fprintf(yyout,"rule:id1s -> id1 id1s\n");;}
    break;

  case 93:
#line 1006 "parser.y"
    {fprintf(yyout,"rule:id1s -> empty\n");	  ;}
    break;

  case 94:
#line 1010 "parser.y"
    { emit(if_eq,&yyvsp[-1].eval,new_BoolExpr(0u),NULL,0,yylineno);
		 									insert_jump_point(1,break_s);
		 									insert_jump_point(0,back_s);;}
    break;

  case 95:
#line 1013 "parser.y"
    { cont_loop = get_cont_point(1); loop = get_loop_point(1);
					 						 emit(jump_while,NULL,NULL,NULL,loop,yylineno);
					 						 
								  	  		 backpatch(back_s); 
											 backpatch(break_s);
											 free(&yyvsp[-3].eval);
							  		  		 fprintf(yyout,"rule:whilestmt -> while ( expr ) stmt\n");;}
    break;

  case 96:
#line 1022 "parser.y"
    {loop = getCurQuad(); insert_loop_point(&loop); cont_loop = getCurQuad(); insert_cont_point(&cont_loop);;}
    break;

  case 97:
#line 1026 "parser.y"
    {emit(if_eq,&yyvsp[-1].eval,new_BoolExpr(0u),NULL,0,yylineno); 
	  								insert_jump_point(0,back_s); ;}
    break;

  case 98:
#line 1028 "parser.y"
    {free(&yyvsp[-4].eval);fprintf(yyout,"rule:ifstmt -> if ( expr ) stmt elsestmt\n");;}
    break;

  case 99:
#line 1031 "parser.y"
    {backpatch(back_s);emit(jump,NULL,NULL,NULL,0,yylineno);insert_jump_point(0,back_s);;}
    break;

  case 100:
#line 1031 "parser.y"
    {backpatch(back_s);fprintf(yyout,"rule:elsestmt -> else stmt\n");;}
    break;

  case 101:
#line 1032 "parser.y"
    {backpatch(back_s);fprintf(yyout,"rule:elsestmt -> empty");	   ;}
    break;

  case 102:
#line 1037 "parser.y"
    {emit(if_eq,&yyvsp[-3].eval,new_BoolExpr(0u),NULL,0,yylineno);
		 									insert_jump_point(1,break_s);
		 									insert_jump_point(0,back_s);;}
    break;

  case 103:
#line 1040 "parser.y"
    {
										 cont_loop = get_cont_point(1); loop = get_loop_point(1);
					 					 emit(jump_for,NULL,NULL,NULL,loop,yylineno);
					 						 
								  	  	 backpatch(back_s); 
										 backpatch(break_s);
										 free(&yyvsp[-5].eval);
										 fprintf(yyout,"rule:forstmt -> for ( elist ; expr ; elist ) stmt\n");;}
    break;

  case 104:
#line 1050 "parser.y"
    {loop = getCurQuad(); insert_loop_point(&loop); cont_loop = getCurQuad();
	   									  insert_cont_point(&cont_loop);;}
    break;

  case 105:
#line 1054 "parser.y"
    {	if( func_flag > 0 )
		  										emit(ret,NULL,NULL,&yyvsp[-1].eval,0,yylineno);
											else{
												emit(nop,NULL,NULL,NULL,0,yylineno);
									 	        fprintf(stderr,"%s: line %d: ---> Warning : return statement out of function (no operation produced)\n",file_name,yylineno);
												 
											}
											yyval.eval = yyvsp[-1].eval;free(&yyvsp[-1].eval); 
											fprintf(yyout,"rule:returnstmt -> return prexpr ;\n");
										   ;}
    break;

  case 106:
#line 1066 "parser.y"
    {yyval.eval = yyvsp[0].eval;free(&yyvsp[0].eval);fprintf(yyout,"rule:prexpr -> expr\n"); ;}
    break;

  case 107:
#line 1067 "parser.y"
    {fprintf(yyout,"rule:prexpr -> empty\n");;}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 2679 "parser.c"

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


#line 1071 "parser.y"


int main(int argc,char **argv){

	int lk;
	struct expr * tmp;

	new = (struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));
	new->s_value=(char *)malloc((MAX_LEXEME)*sizeof(char));
	ayylval = (void *) new;
	

	
	if( argc<2 ){
		fprintf(stderr,"Error.No input file\n");
		return 1;
	}
	else{
	
		if(argc==2){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				fprintf(stderr,"Error while opening the file\n");
				return 1;
			}
			yyout=stdout;
			sym_file=stdout;
		}
		if(argc==3){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				fprintf(stderr,"Error while opening the input file\n");
				return 1;
			}
			if((yyout=fopen(argv[2],"w+"))==NULL){
				fprintf(stderr,"Error while opening the output file\n");
				return 1;
			}
			sym_file=stdout;

		}
		if(argc==4){
			if((yyin=fopen(argv[1],"r+"))==NULL){
				fprintf(stderr,"Error while opening the input file\n");
				return 1;
			}
			if((yyout=fopen(argv[2],"w+"))==NULL){
				fprintf(stderr,"Error while opening the output file\n");
				return 1;
			}
			if((sym_file=fopen(argv[3],"w+"))==NULL){
				fprintf(stderr,"Error while opening the sym file file\n");
				return 1;
			}

		}

	}
	
	if((quad_ofile= fopen("quad.txt","w+")) == NULL){
		fprintf(stderr,"Cannot open quads.txt\n");
		exit(1);
	}
	
	file_name = strdup( argv[1]);

	Init_symbolTable();
	
	yyparse();
	print();


	print_to_file();
	
	print_quads();
	
	

	

    destroy_symboltable();
	free(new->s_value);
	free(new);
	fclose(yyin);
	fclose(yyout);
	
	fclose(sym_file);
	fclose(quad_ofile);
	
	return 0;
}


int yyerror(char *yaccProvideMessage){
	fprintf(stderr,"%s at line %d ,before token:%s\n",yaccProvideMessage,yylineno,yytext);
	return 0;
}

