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
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "hash.c"
#include "pila.c"
#include "matrizSemantica.c"

//Prototipos de metodos
void inicializarMatriz();
void checarOperando1();
void checarOperando2(); 
int checarSemantica(int op, int op1, int op2);
int generarDireccion(int tipo, int alcance);

void secuenciaIf1();
void secuenciaIf2();
void secuenciaElse();
void secuenciaWhile1();
void secuenciaWhile2();	

int yystopparser=0;
int matrizSemantica[4][16][11];

//Direcciones Virtuales
int alcanceDireccion=0; // 1: global, 2: local, 3: temp
int direccionEnteroGlobal=10000;
int direccionDobleGlobal=20000;
int direccionTextoGlobal=3000;
int direccionBooleanoGlobal=4000;

int direccionEnteroLocal=11000;
int direccionDobleLocal=21000;
int direccionTextoLocal=31000;
int direccionBooleanoLocal=41000;

int direccionEnteroTemp=12000;
int direccionDobleTemp=22000;
int direccionTextoTemp=32000;
int direccionBooleanoTemp=42000;

//Tabla de vatiables y procedimientos
struct StrHashTable tbl = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTableProc tblprocs = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashNodeProc nodeProc;

int tipoOp=-1;

//PILAS
ptr pilaOperadores=NULL;
ptr pilaOperando=NULL;
ptr pilaTipos=NULL;





/* Line 268 of yacc.c  */
#line 130 "sintatico.tab.c"

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
#line 60 "sintatico.y"
int cteint; float ctefloat; int cteboolean; char *string;


/* Line 293 of yacc.c  */
#line 233 "sintatico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 245 "sintatico.tab.c"

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
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNRULES -- Number of states.  */
#define YYNSTATES  271

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
       0,     0,     3,    12,    13,    17,    19,    20,    23,    25,
      26,    29,    31,    32,    34,    36,    38,    40,    43,    45,
      46,    48,    50,    52,    54,    56,    58,    60,    62,    64,
      66,    68,    70,    72,    74,    76,    78,    80,    82,    84,
      90,    92,    93,    94,    98,   100,   101,   107,   109,   110,
     115,   119,   120,   126,   128,   130,   132,   133,   138,   142,
     143,   149,   154,   155,   165,   166,   172,   173,   174,   175,
     186,   199,   201,   203,   204,   206,   210,   211,   214,   220,
     223,   226,   227,   230,   231,   234,   236,   238,   241,   242,
     245,   247,   249,   252,   255,   257,   258,   262,   263,   266,
     268,   270,   271,   275,   276,   279,   281,   283,   284,   289,
     291,   294,   296,   298,   300,   302,   310,   312,   314,   316,
     318,   324,   332,   342,   348,   356,   364,   370,   376,   384,
     392,   398,   400,   402
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      65,     0,    -1,     3,    14,    39,    66,    71,    69,    74,
      40,    -1,    -1,    67,    78,    68,    -1,    66,    -1,    -1,
     101,    70,    -1,    69,    -1,    -1,    87,    72,    -1,    71,
      -1,    -1,    21,    -1,    19,    -1,    20,    -1,    22,    -1,
      76,    75,    -1,    74,    -1,    -1,    87,    -1,    94,    -1,
      92,    -1,    93,    -1,    98,    -1,    77,    -1,   106,    -1,
     126,    -1,   128,    -1,   129,    -1,   130,    -1,   133,    -1,
     132,    -1,   134,    -1,   136,    -1,   135,    -1,   137,    -1,
     138,    -1,   131,    -1,     8,    73,    79,    14,    33,    -1,
      85,    -1,    -1,    -1,    81,    83,    82,    -1,    80,    -1,
      -1,     8,    73,    84,    14,    33,    -1,    85,    -1,    -1,
      41,    16,    42,    86,    -1,    41,    16,    42,    -1,    -1,
      14,    89,    23,    88,    33,    -1,    93,    -1,   115,    -1,
      90,    -1,    -1,    41,   115,    42,    91,    -1,    41,   115,
      42,    -1,    -1,     6,    37,   115,    38,    33,    -1,     7,
      37,    38,    33,    -1,    -1,     4,    37,   109,    38,    95,
      39,    74,    40,    96,    -1,    -1,     5,    97,    39,    74,
      40,    -1,    -1,    -1,    -1,     9,    99,    37,   109,    38,
      10,   100,    39,    74,    40,    -1,    11,   102,    14,    37,
     103,    38,    39,    80,    74,    13,   115,    40,    -1,    73,
      -1,    12,    -1,    -1,   104,    -1,    73,    14,   105,    -1,
      -1,    36,   104,    -1,    14,    37,   107,    38,    33,    -1,
     115,   108,    -1,    36,   107,    -1,    -1,   112,   110,    -1,
      -1,   111,   112,    -1,    31,    -1,    32,    -1,   115,   113,
      -1,    -1,   114,   115,    -1,    30,    -1,    29,    -1,    23,
      23,    -1,    24,    23,    -1,    23,    -1,    -1,   119,   116,
     117,    -1,    -1,   118,   115,    -1,    25,    -1,    26,    -1,
      -1,   123,   120,   121,    -1,    -1,   122,   119,    -1,    27,
      -1,    28,    -1,    -1,    37,   124,   112,    38,    -1,   125,
      -1,    14,    89,    -1,    15,    -1,    16,    -1,    17,    -1,
      18,    -1,    43,    37,   127,    36,    14,    38,    33,    -1,
      60,    -1,    59,    -1,    61,    -1,    58,    -1,    44,    37,
      14,    38,    33,    -1,    49,    37,    14,    36,   115,    38,
      33,    -1,    47,    37,    14,    36,   115,    36,   115,    38,
      33,    -1,    48,    37,    14,    38,    33,    -1,    46,    37,
      14,    36,   115,    38,    33,    -1,    45,    37,    14,    36,
     115,    38,    33,    -1,    50,    37,    14,    38,    33,    -1,
      51,    37,    14,    38,    33,    -1,    52,    37,    14,    36,
     115,    38,    33,    -1,    53,    37,    14,    36,   115,    38,
      33,    -1,    54,    37,   139,    38,    33,    -1,    55,    -1,
      56,    -1,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   136,   136,   137,   138,   139,   140,   141,
     143,   144,   145,   148,   149,   150,   151,   153,   154,   155,
     157,   158,   159,   160,   161,   162,   163,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   179,
     180,   181,   184,   184,   185,   186,   188,   198,   199,   202,
     203,   204,   207,   208,   209,   210,   211,   212,   213,   214,
     221,   223,   225,   225,   227,   227,   228,   232,   232,   232,
     234,   240,   241,   242,   243,   244,   245,   246,   248,   249,
     250,   251,   254,   255,   256,   257,   258,   261,   262,   263,
     264,   265,   266,   271,   276,   279,   279,   280,   281,   282,
     283,   285,   285,   286,   287,   288,   289,   291,   291,   292,
     293,   299,   300,   301,   302,   304,   306,   307,   308,   309,
     311,   313,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   335,   336
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
  "gato", "verdadero", "falso", "$accept", "PROGRAMA", "PROGRAMA1", "$@1",
  "PROGRAMA12", "PROGRAMA2", "PROGRAMA22", "PROGRAMASIG", "PROGRAMASIG2",
  "TIPO", "BLOQUE", "BLOQUE1", "ESTATUTO", "FUNCIONESPECIAL",
  "DECLARACION", "DECLARACION2", "DECLARACIONFUNCIONCICLO", "$@2",
  "DECLARACIONFUNCIONCICLO2", "DECLARACIONFUNCION", "DECLARACIONFUNCION2",
  "ARREGLOS", "ARREGLOS2", "ASIGNACION", "ASIGNACION3", "ASIGNACION2",
  "ARREGLOSASIG", "ARREGLOSASIG2", "ESCRITURA", "LECTURA", "CONDICION",
  "$@3", "CONDICION2", "$@4", "CICLO", "$@5", "$@6", "CREARFUNCION",
  "CREARFUNCION2", "CREARFUNCION3", "CREARFUNCION4", "CREARFUNCION5",
  "LLAMARFUNCION", "LLAMARFUNCION2", "LLAMARFUNCION3", "SUPEREXPRESION",
  "SUPEREXPRESION2", "SUPEREXPRESION3", "EXPRESION", "EXPRESION2",
  "EXPRESION3", "EXP", "$@7", "EXP2", "EXP3", "TERMINO", "$@8", "TERMINO2",
  "TERMINO3", "FACTOR", "$@9", "VARCTE", "DIBUJARFIGURA", "FIGURA",
  "BORRARFIGURA", "HABLAR", "MOVER", "OBTENERPOSICION", "GIRARDER",
  "GIRARIZQ", "OBTENERALTURA", "OBTENERANCHURA", "CAMBIARALTURA",
  "CAMBIARANCHURA", "COLORFONDO", "COLOR", 0
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
       0,    64,    65,    67,    66,    68,    68,    69,    70,    70,
      71,    72,    72,    73,    73,    73,    73,    74,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    79,    81,    80,    82,    82,    83,    84,    84,    85,
      86,    86,    87,    88,    88,    89,    89,    90,    91,    91,
      92,    93,    95,    94,    97,    96,    96,    99,   100,    98,
     101,   102,   102,   103,   103,   104,   105,   105,   106,   107,
     108,   108,   109,   110,   110,   111,   111,   112,   113,   113,
     114,   114,   114,   114,   114,   116,   115,   117,   117,   118,
     118,   120,   119,   121,   121,   122,   122,   124,   123,   123,
     123,   125,   125,   125,   125,   126,   127,   127,   127,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   139,   139
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     3,     1,     0,     2,     1,     0,
       2,     1,     0,     1,     1,     1,     1,     2,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     0,     0,     3,     1,     0,     5,     1,     0,     4,
       3,     0,     5,     1,     1,     1,     0,     4,     3,     0,
       5,     4,     0,     9,     0,     5,     0,     0,     0,    10,
      12,     1,     1,     0,     1,     3,     0,     2,     5,     2,
       2,     0,     2,     0,     2,     1,     1,     2,     0,     2,
       1,     1,     2,     2,     1,     0,     3,     0,     2,     1,
       1,     0,     3,     0,     2,     1,     1,     0,     4,     1,
       2,     1,     1,     1,     1,     7,     1,     1,     1,     1,
       5,     7,     9,     5,     7,     7,     5,     5,     7,     7,
       5,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,    56,     0,
      12,     0,     3,     0,     0,    55,     0,     0,     9,    11,
      10,    14,    15,    13,    16,    41,     5,     4,    56,   111,
     112,   113,   114,   107,     0,    95,   101,   109,     0,    72,
      71,     0,     0,     0,     0,    67,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    25,    20,    22,    23,    21,    24,    26,    27,    28,
      29,    30,    38,    32,    31,    33,    35,    34,    36,    37,
       8,     7,     0,     0,    40,   110,     0,    59,    97,   103,
       0,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,    18,    17,     0,     0,     0,    88,     0,    57,
      99,   100,    96,     0,   105,   106,   102,     0,    52,    73,
       0,    83,     0,     0,     0,     0,    81,   119,   117,   116,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   132,   133,     0,    51,    39,   108,    94,
       0,    91,    90,    87,     0,     0,    98,   104,     0,     0,
      74,    62,    85,    86,    82,     0,     0,    61,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    92,    93,    89,    58,
      76,     0,     0,    84,    60,     0,    78,    80,     0,   120,
       0,     0,     0,   123,     0,   126,   127,     0,     0,   130,
       0,     0,    75,    42,     0,    68,     0,     0,     0,     0,
       0,     0,     0,    50,    77,     0,     0,     0,     0,   115,
     125,   124,     0,   121,   128,   129,     0,     0,    45,    66,
       0,     0,     0,    48,    44,    43,    64,    63,     0,   122,
       0,     0,    47,     0,    69,    70,     0,     0,    46,     0,
      65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     7,    27,    17,    81,     9,    20,   168,
      59,   113,    60,    61,    12,    83,   235,   236,   255,   248,
     261,    84,   195,    62,    90,    14,    15,   119,    63,    64,
      65,   202,   257,   263,    66,    97,   238,    18,    41,   169,
     170,   222,    67,   135,   181,   130,   174,   175,   131,   163,
     164,   117,    88,   122,   123,    35,    89,   126,   127,    36,
      86,    37,    68,   141,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   155
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -127
static const yytype_int16 yypact[] =
{
      26,    29,    68,    30,  -127,  -127,    56,    63,    31,    62,
      56,    38,    60,    19,    52,  -127,    -8,     1,    62,  -127,
    -127,  -127,  -127,  -127,  -127,    35,  -127,  -127,    31,  -127,
    -127,  -127,  -127,  -127,    36,  -127,  -127,  -127,     2,  -127,
    -127,    65,    40,    43,    44,  -127,   -11,    46,    47,    49,
      50,    51,    53,    54,    57,    58,    59,    61,    64,    66,
       1,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,    73,    79,  -127,  -127,    19,    67,     6,    -4,
      69,  -127,  -127,    70,    19,    19,    71,    74,    19,     3,
      83,    85,    86,    89,    90,    98,    99,   100,   101,   102,
      10,  -127,  -127,  -127,    75,    87,    80,    -2,    19,  -127,
    -127,  -127,  -127,    19,  -127,  -127,  -127,    19,  -127,    38,
      81,     9,    84,    88,    19,    91,    92,  -127,  -127,  -127,
    -127,    94,    93,    96,    97,   103,   104,   105,   106,   107,
     110,   111,  -127,  -127,  -127,   112,    82,  -127,  -127,   113,
     114,  -127,  -127,  -127,    19,   115,  -127,  -127,   120,   116,
    -127,  -127,  -127,  -127,  -127,    19,   119,  -127,   117,   123,
      19,  -127,   121,   125,    19,    19,    19,   126,    19,   127,
     128,    19,    19,   129,   108,  -127,  -127,  -127,  -127,  -127,
     132,   109,   124,  -127,  -127,   130,  -127,  -127,   131,  -127,
     136,   138,   134,  -127,   142,  -127,  -127,   143,   144,  -127,
     122,    38,  -127,  -127,     1,  -127,   150,   151,   152,    19,
     153,   154,   155,  -127,  -127,     1,   118,   149,   156,  -127,
    -127,  -127,   158,  -127,  -127,  -127,   140,    38,   135,   133,
       1,   157,    19,    35,  -127,  -127,  -127,  -127,   159,  -127,
     160,   177,  -127,   162,  -127,  -127,   161,     1,  -127,   163,
    -127
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,   137,  -127,  -127,   147,  -127,   183,  -127,   -10,
     -58,  -127,  -127,  -127,  -127,  -127,  -123,  -127,  -127,  -127,
    -127,  -126,  -127,    32,  -127,   169,  -127,  -127,  -127,   164,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
     -23,  -127,  -127,    24,  -127,    72,  -127,  -127,   -83,  -127,
    -127,   -13,  -127,  -127,  -127,    78,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -43
static const yytype_int16 yytable[] =
{
      34,    25,   112,   116,    39,    42,    40,    43,    44,    44,
      45,    21,    22,    23,    24,    46,    28,    29,    30,    31,
      32,   159,   160,   124,   125,    92,    98,   161,   162,     1,
      13,   120,   121,    28,    29,    30,    31,    32,    10,    33,
     172,   173,    10,     3,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    33,    21,    22,    23,
      24,   137,   138,   139,   140,   152,   153,   154,     4,     5,
       8,    11,    13,    16,    -6,    38,    82,    94,    87,    93,
      95,    96,   132,    99,   100,   136,   101,   102,   103,   114,
     104,   105,   203,   115,   106,   107,   108,   142,   109,   143,
     144,   110,   128,   145,   146,   165,   111,   129,   118,   133,
     166,   134,   147,   148,   149,   150,   151,   156,   158,   171,
     157,   177,   176,   194,   220,   254,   247,   262,   180,   179,
     182,   183,   184,   185,   200,   208,   196,   197,   256,   186,
     225,   188,   187,   -42,   189,   190,   191,   192,   223,    26,
     193,   198,   204,   252,   201,   205,   206,   199,   209,   213,
     215,   216,   219,   224,   233,    80,   237,   136,   221,   226,
     229,   210,   211,   212,   227,   214,   228,   246,   217,   218,
     230,   231,   232,   239,   240,   241,   243,   244,   245,   249,
     259,   266,   258,    19,   268,   250,   251,    85,   234,   264,
     265,   267,    91,   270,   207,   167,   178,     0,     0,   269,
       0,     0,     0,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,     0,   260
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-127))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      13,    11,    60,    86,    12,     4,    16,     6,     7,     7,
       9,    19,    20,    21,    22,    14,    14,    15,    16,    17,
      18,    23,    24,    27,    28,    38,    37,    29,    30,     3,
      41,    25,    26,    14,    15,    16,    17,    18,     6,    37,
      31,    32,    10,    14,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    37,    19,    20,    21,
      22,    58,    59,    60,    61,    55,    56,    57,     0,    39,
      14,     8,    41,    11,    14,    23,    41,    37,    42,    14,
      37,    37,    95,    37,    37,    98,    37,    37,    37,    16,
      37,    37,   175,    14,    37,    37,    37,    14,    37,    14,
      14,    37,    33,    14,    14,   118,    40,    37,    41,    38,
     123,    37,    14,    14,    14,    14,    14,    42,    38,    38,
      33,    33,    38,    41,    16,   248,     8,   253,    36,    38,
      36,    38,    36,    36,    14,    14,    23,    23,     5,    36,
      10,    36,    38,     8,    38,    38,    36,    36,    39,    12,
      38,   164,    33,    13,    38,    38,    33,    42,    33,    33,
      33,    33,    33,    39,    42,    18,   224,   180,    36,    38,
      36,   184,   185,   186,    38,   188,    38,   235,   191,   192,
      38,    38,    38,    33,    33,    33,    33,    33,    33,    40,
      33,    14,   250,    10,    33,    39,    38,    28,   221,    40,
      40,    39,    38,    40,   180,   127,   134,    -1,    -1,   267,
      -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,    -1,   252
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    65,    14,     0,    39,    66,    67,    14,    71,
      87,     8,    78,    41,    89,    90,    11,    69,   101,    71,
      72,    19,    20,    21,    22,    73,    66,    68,    14,    15,
      16,    17,    18,    37,   115,   119,   123,   125,    23,    12,
      73,   102,     4,     6,     7,     9,    14,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    74,
      76,    77,    87,    92,    93,    94,    98,   106,   126,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
      69,    70,    41,    79,    85,    89,   124,    42,   116,   120,
      88,    93,   115,    14,    37,    37,    37,    99,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    40,    74,    75,    16,    14,   112,   115,    41,    91,
      25,    26,   117,   118,    27,    28,   121,   122,    33,    37,
     109,   112,   115,    38,    37,   107,   115,    58,    59,    60,
      61,   127,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    55,    56,    57,   139,    42,    33,    38,    23,
      24,    29,    30,   113,   114,   115,   115,   119,    73,   103,
     104,    38,    31,    32,   110,   111,    38,    33,   109,    38,
      36,   108,    36,    38,    36,    36,    36,    38,    36,    38,
      38,    36,    36,    38,    41,    86,    23,    23,   115,    42,
      14,    38,    95,   112,    33,    38,    33,   107,    14,    33,
     115,   115,   115,    33,   115,    33,    33,   115,   115,    33,
      16,    36,   105,    39,    39,    10,    38,    38,    38,    36,
      38,    38,    38,    42,   104,    80,    81,    74,   100,    33,
      33,    33,   115,    33,    33,    33,    74,     8,    83,    40,
      39,    38,    13,    73,    80,    82,     5,    96,    74,    33,
     115,    84,    85,    97,    40,    40,    14,    39,    33,    74,
      40
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
#line 135 "sintatico.y"
    {insert(&tbl,(yyvsp[(2) - (8)].string),(yyvsp[(2) - (8)].string),-1); puts(get(&tbl,(yyvsp[(2) - (8)].string))); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 136 "sintatico.y"
    {alcanceDireccion=1;/*global*/}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 148 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); printf("===========tipo: %i\n", tipoOp); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 149 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); printf("===========tipo: %i\n", tipoOp);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 150 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); printf("===========tipo: %i\n", tipoOp);}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 151 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); printf("===========tipo: %i\n", tipoOp);}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 179 "sintatico.y"
    {insert(&tbl,(yyvsp[(4) - (5)].string),(yyvsp[(4) - (5)].string),tipoOp); printf("El tipo eeeeeeessssss: %i\n", getType(&tbl,(yyvsp[(4) - (5)].string)));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 184 "sintatico.y"
    {alcanceDireccion=2;/*local*/}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 225 "sintatico.y"
    {/*secuenciaIf();*/}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 225 "sintatico.y"
    {/*secuenciaIf2();*/}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 227 "sintatico.y"
    {/*secuenciaElse();*/}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 232 "sintatico.y"
    {/*secuenciaWhile1();*/}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 232 "sintatico.y"
    {/*secuenciaWhile2();*/}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 232 "sintatico.y"
    {/*secuenciaWhile3();*/}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 244 "sintatico.y"
    {insert(&tbl,(yyvsp[(2) - (3)].string),(yyvsp[(2) - (3)].string),tipoOp);}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 263 "sintatico.y"
    {/*  checaroperando3();   */}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 264 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 265 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 266 "sintatico.y"
    {char* str = (yyvsp[(1) - (2)].string);
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, (yyvsp[(2) - (2)].string) ); 
				      push(&pilaOperando, str, -1, -1);}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 271 "sintatico.y"
    {char* str = (yyvsp[(1) - (2)].string);
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, (yyvsp[(2) - (2)].string) ); 
				      push(&pilaOperando, str, -1, -1);}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 276 "sintatico.y"
    {push(&pilaOperando, (yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 279 "sintatico.y"
    {  checarOperando2();   }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 282 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 283 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 285 "sintatico.y"
    { checarOperando1();   }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 288 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 289 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 291 "sintatico.y"
    { push(&pilaOperando,(yyvsp[(1) - (1)].string),-1,-1); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 291 "sintatico.y"
    {pop(&pilaOperando);}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 293 "sintatico.y"
    {int tipoId = getType(&tbl,(yyvsp[(1) - (2)].string));
				int direccionVirtual = generarDireccion(tipoId, alcanceDireccion);
				 push(&pilaOperadores, (yyvsp[(1) - (2)].string), tipoId, direccionVirtual); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 299 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string), 3, alcanceDireccion);}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 300 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string), 1, alcanceDireccion);}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 301 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string), 2, alcanceDireccion);}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 302 "sintatico.y"
    {push(&pilaOperadores, (yyvsp[(1) - (1)].string), 4, alcanceDireccion);}
    break;



/* Line 1806 of yacc.c  */
#line 1971 "sintatico.tab.c"
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
#line 338 "sintatico.y"

int main()
{
	inicializarMatriz();
	printf("MATRIZZZIIZIZ %i", matrizSemantica[3][3][9]);

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

int generarDireccion(int tipo, int alcance){
	//global	
	if(alcance==1){ 
		printf(">>>>>>>>>>>>>>>>>>ALCANCE GLOBAL\n");
		if(tipo==1) //entero
			return direccionEnteroGlobal++;
		else if(tipo==2) //doble
			return direccionDobleGlobal++;
		else if(tipo==3) //texto
			return direccionTextoGlobal++;
		else if(tipo==4) //booleano
			return direccionBooleanoGlobal++;
	}
	 //local
	else if(alcance==2){
		printf(">>>>>>>>>>>>>>>>>>ALCANCE LOCAL\n");
		if(tipo==1) //entero
			return direccionEnteroLocal++;
		else if(tipo==2) //doble
			return direccionDobleLocal++;
		else if(tipo==3) //texto
			return direccionTextoLocal++;
		else if(tipo==4) //booleano
			return direccionBooleanoLocal++;
	}
	//temp
	else if (alcance==3){ 
		printf(">>>>>>>>>>>>>>>>>>ALCANCE TEMPORAL\n");
		if(tipo==1)// entero
			return direccionEnteroTemp++;
		else if(tipo==2) //doble
			return direccionDobleTemp++;
		else if(tipo==3) //texto
			return direccionTextoTemp++;
		else if(tipo==4) //booleano
			return direccionBooleanoTemp++;
	}

}




int checarSemantica(int op, int op1, int op2){

	if( matrizSemantica[op1-1][op2-1][op] == 0 ){
		printf("--------------Semantica No Valida!!");
		return 0;	//Error: no se puede hacer operacion de esos tipos
	}
	else {
		printf("--------------Semantica Valida!! tipo: %i. " , matrizSemantica[op1-1][op2-1][op]);
		return 1;
	}
	
}

void checarOperando1(){
	ptr op= malloc (sizeof(p_Nodo)); 
	ptr operador1= malloc (sizeof(p_Nodo)); 
	ptr operador2= malloc (sizeof(p_Nodo)); 
	int semanticaValida=-1;
	int numOp =0;

	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='*' || *pilaOperando->valor=='/' ){ 

				if(*pilaOperando->valor=='*' ) numOp=2;
				else if (*pilaOperando->valor=='/' ) numOp=3;

				printf("Operandoooo  %c",*pilaOperando->valor);
				pop(&pilaOperando);

				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				printf("TIPO op1: %i , op2: %i \n", operador1->tipo, operador2->tipo);
				semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);

				/*
				if(semanticaValida==1){
					if (operador1->tipo==1){int op1v = atoi(operador1->valor);}
					else if (operador1->tipo==2){float op1v = atof(operador1->valor);}

					if (operador2->tipo==1){int op2v = atoi(operador1->valor);}
					else if (operador2->tipo==2){float op2v = atof(operador1->valor);}

					int res = op1v;
				}
				//generar 4 vectores
				*/
				push(&pilaOperadores,"t",1,3);//3: direccion temporal
			
				
			}
		}
	}
	/*			
	if(op->valor=='*' || op->valor=='/' ){ 
	//Checar que los tipos sean compatibles para realizar la operacion
			
	ptr operador1 = pop(pilaOperadores);
	ptr operador2 = pop(pilaOperadores);
			
	//cuadruplo(operando,operador1, operador2, res);
	//Si alguno de los operandos pertenecia a un temporal regresarlo al avail
	//-meter resultado a pilaOperandos
	//-meter tipo  a filaTipo si esque fue compatible
			
	}*/
}

	
void checarOperando2(){

	ptr op= malloc (sizeof(p_Nodo)); 
	ptr operador1= malloc (sizeof(p_Nodo)); 
	ptr operador2= malloc (sizeof(p_Nodo)); 
	int semanticaValida=-1;
	int numOp=-1;

	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='+' || *pilaOperando->valor=='-' ){ 

				if(*pilaOperando->valor=='+' ) numOp=0;
				else if (*pilaOperando->valor=='-' ) numOp=1;

				printf("Operandoooo  %c",*pilaOperando->valor);
				pop(&pilaOperando);

				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				printf("TIPO op1: %i , op2: %i \n", operador1->tipo, operador2->tipo);
				push(&pilaOperadores,"t",1,3);//3: direccion temporal
				
				semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
			}
		}
	}/*
			if(operando=='+' || operando=='-' ){ 
			//Checar que los tipos sean compatibles para realizar la operacion
			
				op = pop(pilaOperandos);
				operador1 = pop(pilaOperadores);
				operador2 = pop(pilaOperadores);
			
			//cuadruplo(operando,operador1, operador2, res);
			//Si alguno de los operandos pertenecia a un temporal regresarlo al avail
			//-meter resultado a pilaOperandos
			//-meter tipo  a filaTipo si esque fue compatible
			}*/
	}


void checarOperando3(char *operando){
	ptr op= malloc (sizeof(p_Nodo)); 
	ptr operador1= malloc (sizeof(p_Nodo)); 
	ptr operador2= malloc (sizeof(p_Nodo)); 
	int semanticaValida=-1;
	int numOp=-1;

	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='>'||*pilaOperando->valor=='<'||*pilaOperando->valor=='='||pilaOperando->valor=="=="||pilaOperando->valor=="!=" ){ 

				if(pilaOperando->valor=="==" ) numOp=4;
				else if (pilaOperando->valor=="!=") numOp=5;
				else if (*pilaOperando->valor=='>') numOp=6;
				else if (*pilaOperando->valor=='<') numOp=7;
				else if (*pilaOperando->valor=='=') numOp=5;

				printf("Operandoooo  %c",*pilaOperando->valor);
				pop(&pilaOperando);

				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				printf("TIPO op1: %i , op2: %i \n", operador1->tipo, operador2->tipo);
				push(&pilaOperadores,"t",1, 3);//3: direccion temporal
				
				semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
			}
		}
	}
}

void secuenciaIf1(){
	/*
	aux = pop(&pilaTipos);
	if(aux->tipo != 4)//dif de boolean
		printf("Error semantico!!");
	else	
		pop(&pilaO);
		generar(GoToF, resultado, __);
		push(&pilaSaltos, cont-1);
	*/
}
void secuenciaIf2(){
	/*
	rellenar(pop(&pilaSaltos),cont);
	*/
}
void secuenciaElse(){
	/*
	generar(goto ___);
	rellenar(pop(&pilaSaltos),cont);
	push(&pilaSaltos, cont-1);
		
	*/
}
void secuenciaWhile1(){
	/*
	push(&pilaSaltos,cont);	
	*/
}
void secuenciaWhile2(){
	/*
	aux = pop(&pilaTipos);
	if(aux->tipo != 4)//dif de boolean
		printf("Error semantico!!");
	else	
		pop(&pilaO);
		generar(GoToF, resultado, __);
		push(&pilaSaltos, cont-1);
	*/
}

void secuenciaWhile3(){
	/*
	falso = pop(&pilaSaltos);
	retorno = pop(&pilaSaltos);
	generar(goto, retorno);
	rellenar(falso,cont);
	*/
}
	



void inicializarMatriz(){
	matrizSemantica[0][0][0]= 1;	//Entero + entero = entero
	matrizSemantica[0][1][0]= 2;	//Entero + doble = doble
	matrizSemantica[0][2][0]= 0;	//Entero + texto = no se puede
	matrizSemantica[0][3][0]= 0;	//Entero + bool = no se puede
	matrizSemantica[1][0][0]= 2;	//doble + entero = doble
	matrizSemantica[1][1][0]= 2;	//doble + doble = doble
	matrizSemantica[1][2][0]= 0;	//doble + texto = no se puede
	matrizSemantica[1][3][0]= 0;	//doble + bool = no se puede
	matrizSemantica[2][0][0]= 0;	//texto + entero = no se puede
	matrizSemantica[2][1][0]= 0;	//texto + doble = no se puede
	matrizSemantica[2][2][0]= 3;	//texto + texto = texto
	matrizSemantica[2][3][0]= 3;	//texto + bool = no se puede
	matrizSemantica[3][0][0]= 0;	//bool + entero = no se puede
	matrizSemantica[3][1][0]= 0;	//bool + doble = no se puede
	matrizSemantica[3][2][0]= 0;	//bool + texto = no se puede
	matrizSemantica[3][3][0]= 0;	//bool + bool = no se puede


	//Z=1 (RESTA)
	matrizSemantica[0][0][1]= 1;	//Entero - entero = entero
	matrizSemantica[0][1][1]= 2;	//Entero - doble = doble
	matrizSemantica[0][2][1]= 0;	//Entero - texto = no se puede
	matrizSemantica[0][3][1]= 0;	//Entero - bool = no se puede
	matrizSemantica[1][0][1]= 2;	//doble -entero = doble
	matrizSemantica[1][1][1]= 2;	//doble - doble = doble
	matrizSemantica[1][2][1]= 0;	//doble - texto = no se puede
	matrizSemantica[1][3][1]= 0;	//doble - bool = no se puede
	matrizSemantica[2][0][1]= 0;	//texto - entero = no se puede
	matrizSemantica[2][1][1]= 0;	//texto - doble = no se puede
	matrizSemantica[2][2][1]= 0;	//texto - texto = no se puede
	matrizSemantica[2][3][1]= 0;	//texto - bool = no se puede
	matrizSemantica[3][0][1]= 0;	//bool - entero = no se puede
	matrizSemantica[3][1][1]= 0;	//bool - doble = no se puede
	matrizSemantica[3][2][1]= 0;	//bool - texto = no se puede
	matrizSemantica[3][3][1]= 0;	//bool - bool = no se puede

	//Z=2 (MULTIPLICACION)
	matrizSemantica[0][0][2]= 1;	//Entero * entero = entero
	matrizSemantica[0][1][2]= 2;	//Entero * doble = doble
	matrizSemantica[0][2][2]= 0;	//Entero * texto = no se puede
	matrizSemantica[0][3][2]= 0;	//Entero * bool = no se puede
	matrizSemantica[1][0][2]= 2;	//doble * entero = doble
	matrizSemantica[1][1][2]= 2;	//doble * doble = doble
	matrizSemantica[1][2][2]= 0;	//doble * texto = no se puede
	matrizSemantica[1][3][2]= 0;	//doble * bool = no se puede
	matrizSemantica[2][0][2]= 0;	//texto * entero = no se puede
	matrizSemantica[2][1][2]= 0;	//texto * doble = no se puede
	matrizSemantica[2][2][2]= 0;	//texto * texto = no se puede
	matrizSemantica[2][3][2]= 0;	//texto * bool = no se puede
	matrizSemantica[3][0][2]= 0;	//bool * entero = no se puede
	matrizSemantica[3][1][2]= 0;	//bool * doble = no se puede
	matrizSemantica[3][2][2]= 0;	//bool * texto = no se puede
	matrizSemantica[3][3][2]= 0;	//bool * bool = no se puede

	//Z=3 (DIVISION)
	matrizSemantica[0][0][3]= 1;	//Entero / entero = entero
	matrizSemantica[0][1][3]= 2;	//Entero / doble = doble
	matrizSemantica[0][2][3]= 0;	//Entero / texto = no se puede
	matrizSemantica[0][3][3]= 0;	//Entero / bool = no se puede
	matrizSemantica[1][0][3]= 2;	//doble / entero = doble
	matrizSemantica[1][1][3]= 2;	//doble / doble = doble
	matrizSemantica[1][2][3]= 0;	//doble / texto = no se puede
	matrizSemantica[1][3][3]= 0;	//doble / bool = no se puede
	matrizSemantica[2][0][3]= 0;	//texto / entero = no se puede
	matrizSemantica[2][1][3]= 0;	//texto / doble = no se puede
	matrizSemantica[2][2][3]= 0;	//texto / texto = no se puede
	matrizSemantica[2][3][3]= 0;	//texto / bool = no se puede
	matrizSemantica[3][0][3]= 0;	//bool / entero = no se puede
	matrizSemantica[3][1][3]= 0;	//bool / doble = no se puede
	matrizSemantica[3][2][3]= 0;	//bool / texto = no se puede
	matrizSemantica[3][3][3]= 0;	//bool / bool = no se puede

	//Z=4 (IGUAL)
	matrizSemantica[0][0][4]= 4;	//Entero == entero = bool
	matrizSemantica[0][1][4]= 4;	//Entero ==doble = bool
	matrizSemantica[0][2][4]= 0;	//Entero == texto = bool
	matrizSemantica[0][3][4]= 0;	//Entero == bool = bool
	matrizSemantica[1][0][4]= 4;	//doble == entero = bool
	matrizSemantica[1][1][4]= 4;	//doble == doble = bool
	matrizSemantica[1][2][4]= 0;	//doble == texto = no se puede
	matrizSemantica[1][3][4]= 0;	//doble == bool = no se puede
	matrizSemantica[2][0][4]= 0;	//texto == entero = no se puede
	matrizSemantica[2][1][4]= 0;	//texto == doble = no se puede
	matrizSemantica[2][2][4]= 4;	//texto == texto = bool
	matrizSemantica[2][3][4]= 0;	//texto == bool = no se puede
	matrizSemantica[3][0][4]= 0;	//bool == entero = no se puede
	matrizSemantica[3][1][4]= 0;	//bool == doble = no se puede
	matrizSemantica[3][2][4]= 0;	//bool == texto = no se puede
	matrizSemantica[3][3][4]= 4;	//bool == bool = bool

	//Z=5 (DIFERENTE)
	matrizSemantica[0][0][5]= 4;	//Entero != entero = bool
	matrizSemantica[0][1][5]= 4;	//Entero !=doble = bool
	matrizSemantica[0][2][5]= 0;	//Entero != texto = bool
	matrizSemantica[0][3][5]= 0;	//Entero != bool = bool
	matrizSemantica[1][0][5]= 4;	//doble != entero = bool
	matrizSemantica[1][1][5]= 4;	//doble != doble = bool
	matrizSemantica[1][2][5]= 0;	//doble != texto = no se puede
	matrizSemantica[1][3][5]= 0;	//doble != bool = no se puede
	matrizSemantica[2][0][5]= 0;	//texto != entero = no se puede
	matrizSemantica[2][1][5]= 0;	//texto != doble = no se puede
	matrizSemantica[2][2][5]= 4;	//texto != texto = bool
	matrizSemantica[2][3][5]= 0;	//texto != bool = no se puede
	matrizSemantica[3][0][5]= 0;	//bool != entero = no se puede
	matrizSemantica[3][1][5]= 0;	//bool != doble = no se puede
	matrizSemantica[3][2][5]= 0;	//bool != texto = no se puede
	matrizSemantica[3][3][5]= 4;	//bool != bool = bool

	//Z=6 (MAYOR)
	matrizSemantica[0][0][6]= 4;	//Entero > entero = bool
	matrizSemantica[0][1][6]= 4;	//Entero >doble = bool
	matrizSemantica[0][2][6]= 0;	//Entero > texto = bool
	matrizSemantica[0][3][6]= 0;	//Entero > bool = bool
	matrizSemantica[1][0][6]= 4;	//doble > entero = bool
	matrizSemantica[1][1][6]= 4;	//doble > doble = bool
	matrizSemantica[1][2][6]= 0;	//doble > texto = no se puede
	matrizSemantica[1][3][6]= 0;	//doble > bool = no se puede
	matrizSemantica[2][0][6]= 0;	//texto > entero = no se puede
	matrizSemantica[2][1][6]= 0;	//texto > doble = no se puede
	matrizSemantica[2][2][6]= 4;	//texto > texto = bool
	matrizSemantica[2][3][6]= 0;	//texto > bool = no se puede
	matrizSemantica[3][0][6]= 0;	//bool > entero = no se puede
	matrizSemantica[3][1][6]= 0;	//bool > doble = no se puede
	matrizSemantica[3][2][6]= 0;	//bool > texto = no se puede
	matrizSemantica[3][3][6]= 4;	//bool > bool = bool

	//Z=7 (MENOR)
	matrizSemantica[0][0][7]= 4;	//Entero < entero = bool
	matrizSemantica[0][1][7]= 4;	//Entero <doble = bool
	matrizSemantica[0][2][7]= 0;	//Entero < texto = bool
	matrizSemantica[0][3][7]= 0;	//Entero < bool = bool
	matrizSemantica[1][0][7]= 4;	//doble < entero = bool
	matrizSemantica[1][1][7]= 4;	//doble < doble = bool
	matrizSemantica[1][2][7]= 0;	//doble < texto = no se puede
	matrizSemantica[1][3][7]= 0;	//doble < bool = no se puede
	matrizSemantica[2][0][7]= 0;	//texto < entero = no se puede
	matrizSemantica[2][1][7]= 0;	//texto < doble = no se puede
	matrizSemantica[2][2][7]= 4;	//texto < texto = bool
	matrizSemantica[2][3][7]= 0;	//texto < bool = no se puede
	matrizSemantica[3][0][7]= 0;	//bool < entero = no se puede
	matrizSemantica[3][1][7]= 0;	//bool < doble = no se puede
	matrizSemantica[3][2][7]= 0;	//bool < texto = no se puede
	matrizSemantica[3][3][7]= 4;	//bool < bool = bool

	//Z=8 (AND)
	matrizSemantica[0][0][8]= 4;	//Entero  && entero = bool
	matrizSemantica[0][1][8]= 4;	//Entero && doble = bool
	matrizSemantica[0][2][8]= 0;	//Entero && texto = bool
	matrizSemantica[0][3][8]= 0;	//Entero && bool = bool
	matrizSemantica[1][0][8]= 4;	//doble && entero = bool
	matrizSemantica[1][1][8]= 4;	//doble && doble = bool
	matrizSemantica[1][2][8]= 0;	//doble && texto = no se puede
	matrizSemantica[1][3][8]= 0;	//doble && bool = no se puede
	matrizSemantica[2][0][8]= 0;	//texto && entero = no se puede
	matrizSemantica[2][1][8]= 0;	//texto && doble = no se puede
	matrizSemantica[2][2][8]= 4;	//texto && texto = bool
	matrizSemantica[2][3][8]= 0;	//texto && bool = no se puede
	matrizSemantica[3][0][8]= 0;	//bool && entero = no se puede
	matrizSemantica[3][1][8]= 0;	//bool && doble = no se puede
	matrizSemantica[3][2][8]= 0;	//bool && texto = no se puede
	matrizSemantica[3][3][8]= 4;	//bool && bool = bool

	//Z=9 (OR)
	matrizSemantica[0][0][9]= 4;	//Entero  || entero = bool
	matrizSemantica[0][1][9]= 4;	//Entero || doble = bool
	matrizSemantica[0][2][9]= 0;	//Entero || texto = bool
	matrizSemantica[0][3][9]= 0;	//Entero || bool = bool
	matrizSemantica[1][0][9]= 4;	//doble || entero = bool
	matrizSemantica[1][1][9]= 4;	//doble || doble = bool
	matrizSemantica[1][2][9]= 0;	//doble || texto = no se puede
	matrizSemantica[1][3][9]= 0;	//doble || bool = no se puede
	matrizSemantica[2][0][9]= 0;	//texto || entero = no se puede
	matrizSemantica[2][1][9]= 0;	//texto || doble = no se puede
	matrizSemantica[2][2][9]= 4;	//texto || texto = bool
	matrizSemantica[2][3][9]= 0;	//texto || bool = no se puede
	matrizSemantica[3][0][9]= 0;	//bool || entero = no se puede
	matrizSemantica[3][1][9]= 0;	//bool || doble = no se puede
	matrizSemantica[3][2][9]= 0;	//bool || texto = no se puede
	matrizSemantica[3][3][9]= 4;	//bool || bool = bool

	//Z=10 (ASIGNACION =)
	matrizSemantica[0][0][10]= 1;	//Entero  = entero -> entero
	matrizSemantica[0][1][10]= 0;	//Entero = doble -> no se puede
	matrizSemantica[0][2][10]= 0;	//Entero =  texto -> no se puede
	matrizSemantica[0][3][10]= 0;	//Entero = bool -> no se puede
	matrizSemantica[1][0][10]= 0;	//doble = entero -> no se puede
	matrizSemantica[1][1][10]= 2;	//doble = doble -> doble
	matrizSemantica[1][2][10]= 0;	//doble = texto -> no se puede
	matrizSemantica[1][3][10]= 0;	//doble = bool -> no se puede
	matrizSemantica[2][0][10]= 0;	//texto = entero -> no se puede
	matrizSemantica[2][1][10]= 0;	//texto = doble -> no se puede
	matrizSemantica[2][2][10]= 3;	//texto = texto -> texto
	matrizSemantica[2][3][10]= 0;	//texto = bool -> no se puede
	matrizSemantica[3][0][10]= 0;	//bool = entero -> no se puede
	matrizSemantica[3][1][10]= 0;	//bool = doble -> no se puede
	matrizSemantica[3][2][10]= 0;	//bool = texto -> no se puede
	matrizSemantica[3][3][10]= 4;	//bool = bool -> bool
}

yyerror(s)
char *s;
	{
		fprintf(stderr, "%s\n",s);
	}


