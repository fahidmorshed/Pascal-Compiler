/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */



#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#include "symboltable.h"


///////////////////////////////////////
void yyerror(char *);
extern int yyparse();
extern int yylex(void);
extern int number_of_lines ;
/////////////////////////////////


//varibales for bss section
SymbolInfo* variable[100];
bool Start = false;

//////////////////////temp variables/////////////////
char strTemp[10];
char strLabel[10];

SymbolTable st; /////////////symbol table


char strRes[10];
char bss[1000];
char data[10000];

int counter = 0; //number of variables

//Give name to temp variable
char* newTemp(){
	
	static int i = 1;
	
	//ItoA(i);
	sprintf(strRes,"%d",i) ;
	
	strcpy(strTemp,"temp");
	strcat(strTemp,strRes);
	
	strcat(bss,strTemp);
	strcat(bss," resd 1\n");
	
	i++;
	return strTemp;
}

//Give name to new label
char* newLabel(){

	static int i = 1;
	
	//ItoA(i);
	sprintf(strRes,"%d",i) ;
	strcpy(strLabel,"label");
	strcat(strLabel,strRes);

	i++;
	return strLabel;
}




#line 140 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 75 "Parser.y" /* yacc.c:355  */

	int ival;
	double dval;
	char string[100];
	SymbolInfo *symp;

#line 245 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 260 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    31,    29,    37,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   115,   140,   160,   164,   169,   174,   181,
     189,   200,   205,   210,   216,   220,   226,   231,   236,   240,
     246,   258,   268,   272,   286,   309,   374,   396,   400,   404,
     443,   499,   570,   582,   586,   588,   592,   595,   599,   605,
     701,   705,   710,   777,   839,   845,   928,   942,   948,   962,
     966
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "PROGRAM", "BEGIN1", "END",
  "VAR", "ARRAY", "OF", "DOTDOT", "INTEGER", "REAL", "ID", "DO", "THEN",
  "WHILE", "NOT", "RELOP", "MULOP", "OR", "AND", "UNARY", "ASSIGNOP",
  "PROCEDURE", "FUNCTION", "WRITE", "NUM", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "'('", "')'", "';'", "','", "':'", "'['", "']'", "$accept",
  "program", "identifier_list", "declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "arguments", "parameter_list", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    43,
      45,    42,    47,   284,    40,    41,    59,    44,    58,    91,
      93
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,    -2,    18,    -6,   -85,    42,   -85,   -20,    17,    46,
     -85,   -85,    54,    42,    15,    27,     2,    56,    64,    43,
     -85,   -85,    38,     9,   -14,     9,    47,   -85,    73,    48,
     -85,    58,   -85,    49,    49,   -85,    40,    50,   -85,   -85,
      51,   -85,    57,    24,   -85,    24,     9,    69,    25,    68,
     -85,     9,     9,    75,    78,   -85,     2,     9,    42,    59,
      55,   -85,    66,   -85,     9,   -85,    68,    61,     2,     9,
      24,    24,    24,    22,   -85,    62,     2,    63,   -85,   -85,
      29,    33,   -85,    60,    86,    26,   -85,    95,    45,    68,
      68,   -85,   -85,     9,   -85,   -85,   -85,    38,   -85,    42,
      65,    72,   -85,     2,   -85,   -85,    39,   -85,    67,   -85,
      38,    93,   -85,    60,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       6,     4,    12,     0,     0,     0,    22,     0,     0,     0,
       6,     2,     0,     0,    34,     0,     0,    28,     0,    21,
      23,     0,    27,    17,    17,    11,     0,     0,     9,    10,
       0,     7,    46,     0,    48,     0,     0,     0,    38,    40,
      44,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    13,     0,     5,     0,    50,    41,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,    24,    25,
       0,     0,    15,     0,     0,     0,    49,    29,    39,    42,
      43,    45,    35,     0,    33,    31,    26,     0,    16,     0,
       0,     0,    47,     0,    37,    18,     0,    14,     0,    30,
       0,     0,    19,     0,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -13,    84,   -84,   -79,   -85,   -85,   -85,    71,
     -85,    -3,   -85,   -85,   -54,   -85,   -85,    44,   -22,    37,
     -39,   -36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    12,    40,    41,    14,    19,    20,    59,
      81,    27,    28,    29,    30,    31,    32,    73,    74,    48,
      49,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    47,    78,    53,   100,    23,    66,    65,    16,     1,
     -32,    21,     3,   105,    87,     8,    24,     9,     4,    25,
      51,    16,    95,    42,    67,    52,   112,    43,     5,    26,
      75,    89,    90,    61,   114,    79,    91,    44,    42,    45,
      17,    18,    43,    46,    69,    80,    16,    37,    13,   109,
      38,    39,    44,    10,    70,    71,     6,    92,    46,    93,
      11,   102,    13,    93,     9,    22,     9,    97,    98,    99,
      33,   104,    38,    39,    70,    71,     9,   110,    34,    35,
      55,    54,    57,    58,    56,    68,   106,    63,    72,    62,
      76,    64,    77,    83,    84,    82,    86,   101,    96,   103,
     108,   107,    94,   113,    36,    60,    88,   111,    85
};

static const yytype_uint8 yycheck[] =
{
      13,    23,    56,    25,    83,     3,    45,    43,     6,     5,
      24,    14,    14,    97,    68,    35,    14,    37,     0,    17,
      34,     6,    76,    14,    46,    39,   110,    18,    34,    27,
      52,    70,    71,    36,   113,    57,    72,    28,    14,    30,
      25,    26,    18,    34,    19,    58,     6,     9,     8,   103,
      12,    13,    28,    36,    29,    30,    14,    35,    34,    37,
      14,    35,     8,    37,    37,    38,    37,    38,    35,    36,
      14,    93,    12,    13,    29,    30,    37,    38,    14,    36,
       7,    34,    24,    34,    36,    16,    99,    36,    20,    39,
      15,    34,    14,    38,    28,    36,    35,    11,    35,     4,
      28,    36,    40,    10,    20,    34,    69,    40,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    42,    14,     0,    34,    14,    43,    35,    37,
      36,    14,    44,     8,    47,    43,     6,    25,    26,    48,
      49,    52,    38,     3,    14,    17,    27,    52,    53,    54,
      55,    56,    57,    14,    14,    36,    44,     9,    12,    13,
      45,    46,    14,    18,    28,    30,    34,    59,    60,    61,
      62,    34,    39,    59,    34,     7,    36,    24,    34,    50,
      50,    52,    39,    36,    34,    62,    61,    59,    16,    19,
      29,    30,    20,    58,    59,    59,    15,    14,    55,    59,
      43,    51,    36,    38,    28,    58,    35,    55,    60,    61,
      61,    62,    35,    37,    40,    55,    35,    38,    35,    36,
      46,    11,    35,     4,    59,    45,    43,    36,    28,    55,
      38,    40,    45,    10,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    47,    48,    49,    49,    50,    50,    51,    51,
      52,    53,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    62,
      62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     1,     3,     6,     0,     1,     8,     1,
       1,     3,     0,     3,     6,     4,     3,     0,     3,     5,
       3,     1,     0,     1,     3,     3,     4,     1,     1,     4,
       6,     4,     1,     4,     1,     4,     1,     3,     1,     3,
       1,     2,     3,     3,     1,     3,     1,     4,     1,     3,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 109 "Parser.y" /* yacc.c:1646  */
    {

			printf("In Program --> Start of Production Rule\n");
		}
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 115 "Parser.y" /* yacc.c:1646  */
    {
				static int i = 1;

				printf("In identifier_list :ID \n");
				if((yyvsp[0].symp)->typeVal){
					
					variable[counter] = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					variable[counter++] = (yyvsp[0].symp);
					
					//building section.bss
					if(i++ <= 1){
						strcpy(bss,(yyvsp[0].symp)->symbol);
						strcat(bss," resd 1\n");
					}
					else{
						strcat(bss,(yyvsp[0].symp)->symbol);
						strcat(bss," resd 1\n");
					}
					
					//printf("In identifier list: bss is now\n%s\n",bss);
				}
				
				//printf("The pointer for %s is %p\n",$1->symbol,$1);	
				
		}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 140 "Parser.y" /* yacc.c:1646  */
    {
		
				printf("In identifier_list ',' ID \n");
				if((yyvsp[0].symp)->typeVal){
					
					
					variable[counter] = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					variable[counter++] = (yyvsp[0].symp);
					
					//building section.bss
					
					strcat(bss,(yyvsp[0].symp)->symbol);
					strcat(bss," resd 1\n");
					
					//printf("In identifier list: bss is now\n%s\n",bss);
					//printf("The pointer for %s is %p\n",$3->symbol,$3);
				}
		}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 161 "Parser.y" /* yacc.c:1646  */
    {
				printf("This is the declaration\n");
			}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 164 "Parser.y" /* yacc.c:1646  */
    {
				printf("No Declaration\n");
			}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 170 "Parser.y" /* yacc.c:1646  */
    {
			printf("type : standard_type\n");
			counter = 0;
		}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 175 "Parser.y" /* yacc.c:1646  */
    {
			printf("type : ARRAY [ num .. num ] of standard_type\n");
			//printf("Lower index %0.lf , Upper index %0.lf\n",$3,$5);
		}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 181 "Parser.y" /* yacc.c:1646  */
    {	
				printf("standard_type :  integer\n");
				
				for(int i = 0 ; i < counter ; i++){
					strcpy(variable[i]->dataType,"INTEGER");
				}
				counter = 0;
			}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 189 "Parser.y" /* yacc.c:1646  */
    {	
				printf("standard_type is REAL\n");
				
				for(int i = 0 ; i < counter ; i++){
					strcpy(variable[i]->dataType,"REAL");
				}
				counter = 0;
			}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 201 "Parser.y" /* yacc.c:1646  */
    {
					printf("subprog_declarations : subprog_declarations subprogram declarations ;\n");
				}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 205 "Parser.y" /* yacc.c:1646  */
    {
					printf("subprogram declarations :  empty\n");
				}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 211 "Parser.y" /* yacc.c:1646  */
    {
					printf("subprog_declaration :subprogram_head declarations compound_statement \n");
				}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 217 "Parser.y" /* yacc.c:1646  */
    {
					printf("subprogram_head		:	FUNCTION ID arguments ':' standard_type ';'\n");
				}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 221 "Parser.y" /* yacc.c:1646  */
    {
					printf("subprogram  head : procedure ID agrguments;\n");
				}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 227 "Parser.y" /* yacc.c:1646  */
    {
				printf("arguments : ( parameter_list )\n");
			}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 231 "Parser.y" /* yacc.c:1646  */
    {
				printf("arguments :  empty\n");
			}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 237 "Parser.y" /* yacc.c:1646  */
    {
				printf("parameter_list : type\n");
			}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 241 "Parser.y" /* yacc.c:1646  */
    {
				printf("parameter_list ; parameter_list ';' identifier_list ':' type\n");
			}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 248 "Parser.y" /* yacc.c:1646  */
    {
					printf("\ncompound_statement  : BEGIN1\n\toptional_statements\n\tEND\n");
					SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					
					strcpy(temp->code,(yyvsp[-1].symp)->code);
					
					(yyval.symp)=temp;
				}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 259 "Parser.y" /* yacc.c:1646  */
    {
					printf("optional_statements	:	statement_list\n");
					
					
					SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					strcpy(temp->code,(yyvsp[0].symp)->code);
					
					(yyval.symp)=temp;
				}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 268 "Parser.y" /* yacc.c:1646  */
    {
					//printf("optional-statement empty \n");
				}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 273 "Parser.y" /* yacc.c:1646  */
    {
			
				printf("statement_list	:	statement\n");
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				strcpy(temp->code,(yyvsp[0].symp)->code);
				
				//printf("The code %s\n",$1->code);
				
				(yyval.symp)=temp;
				
				
			}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 287 "Parser.y" /* yacc.c:1646  */
    {
				printf("statement_list	: : statement_list ';' statement\n");
				//printf("The symbol now %s\n",$3->symbol);
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				//temp = st.Lookup("Code","Help");

				//strcat(data,$3->code);				
							
				//printf("---------------------------------\nThe Code for $1 \n%s\n",$1->code);			
				//printf("---------------------------------\nThe Code for $3 \n%s\n",$3->code);			
				
				strcpy(temp->code,(yyvsp[-2].symp)->code);
				strcat(temp->code,(yyvsp[0].symp)->code);
				
				strcpy(data,temp->code);
				
				(yyval.symp) = temp;
			}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 310 "Parser.y" /* yacc.c:1646  */
    {
			
				//Fine, it is working well
				//mov eax,3
				//or
				//mov dword[x],eax

			
				printf("statement	:	variable ASSIGNOP expression\n");

			
				if((yyvsp[0].symp)->numVal){
					(yyvsp[-2].symp)->value = (yyvsp[0].symp)->value;
					
					//adding previous codes
					strcpy((yyvsp[-2].symp)->code,(yyvsp[0].symp)->code);
					
					//generating new code
					
					
					strcat((yyvsp[-2].symp)->code,"mov eax,");
					//ItoA($3->value);
					sprintf(strRes,"%d",(yyvsp[0].symp)->value) ;
					strcat((yyvsp[-2].symp)->code,strRes);
					strcat((yyvsp[-2].symp)->code,"\n");
					strcat((yyvsp[-2].symp)->code,"mov dword[");
					strcat((yyvsp[-2].symp)->code,(yyvsp[-2].symp)->symbol);
					strcat((yyvsp[-2].symp)->code,"],");
					strcat((yyvsp[-2].symp)->code,"eax\n");
					
					
					printf("The code is %s",(yyvsp[-2].symp)->code);
				}
			
				else{
					(yyvsp[-2].symp)->value = (yyvsp[0].symp)->value;
					
					//adding previous codes
					strcpy((yyvsp[-2].symp)->code,(yyvsp[0].symp)->code);
					
					//generating new codes
					strcat((yyvsp[-2].symp)->code,"mov eax,dword[");
					strcat((yyvsp[-2].symp)->code,(yyvsp[0].symp)->symbol);
					strcat((yyvsp[-2].symp)->code,"]\n");
					strcat((yyvsp[-2].symp)->code,"mov dword[");
					strcat((yyvsp[-2].symp)->code,(yyvsp[-2].symp)->symbol);
					strcat((yyvsp[-2].symp)->code,"],eax\n");
					
					//printf("The code is %s",$1->code);
				}
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				//temp = st.Insert("Code","Help");
				strcpy(temp->code,(yyvsp[-2].symp)->code);
				strcpy(temp->symbol,(yyvsp[-2].symp)->symbol);
				
			//	printf("The pointer for %s is %p\n",$1->symbol,$1);
			//	printf("Before passing the code is %s\n",$1->code);

				(yyval.symp) = temp;
				
				
			}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 375 "Parser.y" /* yacc.c:1646  */
    {
				//printf("In write id\n");
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = '\0';
				
				//mov eax,[x]
				//push eax
				//call printFunc
				//pop eax
				
				strcat(temp->code,"\nmov eax,dword[");
				strcat(temp->code,(yyvsp[-1].symp)->symbol);
				strcat(temp->code,"]\n");
				strcat(temp->code,"push eax\n");
				strcat(temp->code,"call printFunc\n");
				strcat(temp->code,"pop eax\n");
				
				(yyval.symp)=temp;
			}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 397 "Parser.y" /* yacc.c:1646  */
    {
				printf("statement -> procedure_statement\n");
			}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 401 "Parser.y" /* yacc.c:1646  */
    {
				printf("statement -> compound_statement\n");
			}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 405 "Parser.y" /* yacc.c:1646  */
    {
				printf("statement -> if exp then statement\n");
				
				char tempLabel[10];
				char string[1000];
				
				strcpy(string,(yyvsp[0].symp)->code);
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = '\0';
				strcat(temp->code,(yyvsp[-2].symp)->code);			//add code from expression
				
				
				newLabel();
				strcpy(tempLabel,strLabel);			//keeping backup
				
								
				strcat(temp->code,(yyvsp[-2].symp)->branchInfo);		//cmp x,y; jg label1; 
				strcat(temp->code," ");
				strcat(temp->code,strLabel);
				strcat(temp->code,"\n");
				
				strcat(temp->code,"jmp ");			//jmp label2
				newLabel();						
				strcat(temp->code,strLabel);
				strcat(temp->code,"\n\n");
				
				strcat(temp->code,tempLabel);			//label1:
				strcat(temp->code,":\n\n");			
				
				strcat(temp->code,string);			//code for statement
			
				strcat(temp->code,strLabel);			//label2:
				strcat(temp->code,":\n\n");	
			
			
				(yyval.symp) = temp;				
			}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 444 "Parser.y" /* yacc.c:1646  */
    {
				printf("statement -> if exp then statement else statement\n");
				
				char temp1[100],temp2[100];
				char tempLabel[10];
				
				printf("And in if-else the address $4-> %p,name %s,code %s\n",(yyvsp[-2].symp),(yyvsp[-2].symp)->symbol,(yyvsp[-2].symp)->code);
				strcpy(temp1,(yyvsp[-2].symp)->code);
				strcpy(temp2,(yyvsp[0].symp)->code);
				
				printf("$4->code %s\n",(yyvsp[-2].symp)->code);
				printf("$6->code %s\n",(yyvsp[0].symp)->code);
				
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = '\0';
				
				
				//adding code for expression
				strcat(temp->code,(yyvsp[-4].symp)->code);
				
				newLabel();
				strcpy(tempLabel,strLabel);
				strcat(temp->code,(yyvsp[-4].symp)->branchInfo);		// jg label1; 
				strcat(temp->code," ");
				strcat(temp->code,strLabel);
				strcat(temp->code,"\n");
				
				strcat(temp->code,"jmp ");			//jmp label2
				newLabel();						
				strcat(temp->code,strLabel);				
				strcat(temp->code,"\n\n");
				
				strcat(temp->code,tempLabel);			//label1:
				strcat(temp->code,":\n\n");
				
				strcat(temp->code,temp1);			//code under label1
				
				strcpy(tempLabel,strLabel);
				
				strcat(temp->code,"jmp ");			//jmp label3(skipping label2:)
				newLabel();
				strcat(temp->code,strLabel);	
				strcat(temp->code,"\n\n");		
				
				strcat(temp->code,tempLabel);			//label2:
				strcat(temp->code,":\n\n");
				strcat(temp->code,temp2);			//code under label2
				
				strcat(temp->code,strLabel);			//label3:
				strcat(temp->code,":\n\n");
			
				(yyval.symp) = temp;				
				
			}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 500 "Parser.y" /* yacc.c:1646  */
    {
				printf("statement : WHILE expression DO statement\n");
				
				char tempLabel[10];
				char tempLabel1[10],tempLabel2[10];
				char string[100];
				
				//printf("The pointer is %");
				//printf("$4->symbol %s\n",$4->symbol);
				strcpy(string,(yyvsp[0].symp)->code);		//Another problem
				
				//printf("problem finding\n");
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = '\0';
				
				strcat(temp->code,(yyvsp[-2].symp)->code);
				strcat(temp->code,(yyvsp[-2].symp)->branchCont);			//jle 
				newLabel();
				strcat(temp->code," ");
				strcat(temp->code,strLabel);				//label1
				strcat(temp->code,"\n\n");
				
				strcpy(tempLabel,strLabel);
				
				strcat(temp->code,"mov ecx,eax\n");		//before looping
				strcat(temp->code,"push ebx\n\n");
				
				
				
				newLabel();							//label:
				strcat(temp->code,strLabel);
				strcat(temp->code,":\n\n");
				
				
				strcat(temp->code,"pop ebx\n");
				strcat(temp->code,"push ebx\n");
				strcat(temp->code,"mov ecx,dword[");
				strcat(temp->code,(yyvsp[-2].symp)->symbol);
				strcat(temp->code,"]\n");
				
				strcat(temp->code,"cmp ecx,ebx\n");
				strcat(temp->code,(yyvsp[-2].symp)->branchCont);
				strcat(temp->code," ");
				strcpy(tempLabel1,strLabel);				//looping label - label3 tempLabel1
				newLabel();
				strcat(temp->code,strLabel);				//label4
				strcat(temp->code,"\n\n");
				
				//printf("Problem finding1 \n");
				
				strcat(temp->code,string);				//problem is here
				
				//printf("Problem finding2\n");
				
				strcat(temp->code,"jmp ");
				strcat(temp->code,tempLabel1);
				strcat(temp->code,"\n\n");
				
				strcat(temp->code,strLabel);
				strcat(temp->code,":\n");
				
				strcat(temp->code,"pop ebx\n\n");
				strcat(temp->code,tempLabel);
				strcat(temp->code,":\n\n");
				
				(yyval.symp) = temp;
			}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 571 "Parser.y" /* yacc.c:1646  */
    {	
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				strcpy(temp->symbol,(yyvsp[0].symp)->symbol);
				temp->code[0] = '\0';
				
				//$1->code[0] = '\0';
				
				(yyval.symp) = temp;
				
				//printf("In variable:ID\nThe code for %s is %s\n",$1->symbol,$1->code);
			}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 583 "Parser.y" /* yacc.c:1646  */
    {	printf("variable -> id [ expression ]\n");	}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 587 "Parser.y" /* yacc.c:1646  */
    {	printf("procedure_statement -> id\n");	}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 589 "Parser.y" /* yacc.c:1646  */
    {	printf("procedure_statement -> id ( exp_list )\n");	}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 593 "Parser.y" /* yacc.c:1646  */
    {    printf("expression_list	:	expression\n");	
			}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 596 "Parser.y" /* yacc.c:1646  */
    {	printf("expression_list	:expression_list ',' expression\n");	}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 600 "Parser.y" /* yacc.c:1646  */
    {	
				printf("expression	:	simple_expression\n");	
				(yyval.symp) = (yyvsp[0].symp);
				//printf("The string is %s\n",$1->code);
			}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 605 "Parser.y" /* yacc.c:1646  */
    {	
				printf("expression -> simple_expression RELOP simple_expression\n");	
			
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = temp->symbol[0] = '\0';
				
				//mov eax,[x]
				//mov ebx,[y]
				//cmp eax,ebx
				
				strcat(temp->code,(yyvsp[-2].symp)->code);
				strcat(temp->code,(yyvsp[0].symp)->code);
		
				//value decides the branching
				double decide = (yyvsp[-2].symp)->value - (yyvsp[0].symp)->value;
	
				if((yyvsp[-2].symp)->numVal && (yyvsp[0].symp)->numVal){
					strcat(temp->code,"mov eax,");
					//ItoA($1->value);
					sprintf(strRes,"%d",(yyvsp[-2].symp)->value) ;
					strcat(temp->code,strRes);
					strcat(temp->code,"\n");
				
					strcat(temp->code,"mov ebx,");
					//ItoA($3->value);
					sprintf(strRes,"%d",(yyvsp[0].symp)->value) ;
					strcat(temp->code,strRes);
					strcat(temp->code,"\n");							
				}
				
				else if((yyvsp[-2].symp)->numVal && !(yyvsp[0].symp)->numVal){
					strcat(temp->code,"mov ebx,dword[");
					strcat(temp->code,(yyvsp[0].symp)->symbol);
					strcat(temp->code,"]\n");
					strcat(temp->code,"mov eax,");
					//ItoA($1->value);
					sprintf(strRes,"%d",(yyvsp[-2].symp)->value) ;
					strcat(temp->code,strRes);
					strcat(temp->code,"\n");
				
				}
				
				else if(!(yyvsp[-2].symp)->numVal && (yyvsp[0].symp)->numVal){
					strcat(temp->code,"mov eax,dword[");
					strcat(temp->code,(yyvsp[-2].symp)->symbol);
					strcat(temp->code,"]\n");
					strcat(temp->code,"mov ebx,");
					//ItoA($3->value);
					sprintf(strRes,"%d",(yyvsp[0].symp)->value) ;
					printf("The value of strRes is %s\n",strRes);
					strcat(temp->code,strRes);
					strcat(temp->code,"\n");
				}
				
				else {
					strcat(temp->code,"mov eax,dword[");
					strcat(temp->code,(yyvsp[-2].symp)->symbol);
					strcat(temp->code,"]\n");
					strcat(temp->code,"mov ebx,dword[");
					strcat(temp->code,(yyvsp[0].symp)->symbol);
					strcat(temp->code,"]\n");
				}
				
				strcat(temp->code,"cmp eax,ebx\n");
				
				if(!strcmp((yyvsp[-1].string),"=")){
					strcpy(temp->branchInfo,"je");
					strcpy(temp->branchCont,"jne");
							
				}else if(!strcmp((yyvsp[-1].string),"<>")){
					strcpy(temp->branchInfo,"jne");
					strcpy(temp->branchCont,"je");
					
				}else if(!strcmp((yyvsp[-1].string),"<")){
					strcpy(temp->branchInfo,"jl");
					strcpy(temp->branchCont,"jge");
				}else if(!strcmp((yyvsp[-1].string),"<=")){
					strcpy(temp->branchInfo,"jle");
					strcpy(temp->branchCont,"jg");
					
				}else if(!strcmp((yyvsp[-1].string),">")){
					strcpy(temp->branchInfo,"jg");
					strcpy(temp->branchCont,"jle");					
				}else if(!strcmp((yyvsp[-1].string),">=")){
					strcpy(temp->branchInfo,"jge");
					strcpy(temp->branchCont,"jl");
				}			
				
				
				strcpy(temp->symbol,(yyvsp[-2].symp)->symbol);
				(yyval.symp) = temp;
				//printf("The jumping info is %s\n",temp->branchInfo);
			}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 702 "Parser.y" /* yacc.c:1646  */
    {	printf("simple_expression : term\n");	
					(yyval.symp) = (yyvsp[0].symp);
				}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 706 "Parser.y" /* yacc.c:1646  */
    {	printf("simple_expression : Minus\n");
						//$$ = -$2;
					}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 711 "Parser.y" /* yacc.c:1646  */
    {	
				
					
					
					printf("simple_expression : simple_expression addop term\n");	
					//printf("going to add\n");
					
					SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					temp->code[0] = temp->symbol[0] = '\0';
					
					
					
					//First Expression
					if((yyvsp[-2].symp)->numVal){
							strcat((yyvsp[-2].symp)->code,"mov eax,");
							//ItoA($1->value);
							sprintf(strRes,"%d",(yyvsp[-2].symp)->value) ;
							strcat((yyvsp[-2].symp)->code,strRes);	
							strcat((yyvsp[-2].symp)->code,"\n");	
										
					}
					else if((yyvsp[-2].symp)->symbol){
						strcat((yyvsp[-2].symp)->code,"mov eax,dword[");
						strcat((yyvsp[-2].symp)->code,(yyvsp[-2].symp)->symbol);
						strcat((yyvsp[-2].symp)->code,"]\n");
						
					}
					
					else{
						
					}
					
					//second Expression
					if((yyvsp[0].symp)->numVal){
						strcat((yyvsp[0].symp)->code,"add eax,");
						//ItoA($3->value);
						sprintf(strRes,"%d",(yyvsp[0].symp)->value) ;
						strcat((yyvsp[0].symp)->code,strRes);	
						strcat((yyvsp[0].symp)->code,"\n");
					}
					else{
						printf("I am here the problem\n");
					
						strcat((yyvsp[0].symp)->code,"add eax,dword[");			//Some problem
						strcat((yyvsp[0].symp)->code,(yyvsp[0].symp)->symbol);
						strcat((yyvsp[0].symp)->code,"]\n");					//problem here
					}
					
					
					strcpy(temp->code,(yyvsp[-2].symp)->code);		//temp->code = $1->code
					strcat(temp->code,(yyvsp[0].symp)->code);
					
					strcat(temp->code,"mov dword[");
					newTemp();
					strcat(temp->code,strTemp);
					strcat(temp->code,"],");
					strcat(temp->code,"eax\n");
					
					
					strcpy(temp->symbol,strTemp);
					temp->value = (yyvsp[-2].symp)->value + (yyvsp[0].symp)->value;
					
					printf("temp->code is %s\n",temp->code);		//how it is right?
					
					(yyval.symp) = temp ;
				}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 777 "Parser.y" /* yacc.c:1646  */
    {
					
					//It's also working
					
					printf("going to subtract\n");
						
					//Wow! This is working
					
					SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
					temp->code[0] = temp->symbol[0] = '\0';
					
					
					
					//First Expression
					if((yyvsp[-2].symp)->numVal){
							strcat((yyvsp[-2].symp)->code,"mov eax,");
							//ItoA($1->value);
							sprintf(strRes,"%d",(yyvsp[-2].symp)->value) ;
							strcat((yyvsp[-2].symp)->code,strRes);	
							strcat((yyvsp[-2].symp)->code,"\n");	
					}
					else {
						strcat((yyvsp[-2].symp)->code,"mov eax,dword[");
						strcat((yyvsp[-2].symp)->code,(yyvsp[-2].symp)->symbol);
						strcat((yyvsp[-2].symp)->code,"]\n");	
					}
					
					
					//second Expression
					if((yyvsp[0].symp)->numVal){
						strcat((yyvsp[0].symp)->code,"sub eax,");
					//	ItoA($3->value);
						sprintf(strRes,"%d",(yyvsp[0].symp)->value) ;
						strcat((yyvsp[0].symp)->code,strRes);	
						strcat((yyvsp[0].symp)->code,"\n");
					}
					else{
						strcat((yyvsp[0].symp)->code,"sub eax,[");
						strcat((yyvsp[0].symp)->code,(yyvsp[0].symp)->symbol);
						strcat((yyvsp[0].symp)->code,"];\n");
					}
					
					
					strcpy(temp->code,(yyvsp[-2].symp)->code);		//temp->code = $1->code
					strcat(temp->code,(yyvsp[0].symp)->code);
					
					strcat(temp->code,"mov dword[");
					newTemp();
					strcat(temp->code,strTemp);
					strcat(temp->code,"],");
					strcat(temp->code,"eax\n");
					
					
					strcpy(temp->symbol,strTemp);
					temp->value = (yyvsp[-2].symp)->value - (yyvsp[0].symp)->value;
					
					printf("temp->code is %s\n",temp->code);
					
					(yyval.symp) = temp ;
			}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 840 "Parser.y" /* yacc.c:1646  */
    {
			printf("term	:	factor\n") ;
			//printf("The value of result factor is %lf\n",$1);	
			(yyval.symp)=(yyvsp[0].symp);
		}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 845 "Parser.y" /* yacc.c:1646  */
    {
				printf("term	:	term MULOP factor\n") ;
				
				SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
				temp->code[0] = temp->symbol[0] = '\0';
				
				if((yyvsp[-1].ival) == 42 || (yyvsp[-1].ival) == 47 || (yyvsp[-1].ival) == 320){
					//multiplication - 42
					//division - 47
					
					
					//First Expression
					if((yyvsp[-2].symp)->numVal){
						//mov eax,3
						strcat((yyvsp[-2].symp)->code,"mov eax,");
						//ItoA($1->value);
						sprintf(strRes,"%d",(yyvsp[-2].symp)->value) ;
						strcat((yyvsp[-2].symp)->code,strRes);	
						strcat((yyvsp[-2].symp)->code,"\n");	
					}
					else {
						//mov eax,dword[x]	
						strcat((yyvsp[-2].symp)->code,"mov eax,dword[");
						strcat((yyvsp[-2].symp)->code,(yyvsp[-2].symp)->symbol);
						strcat((yyvsp[-2].symp)->code,"]\n");	
					}
					
					//second expression
					if((yyvsp[0].symp)->numVal){
						//mov ebx,1
						strcat((yyvsp[0].symp)->code,"mov ebx,");
						//ItoA($3->value);
						sprintf(strRes,"%d",(yyvsp[0].symp)->value) ;
						strcat((yyvsp[0].symp)->code,strRes);	
						strcat((yyvsp[0].symp)->code,"\n");	
					}
					else {
						//mov ebx,dword[y]
						strcat((yyvsp[0].symp)->code,"mov ebx,dword[");
						strcat((yyvsp[0].symp)->code,(yyvsp[0].symp)->symbol);
						strcat((yyvsp[0].symp)->code,"]\n");	
					}
					
					
					strcpy(temp->code,(yyvsp[-2].symp)->code);		//temp->code = $1->code
					strcat(temp->code,(yyvsp[0].symp)->code);
					
										
					if((yyvsp[-1].ival) == 42){
						//printf("i am in if to multiply\n");
						
						strcat(temp->code,"mul eax\n");
						temp->value = (yyvsp[-2].symp)->value * (yyvsp[0].symp)->value;
					}
					else {
					//	printf("i am in else to divide\n");
					
						strcat(temp->code,"mov edx,0\n");
						strcat(temp->code,"div ebx\n");
						if((yyvsp[-1].ival) == 47)
							temp->value = (yyvsp[-2].symp)->value / (yyvsp[0].symp)->value;
						else temp->value = (int)(yyvsp[-2].symp)->value % (int)(yyvsp[0].symp)->value;
					}

					newTemp();
					strcat(temp->code,"mov dword[");					
					strcat(temp->code,strTemp);
					strcat(temp->code,"],");
					
					if((yyvsp[-1].ival) != 320)
						strcat(temp->code,"eax\n");
					else strcat(temp->code,"edx\n");
					
					strcpy(temp->symbol,strTemp);
					
					(yyval.symp)=temp;
					
					//printf("The value is now %d\n",temp->value);	
				}
				
				else;
			}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 929 "Parser.y" /* yacc.c:1646  */
    {	
			printf("factor -> ID \n");
			
			SymbolInfo * temp = (SymbolInfo *)malloc(sizeof(SymbolInfo));
			temp->code[0] = '\0';
			strcpy(temp->symbol,(yyvsp[0].symp)->symbol);
			
			//$1->code[0] = '\0';
			
			//$$ = $1;
			(yyval.symp) = temp;
			
		}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 943 "Parser.y" /* yacc.c:1646  */
    {	printf("factor -> ID '(' expression_list ')' \n");	
			
			//$$ = $1->value;
				
		}
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 949 "Parser.y" /* yacc.c:1646  */
    {	printf("factor -> num value is %lf\n",(yyvsp[0].dval));
		
			SymbolInfo* first = st.Insert("num1","NUM");
			first->value = (yyvsp[0].dval);	
			first->numVal = true;
			first->code[0] = '\0';
			
			if(first->numVal)
				printf("numVal is true\n");
			
			(yyval.symp) = first;	
			
		}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 963 "Parser.y" /* yacc.c:1646  */
    {	printf("factor : ( expression )\n");	
			(yyval.symp) = (yyvsp[-1].symp);	
		}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 967 "Parser.y" /* yacc.c:1646  */
    {	printf("factor : NOT factor\n");	}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2432 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 971 "Parser.y" /* yacc.c:1906  */


int main(int argc,char*argv[])
{	



	char str[20];
	yyparse();
	
	
	
	
	
	
	
	
	
	//assembly code
	printf("\\\\\\\\\\\\\\\\\\\\\Assembly Code\\\\\\\\\\\\\n") ;
	strcat(bss,"buffer resb 1\n");
	strcat(bss,"temp resb 10\n");
 
 	printf("section .data\n\n");
 	printf("section .bss\n\n");
 	printf("%s\n\n",bss);
 	printf("section .text\n\nglobal _start\n\n_start:\n");
 	printf("%s\n",data);
 	printf("mov eax,1\nmov ebx,0\nint 80h\n");
 	
 	//Writing the function in string
	printf("mov ecx,0\n\n");
	printf("printFunc:\n\nmov dx,0\nmov bx,10\ndiv bx\nadd dl,30h\nmov [temp+ecx],dl\ninc ecx\n");
	printf("cmp ax,0\njne printFunc\n\n");
	printf("print:\ndec ecx\nmov al,[temp+ecx]\nmov byte[buffer],al\n\npusha\nmov eax,4\nmov ebx,1\n");
	printf("mov ecx,buffer\nmov edx,1\nint 80h\n\npopa\n\ncmp ecx,0\njne print\n\n");
	printf("mov byte[buffer],10\n\nmov eax,4\nmov ebx,1\nmov ecx,buffer\nmov edx,1\nint 80h\n\n");
	printf("ret\n");
	
	
	
	return 0;
	
}

void yyerror(char *msg)
{
	printf("%s found at line %d\n", msg,number_of_lines);
}


SymbolInfo* SymbolTable::Insert(char *str1,char *str2){


	
	int symbol = 0;
	
	//printf("String is %s key is %d\n",str1,symbol);
	
	SymbolInfo *returnPointer = Lookup(str1,str2);
	return returnPointer;
}

SymbolInfo* SymbolTable::Lookup(char *str1,char* str2){

	int index = 0;
	
	for( int i = 0 ; str1[i] ; i++)
		index += str1[i];
	index %= 20;


	SymbolInfo *p = total[index];
	if(p->next == NULL){
		
		
		SymbolInfo *New = (SymbolInfo *)malloc(sizeof(SymbolInfo));
		strcpy(New->symbol,str1);
		if(str2)
			strcpy(New->type,str2);
		New->next = NULL;
		p->next = New;
		
		//printf("Inserted the string %s in table\n ",New->symbol);
		
		return New;
		
	}
	
	
	do{
		p = p -> next;
		if(p->symbol && !strcmp(str1,p->symbol))
			return p;
	
	}while(p->next);

	SymbolInfo *New = (SymbolInfo *)malloc(sizeof(SymbolInfo));
	strcpy(New->symbol,str1);
	if(str2)
		strcpy(New->type,str2);
	New->next = NULL;
	p->next = New;

	return New;
}

void SymbolTable::Dump(){


	printf("\nSymbol Table\n\n");

	SymbolInfo* p;
	for(int i = 0 ; i < SIZE ; i++){
	
		p = total[i]; 
		if(p -> next != NULL){
			
			printf("At index[%d]\n",i);
			int i = 0;
			
			do{
				p = p->next;
				printf("\t%s %lf\n type %s\n",p->symbol,p->value,p->dataType);
				
			}while(p->next != NULL);		
			printf("\n");
		}
	}

	printf("\nSymbolTable\n");
}
