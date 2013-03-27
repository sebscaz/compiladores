/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "sintatico.y"

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hash.c"
#include "pila.c"

int yystopparser=0;

struct StrHashTable tbl = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTableProc tblprocs = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashNodeProc nodeProc;

int tipoOp=-1;

//PILAS
ptr pilaOperadores=NULL;
ptr pilaOperando=NULL;
ptr pilaTipos=NULL;





/* Line 268 of yacc.c  */
#line 96 "sintatico.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     programa = 258,
     si = 259,
     no = 260,
     imprimir = 261,
     leer = 262,
     crear = 263,
     mientras = 264,
     hacer = 265,
     funcion = 266,
     neutral = 267,
     regresar = 268,
     id = 269,
     ctetexto = 270,
     cteentero = 271,
     ctedecimal = 272,
     ctebooleano = 273,
     entero = 274,
     decimal = 275,
     texto = 276,
     booleano = 277,
     igual = 278,
     diferente = 279,
     mas = 280,
     menos = 281,
     multiplicacion = 282,
     division = 283,
     mayor = 284,
     menor = 285,
     and = 286,
     or = 287,
     ptocoma = 288,
     dospuntos = 289,
     punto = 290,
     coma = 291,
     parentesisa = 292,
     parentesisc = 293,
     llavea = 294,
     llavec = 295,
     corchetea = 296,
     corchetec = 297,
     dibujarFigura = 298,
     borrarFigura = 299,
     girarIzquierda = 300,
     girarDerecha = 301,
     mover = 302,
     obtenerPosicion = 303,
     hablar = 304,
     obtenerAltura = 305,
     obtenerAnchura = 306,
     cambiarAltura = 307,
     cambiarAnchura = 308,
     colorFondo = 309,
     rojo = 310,
     azul = 311,
     verde = 312,
     carro = 313,
     persona = 314,
     perro = 315,
     gato = 316,
     verdadero = 317,
     falso = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 26 "sintatico.y"
int cteint; float ctefloat; int cteboolean; char *string;


/* Line 293 of yacc.c  */
#line 199 "sintatico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 211 "sintatico.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   224

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNRULES -- Number of states.  */
#define YYNSTATES  259

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    14,    16,    17,    20,    22,    23,
      25,    27,    29,    31,    34,    36,    37,    39,    41,    43,
      45,    47,    49,    51,    53,    55,    57,    59,    61,    63,
      65,    67,    69,    71,    73,    75,    81,    83,    84,    90,
      92,    93,    98,   102,   103,   110,   112,   114,   116,   117,
     122,   126,   127,   133,   138,   147,   152,   153,   162,   175,
     177,   179,   180,   182,   186,   187,   190,   196,   199,   202,
     203,   206,   207,   210,   212,   214,   217,   218,   221,   223,
     225,   228,   231,   232,   236,   237,   240,   242,   244,   245,
     249,   250,   253,   255,   257,   258,   263,   266,   268,   269,
     271,   273,   275,   277,   279,   287,   289,   291,   293,   295,
     301,   309,   319,   325,   333,   341,   347,   353,   361,   369,
     375,   377,   379
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      65,     0,    -1,     3,    14,    39,    66,    68,    71,    40,
      -1,    75,    67,    -1,    66,    -1,    -1,    91,    69,    -1,
      68,    -1,    -1,    21,    -1,    19,    -1,    20,    -1,    22,
      -1,    73,    72,    -1,    71,    -1,    -1,    81,    -1,    88,
      -1,    86,    -1,    87,    -1,    90,    -1,    74,    -1,    96,
      -1,   117,    -1,   119,    -1,   120,    -1,   121,    -1,   124,
      -1,   123,    -1,   125,    -1,   127,    -1,   126,    -1,   128,
      -1,   129,    -1,   122,    -1,     8,    70,    76,    14,    33,
      -1,    79,    -1,    -1,     8,    70,    78,    14,    33,    -1,
      79,    -1,    -1,    41,    16,    42,    80,    -1,    41,    16,
      42,    -1,    -1,    14,    83,    34,    23,    82,    33,    -1,
      87,    -1,   105,    -1,    84,    -1,    -1,    41,   105,    42,
      85,    -1,    41,   105,    42,    -1,    -1,     6,    37,   105,
      38,    33,    -1,     7,    37,    38,    33,    -1,     4,    37,
      99,    38,    39,    71,    40,    89,    -1,     5,    39,    71,
      40,    -1,    -1,     9,    37,    99,    38,    10,    39,    71,
      40,    -1,    11,    92,    14,    37,    93,    38,    39,    77,
      71,    13,   105,    40,    -1,    70,    -1,    12,    -1,    -1,
      94,    -1,    70,    14,    95,    -1,    -1,    36,    94,    -1,
      14,    37,    97,    38,    33,    -1,   105,    98,    -1,    36,
      97,    -1,    -1,   102,   100,    -1,    -1,   101,   102,    -1,
      31,    -1,    32,    -1,   105,   103,    -1,    -1,   104,   105,
      -1,    30,    -1,    29,    -1,    23,    23,    -1,    24,    23,
      -1,    -1,   109,   106,   107,    -1,    -1,   108,   105,    -1,
      25,    -1,    26,    -1,    -1,   113,   110,   111,    -1,    -1,
     112,   109,    -1,    27,    -1,    28,    -1,    -1,    37,   114,
     102,    38,    -1,   115,   116,    -1,    14,    -1,    -1,   108,
      -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,    43,
      37,   118,    36,    14,    38,    33,    -1,    60,    -1,    59,
      -1,    61,    -1,    58,    -1,    44,    37,    14,    38,    33,
      -1,    49,    37,    14,    36,   105,    38,    33,    -1,    47,
      37,    14,    36,   105,    36,   105,    38,    33,    -1,    48,
      37,    14,    38,    33,    -1,    46,    37,    14,    36,   105,
      38,    33,    -1,    45,    37,    14,    36,   105,    38,    33,
      -1,    50,    37,    14,    38,    33,    -1,    51,    37,    14,
      38,    33,    -1,    52,    37,    14,    36,   105,    38,    33,
      -1,    53,    37,    14,    36,   105,    38,    33,    -1,    54,
      37,   130,    38,    33,    -1,    55,    -1,    56,    -1,    57,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   102,   103,   104,   105,   106,   107,   110,
     111,   112,   113,   115,   116,   117,   119,   120,   121,   122,
     123,   124,   125,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   141,   142,   143,   146,   153,
     154,   157,   158,   159,   162,   163,   164,   165,   166,   167,
     168,   169,   176,   178,   180,   182,   183,   187,   189,   195,
     196,   197,   198,   199,   200,   201,   203,   204,   205,   206,
     209,   210,   211,   212,   213,   216,   217,   218,   219,   220,
     221,   222,   224,   224,   225,   226,   227,   228,   230,   230,
     231,   232,   233,   234,   236,   236,   237,   238,   239,   240,
     243,   244,   245,   246,   248,   250,   251,   252,   253,   255,
     257,   260,   262,   264,   266,   268,   270,   272,   274,   276,
     278,   279,   280
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "programa", "si", "no", "imprimir",
  "leer", "crear", "mientras", "hacer", "funcion", "neutral", "regresar",
  "id", "ctetexto", "cteentero", "ctedecimal", "ctebooleano", "entero",
  "decimal", "texto", "booleano", "igual", "diferente", "mas", "menos",
  "multiplicacion", "division", "mayor", "menor", "and", "or", "ptocoma",
  "dospuntos", "punto", "coma", "parentesisa", "parentesisc", "llavea",
  "llavec", "corchetea", "corchetec", "dibujarFigura", "borrarFigura",
  "girarIzquierda", "girarDerecha", "mover", "obtenerPosicion", "hablar",
  "obtenerAltura", "obtenerAnchura", "cambiarAltura", "cambiarAnchura",
  "colorFondo", "rojo", "azul", "verde", "carro", "persona", "perro",
  "gato", "verdadero", "falso", "$accept", "PROGRAMA", "PROGRAMA1",
  "PROGRAMA12", "PROGRAMA2", "PROGRAMA22", "TIPO", "BLOQUE", "BLOQUE1",
  "ESTATUTO", "FUNCIONESPECIAL", "DECLARACION", "DECLARACION2",
  "DECLARACIONFUNCION", "DECLARACIONFUNCION2", "ARREGLOS", "ARREGLOS2",
  "ASIGNACION", "ASIGNACION3", "ASIGNACION2", "ARREGLOSASIG",
  "ARREGLOSASIG2", "ESCRITURA", "LECTURA", "CONDICION", "CONDICION2",
  "CICLO", "CREARFUNCION", "CREARFUNCION2", "CREARFUNCION3",
  "CREARFUNCION4", "CREARFUNCION5", "LLAMARFUNCION", "LLAMARFUNCION2",
  "LLAMARFUNCION3", "SUPEREXPRESION", "SUPEREXPRESION2", "SUPEREXPRESION3",
  "EXPRESION", "EXPRESION2", "EXPRESION3", "EXP", "$@1", "EXP2", "EXP3",
  "TERMINO", "$@2", "TERMINO2", "TERMINO3", "FACTOR", "$@3", "FACTOR2",
  "VARCTE", "DIBUJARFIGURA", "FIGURA", "BORRARFIGURA", "HABLAR", "MOVER",
  "OBTENERPOSICION", "GIRARDER", "GIRARIZQ", "OBTENERALTURA",
  "OBTENERANCHURA", "CAMBIARALTURA", "CAMBIARANCHURA", "COLORFONDO",
  "COLOR", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    67,    67,    68,    69,    69,    70,
      70,    70,    70,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    76,    76,    77,    78,
      78,    79,    80,    80,    81,    82,    82,    83,    83,    84,
      85,    85,    86,    87,    88,    89,    89,    90,    91,    92,
      92,    93,    93,    94,    95,    95,    96,    97,    98,    98,
      99,   100,   100,   101,   101,   102,   103,   103,   104,   104,
     104,   104,   106,   105,   107,   107,   108,   108,   110,   109,
     111,   111,   112,   112,   114,   113,   113,   113,   115,   115,
     116,   116,   116,   116,   117,   118,   118,   118,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   130,   130
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     1,     0,     2,     1,     0,     1,
       1,     1,     1,     2,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     0,     5,     1,
       0,     4,     3,     0,     6,     1,     1,     1,     0,     4,
       3,     0,     5,     4,     8,     4,     0,     8,    12,     1,
       1,     0,     1,     3,     0,     2,     5,     2,     2,     0,
       2,     0,     2,     1,     1,     2,     0,     2,     1,     1,
       2,     2,     0,     3,     0,     2,     1,     1,     0,     3,
       0,     2,     1,     1,     0,     4,     2,     1,     0,     1,
       1,     1,     1,     1,     7,     1,     1,     1,     1,     5,
       7,     9,     5,     7,     7,     5,     5,     7,     7,     5,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     5,    10,
      11,     9,    12,    37,     0,     0,     8,     4,     3,     0,
       0,    36,    60,    59,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    21,    16,    18,    19,    17,    20,
      22,    23,    24,    25,    26,    34,    28,    27,    29,    31,
      30,    32,    33,     7,     6,     0,     0,     0,    98,    98,
       0,    98,    98,    98,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,    14,
      13,    43,    35,    61,    97,    86,    87,    94,     0,    71,
      76,    99,    82,    88,     0,     0,     0,     0,     0,    69,
       0,     0,   108,   106,   105,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,   122,
       0,     0,    41,     0,     0,    62,    98,     0,    73,    74,
      70,    98,     0,     0,    79,    78,    75,    98,    84,    90,
     100,   101,   102,   103,    96,     0,    53,     0,     0,    98,
      67,    51,    98,     0,     0,    98,    98,    98,     0,    98,
       0,     0,    98,    98,     0,     0,    64,     0,     0,     0,
      72,    80,    81,    77,    83,    98,    92,    93,    89,    98,
      52,     0,    66,    68,    98,    49,     0,    45,    46,     0,
     109,     0,     0,     0,   112,     0,   115,   116,     0,     0,
     119,    42,     0,    63,     0,    95,     0,    85,    91,     0,
       0,    44,     0,     0,     0,    98,     0,     0,     0,    65,
       0,     0,    56,     0,    50,   104,   114,   113,     0,   110,
     117,   118,    40,     0,     0,    54,    57,     0,     0,    39,
      98,     0,   111,     0,     0,     0,    38,    58,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    18,    15,    64,   133,    42,    90,    43,
      44,     8,    20,   231,   248,    21,   132,    45,   196,    74,
      75,   195,    46,    47,    48,   245,    49,    16,    24,   134,
     135,   213,    50,   108,   160,    98,   140,   141,    99,   146,
     147,   100,   148,   184,   101,   102,   149,   188,   189,   103,
     136,   104,   154,    51,   116,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   130
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
      64,    -1,    68,    30,  -121,    62,    19,    60,    62,  -121,
    -121,  -121,  -121,    31,     8,     3,    60,  -121,  -121,    57,
      61,  -121,  -121,  -121,    63,    37,    39,    41,    42,    -4,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    56,    67,     3,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,    55,    70,    59,   -11,   -11,
      66,   -11,   -11,   -11,    74,  -121,   -16,    80,    87,    95,
      96,    97,    98,    99,   100,   101,   102,     7,  -121,  -121,
    -121,    76,  -121,    19,  -121,  -121,  -121,  -121,    81,     0,
      -5,  -121,  -121,  -121,    43,    82,    88,    84,    85,    89,
      86,   103,  -121,  -121,  -121,  -121,    93,    92,   104,   105,
     106,    94,   107,   108,   109,   112,   113,  -121,  -121,  -121,
     114,   115,  -121,   110,   116,  -121,   -11,   111,  -121,  -121,
    -121,   -11,   121,   122,  -121,  -121,  -121,   -11,    10,    38,
    -121,  -121,  -121,  -121,  -121,   118,  -121,   123,   120,   -11,
    -121,   119,    -3,   124,   126,   -11,   -11,   -11,   128,   -11,
     129,   130,   -11,   -11,   131,   125,   132,   117,   127,     3,
    -121,  -121,  -121,  -121,  -121,   -11,  -121,  -121,  -121,   -11,
    -121,   133,  -121,  -121,   -11,  -121,   136,  -121,  -121,   135,
    -121,   137,   138,   134,  -121,   140,  -121,  -121,   141,   142,
    -121,  -121,    19,  -121,   147,  -121,   144,  -121,  -121,     3,
     139,  -121,   149,   152,   153,   -11,   154,   155,   157,  -121,
      19,     3,   161,   151,  -121,  -121,  -121,  -121,   156,  -121,
    -121,  -121,    31,   158,   159,  -121,  -121,   160,   143,  -121,
     -11,     3,  -121,   162,   163,   164,  -121,  -121,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,   166,  -121,   176,  -121,    -6,   -42,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -108,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,   -27,  -121,  -121,  -121,  -121,  -121,  -121,
     -76,  -121,  -121,   -20,  -121,   145,  -121,  -121,  -120,  -121,
    -121,   -67,  -121,  -121,    58,    11,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      13,    89,   105,    94,    27,   109,   110,    25,    23,    26,
      27,    94,    28,     3,    95,    96,   178,    29,   142,   143,
      22,   180,    95,    96,   144,   145,    97,     9,    10,    11,
      12,   138,   139,    72,    97,    95,    96,    73,     9,    10,
      11,    12,   112,   113,   114,   115,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   150,   151,
     152,   153,   127,   128,   129,   186,   187,     1,     4,     5,
       6,    14,    19,    65,    68,    66,    69,    67,    70,    71,
     183,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   109,    87,   117,   198,    93,    91,   201,   202,
     203,   118,   205,    92,   106,   208,   209,    88,   111,   119,
     120,   121,   122,   123,   124,   125,   126,   131,   217,   137,
     155,   156,   157,   158,   176,   159,   162,   220,   161,   163,
     164,   175,   168,   191,   249,   197,   229,   216,   199,   193,
     165,   166,   167,   169,   181,   182,   170,   171,   172,   173,
     179,   190,   174,   192,   177,   230,   214,   253,   238,   200,
     194,   204,   206,   207,   210,   215,   244,   211,   212,   221,
     225,   250,   219,   222,    17,   223,   224,   233,   226,   227,
     228,   234,   235,   254,   232,   236,   237,   239,   240,   243,
     241,   246,    63,   252,   247,   256,     0,     0,   251,     0,
     218,     0,     0,   257,   258,     0,   185,     0,     0,   255,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,   242
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-121))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,    43,    69,    14,     7,    72,    73,     4,    14,     6,
       7,    14,     9,    14,    25,    26,   136,    14,    23,    24,
      12,   141,    25,    26,    29,    30,    37,    19,    20,    21,
      22,    31,    32,    37,    37,    25,    26,    41,    19,    20,
      21,    22,    58,    59,    60,    61,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    15,    16,
      17,    18,    55,    56,    57,    27,    28,     3,     0,    39,
       8,    11,    41,    16,    37,    14,    37,    14,    37,    37,
     147,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,   159,    37,    14,   162,    37,    42,   165,   166,
     167,    14,   169,    33,    38,   172,   173,    40,    34,    14,
      14,    14,    14,    14,    14,    14,    14,    41,   185,    38,
      38,    33,    38,    38,    14,    36,    23,   194,    42,    36,
      38,    16,    38,    10,   242,   162,   212,   179,    14,   159,
      36,    36,    36,    36,    23,    23,    38,    38,    36,    36,
      39,    33,    38,    33,    38,     8,    39,    14,   225,    33,
      41,    33,    33,    33,    33,    38,     5,    42,    36,    33,
      36,    13,    39,    38,     8,    38,    38,   219,    38,    38,
      38,    42,    33,   250,    40,    33,    33,    33,    33,   231,
      33,    40,    16,    33,    38,    33,    -1,    -1,    39,    -1,
     189,    -1,    -1,    40,    40,    -1,   148,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    65,    14,     0,    39,     8,    66,    75,    19,
      20,    21,    22,    70,    11,    68,    91,    66,    67,    41,
      76,    79,    12,    70,    92,     4,     6,     7,     9,    14,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    71,    73,    74,    81,    86,    87,    88,    90,
      96,   117,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    68,    69,    16,    14,    14,    37,    37,
      37,    37,    37,    41,    83,    84,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    40,    71,
      72,    42,    33,    37,    14,    25,    26,    37,    99,   102,
     105,   108,   109,   113,   115,   105,    38,    99,    97,   105,
     105,    34,    58,    59,    60,    61,   118,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    55,    56,    57,
     130,    41,    80,    70,    93,    94,   114,    38,    31,    32,
     100,   101,    23,    24,    29,    30,   103,   104,   106,   110,
      15,    16,    17,    18,   116,    38,    33,    38,    38,    36,
      98,    42,    23,    36,    38,    36,    36,    36,    38,    36,
      38,    38,    36,    36,    38,    16,    14,    38,   102,    39,
     102,    23,    23,   105,   107,   108,    27,    28,   111,   112,
      33,    10,    33,    97,    41,    85,    82,    87,   105,    14,
      33,   105,   105,   105,    33,   105,    33,    33,   105,   105,
      33,    42,    36,    95,    39,    38,    71,   105,   109,    39,
     105,    33,    38,    38,    38,    36,    38,    38,    38,    94,
       8,    77,    40,    71,    42,    33,    33,    33,   105,    33,
      33,    33,    70,    71,     5,    89,    40,    38,    78,    79,
      13,    39,    33,    14,   105,    71,    33,    40,    40
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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

/* Line 1806 of yacc.c  */
#line 101 "sintatico.y"
    {insert(&tbl,(yyvsp[(2) - (7)].string),(yyvsp[(2) - (7)].string),-1); puts(get(&tbl,(yyvsp[(2) - (7)].string))); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 110 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); printf("===========tipo: %i\n", tipoOp); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 111 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); printf("===========tipo: %i\n", tipoOp);}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 112 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); printf("===========tipo: %i\n", tipoOp);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 113 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); printf("===========tipo: %i\n", tipoOp);}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 141 "sintatico.y"
    {insert(&tbl,(yyvsp[(4) - (5)].string),(yyvsp[(4) - (5)].string),tipoOp); printf("El tipo eeeeeeessssss: %i\n", getType(&tbl,(yyvsp[(4) - (5)].string)));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 199 "sintatico.y"
    {insert(&tbl,(yyvsp[(2) - (3)].string),(yyvsp[(2) - (3)].string),tipoOp);}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 218 "sintatico.y"
    {/*  checaroperando3();   */}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 219 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1);}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 220 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string), -1);}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 221 "sintatico.y"
    {push(&pilaOperando, (yyvsp[(1) - (2)].string), -1);}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 222 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (2)].string), -1);}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 224 "sintatico.y"
    {/*  checaroperando2();   */}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 227 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1);}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 228 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1);}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 230 "sintatico.y"
    {/*  checaroperando1();   */}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 233 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1);}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 234 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1);}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 236 "sintatico.y"
    { push(&pilaOperando,(yyvsp[(1) - (1)].string),-1); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 238 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string),tipoOp);}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 243 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string), tipoOp);}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 244 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string), tipoOp);}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 245 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string), tipoOp);}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 246 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string), tipoOp);}
    break;



/* Line 1806 of yacc.c  */
#line 1840 "sintatico.tab.c"
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 282 "sintatico.y"

int main()
{
 
	if (yyparse()==0)
		printf("Sintaxis Correctaa\n");
	else
		printf("Sintaxis Incorrecta\n");

return 0;
}

int generarTipo(char *operando){
	if(*operando=='e') //entero
		return 1;
	if(*operando=='d') //doble
		return 2;
	if(*operando=='t') //texto
		return 3;
	if(*operando=='b') //booleano
		return 4;
}

/*
void checarOperando1(char *operando){
			if(operando=='*' || operando=='/' ){ 
			//Checar que los tipos sean compatibles para realizar la operacion
			
				op = pop(pilaOperandos);
				operador1 = pop(pilaOperadores);
				operador2 = pop(pilaOperadores);
			
			//cuadruplo(operando,operador1, operador2, res);
			//Si alguno de los operandos pertenecia a un temporal regresarlo al avail
			//-meter resultado a pilaOperandos
			//-meter tipo  a filaTipo si esque fue compatible
			
			}
	}
*/
/*	
void checarOperando2(char *operando){
			if(operando=='+' || operando=='-' ){ 
			//Checar que los tipos sean compatibles para realizar la operacion
			
				op = pop(pilaOperandos);
				operador1 = pop(pilaOperadores);
				operador2 = pop(pilaOperadores);
			
			//cuadruplo(operando,operador1, operador2, res);
			//Si alguno de los operandos pertenecia a un temporal regresarlo al avail
			//-meter resultado a pilaOperandos
			//-meter tipo  a filaTipo si esque fue compatible
			}
	}
*/
/*
void checarOperando3(char *operando){
			if(operando=='<' || operando=='>' || operando=='='){ 
			//Checar que los tipos sean compatibles para realizar la operacion
			
				op = pop(pilaOperandos);
				operador1 = pop(pilaOperadores);
				operador2 = pop(pilaOperadores);
			
			//cuadruplo(operando,operador1, operador2, res);
			//Si alguno de los operandos pertenecia a un temporal regresarlo al avail
			//-meter resultado a pilaOperandos
			//-meter tipo  a filaTipo si esque fue compatible
			}
			}
	}
	*/
/*
void quitarParentesis(ptr *cabeza_ptr){
		
	}
*/
yyerror(s)
char *s;
	{
		fprintf(stderr, "%s\n",s);
	}


