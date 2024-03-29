/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

  #include "global.h"
  #include <iostream>
  extern Symtable symtab;
  
  extern int yylex();

  void yyerror (char const *s)
  {
    error((char *)s);
  }
  void yywarning (const char *m) 
  {
    fprintf (stderr, "warning w linii: %d:%s\n", lineno, m);
  }


#line 84 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    PROGRAM = 258,
    NUM = 259,
    ID = 260,
    VAR = 261,
    DIV = 262,
    MODULO = 263,
    MUL = 264,
    M_DIV = 265,
    INTEGER = 266,
    BEGIN_TOKEN = 267,
    END_TOKEN = 268,
    OPERATOR = 269,
    ASSIGNOP = 270,
    READ = 271,
    WRITE = 272,
    REAL = 273,
    ARRAY = 274,
    OF = 275,
    FUNCTION = 276,
    PROCEDURE = 277,
    IF = 278,
    THEN = 279,
    ELSE = 280,
    WHILE = 281,
    DO = 282,
    RELOP = 283,
    OR = 284,
    EQUAL = 285,
    NOT_EQUAL = 286,
    LESS = 287,
    LESS_OR_EQ = 288,
    GREATER = 289,
    GREATER_OR_EQ = 290,
    t_PLUS = 291,
    t_MINUS = 292,
    AND = 293,
    NOT = 294,
    NONE = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      41,    42,     2,     2,    45,     2,    44,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    63,    66,    69,    63,    80,    83,    90,
      94,    98,    99,   103,   106,   113,   114,   118,   129,   150,
     169,   170,   174,   181,   189,   199,   205,   206,   210,   211,
     215,   220,   222,   223,   229,   223,   240,   245,   240,   256,
     256,   270,   270,   287,   288,   292,   295,   295,   355,   359,
     365,   366,   385,   406,   426,   448,   469,   491,   492,   496,
     503,   516,   529,   540,   554,   555,   568,   582,   598,   615,
     615,   687,   688,   691
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "NUM", "ID", "VAR", "DIV",
  "MODULO", "MUL", "M_DIV", "INTEGER", "BEGIN_TOKEN", "END_TOKEN",
  "OPERATOR", "ASSIGNOP", "READ", "WRITE", "REAL", "ARRAY", "OF",
  "FUNCTION", "PROCEDURE", "IF", "THEN", "ELSE", "WHILE", "DO", "RELOP",
  "OR", "EQUAL", "NOT_EQUAL", "LESS", "LESS_OR_EQ", "GREATER",
  "GREATER_OR_EQ", "t_PLUS", "t_MINUS", "AND", "NOT", "NONE", "'('", "')'",
  "';'", "'.'", "','", "':'", "'['", "']'", "$accept", "program", "$@1",
  "$@2", "$@3", "$@4", "identifier_list", "declarations", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "arguments", "parameter_list", "compound_statement",
  "optional_statements", "statement_list", "statement", "@5", "@6", "@7",
  "@8", "$@9", "$@10", "variable", "procedure_statement", "$@11",
  "expression_list", "expression", "simple_expression", "term", "factor",
  "$@12", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    40,    41,    59,    46,    44,    58,    91,    93
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -44

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    21,    38,   -13,   -81,    54,   -81,    27,    61,    34,
     -81,    40,   -81,   -81,    82,    54,   -81,    65,    91,    18,
      92,   116,   110,    81,   -81,   -81,   -81,    78,    83,   -81,
      86,    86,    63,    84,   -81,    51,   125,   -81,    54,    85,
      87,    -6,    93,    94,    17,   -81,   -81,   119,    90,   -81,
     121,   -81,   -81,   -81,    95,    70,    42,    37,   -81,   -81,
      17,   -81,   -81,   -81,   -17,    28,    28,    28,    17,   -81,
     -81,    71,    52,   -81,    17,   -81,    63,    17,    96,    18,
     -81,    54,    54,    98,    17,    89,    17,    17,   -81,    52,
      52,   -81,   100,   114,    28,    17,    17,    17,    17,    17,
      17,    28,    28,    28,    28,    28,    28,   117,   -81,   -81,
     139,   -81,    72,    74,   -81,   -29,   -81,   -81,    -3,    32,
      17,   -81,    63,    52,   -18,   -18,   -18,   -18,   -18,   -18,
      52,    52,    52,   -81,   -81,   -81,   -81,    97,    18,    18,
     -81,    17,   -81,   -81,    36,   -81,    63,   126,   -81,   -81,
     -81,   -81,   122,   -81,    37,    63,   -81,   -81
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     7,     2,     0,     0,
       8,     0,     3,    10,     4,     0,    16,     0,     5,     0,
       0,     0,     0,     0,    10,    13,    14,     0,     0,    11,
      21,    21,    27,     0,    15,     0,     0,     9,     0,     0,
       0,    45,     0,     0,     0,    36,    32,     0,    26,    28,
       0,    31,     6,    17,     0,     0,     0,     0,    19,    46,
       0,    41,    39,    71,    43,     0,     0,     0,     0,    68,
      33,    50,    57,    64,     0,    25,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,    69,    58,
      59,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
       0,    22,     0,     0,    18,     0,    48,    44,     0,     0,
       0,    72,     0,    62,    51,    52,    53,    54,    55,    56,
      60,    61,    63,    65,    66,    67,    37,     0,     0,     0,
      47,     0,    42,    40,     0,    34,     0,     0,    24,    23,
      49,    70,     0,    38,     0,     0,    12,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -81,   -81,   -11,   124,   -74,   -55,
     -81,   -81,   -81,   118,   -81,   -12,   -81,   -81,   -73,   -81,
     -81,   -81,   -81,   -81,   -81,   -32,   -81,   -81,   -80,   -43,
      -4,   -51,   -59,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    13,    16,    22,     7,    14,    28,    29,
      18,    23,    24,    39,    56,    46,    47,    48,    49,    93,
     152,    74,   146,    87,    86,    69,    51,    84,   115,   116,
      71,    72,    73,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    70,    83,   108,    17,   111,   118,   119,    91,   -43,
      33,    94,     1,   140,    89,    90,   141,    85,   101,   102,
     103,    63,    64,    53,    88,    92,     3,    55,     5,    25,
      60,   107,    63,    64,   109,    59,    26,    27,     4,   142,
     144,    60,   141,   123,    50,   133,   134,   135,    25,   145,
     130,   131,   132,    65,    66,    26,    67,    15,    68,     6,
     104,   105,   106,    32,   148,   149,    10,    67,    41,    68,
     112,   113,     8,   153,   143,    32,    11,   141,   151,    42,
      43,   141,   157,    12,    80,    81,    44,    82,    15,    45,
      50,   124,   125,   126,   127,   128,   129,    30,   150,   156,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       8,    19,    20,    21,    50,     8,    79,     8,   138,     8,
     139,    31,    32,    50,    34,    36,    37,    38,    52,    54,
      58,    57,    75,    76,    61,    62,    77,   117,   122,    78,
     110,   114,   121,   137,   136,   147,   154,   155,    35,    40
};

static const yytype_uint8 yycheck[] =
{
      32,    44,    57,    76,    15,    79,    86,    87,    67,    15,
      22,    29,     3,    42,    65,    66,    45,    60,    36,    37,
      38,     4,     5,    35,    41,    68,     5,    38,    41,    11,
      47,    74,     4,     5,    77,    41,    18,    19,     0,    42,
     120,    47,    45,    94,    76,   104,   105,   106,    11,   122,
     101,   102,   103,    36,    37,    18,    39,     6,    41,     5,
       8,     9,    10,    12,   138,   139,     5,    39,     5,    41,
      81,    82,    45,   146,    42,    12,    42,    45,    42,    16,
      17,    45,   155,    43,    42,    43,    23,    45,     6,    26,
     122,    95,    96,    97,    98,    99,   100,     5,   141,   154,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      45,    46,    21,    22,   146,    45,    46,    45,    46,    45,
      46,     5,    12,   155,    43,    47,    43,    41,    44,     4,
      43,    46,    13,    43,    41,    41,    15,    48,    24,    44,
      44,    43,    42,     4,    27,    48,    20,    25,    24,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,     5,     0,    41,     5,    55,    45,    51,
       5,    42,    43,    52,    56,     6,    53,    55,    59,    46,
      21,    22,    54,    60,    61,    11,    18,    19,    57,    58,
       5,     5,    12,    64,    43,    56,    47,    43,    41,    62,
      62,     5,    16,    17,    23,    26,    64,    65,    66,    67,
      74,    75,    44,    64,     4,    55,    63,    46,    43,    41,
      47,    41,    41,     4,     5,    36,    37,    39,    41,    74,
      78,    79,    80,    81,    70,    13,    43,    15,    44,    46,
      42,    43,    45,    58,    76,    78,    73,    72,    41,    80,
      80,    81,    78,    68,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     8,     9,    10,    78,    67,    78,
      44,    57,    55,    55,    43,    77,    78,    48,    77,    77,
      82,    42,    24,    80,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    81,    81,    81,    27,     4,    46,    46,
      42,    45,    42,    42,    77,    67,    71,    48,    57,    57,
      78,    42,    69,    67,    20,    25,    58,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    51,    52,    53,    54,    50,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    61,    61,
      62,    62,    63,    63,    63,    64,    65,    65,    66,    66,
      67,    67,    67,    68,    69,    67,    70,    71,    67,    72,
      67,    73,    67,    74,    74,    75,    76,    75,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    81,    82,
      81,    81,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    14,     1,     3,     6,
       0,     1,     9,     1,     1,     3,     0,     3,     6,     4,
       3,     0,     3,     5,     5,     3,     1,     0,     1,     3,
       3,     1,     1,     0,     0,     8,     0,     0,     6,     0,
       5,     0,     5,     1,     4,     1,     0,     5,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     0,
       5,     1,     3,     2
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
#line 63 "parser.y" /* yacc.c:1646  */
    {symtab.IDlist.clear();}
#line 1361 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 63 "parser.y" /* yacc.c:1646  */
    {
        myfile << "\tjump.i #" +symtab.symtable.at((yyvsp[-5])).name + " \n";
  }
#line 1369 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "parser.y" /* yacc.c:1646  */
    {
    isGlobalScope = false;
  }
#line 1377 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "parser.y" /* yacc.c:1646  */
    {
 myfile << symtab.symtable.at((yyvsp[-9])).name + ": \n";
 isGlobalScope = true;
  }
#line 1386 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "parser.y" /* yacc.c:1646  */
    {
    myfile << "\texit";
  }
#line 1394 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "parser.y" /* yacc.c:1646  */
    {
    symtab.IDlist.push_back((yyvsp[0]));
  }
#line 1402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "parser.y" /* yacc.c:1646  */
    {
    symtab.IDlist.push_back((yyvsp[0]));

  }
#line 1411 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 90 "parser.y" /* yacc.c:1646  */
    {
    symtab.IDrecogized((yyvsp[-1]));
    symtab.IDlist.clear();
  }
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = INTEGER;
  }
#line 1428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = REAL;
  }
#line 1436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 119 "parser.y" /* yacc.c:1646  */
    {
    //end of function or procedure
    myfile << "\tleave\n";
    myfile << "\treturn\n";
    updateEnter((-1)*symtab.negative_current_address);
    symtab.negative_current_address = 0; 
  }
#line 1448 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "parser.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-1]) == INTEGER) {
            symtab.symtable.at((yyvsp[-4])).vartype = VarType::INTEGER;
        } else {
            symtab.symtable.at((yyvsp[-4])).vartype = VarType::REAL;
        }
    symtab.symtable.at((yyvsp[-4])).type = SymbolType::FUNCTION;
    symtab.symtable.at((yyvsp[-4])).isRef = true;
    myfile << symtab.symtable.at((yyvsp[-4])).name + ": \n";
    myfile << "\tenter.i ####  \n";
    int max_param_address = symtab.parameters.size()*4 +8 ;
    for( int i =0; i < symtab.parameters.size();i++){
        symtab.symtable.at((yyvsp[-4])).function_types.push_back(symtab.symtable.at(symtab.parameters.at(i)).vartype);
        symtab.symtable.at(symtab.parameters.at(i)).isRef = true;
        symtab.symtable.at(symtab.parameters.at(i)).address = max_param_address;
        max_param_address -= 4;
    }
    symtab.parameters.clear();
    symtab.symtable.at((yyvsp[-4])).isRef = true;
    symtab.symtable.at((yyvsp[-4])).address = 8;
  }
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 150 "parser.y" /* yacc.c:1646  */
    {
    symtab.symtable.at((yyvsp[-2])).type = SymbolType::PROCEDURE;
    myfile << symtab.symtable.at((yyvsp[-2])).name + ": \n";
    int max_param_address = symtab.parameters.size()*4 +4;
    
    myfile << "\tenter.i ####  \n";
    for( int i =0; i < symtab.parameters.size();i++){
        symtab.symtable.at((yyvsp[-2])).function_types.push_back(symtab.symtable.at(symtab.parameters.at(i)).vartype);
        symtab.symtable.at(symtab.parameters.at(i)).isRef = true;
        symtab.symtable.at(symtab.parameters.at(i)).address = max_param_address;
        max_param_address -= 4;
    }
    symtab.parameters.clear();
    symtab.symtable.at((yyvsp[-2])).isRef = true;

  }
#line 1495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 174 "parser.y" /* yacc.c:1646  */
    {
    symtab.IDrecogizedWOAdress((yyvsp[0]));
    for( int i = 0; i < symtab.IDlist.size() ;i++){
      symtab.parameters.push_back(symtab.IDlist.at(i));
    }
    symtab.IDlist.clear();
  }
#line 1507 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 182 "parser.y" /* yacc.c:1646  */
    {
    symtab.IDrecogizedWOAdress((yyvsp[0]));
    for( int i = 0; i < symtab.IDlist.size() ;i++){
      symtab.parameters.push_back(symtab.IDlist.at(i));
    }
    symtab.IDlist.clear();
  }
#line 1519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "parser.y" /* yacc.c:1646  */
    {
    symtab.IDrecogizedWOAdress((yyvsp[0]));
    for( int i = 0; i < symtab.IDlist.size() ;i++){
      symtab.parameters.push_back(symtab.IDlist.at(i));
    }
    symtab.IDlist.clear();
  }
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 216 "parser.y" /* yacc.c:1646  */
    {
    changeTypeBeforeMove((yyvsp[-2]), (yyvsp[0]));
    forMove((yyvsp[-2]), (yyvsp[0]));
  }
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 223 "parser.y" /* yacc.c:1646  */
    {
    int new_label = symtab.insertLabel();
    myfile << "\tje.i\t" + VarOutput((yyvsp[0])) + ",#0,#" + symtab.symtable.at(new_label).name + "\n";

    (yyval) = new_label;

   }
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 229 "parser.y" /* yacc.c:1646  */
    {
    int new_label1 = symtab.insertLabel();
    myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";
    myfile << symtab.symtable.at((yyvsp[-2])).name + ":\n";

    (yyval) = new_label1;

   }
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 236 "parser.y" /* yacc.c:1646  */
    {
    myfile << symtab.symtable.at((yyvsp[-2])).name + ":\n";
   }
#line 1573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 240 "parser.y" /* yacc.c:1646  */
    {
    int new_label1 = symtab.insertLabel();
    myfile << symtab.symtable.at(new_label1).name + ":\n";

    (yyval) = new_label1;
  }
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 245 "parser.y" /* yacc.c:1646  */
    {
    int new_label2 = symtab.insertLabel();

    myfile << "\tje.i\t" + VarOutput((yyvsp[-1])) + ",#0,#" + symtab.symtable.at(new_label2).name + "\n";
    (yyval) = new_label2;

  }
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 251 "parser.y" /* yacc.c:1646  */
    {
    myfile << "\tjump.i\t#" + symtab.symtable.at((yyvsp[-4])).name + "\n";
    myfile << symtab.symtable.at((yyvsp[-1])).name + ":\n";
  }
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 256 "parser.y" /* yacc.c:1646  */
    {
    symtab.Stack.push(symtab.expressions);
    symtab.expressions.clear();}
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 259 "parser.y" /* yacc.c:1646  */
    {
    for(int i=0; i < symtab.expressions.size();i++){
      if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::REAL){
        myfile << "\twrite.r\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "\n";}
      else{
        myfile << "\twrite.i\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "\n";
      }
    }
    symtab.expressions = symtab.Stack.top();
    symtab.Stack.pop();
  }
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 270 "parser.y" /* yacc.c:1646  */
    {
    symtab.Stack.push(symtab.expressions);
    symtab.expressions.clear();
  }
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 273 "parser.y" /* yacc.c:1646  */
    {
    for(int i=0; i < symtab.expressions.size();i++){
      if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::REAL){
        myfile << "\tread.r\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "\n";}
      else{
        myfile << "\tread.i\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "\n";
      }
    }
    symtab.expressions = symtab.Stack.top();
    symtab.Stack.pop();
      }
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 292 "parser.y" /* yacc.c:1646  */
    {
    myfile << "\tcall.i\t #" +symtab.symtable.at((yyvsp[0])).name + "\n"; 
  }
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 295 "parser.y" /* yacc.c:1646  */
    {
    symtab.Stack.push(symtab.expressions);
    symtab.expressions.clear();
  }
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 298 "parser.y" /* yacc.c:1646  */
    {
    for(int i = 0; i < symtab.expressions.size(); i++){
       //printf("%s \n", symtab.symtable.at(symtab.expressions.at(i)).name.c_str());
      if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::INTEGER && symtab.symtable.at((yyvsp[-4])).function_types.at(i) == VarType::REAL){
        //inttoreal
        int new_temp = symtab.insertTempGlobal(VarType::REAL);
        if ( symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM ){
          myfile << "\tinttoreal.i\t#" + symtab.symtable.at(symtab.expressions.at(i)).name + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        else{
          myfile << "\tinttoreal.i\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        symtab.expressions.at(i) = new_temp;
      }  
      else if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::REAL && symtab.symtable.at((yyvsp[-4])).function_types.at(i) == VarType::INTEGER){
        //realtoint
        int new_temp = symtab.insertTempGlobal(VarType::INTEGER);
        if (symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM){
          myfile << "\trealtoint.r\t#" + symtab.symtable.at(symtab.expressions.at(i)).name + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        else{
          myfile << "\trealtoint.r\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        symtab.expressions.at(i) = new_temp;
      }
      if (symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM){
        if (isGlobalScope == true){
          int newTempVar = symtab.insertTempGlobal(symtab.symtable.at(symtab.expressions.at(i)).vartype);
          forMove( newTempVar, symtab.expressions.at(i));
          symtab.expressions.at(i) = newTempVar;
        }
        else{
          int newTempVar = symtab.insertTempLocal(symtab.symtable.at(symtab.expressions.at(i)).vartype);
          forMove(newTempVar, symtab.expressions.at(i));
          symtab.expressions.at(i) = newTempVar;
        }
      }
      string var = VarOutput(symtab.expressions.at(i));
      if (symtab.symtable.at(symtab.expressions.at(i)).isRef == true && isGlobalScope == false){
        var.erase(0,1);
        myfile << "\tpush.i\t " + var + "\n"; 
      }
      else{
        myfile << "\tpush.i\t #" + var + "\n"; 
      }
    }
    myfile << "\tcall.i\t #" + symtab.symtable.at((yyvsp[-4])).name + "\n"; 

    myfile << "\tincsp.i\t #" + std::to_string(symtab.expressions.size()*4) + "\n";

    symtab.expressions = symtab.Stack.top();
    symtab.Stack.pop();
  }
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 356 "parser.y" /* yacc.c:1646  */
    {
    symtab.expressions.push_back((yyvsp[0]));
  }
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 359 "parser.y" /* yacc.c:1646  */
    {
    symtab.expressions.push_back((yyvsp[0]));
  }
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 366 "parser.y" /* yacc.c:1646  */
    {
      int new_label = symtab.insertLabel();
      generate_relop('=', (yyvsp[-2]), (yyvsp[0]), new_label);
      int new_temp = 0;
      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);}
      else {
         new_temp = symtab.insertTempLocal(VarType::INTEGER);}
      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      (yyval) = new_temp;
  }
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 385 "parser.y" /* yacc.c:1646  */
    {
      int new_label = symtab.insertLabel();
      generate_relop('!', (yyvsp[-2]), (yyvsp[0]), new_label);
      int new_temp = 0;

      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);}
      else {
         new_temp = symtab.insertTempLocal(VarType::INTEGER);}
      
      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      (yyval) = new_temp;
  }
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 406 "parser.y" /* yacc.c:1646  */
    {
      int new_label = symtab.insertLabel();
      generate_relop('<', (yyvsp[-2]), (yyvsp[0]), new_label);  
      int new_temp = 0; 
      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);}
      else {
         new_temp = symtab.insertTempLocal(VarType::INTEGER);}

      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      (yyval) = new_temp;
  }
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 426 "parser.y" /* yacc.c:1646  */
    {
      int new_label = symtab.insertLabel();
      generate_relop('l', (yyvsp[-2]), (yyvsp[0]), new_label);
      int new_temp = 0;

      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);
      }
      else {
         new_temp = symtab.insertTempLocal(VarType::INTEGER);}

      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      (yyval) = new_temp;
  }
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 448 "parser.y" /* yacc.c:1646  */
    {
      int new_label = symtab.insertLabel();
      generate_relop('>', (yyvsp[-2]), (yyvsp[0]), new_label);
      int new_temp = 0;
      if (isGlobalScope == true){
        new_temp = symtab.insertTempGlobal(VarType::INTEGER);
      }
      else {
        new_temp = symtab.insertTempLocal(VarType::INTEGER);}

      int new_label1 = symtab.insertLabel();

      myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
      myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

      myfile << symtab.symtable.at(new_label).name +":"+ "\n";
      myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
      myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
      
      (yyval) = new_temp;
  }
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 469 "parser.y" /* yacc.c:1646  */
    {
      int new_label = symtab.insertLabel();
      generate_relop('g', (yyvsp[-2]), (yyvsp[0]), new_label);
      int new_temp = 0;
      if (isGlobalScope == true){
         new_temp = symtab.insertTempGlobal(VarType::INTEGER);}
      else {
        new_temp = symtab.insertTempLocal(VarType::INTEGER);}
        int new_label1 = symtab.insertLabel();

        myfile << "\tmov.i\t#0," + VarOutput(new_temp) + "\n";
        myfile << "\tjump.i\t#" + symtab.symtable.at(new_label1).name + "\n";

        myfile << symtab.symtable.at(new_label).name +":"+ "\n";
        myfile << "\tmov.i\t#1," + VarOutput(new_temp) + "\n";
        myfile << symtab.symtable.at(new_label1).name +":"+ "\n";
        
        (yyval) = new_temp;    
  }
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 493 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
  }
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 497 "parser.y" /* yacc.c:1646  */
    {
    int temp_num_pos  = symtab.insertNUM(0);
    int temp_pos = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[0])).vartype);
    gencode('-', temp_num_pos, (yyvsp[0]), temp_pos);
    (yyval) = temp_pos;
  }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 504 "parser.y" /* yacc.c:1646  */
    {
    needToTypeChange((yyvsp[-2]), (yyvsp[0]));
    if (isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('+', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;}
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('+', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;
    }
  }
#line 1933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 517 "parser.y" /* yacc.c:1646  */
    {
    needToTypeChange((yyvsp[-2]), (yyvsp[0]));
    if (isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('-', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;   }
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('+', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;      
    }
  }
#line 1950 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 529 "parser.y" /* yacc.c:1646  */
    {
    if (isGlobalScope == true){
      int new_temp = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[-2])).vartype);
      myfile << "\tor.i\t" + std::to_string(symtab.symtable.at((yyvsp[-2])).address) + "," + std::to_string(symtab.symtable.at((yyvsp[0])).address)+ ","  + std::to_string(symtab.symtable.at(new_temp).address)  + "\n";
      (yyval) = new_temp;}
    else{
      int new_temp = symtab.insertTempLocal(symtab.symtable.at((yyvsp[-2])).vartype);
      myfile << "\tor.i\t" + std::to_string(symtab.symtable.at((yyvsp[-2])).address)+ "," + std::to_string(symtab.symtable.at((yyvsp[0])).address)  +"," +std::to_string(symtab.symtable.at(new_temp).address)  + "\n";
      (yyval) = new_temp;
    }
  }
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 540 "parser.y" /* yacc.c:1646  */
    {
    if (isGlobalScope == true){
      int new_temp = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[-2])).vartype);
      myfile << "\tand.i\t" + std::to_string(symtab.symtable.at((yyvsp[-2])).address) + "," + std::to_string(symtab.symtable.at((yyvsp[0])).address)+ ","  + std::to_string(symtab.symtable.at(new_temp).address)  + "\n";
      (yyval) = new_temp;}
    else{
      int new_temp = symtab.insertTempLocal(symtab.symtable.at((yyvsp[-2])).vartype);
      myfile << "\tand.i\t" + std::to_string(symtab.symtable.at((yyvsp[-2])).address) +"," +std::to_string(symtab.symtable.at((yyvsp[0])).address)+ ","  + std::to_string(symtab.symtable.at(new_temp).address)  + "\n";
      (yyval) = new_temp;
    }
  }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 555 "parser.y" /* yacc.c:1646  */
    {
    needToTypeChange((yyvsp[-2]), (yyvsp[0]));
    if(isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('%', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;
   }
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('%', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;      
    }
  }
#line 2000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 569 "parser.y" /* yacc.c:1646  */
    {
    needToTypeChange((yyvsp[-2]), (yyvsp[0]));
    if(isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('x', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;
    }
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('+', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;   
    }
    }
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 583 "parser.y" /* yacc.c:1646  */
    {
    needToTypeChange((yyvsp[-2]), (yyvsp[0]));
    if(isGlobalScope == true){
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('/', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;}
    else{
      int temp_variable_pos = symtab.insertTempLocal(symtab.symtable.at((yyvsp[-2])).vartype);
      gencode('+', (yyvsp[-2]), (yyvsp[0]), temp_variable_pos);
      (yyval) = temp_variable_pos;   
    }
}
#line 2035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 599 "parser.y" /* yacc.c:1646  */
    {
    //funkcja bez parametru lub zmienna
    if (symtab.symtable.at((yyvsp[0])).type == SymbolType::FUNCTION ){
      if(symtab.symtable.at((yyvsp[0])).function_types.size()> 0)
					{
						yyerror("Wywołanie funkcji przyjmującej parametry bez parametrów");
						YYERROR;
					}
      int temp_variable_pos = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[0])).vartype);
      myfile << "\tpush.i #" + std::to_string(symtab.symtable.at(temp_variable_pos).address) + "\n";
      myfile << "\tcall.i #" + symtab.symtable.at((yyvsp[0])).name + "\n";
      myfile << "\tincsp.i #4\n";
      symtab.symtable.at((yyvsp[0])).address = symtab.symtable.at(temp_variable_pos).address;

    }
  }
#line 2056 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 615 "parser.y" /* yacc.c:1646  */
    {
    symtab.Stack.push(symtab.expressions);
    symtab.expressions.clear();
    }
#line 2065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 619 "parser.y" /* yacc.c:1646  */
    {
        for(int i = 0; i < symtab.expressions.size(); i++){
      if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::INTEGER && symtab.symtable.at((yyvsp[-4])).function_types.at(i) == VarType::REAL){
        //inttoreal
        int new_temp = symtab.insertTempGlobal(VarType::REAL);
        if ( symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM ){
          myfile << "\tinttoreal.i\t#" + symtab.symtable.at(symtab.expressions.at(i)).name + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        else{
          myfile << "\tinttoreal.i\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        symtab.expressions.at(i) = new_temp;
      }  
      else if (symtab.symtable.at(symtab.expressions.at(i)).vartype == VarType::REAL && symtab.symtable.at((yyvsp[-4])).function_types.at(i) == VarType::INTEGER){
        //realtoint
        int new_temp = symtab.insertTempGlobal(VarType::INTEGER);
        if (symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM){
          myfile << "\trealtoint.r\t#" + symtab.symtable.at(symtab.expressions.at(i)).name + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        else{
          myfile << "\trealtoint.r\t" + std::to_string(symtab.symtable.at(symtab.expressions.at(i)).address) + "," + std::to_string(symtab.symtable.at(new_temp).address) +"\n";
        }
        symtab.expressions.at(i) = new_temp;
      }
      if (symtab.symtable.at(symtab.expressions.at(i)).type == SymbolType::NUM){
        if (isGlobalScope == true){
          int newTempVar = symtab.insertTempGlobal(symtab.symtable.at(symtab.expressions.at(i)).vartype);
          forMove( newTempVar, symtab.expressions.at(i));
          symtab.expressions.at(i) = newTempVar;
        }
        else{
          int newTempVar = symtab.insertTempLocal(symtab.symtable.at(symtab.expressions.at(i)).vartype);
          forMove(newTempVar, symtab.expressions.at(i));
          symtab.expressions.at(i) = newTempVar;
        }
      }
      string var = VarOutput(symtab.expressions.at(i));
      if (symtab.symtable.at(symtab.expressions.at(i)).isRef == true && isGlobalScope == false) {
        var.erase(0,1);
        myfile << "\tpush.i\t " + var + "\n"; 
      }
      else {
        myfile << "\tpush.i\t #" + var + "\n"; 
      }
      }
      //jesli jest funkcją to potrzebuje adres na wynik
        if (isGlobalScope == true){
          int additional_temp = symtab.insertTempGlobal(symtab.symtable.at((yyvsp[-4])).vartype); 
          (yyval) = additional_temp;
        }
        else{
          int additional_temp = symtab.insertTempLocal(symtab.symtable.at((yyvsp[-4])).vartype); 
          (yyval) = additional_temp;
        } 
      string var = VarOutput((yyval));
      if (symtab.symtable.at((yyval)).isRef == true && isGlobalScope == false){
        myfile << "\tpush.i\t " + var + "\n"; 
      }
      else{
        myfile << "\tpush.i\t #" + var + "\n"; }

    myfile << "\tcall.i\t #" + symtab.symtable.at((yyvsp[-4])).name + "\n"; 
    myfile << "\tincsp.i\t #" + std::to_string(symtab.expressions.size()*4 +4) + "\n";

    symtab.expressions = symtab.Stack.top();
    symtab.Stack.pop();
  }
#line 2137 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 688 "parser.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1]);
  }
#line 2145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 691 "parser.y" /* yacc.c:1646  */
    {
    int new_label = symtab.insertLabel();
    string var = VarOutput((yyvsp[0]));

    string num_type = "";
    if (symtab.symtable.at((yyvsp[0])).vartype == VarType::REAL){
      num_type = "r";
    }
    else{
      num_type = "i";
    }
    myfile << "\tje." + num_type + "\t" + var + ",#0,#" + symtab.symtable.at(new_label).name + "\n";

    int temp_variable_pos = 0;
    if (isGlobalScope == true) {
      temp_variable_pos = symtab.insertTempGlobal(VarType::INTEGER);
    } else {
      temp_variable_pos = symtab.insertTempLocal(VarType::INTEGER);
    }
    (yyval) = temp_variable_pos;

    myfile << "\tmov.i\t#0," + VarOutput(temp_variable_pos) + "\n";

    int new_label2 = symtab.insertLabel();

    myfile << "\tjump.i\t#" + symtab.symtable.at(new_label2).name + "\n";
    myfile << symtab.symtable.at(new_label).name + ":\n";
    myfile << "\tmov.i\t#1," + VarOutput(temp_variable_pos) + "\n";
    myfile << symtab.symtable.at(new_label2).name + ":\n";
  }
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2184 "parser.tab.c" /* yacc.c:1646  */
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
#line 722 "parser.y" /* yacc.c:1906  */


void parse()
{
  yyparse();
}
