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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 35 "parser.y"
typedef union token_A{

	  struct expr eval;
	  int ival;
	  float fval;
	  char *sval;
	
} YYSTYPE;
/* Line 1285 of yacc.c.  */
#line 142 "parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



