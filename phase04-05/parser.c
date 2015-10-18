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
	#include "f_code.h"
	#include "stack/stack.h"
	
	#define MAXSIZE 300000


	extern int   yylineno , ScopeSpaceCounter;
	extern char *yytext;
	extern FILE *yyin,*yyout;
	extern int MaxScope;
	extern unsigned int quadCnt;
	extern unsigned totalNumConsts;
	extern unsigned totalStringConsts;
	extern unsigned totalNameLibFuncs;
	extern unsigned totalUserFuncs;
	extern struct instruction avm_incode[MAXSIZE];
	extern double * numConsts;
	extern char ** stringConsts;
	extern struct userfunc * userFuncs[1000];
	extern char ** nameLibFuncs;
	extern int curr_incode;
	extern int create_binary( char *filename,struct userfunc* userFuncs[],char *NameLibFuncs[],char *stringConsts[],double *numConsts,
		struct instruction avm_incode[],int num_of_programm_vars,unsigned int quadCnt, unsigned totalNumConsts,unsigned totalStringConsts,unsigned totalNameLibFuncs,unsigned totalUserFuncs);

	struct expr *elist_head=NULL;
	struct expr *index_head=NULL;
	extern void Loading(void);
	int flag_error = 0;
	int loop = 0 , cont_loop = 0;
	int yyerror(char *);
	struct alpha_token_t *new;
	int    Scope = 0,upScope=0,upScope2=0,fn_i=0;
	FILE * sym_file, *quad_ofile,*fcode_ofile;
	char * func_name, *id_tmp;
	char * fun_names[100]={"_?_"};
	char * file_name;
	int func_flag = 0;
    int varsFlag =0; 
	int funcVars=0;
	int oof_counter = 0;
	
//	Stack_T oof_st = NULL;

	


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
#line 59 "parser.y"
typedef union token_A{

	  struct expr eval;
	  int ival;
	  float fval;
	  char *sval;
	
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 239 "parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 251 "parser.c"

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
#define YYLAST   628

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
      53,    89,    44,    61,    38,    52,    -1,    44,    -1,    12,
      92,    44,    -1,    53,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   104,   104,   107,   108,   112,   113,   114,   115,   116,
     117,   118,   119,   129,   140,   151,   152,   156,   165,   173,
     182,   191,   200,   209,   218,   227,   237,   247,   257,   267,
     278,   287,   294,   295,   304,   312,   323,   352,   364,   390,
     395,   435,   439,   440,   441,   442,   448,   488,   524,   558,
     563,   564,   567,   604,   636,   666,   696,   731,   765,   803,
     828,   847,   855,   897,   900,   912,   915,   945,   957,   968,
     970,   975,   980,   983,  1005,  1032,  1032,  1036,  1055,  1056,
    1036,  1091,  1130,  1150,  1151,  1152,  1153,  1154,  1155,  1158,
    1169,  1173,  1182,  1183,  1187,  1187,  1199,  1203,  1203,  1208,
    1208,  1209,  1214,  1214,  1226,  1230,  1245,  1246
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
      56,    55,     0,   102,    90,     0,    59,     0,     0,    58,
     101,     0,    93,     0,    95,    61,    71,    99,    98,    63,
       0,    93,    89,    79,     0,     0,    91,    92,     0,   100,
       0,    80,   103
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,    28,    29,    30,    70,    32,    33,    34,    35,    36,
      37,    38,    71,   115,   116,    72,   118,   119,    73,    39,
      74,    40,    68,    41,   105,   164,   188,    52,    42,   173,
     181,   182,    43,   165,    54,    44,   162,   178,   184,    45,
     171,   145,    46,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const short int yypact[] =
{
     112,   286,   -42,   -42,   -42,   -31,   -26,   -13,    12,    -8,
     358,     4,     6,    47,   -42,   -42,   -42,   358,   -42,    55,
      55,   358,    10,   -42,   331,   -42,    17,   -42,    60,   -42,
     192,   403,   -42,   -42,   -42,    14,    56,    27,   -33,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   358,   358,
     358,   -42,   -42,   -42,   358,   556,    22,   -42,   -42,    28,
     -42,    61,   -22,   -33,   -22,   -42,   496,    34,   239,   358,
     423,   -42,   -42,    30,    32,   -42,   -42,   -42,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   -42,   -42,   -42,   358,   358,    69,    39,   358,   358,
     358,    85,    59,   516,    49,    62,   536,   -42,   358,    64,
     -42,    66,    58,   381,   358,   -42,    63,    65,   -42,    30,
     -42,   568,   142,   -42,   -42,   580,    20,    20,   580,   -42,
     592,   592,   592,   592,   556,   442,   -42,   358,    67,    70,
     460,   -42,   -42,   -42,   -42,   358,   -42,   -42,    72,    66,
     358,   -42,   358,   556,   -42,   -42,   -42,   -42,    73,   -42,
     -42,   -42,   286,   556,   101,   286,   -42,    83,   478,   -42,
     122,    88,    94,   102,   -42,   -42,   -42,   -42,   -42,   358,
     133,    94,   -42,   -42,   286,   104,   -42,   -42,   105,   -42,
     286,   -42,   -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -42,   -42,   -25,     1,     0,   -42,   -42,   -42,    16,   -42,
     -42,    21,   -41,    31,   -42,   -42,    24,   -42,    29,   -42,
     -42,   -40,   -42,   -19,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -27,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42
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
     140,    26,   149,   150,    69,   159,   114,   172,   160,   167,
     166,   169,    -4,     1,   153,     2,     3,     4,     5,     6,
       7,   175,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   177,   179,    17,    18,    19,    20,   180,   185,   186,
     183,    21,   190,   156,    23,   163,   155,   154,   191,    22,
       0,    23,   168,    24,   187,     0,    25,     0,    26,    27,
       0,    78,    31,   170,     0,    31,   174,    80,    81,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    31,   189,     0,     0,     0,     0,
      31,   192,    -4,     1,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,    17,    18,    19,    20,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    23,    -4,    24,     0,     0,    25,     0,    26,    27,
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
      21,     2,     3,     4,     5,     0,     0,     0,    22,     0,
      69,     0,    24,    13,    14,    15,    16,    26,     0,    17,
      18,    19,    20,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,    24,
      78,    79,     0,     0,    26,     0,    80,    81,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    78,    79,     0,     0,     0,   152,    80,    81,
      82,    83,    84,     0,    85,    86,    87,    88,    89,    90,
       0,     0,    78,    79,     0,     0,     0,    91,    80,    81,
      82,    83,    84,     0,    85,    86,    87,    88,    89,    90,
       0,    78,    79,     0,     0,     0,   114,    80,    81,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,    78,
      79,     0,     0,     0,   157,    80,    81,    82,    83,    84,
       0,    85,    86,    87,    88,    89,    90,    78,    79,     0,
       0,     0,   161,    80,    81,    82,    83,    84,     0,    85,
      86,    87,    88,    89,    90,    78,    79,     0,   176,     0,
       0,    80,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,     0,   110,    78,    79,     0,     0,     0,
       0,    80,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,     0,   143,    78,    79,     0,     0,     0,
       0,    80,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,     0,   147,    78,    79,     0,     0,     0,
       0,    80,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,    80,    81,    82,    83,    84,     0,    85,
      86,    87,    88,    89,    90,    80,    81,    -5,    83,    84,
       0,    -5,    86,    87,    88,    89,    90,    80,    81,     0,
      83,    84,     0,     0,    86,    -5,    -5,    -5,    -5
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
     100,    46,    38,    37,    39,    38,    43,     6,    38,   150,
      38,    38,     0,     1,   114,     3,     4,     5,     6,     7,
       8,    38,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     9,    44,    21,    22,    23,    24,    43,   179,     6,
      38,    29,    38,   119,    39,   145,   117,   116,   188,    37,
      -1,    39,   152,    41,   181,    -1,    44,    -1,    46,    47,
      -1,    19,   162,   162,    -1,   165,   165,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,   184,   184,    -1,    -1,    -1,    -1,
     190,   190,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    40,    41,    -1,    -1,    44,    -1,    46,    47,
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
      29,     3,     4,     5,     6,    -1,    -1,    -1,    37,    -1,
      39,    -1,    41,    15,    16,    17,    18,    46,    -1,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,
      19,    20,    -1,    -1,    46,    -1,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    46,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      -1,    -1,    19,    20,    -1,    -1,    -1,    44,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      -1,    19,    20,    -1,    -1,    -1,    43,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    19,
      20,    -1,    -1,    -1,    42,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    19,    20,    -1,
      -1,    -1,    42,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    19,    20,    -1,    40,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    25,    26,    -1,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36
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
      52,    89,     6,    78,    52,    38,    40,     9,    86,    44,
      43,    79,    80,    38,    87,    61,     6,    80,    75,    52,
      38,    70,    52
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
#line 104 "parser.y"
    {fprintf(yyout,"rule:programm->stmts\n");  ;}
    break;

  case 3:
#line 107 "parser.y"
    { fprintf(yyout,"rule:stmts->stmt stmts\n");;}
    break;

  case 4:
#line 108 "parser.y"
    {fprintf(yyout,"rule:stmts->empty\n");	   ;}
    break;

  case 5:
#line 112 "parser.y"
    {yyerrok;;}
    break;

  case 6:
#line 113 "parser.y"
    {yyerror("Parse error invalid character ");;}
    break;

  case 7:
#line 114 "parser.y"
    {fprintf(yyout,"rule:stmt->expr ;\n");;}
    break;

  case 8:
#line 115 "parser.y"
    {fprintf(yyout,"rule:stmt->ifstmt\n");;}
    break;

  case 9:
#line 116 "parser.y"
    {fprintf(yyout,"rule:stmt->whilestmt\n");  ;}
    break;

  case 10:
#line 117 "parser.y"
    {fprintf(yyout,"rule:stmt->forstmt\n");	   ;}
    break;

  case 11:
#line 118 "parser.y"
    {fprintf(yyout,"rule:stmt->returnstmt\n"); ;}
    break;

  case 12:
#line 119 "parser.y"
    {
	 								 if( Num_of_StackEls(break_s) == 0 ){
									 	emit(nop,NULL,NULL,NULL,0,yylineno);
									 	fprintf(stderr,"%s: line %d: ---> Warning : break statement out of loop (no operation produced)\n",file_name,yylineno);
	
									 }else{
									 	emit(jump,NULL,NULL,NULL,0,yylineno);
	 								 	insert_jump_point(0,break_s);
									 }
	 								 fprintf(yyout,"rule:stmt->break;\n");     ;}
    break;

  case 13:
#line 129 "parser.y"
    {
	 								 if(Num_of_StackEls(continue_s) == 0){
									 	emit(nop,NULL,NULL,NULL,0,yylineno);
									 	fprintf(stderr,"%s: line %d: ---> Warning : continue statement out of loop (no operation produced)\n",file_name,yylineno);
										
									 }
									 else{
									 	cont_loop = get_cont_point(0);
	 								    emit(jump,NULL,NULL,NULL,cont_loop,yylineno);
									  }
	 								  fprintf(yyout,"rule:stmt->continue;\n");  ;}
    break;

  case 14:
#line 140 "parser.y"
    {
	                                    if(varsFlag>0){
	                                     funcVars+=count_funcVars(Scope);
                           			    }


	 								  Hide(Scope);Scope--;
   									  resetTemp();
	 								  reset_fun_cnt();
	 								  fprintf(yyout,"rule:stmt->block\n");     
									;}
    break;

  case 15:
#line 151 "parser.y"
    {fprintf(yyout,"rule:stmt->funcdef\n");	   ;}
    break;

  case 16:
#line 152 "parser.y"
    {fprintf(yyout,"rule:stmt->;\n");		   ;}
    break;

  case 17:
#line 156 "parser.y"
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
#line 165 "parser.y"
    {   if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  								  		yyval.eval = op_expr(add,&yyvsp[-2].eval,&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;

									  fprintf(yyout,"rule:expr->expr + expr\n");  ;}
    break;

  case 19:
#line 173 "parser.y"
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
#line 182 "parser.y"
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
#line 191 "parser.y"
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
#line 200 "parser.y"
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
#line 209 "parser.y"
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
#line 218 "parser.y"
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
#line 227 "parser.y"
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
#line 237 "parser.y"
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
#line 247 "parser.y"
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
#line 257 "parser.y"
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
#line 267 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  
	  										 yyval.eval=op_expr(and,&yyvsp[-2].eval,&yyvsp[0].eval);
	  										 free(&yyvsp[-2].eval);
											 free(&yyvsp[0].eval);

										}
										else
											yyval.eval.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr and expr\n");;}
    break;

  case 30:
#line 278 "parser.y"
    {	if ( yyvsp[-2].eval.sym != NULL && yyvsp[0].eval.sym != NULL ){
	  										yyval.eval=op_expr(or,&yyvsp[-2].eval,&yyvsp[0].eval);
	  								 		free(&yyvsp[-2].eval);
									 		free(&yyvsp[0].eval);
										}
										else
											yyval.eval.sym = NULL;
	  								fprintf(yyout,"rule:expr->expr or expr\n"); ;}
    break;

  case 31:
#line 287 "parser.y"
    {yyval.eval = yyvsp[0].eval;fprintf(yyout,"rule:expr->term\n");
	  								 free(&yyvsp[0].eval);
									 ;}
    break;

  case 32:
#line 294 "parser.y"
    { yyval.eval = yyvsp[-1].eval; free(&yyvsp[-1].eval);fprintf(yyout,"rule:term -> ( expr )\n"); ;}
    break;

  case 33:
#line 295 "parser.y"
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
#line 304 "parser.y"
    {	if ( yyvsp[0].eval.sym != NULL){
	   										yyval.eval=andor_oper(not,&yyvsp[0].eval,NULL);
	   									    free(&yyvsp[0].eval);
									 	}
										else
											yyval.eval.sym = NULL;
	   									fprintf(yyout,"rule:term -> not expr\n"); ;}
    break;

  case 35:
#line 312 "parser.y"
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
#line 323 "parser.y"
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
									  
									      //free(new_tmp);
									      //free(tmp_var);

									      lvalue_prefix(add,&yyvsp[-1].eval,new_IntExpr(1));
									  
									      free(&yyvsp[-1].eval);
									  }
										else
											yyval.eval.sym = NULL;
	   								  fprintf(yyout,"rule:term -> lvalue ++\n");;}
    break;

  case 37:
#line 352 "parser.y"
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
#line 364 "parser.y"
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
#line 390 "parser.y"
    { yyval.eval = yyvsp[0].eval; fprintf(yyout,"rule:term -> primary\n");  
	   									free(&yyvsp[0].eval);
									;}
    break;

  case 40:
#line 395 "parser.y"
    {  struct expr * new_tmp;
	   								   char * tmp_var = new_tmp_var();


										if(yyvsp[-2].eval.sym!=NULL && yyvsp[0].eval.sym!=NULL){

		  									if ( yyvsp[-2].eval.e_type == tableitem_e ){
		  										emit(tablesetelem,yyvsp[-2].eval.index,&yyvsp[0].eval,&yyvsp[-2].eval,0,yylineno);
											}
											else if(yyvsp[0].eval.e_type == tableitem_e){
		  										emit(tablegetelem,&yyvsp[0].eval,yyvsp[0].eval.index,&yyvsp[-2].eval,0,yylineno);
											
											}
											else{
												
												emit(assign,&yyvsp[0].eval,NULL,&yyvsp[-2].eval,0,yylineno);
												 S_entry sym,sym2;
									 										  
										 if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									     }
									     sym2 = find_rec( tmp_var , Scope, 1);

									     if(sym2 != NULL)
									   		new_tmp = new_VarE( sym2 );
									  
									  	 
										 emit(assign, &yyvsp[-2].eval, NULL, new_tmp, 0, yylineno);
											
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
#line 435 "parser.y"
    {yyval.eval = yyvsp[0].eval;
	   								 free(&yyvsp[0].eval);
									 fprintf(yyout,"rule:primary -> lvalue\n");;}
    break;

  case 42:
#line 439 "parser.y"
    {yyval.eval = yyvsp[0].eval; fprintf(yyout,"rule:primary -> call\n");		;}
    break;

  case 43:
#line 440 "parser.y"
    {yyval.eval = yyvsp[0].eval; fprintf(yyout,"rule:primary -> tablemake\n");	;}
    break;

  case 44:
#line 441 "parser.y"
    {yyval.eval = yyvsp[-1].eval; fprintf(yyout,"rule:primary -> ( funcdef )\n");;}
    break;

  case 45:
#line 442 "parser.y"
    {yyval.eval = const_expr(assign,&yyvsp[0].eval);
	   									fprintf(yyout,"rule:primary -> const\n");		
										free(&yyvsp[0].eval);
									;}
    break;

  case 46:
#line 448 "parser.y"
    { int i;
	  								  struct expr *new_lval;
									  S_entry sym,sym2;
									  struct expr * new_tmp;
	   								  //char * tmp_var = new_tmp_var();
									  i = id_scope(yyvsp[0].sval,Scope,upScope,upScope2);
									  
										/* if( !lookup( tmp_var, Scope, 1 ) ){
									  		insert( Scope, tmp_var, yylineno, 1 );
									     }
									     sym2 = find_rec( tmp_var , Scope, 1);

									     if(sym2 != NULL)
									   		new_tmp = new_VarE( sym2 );
									  */
									  	 
									  if ( i == 1 ){

									  		sym = find_rec(yyvsp[0].sval,Scope,1);
									  		if(sym == NULL){
									  			sym = find_rec(yyvsp[0].sval,Scope,2);
									  		}
									  		if( sym != NULL ){
									  	   		 new_lval = new_VarE(sym);
										 		yyval.eval = *new_lval;
											    //emit(assign, new_lval, NULL, new_tmp, 0, yylineno);

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
#line 488 "parser.y"
    { int res;
	                                  struct expr *new_lval;
									  S_entry sym,sym2;
									  struct expr * new_tmp;
	   								  char * tmp_var = new_tmp_var();
									  
									  if( !lookup( tmp_var, Scope, 1 ) ){
									  	insert( Scope, tmp_var, yylineno, 1 );
									  }
									  sym2 = find_rec( tmp_var , Scope, 1);

									  if(sym2 != NULL)
									  	new_tmp = new_VarE( sym2 );

	                                  res=local_id_scope(yyvsp[0].sval,Scope);
	   								  if(res==1){
									    
									  							 
									 	sym = find_rec(yyvsp[0].sval,Scope,1);
									  
									  	if(sym != NULL){

									  		 new_lval = new_VarE(sym);
									     	yyval.eval = *new_lval;
									  	}
										//emit(assign, new_lval, NULL, new_tmp, 0, yylineno);

										free(new_lval);
										free(&yyvsp[0].sval);
									}
									else 
									   yyval.eval.sym=NULL;

									 fprintf(yyout,"rule:lvalue -> local ID\n");
									;}
    break;

  case 48:
#line 524 "parser.y"
    {int res; 
	   								 S_entry sym; 
									 struct expr *new_lval;
									 S_entry sym2;
									 struct expr * new_tmp;
	   								 char * tmp_var = new_tmp_var();
								
									 if( !lookup( tmp_var, Scope, 1 ) ){
									  	insert( Scope, tmp_var, yylineno, 1 );
									 }
									 sym2 = find_rec( tmp_var , Scope, 1);

									 if(sym2 != NULL)
									 	new_tmp = new_VarE( sym2 );

	                                 res=global_id_scope(yyvsp[0].sval,Scope);

									  if(res!=0){							 
									  	sym = find_rec(yyvsp[0].sval,0,1);
									  
									  	if(sym != NULL){
									  	 	new_lval = new_VarE(sym);
  										 	yyval.eval = *new_lval;
									  	}
										//emit(assign, new_lval, NULL, new_tmp, 0, yylineno);
										free(&yyvsp[0].sval);
										free(new_lval);
									 }
									 else
									    yyval.eval.sym=NULL;
	   								  
									  fprintf(yyout,"rule:lvalue -> global ID\n");
									;}
    break;

  case 49:
#line 558 "parser.y"
    {yyval.eval = yyvsp[0].eval;fprintf(yyout,"rule:lvalue -> tableitem\n");;}
    break;

  case 50:
#line 563 "parser.y"
    {fprintf(yyout,"rule:glbl -> global\n");;}
    break;

  case 51:
#line 564 "parser.y"
    {fprintf(yyout,"rule:glbl -> ::\n");;}
    break;

  case 52:
#line 567 "parser.y"
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
#line 604 "parser.y"
    { 
	   								  if( yyvsp[-3].eval.sym != NULL && yyvsp[-1].eval.sym != NULL){
	   								  	struct expr * table = new_expr(tableitem_e);
		 							  
									  	//struct expr * res;
  								  	  	//struct expr *up = new_expr(tableitem_e);
										//S_entry sym;
										
										//char  * tmp_var = new_tmp_var();
									  	
										table->sym = yyvsp[-3].eval.sym;
										table->index = Expr_cpy(table->index,&yyvsp[-1].eval) ;								  
									  		
	
									  	//if( !lookup( tmp_var, Scope, 1 ) ){
									  //		insert( Scope, tmp_var, yylineno, 1 );
									  //	}
									   	//sym= find_rec( tmp_var , Scope, 1);
									  	///if(sym != NULL){
									  	//	res = new_VarE( sym );
										//	res->index = table->index;								  
									  	//	up->sym = res->sym;
										//	up->index = res->index;
									  //	}
									  //	emit(tablegetelem,table,&$3,res,0,yylineno);
									  	yyval.eval = *table;
									 }
									 else
									 	yyval.eval.sym = NULL;
	   			
	   									fprintf(yyout,"rule:tableitem -> lvalue ( expr )\n");;}
    break;

  case 54:
#line 636 "parser.y"
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
#line 666 "parser.y"
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
#line 696 "parser.y"
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
#line 731 "parser.y"
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

										if(search ==0 ){
											if(lookup(yyvsp[-3].sval,0,3))
												search = 1;
										}
										
										if ( search == 1 ){
											sym = find_rec(yyvsp[-3].sval,Scope,2);
											if(sym == NULL){
												sym = find_rec(yyvsp[-3].sval,0,3);
											}
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
#line 765 "parser.y"
    {  	int i=0;
										int search = 0;
                                     	S_entry sym;
										struct expr * new_lval;
										
									    
										if (lookup(yyvsp[-3].sval,0,2) ){
												search = 1;
												
										}

										if(search == 0 ){
											if(lookup(yyvsp[-3].sval,0,3))
												search = 1;
										}

										if ( search == 1 ){
											sym = find_rec(yyvsp[-3].sval,Scope,2);
											if(sym == NULL){
												sym = find_rec(yyvsp[-3].sval,0,3);
											}

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
#line 803 "parser.y"
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
#line 828 "parser.y"
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
#line 849 "parser.y"
    {  yyval.eval = *call_expr(&yyvsp[-4].eval,elist_head);
										elist_head = NULL;
	   								fprintf(yyout,"rule:call -> ( funcdef ) ( elist )\n");;}
    break;

  case 62:
#line 855 "parser.y"
    { 	if(yyvsp[-1].eval.e_type == tableitem_e){
										struct expr * res;
  								  	  	//struct expr *up = new_expr(tableitem_e);
										S_entry sym;
										
										char  * tmp_var = new_tmp_var();
									  	
										//table->sym = $1.sym;
										//table->index = Expr_cpy(table->index,&$3) ;								  
									  		
	
									  		if( !lookup( tmp_var, Scope, 1 ) ){
									  			insert( Scope, tmp_var, yylineno, 1 );
									  		}
									   		sym= find_rec( tmp_var , Scope, 1);
									  		if(sym != NULL){
									  			res = new_VarE( sym );
											//res->index = Expr_cpy(res->index,$2.index);
									  	//	up->sym = res->sym;
										//	up->index = res->index;
									  		}
									    	emit(tablegetelem,&yyvsp[-1].eval,yyvsp[-1].eval.index,res,0,yylineno);
											yyval.eval = *res;
	 
	 							  		if( elist_head == NULL ){
								  		elist_head = Expr_cpy(elist_head,res);
								  		}
								  		else{
								  			res->next = elist_head;
											elist_head = Expr_cpy(elist_head,res);
								  		}
								  }
								  else{
										if( elist_head == NULL ){
								  			elist_head = Expr_cpy(elist_head,&yyvsp[-1].eval);
								  		}
								  		else{
								  			yyvsp[-1].eval.next = elist_head;
											elist_head = Expr_cpy(elist_head,&yyvsp[-1].eval);
								  		}
								    }
	                              		fprintf(yyout,"rule:elist -> expr elist1s\n");;}
    break;

  case 63:
#line 897 "parser.y"
    {elist_head = NULL;fprintf(yyout,"rule:elist -> empty\n");	   ;}
    break;

  case 64:
#line 900 "parser.y"
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
#line 912 "parser.y"
    {elist_head = (struct expr *)0;fprintf(yyout,"rule:elist1s -> empty\n");		   ;}
    break;

  case 66:
#line 915 "parser.y"
    {	
								 	if(yyvsp[0].eval.e_type == tableitem_e){
										struct expr * res;
  								  	  	//struct expr *up = new_expr(tableitem_e);
										S_entry sym;
										
										char  * tmp_var = new_tmp_var();
									  	
										//table->sym = $1.sym;
										//table->index = Expr_cpy(table->index,&$3) ;								  
									  		
	
									  		if( !lookup( tmp_var, Scope, 1 ) ){
									  			insert( Scope, tmp_var, yylineno, 1 );
									  		}
									   		sym= find_rec( tmp_var , Scope, 1);
									  		if(sym != NULL){
									  			res = new_VarE( sym );
											//res->index = Expr_cpy(res->index,$2.index);
									  	//	up->sym = res->sym;
										//	up->index = res->index;
									  		}
									    	emit(tablegetelem,&yyvsp[0].eval,yyvsp[0].eval.index,res,0,yylineno);
											yyval.eval = *res;
										}
										else
	  										yyval.eval = yyvsp[0].eval;
	  								fprintf(yyout,"rule:elist1 -> COMMA expr\n");;}
    break;

  case 67:
#line 945 "parser.y"
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
#line 957 "parser.y"
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
#line 968 "parser.y"
    {index_head = NULL;fprintf(yyout,"rule:ind1s -> empty");		 ;}
    break;

  case 70:
#line 970 "parser.y"
    {	yyval.eval = yyvsp[0].eval;
									fprintf(yyout,"rule:ind1 -> COMMA indexedelem\n");;}
    break;

  case 71:
#line 975 "parser.y"
    { yyvsp[-3].eval.index = Expr_cpy(yyvsp[-3].eval.index,&yyvsp[-1].eval);
		   									yyval.eval = yyvsp[-3].eval;
		   									fprintf(yyout,"rule:indexedelem -> { expr : expr }\n");
										  ;}
    break;

  case 72:
#line 980 "parser.y"
    { yyval.eval = yyvsp[-1].eval; fprintf(yyout,"rule:tablemake -> [ tsize ]\n");;}
    break;

  case 73:
#line 983 "parser.y"
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
#line 1005 "parser.y"
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
#line 1032 "parser.y"
    {++MaxScope; Scope++; ;}
    break;

  case 76:
#line 1032 "parser.y"
    {fprintf(yyout,"rule:block -> { stmts }\n");
												;}
    break;

  case 77:
#line 1036 "parser.y"
    { //push(&oof_counter,oof_st);
								//oof_counter = 0;
								insert_jump_point(1,ret_s);
								func_flag += 1; funcVars=0; varsFlag++; 

	   							if( yyvsp[0].eval.sym != NULL){
									//kainoyrio
									//emit(ret,NULL,NULL,&$2,0,yylineno);
									emit(jump,NULL,NULL,NULL,0,yylineno);
	 								insert_jump_point(0,ret_s);
									
									emit(funcstart,&yyvsp[0].eval,NULL,NULL,0,yylineno);
									yyval.eval = yyvsp[0].eval;
								}
								else
									yyval.eval.sym = NULL;
								
								
							  ;}
    break;

  case 78:
#line 1055 "parser.y"
    { ++MaxScope; Scope++; ScopeSpaceCounter++;;}
    break;

  case 79:
#line 1056 "parser.y"
    { insert_arguments(Scope); ScopeSpaceCounter++;;}
    break;

  case 80:
#line 1057 "parser.y"
    {	//int tmp_oof = oof_counter;
								//oof_counter = 0;

								func_name = fun_names[--fn_i];

								funcVars+=count_funcVars(Scope);
								set_sumOfVars(funcVars,Scope);

								Hide(Scope);
								Scope--;
								Hide(Scope--);
								ScopeSpaceCounter -= 2;
								
								if( yyvsp[-7].eval.sym != NULL ){
								  	backpatch(ret_s); 									
									emit(funcend,&yyvsp[-7].eval,NULL,NULL,0,yylineno);
									
									yyval.eval = yyvsp[-7].eval;
									free(&yyvsp[-7].eval);
									free(func_name);
									free(fun_names[fn_i]);
								}
								else
									yyval.eval.sym = NULL;

								varsFlag--;
								func_flag -= 1;
								funcVars=0;
								//oof_counter = tmp_oof;
								//oof_counter = *(int *)pop(oof_st);
								fprintf(yyout,"rule:funcdef -> function fid ( idlist ) block\n");
							;}
    break;

  case 81:
#line 1091 "parser.y"
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
#line 1130 "parser.y"
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
#line 1150 "parser.y"
    {struct expr *const_new = new_IntExpr(yyvsp[0].ival);  yyval.eval = *const_new; free(&yyvsp[0].ival); free(const_new); fprintf(yyout,"rule:const -> INTCONST\n");  ;}
    break;

  case 84:
#line 1151 "parser.y"
    {struct expr *const_new = new_FltExpr(yyvsp[0].fval);  yyval.eval = *const_new; free(&yyvsp[0].fval); free(const_new);fprintf(yyout,"rule:const -> FLOATCONST\n");;}
    break;

  case 85:
#line 1152 "parser.y"
    {struct expr *const_new = new_StrExpr(yyvsp[0].sval);  yyval.eval = *const_new; free(&yyvsp[0].sval); free(const_new);fprintf(yyout,"rule:const -> STRING\n");    ;}
    break;

  case 86:
#line 1153 "parser.y"
    {struct expr *const_new = new_NillExpr(yyvsp[0].sval); yyval.eval = *const_new; free(&yyvsp[0].sval); fprintf(yyout,"rule:const -> nil\n");						 							 ;}
    break;

  case 87:
#line 1154 "parser.y"
    {struct expr *const_new = new_BoolExpr(1u); yyval.eval = *const_new; free(const_new); fprintf(yyout,"rule:const -> true\n");	 	 ;}
    break;

  case 88:
#line 1155 "parser.y"
    {struct expr *const_new = new_BoolExpr(0u); yyval.eval = *const_new; free(const_new);fprintf(yyout,"rule:const -> false\n");	 ;}
    break;

  case 89:
#line 1158 "parser.y"
    {  		
	  						if( !lookup(yyvsp[-1].sval,Scope,1) && !lookup(yyvsp[-1].sval,Scope-1,2) )
								
								insert(Scope,yyvsp[-1].sval,yylineno,1);
								
							else
								fprintf(stderr,"Redifine id:%s at line:%d\n",yyvsp[-1].sval,yylineno);
							
							fprintf(yyout,"rule:idlist -> ID id1s\n");
						;}
    break;

  case 90:
#line 1169 "parser.y"
    {fprintf(yyout,"rule:idlist -> empty\n");;}
    break;

  case 91:
#line 1173 "parser.y"
    {   if (!lookup(yyvsp[0].sval,Scope,1) && !lookup(yyvsp[0].sval,Scope-1,2))
								insert(Scope,yyvsp[0].sval,yylineno,1);
							else
								fprintf(stderr,"Redifine id:%s at line:%d\n",yyvsp[0].sval,yylineno);
								
							fprintf(yyout,"rule:id1 -> , ID\n");
						;}
    break;

  case 92:
#line 1182 "parser.y"
    {fprintf(yyout,"rule:id1s -> id1 id1s\n");;}
    break;

  case 93:
#line 1183 "parser.y"
    {fprintf(yyout,"rule:id1s -> empty\n");	  ;}
    break;

  case 94:
#line 1187 "parser.y"
    { emit(if_eq,&yyvsp[-1].eval,new_BoolExpr(0u),NULL,0,yylineno);
		 									insert_jump_point(1,break_s);
		 									insert_jump_point(0,back_s);;}
    break;

  case 95:
#line 1190 "parser.y"
    { cont_loop = get_cont_point(1); loop = get_loop_point(1);
					 						 emit(jump,NULL,NULL,NULL,loop,yylineno);
					 						 
								  	  		 backpatch(back_s); 
											 backpatch(break_s);
											 free(&yyvsp[-3].eval);
							  		  		 fprintf(yyout,"rule:whilestmt -> while ( expr ) stmt\n");;}
    break;

  case 96:
#line 1199 "parser.y"
    {loop = getCurQuad(); insert_loop_point(&loop); cont_loop = getCurQuad(); insert_cont_point(&cont_loop);;}
    break;

  case 97:
#line 1203 "parser.y"
    {emit(if_eq,&yyvsp[-1].eval,new_BoolExpr(0u),NULL,0,yylineno); 
	  								insert_jump_point(0,back_s); ;}
    break;

  case 98:
#line 1205 "parser.y"
    {free(&yyvsp[-4].eval);fprintf(yyout,"rule:ifstmt -> if ( expr ) stmt elsestmt\n");;}
    break;

  case 99:
#line 1208 "parser.y"
    {emit(jump,NULL,NULL,NULL,0,yylineno);backpatch(back_s);insert_jump_point(0,back_s);;}
    break;

  case 100:
#line 1208 "parser.y"
    {backpatch(back_s);fprintf(yyout,"rule:elsestmt -> else stmt\n");;}
    break;

  case 101:
#line 1209 "parser.y"
    {backpatch(back_s);fprintf(yyout,"rule:elsestmt -> empty");	   ;}
    break;

  case 102:
#line 1214 "parser.y"
    {emit(if_eq,&yyvsp[0].eval,new_BoolExpr(0u),NULL,0,yylineno);
		 									insert_jump_point(1,break_s);
		 									insert_jump_point(0,back_s);;}
    break;

  case 103:
#line 1216 "parser.y"
    {
										 cont_loop = get_cont_point(1); loop = get_loop_point(1);
					 					 emit(jump,NULL,NULL,NULL,loop,yylineno);
					 						 
								  	  	 backpatch(back_s); 
										 backpatch(break_s);
										 free(&yyvsp[-5].eval);
										 fprintf(yyout,"rule:forstmt -> for ( elist ; expr ; elist ) stmt\n");;}
    break;

  case 104:
#line 1226 "parser.y"
    {loop = getCurQuad(); insert_loop_point(&loop); cont_loop = getCurQuad();
	   									  insert_cont_point(&cont_loop);;}
    break;

  case 105:
#line 1230 "parser.y"
    {	if( func_flag > 0 ){
		  										emit(ret,NULL,NULL,&yyvsp[-1].eval,0,yylineno);
											 	emit(jump,NULL,NULL,NULL,0,yylineno);
	 								 			insert_jump_point(0,ret_s);
									 	  	}
											else{
												emit(nop,NULL,NULL,NULL,0,yylineno);
									 	        fprintf(stderr,"%s: line %d: ---> Warning : return statement out of function (no operation produced)\n",file_name,yylineno);
												 
											}
											yyval.eval = yyvsp[-1].eval;free(&yyvsp[-1].eval); 
											fprintf(yyout,"rule:returnstmt -> return prexpr ;\n");
										   ;}
    break;

  case 106:
#line 1245 "parser.y"
    {yyval.eval = yyvsp[0].eval;free(&yyvsp[0].eval);fprintf(yyout,"rule:prexpr -> expr\n"); ;}
    break;

  case 107:
#line 1246 "parser.y"
    {fprintf(yyout,"rule:prexpr -> empty\n");;}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 2853 "parser.c"

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


#line 1250 "parser.y"

int main(int argc,char **argv){

	int lk , skata;
	struct expr * tmp;
	char **LF,**SC;
	double *NC;
	struct userfunc **UF;
	struct instruction *IN;
	new = (struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));
	new->s_value=(char *)malloc((MAX_LEXEME)*sizeof(char));
	ayylval = (void *) new;
	char *binary_filename;
	//oof_st = newStack(1024,sizeof( int ));
	
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
	
	if((fcode_ofile= fopen("fcode.txt","w+")) == NULL){
		fprintf(stderr,"Cannot open fcode.txt\n");
		exit(1);
	}

	file_name = strdup( argv[1]);
	binary_filename = (char *)malloc( strlen( file_name )*sizeof( char )+5 );
	binary_filename = strcpy(binary_filename,file_name);
	binary_filename = strcat(binary_filename,".abc");
	
	Init_symbolTable();
	
	yyparse();
	emit(nop,NULL,NULL,NULL,0,yylineno);

	print();


	print_to_file();
	
	//print_quads();
	
    generate_all();
	//print2_final_code();
	if(flag_error != 1){

	print_fcode();

	create_binary( binary_filename,userFuncs,nameLibFuncs,stringConsts,numConsts,
					avm_incode,oof_counter,curr_incode,totalNumConsts,totalStringConsts,totalNameLibFuncs,totalUserFuncs);
	
	
//	print_str_array(LF);
	}
	else{
		fprintf(stderr,"No executable produced.\n");
	}
	fclose(fcode_ofile);
	destroy_symboltable();
	free(new->s_value);
	free(new);
	fclose(yyin);
	fclose(yyout);
	
	fclose(sym_file);
	fclose(quad_ofile);

	
	//free(userFuncs);
	//fclose(fcode_ofile);
	return 0;
}


int yyerror(char *yaccProvideMessage){
	fprintf(stderr,"%s at line %d ,before token:%s\n",yaccProvideMessage,yylineno,yytext);
	flag_error = 1;
	return 0;
}

