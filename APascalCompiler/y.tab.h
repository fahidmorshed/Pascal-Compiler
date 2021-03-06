/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    PROGRAM = 260,
    BEGIN1 = 261,
    END = 262,
    VAR = 263,
    ARRAY = 264,
    OF = 265,
    DOTDOT = 266,
    INTEGER = 267,
    REAL = 268,
    ID = 269,
    DO = 270,
    THEN = 271,
    WHILE = 272,
    NOT = 273,
    RELOP = 274,
    MULOP = 275,
    OR = 276,
    AND = 277,
    UNARY = 278,
    ASSIGNOP = 279,
    PROCEDURE = 280,
    FUNCTION = 281,
    WRITE = 282,
    NUM = 283,
    UMINUS = 284
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define PROGRAM 260
#define BEGIN1 261
#define END 262
#define VAR 263
#define ARRAY 264
#define OF 265
#define DOTDOT 266
#define INTEGER 267
#define REAL 268
#define ID 269
#define DO 270
#define THEN 271
#define WHILE 272
#define NOT 273
#define RELOP 274
#define MULOP 275
#define OR 276
#define AND 277
#define UNARY 278
#define ASSIGNOP 279
#define PROCEDURE 280
#define FUNCTION 281
#define WRITE 282
#define NUM 283
#define UMINUS 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 75 "Parser.y" /* yacc.c:1909  */

	int ival;
	double dval;
	char string[100];
	SymbolInfo *symp;

#line 119 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
