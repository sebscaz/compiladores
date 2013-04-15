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
#include "hash2.c"
#include "pila.c"
#include "matrizSemantica.c"

//Prototipos de metodos
void inicializarMatriz();
void inicializarVectores();
void checarOperando1();
void checarOperando2(); 
void checarOperando3(); 
void rellenar(int goTo, int contador);
int checarSemantica(int op, int op1, int op2);
int generarDireccion(int tipo, int alcance);
void generarCuadruplo(int numOp ,int tipo1, int tipo2, int res);
int hacerPush = 1;	//bool para saber si meter variables a la pila - 1:hacer push, 0:no hacer push

void secuenciaIf1();
void secuenciaIf2();
void secuenciaElse();
void secuenciaWhile1();
void secuenciaWhile2();	
void secuenciaWhile3();

int yystopparser=0;
int matrizSemantica[4][16][11];
int contT=1;
int contS=0; /*contador de saltos*/ 
char strCuadruplos[1000];

//Direcciones Virtuales
int alcanceDireccion=0; // 1: global, 2: local, 3: temp
int direccionEnteroGlobal=10000;
int direccionDobleGlobal=20000;
int direccionTextoGlobal=30000;
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
struct StrHashTableProc tblProc = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashNodeProc nodeProc;

struct StrHashTable tablaGlobal = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTable tablaLocal = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTable tablaTemporal = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTable tablaConstantes = {{0},NULL,NULL,foo_strhash,strcmp};

int tipoOp=-1;

//PILAS
ptr pilaOperadores=NULL;
ptr pilaOperando=NULL;
ptr pilaTipos=NULL;
ptr pilaSaltos=NULL;

/*Vectores dinamicos*/
int* vectorTemporal;
int* vectorOp;
int* vectorOp1;
int* vectorOp2;
int* vectorRes;





/* Line 268 of yacc.c  */
#line 152 "sintatico.tab.c"

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
#line 82 "sintatico.y"
int cteint; float ctefloat; int cteboolean; char *string;


/* Line 293 of yacc.c  */
#line 255 "sintatico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 267 "sintatico.tab.c"

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
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  274

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
       0,     0,     3,     4,    14,    15,    19,    21,    22,    25,
      27,    28,    31,    33,    34,    36,    38,    40,    42,    45,
      47,    48,    50,    52,    54,    56,    58,    60,    62,    64,
      66,    68,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    92,    94,    95,    96,   100,   102,   103,   109,   111,
     112,   117,   121,   122,   123,   124,   132,   134,   136,   137,
     140,   141,   146,   150,   151,   157,   162,   163,   173,   174,
     180,   181,   182,   183,   194,   207,   209,   211,   212,   214,
     218,   219,   222,   228,   231,   234,   235,   238,   239,   242,
     244,   246,   249,   250,   253,   255,   257,   259,   262,   263,
     267,   268,   271,   273,   275,   276,   280,   281,   284,   286,
     288,   289,   294,   296,   299,   301,   303,   305,   307,   315,
     317,   319,   321,   323,   329,   337,   347,   353,   361,   369,
     375,   381,   389,   397,   403,   405,   407
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      65,     0,    -1,    -1,     3,    14,    66,    39,    67,    72,
      70,    75,    40,    -1,    -1,    68,    79,    69,    -1,    67,
      -1,    -1,   105,    71,    -1,    70,    -1,    -1,    88,    73,
      -1,    72,    -1,    -1,    21,    -1,    19,    -1,    20,    -1,
      22,    -1,    77,    76,    -1,    75,    -1,    -1,    88,    -1,
      98,    -1,    96,    -1,    97,    -1,   102,    -1,    78,    -1,
     110,    -1,   130,    -1,   132,    -1,   133,    -1,   134,    -1,
     137,    -1,   136,    -1,   138,    -1,   140,    -1,   139,    -1,
     141,    -1,   142,    -1,   135,    -1,     8,    74,    80,    14,
      33,    -1,    86,    -1,    -1,    -1,    82,    84,    83,    -1,
      81,    -1,    -1,     8,    74,    85,    14,    33,    -1,    86,
      -1,    -1,    41,    16,    42,    87,    -1,    41,    16,    42,
      -1,    -1,    -1,    -1,    14,    92,    89,    23,    90,    91,
      33,    -1,    97,    -1,   119,    -1,    -1,    93,    94,    -1,
      -1,    41,   119,    42,    95,    -1,    41,   119,    42,    -1,
      -1,     6,    37,   119,    38,    33,    -1,     7,    37,    38,
      33,    -1,    -1,     4,    37,   113,    38,    99,    39,    75,
      40,   100,    -1,    -1,     5,   101,    39,    75,    40,    -1,
      -1,    -1,    -1,     9,   103,    37,   113,    38,    10,   104,
      39,    75,    40,    -1,    11,   106,    14,    37,   107,    38,
      39,    81,    75,    13,   119,    40,    -1,    74,    -1,    12,
      -1,    -1,   108,    -1,    74,    14,   109,    -1,    -1,    36,
     108,    -1,    14,    37,   111,    38,    33,    -1,   119,   112,
      -1,    36,   111,    -1,    -1,   116,   114,    -1,    -1,   115,
     116,    -1,    31,    -1,    32,    -1,   119,   117,    -1,    -1,
     118,   119,    -1,    30,    -1,    29,    -1,    23,    -1,    24,
      23,    -1,    -1,   123,   120,   121,    -1,    -1,   122,   119,
      -1,    25,    -1,    26,    -1,    -1,   127,   124,   125,    -1,
      -1,   126,   123,    -1,    27,    -1,    28,    -1,    -1,    37,
     128,   116,    38,    -1,   129,    -1,    14,    92,    -1,    15,
      -1,    16,    -1,    17,    -1,    18,    -1,    43,    37,   131,
      36,    14,    38,    33,    -1,    60,    -1,    59,    -1,    61,
      -1,    58,    -1,    44,    37,    14,    38,    33,    -1,    49,
      37,    14,    36,   119,    38,    33,    -1,    47,    37,    14,
      36,   119,    36,   119,    38,    33,    -1,    48,    37,    14,
      38,    33,    -1,    46,    37,    14,    36,   119,    38,    33,
      -1,    45,    37,    14,    36,   119,    38,    33,    -1,    50,
      37,    14,    38,    33,    -1,    51,    37,    14,    38,    33,
      -1,    52,    37,    14,    36,   119,    38,    33,    -1,    53,
      37,    14,    36,   119,    38,    33,    -1,    54,    37,   143,
      38,    33,    -1,    55,    -1,    56,    -1,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   157,   157,   157,   158,   158,   159,   160,   161,   162,
     163,   165,   166,   167,   170,   171,   172,   173,   175,   176,
     177,   179,   180,   181,   182,   183,   184,   185,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     201,   202,   203,   206,   206,   207,   208,   210,   212,   213,
     216,   217,   218,   221,   229,   221,   231,   232,   233,   233,
     234,   235,   236,   237,   239,   241,   243,   243,   245,   245,
     246,   250,   250,   250,   252,   257,   258,   259,   260,   261,
     262,   263,   265,   266,   267,   268,   271,   272,   273,   274,
     275,   278,   279,   280,   281,   282,   283,   284,   291,   291,
     292,   293,   294,   295,   297,   297,   298,   299,   300,   301,
     303,   303,   304,   305,   311,   312,   313,   314,   316,   318,
     319,   320,   321,   323,   325,   328,   330,   332,   334,   336,
     338,   340,   342,   344,   346,   347,   348
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
  "gato", "verdadero", "falso", "$accept", "PROGRAMA", "$@1", "PROGRAMA1",
  "$@2", "PROGRAMA12", "PROGRAMA2", "PROGRAMA22", "PROGRAMASIG",
  "PROGRAMASIG2", "TIPO", "BLOQUE", "BLOQUE1", "ESTATUTO",
  "FUNCIONESPECIAL", "DECLARACION", "DECLARACION2",
  "DECLARACIONFUNCIONCICLO", "$@3", "DECLARACIONFUNCIONCICLO2",
  "DECLARACIONFUNCION", "DECLARACIONFUNCION2", "ARREGLOS", "ARREGLOS2",
  "ASIGNACION", "$@4", "$@5", "ASIGNACION3", "ASIGNACION2", "$@6",
  "ARREGLOSASIG", "ARREGLOSASIG2", "ESCRITURA", "LECTURA", "CONDICION",
  "$@7", "CONDICION2", "$@8", "CICLO", "$@9", "$@10", "CREARFUNCION",
  "CREARFUNCION2", "CREARFUNCION3", "CREARFUNCION4", "CREARFUNCION5",
  "LLAMARFUNCION", "LLAMARFUNCION2", "LLAMARFUNCION3", "SUPEREXPRESION",
  "SUPEREXPRESION2", "SUPEREXPRESION3", "EXPRESION", "EXPRESION2",
  "EXPRESION3", "EXP", "$@11", "EXP2", "EXP3", "TERMINO", "$@12",
  "TERMINO2", "TERMINO3", "FACTOR", "$@13", "VARCTE", "DIBUJARFIGURA",
  "FIGURA", "BORRARFIGURA", "HABLAR", "MOVER", "OBTENERPOSICION",
  "GIRARDER", "GIRARIZQ", "OBTENERALTURA", "OBTENERANCHURA",
  "CAMBIARALTURA", "CAMBIARANCHURA", "COLORFONDO", "COLOR", 0
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
       0,    64,    66,    65,    68,    67,    69,    69,    70,    71,
      71,    72,    73,    73,    74,    74,    74,    74,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    80,    80,    82,    81,    83,    83,    84,    85,    85,
      86,    87,    87,    89,    90,    88,    91,    91,    93,    92,
      92,    94,    95,    95,    96,    97,    99,    98,   101,   100,
     100,   103,   104,   102,   105,   106,   106,   107,   107,   108,
     109,   109,   110,   111,   112,   112,   113,   114,   114,   115,
     115,   116,   117,   117,   118,   118,   118,   118,   120,   119,
     121,   121,   122,   122,   124,   123,   125,   125,   126,   126,
     128,   127,   127,   127,   129,   129,   129,   129,   130,   131,
     131,   131,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   143,   143
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     0,     3,     1,     0,     2,     1,
       0,     2,     1,     0,     1,     1,     1,     1,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     0,     0,     3,     1,     0,     5,     1,     0,
       4,     3,     0,     0,     0,     7,     1,     1,     0,     2,
       0,     4,     3,     0,     5,     4,     0,     9,     0,     5,
       0,     0,     0,    10,    12,     1,     1,     0,     1,     3,
       0,     2,     5,     2,     2,     0,     2,     0,     2,     1,
       1,     2,     0,     2,     1,     1,     1,     2,     0,     3,
       0,     2,     1,     1,     0,     3,     0,     2,     1,     1,
       0,     4,     1,     2,     1,     1,     1,     1,     7,     1,
       1,     1,     1,     5,     7,     9,     5,     7,     7,     5,
       5,     7,     7,     5,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     4,     0,     0,    58,
       0,    13,     0,     4,    53,     0,     0,     0,    10,    12,
      11,    15,    16,    14,    17,    42,     6,     5,     0,     0,
      59,    76,    75,     0,     0,     0,     0,    71,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    26,    21,    23,    24,    22,    25,    27,
      28,    29,    30,    31,    39,    33,    32,    34,    36,    35,
      37,    38,     9,     8,     0,     0,    41,    54,    60,   114,
     115,   116,   117,   110,     0,    98,   104,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,    19,    18,     0,
       0,     0,   113,     0,    63,   100,   106,    77,     0,    87,
      92,     0,     0,     0,     0,    85,   122,   120,   119,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,     0,    52,    40,     0,    56,    57,
       0,     0,    61,   102,   103,    99,     0,   108,   109,   105,
       0,     0,     0,    78,    66,    89,    90,    86,     0,    96,
       0,    95,    94,    91,     0,     0,    65,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    55,   111,     0,   101,   107,
      80,     0,     0,    88,    97,    93,    64,     0,    82,    84,
       0,   123,     0,     0,     0,   126,     0,   129,   130,     0,
       0,   133,     0,    62,     0,    79,    43,     0,    72,     0,
       0,     0,     0,     0,     0,     0,    51,    81,     0,     0,
       0,     0,   118,   128,   127,     0,   124,   131,   132,     0,
       0,    46,    70,     0,     0,     0,    49,    45,    44,    68,
      67,     0,   125,     0,     0,    48,     0,    73,    74,     0,
       0,    47,     0,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     7,     8,    27,    17,    73,    10,    20,
     161,    51,   108,    52,    53,    13,    75,   238,   239,   258,
     251,   264,    76,   194,    54,    28,   111,   147,    14,    15,
      30,   152,    55,    56,    57,   202,   260,   266,    58,    92,
     241,    18,    33,   162,   163,   225,    59,   124,   180,   118,
     167,   168,   119,   173,   174,   120,   115,   155,   156,    85,
     116,   159,   160,    86,   113,    87,    60,   130,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   144
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -128
static const yytype_int16 yypact[] =
{
       3,    -3,    22,  -128,  -128,    -7,  -128,    24,    49,    36,
      64,    24,    21,    62,  -128,    38,     9,     1,    64,  -128,
    -128,  -128,  -128,  -128,  -128,    39,  -128,  -128,    54,    19,
    -128,  -128,  -128,    67,    41,    45,    47,  -128,   -11,    48,
      50,    51,    52,    53,    55,    56,    57,    58,    59,    60,
      61,    46,     1,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,    75,    85,  -128,  -128,    63,  -128,
    -128,  -128,  -128,  -128,    65,  -128,  -128,  -128,    66,    19,
      19,    68,    71,    19,    10,    86,    87,    88,    91,    95,
      96,    97,    98,    99,   100,    17,  -128,  -128,  -128,    73,
      83,     2,  -128,    19,    76,    -1,   -14,    21,    80,    32,
      37,    81,    89,    19,    82,    90,  -128,  -128,  -128,  -128,
      93,    92,   101,   102,   103,    94,   104,   105,   106,   109,
     111,  -128,  -128,  -128,   110,    84,  -128,   108,  -128,  -128,
     112,    19,  -128,  -128,  -128,  -128,    19,  -128,  -128,  -128,
      19,   107,   114,  -128,  -128,  -128,  -128,  -128,    19,  -128,
     113,  -128,  -128,  -128,    19,   116,  -128,   115,   121,    19,
    -128,   117,   125,    19,    19,    19,   127,    19,   128,   131,
      19,    19,   132,   118,  -128,  -128,  -128,   124,  -128,  -128,
     133,   129,   134,  -128,  -128,  -128,  -128,   123,  -128,  -128,
     136,  -128,   137,   138,   135,  -128,   140,  -128,  -128,   141,
     142,  -128,   130,  -128,    21,  -128,  -128,     1,  -128,   148,
     149,   150,    19,   151,   152,   153,  -128,  -128,     1,   119,
     147,   154,  -128,  -128,  -128,   156,  -128,  -128,  -128,   122,
      21,   159,   165,     1,   157,    19,    39,  -128,  -128,  -128,
    -128,   155,  -128,   158,   175,  -128,   160,  -128,  -128,   163,
       1,  -128,   161,  -128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,   178,  -128,  -128,   174,  -128,   186,  -128,
     -12,   -50,  -128,  -128,  -128,  -128,  -128,  -127,  -128,  -128,
    -128,  -128,  -114,  -128,    16,  -128,  -128,  -128,   139,  -128,
    -128,  -128,  -128,   120,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,   -24,  -128,  -128,    23,  -128,   126,
    -128,  -128,  -110,  -128,  -128,   -28,  -128,  -128,  -128,    69,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -61
static const yytype_int16 yytable[] =
{
      25,    84,   107,   150,    32,    34,     1,    35,    36,    36,
      37,     3,   -60,   157,   158,    38,    78,    79,    80,    81,
      82,    31,     4,    11,   153,   154,    93,    11,    21,    22,
      23,    24,     6,    78,    79,    80,    81,    82,     9,    83,
      21,    22,    23,    24,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    83,    12,   203,   -60,
     169,   170,   121,   165,   166,   125,   171,   172,   126,   127,
     128,   129,   141,   142,   143,    16,    -7,    77,    89,    29,
      74,    88,    90,   149,    91,    94,   106,    95,    96,    97,
      98,   109,    99,   100,   101,   102,   103,   104,   105,   110,
     131,   132,   133,   117,   -58,   134,   122,   114,   123,   135,
     136,   137,   138,   139,   140,   145,   146,   151,   164,   175,
     178,   200,   176,   197,   257,   193,   179,   250,   198,   181,
     182,   210,   186,   228,   222,   255,   204,   183,   184,   185,
     187,   195,   265,   188,   189,   190,   205,   191,   192,   206,
     196,   125,   201,   207,   208,   212,   213,   214,   211,   216,
     215,   217,   219,   220,   218,   221,   223,   -43,   226,   224,
     259,   232,   236,   227,   229,   230,   231,   240,   233,   234,
     235,   242,   243,   244,   246,   247,   248,   252,   249,   269,
     262,    26,    72,   253,   254,   267,   271,    19,   268,   270,
     237,   273,   209,   261,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,     0,     0,
     272,     0,     0,     0,     0,     0,     0,   263,     0,   199,
       0,   148,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-128))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      12,    29,    52,   113,    16,     4,     3,     6,     7,     7,
       9,    14,    23,    27,    28,    14,    14,    15,    16,    17,
      18,    12,     0,     7,    25,    26,    37,    11,    19,    20,
      21,    22,    39,    14,    15,    16,    17,    18,    14,    37,
      19,    20,    21,    22,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    37,     8,   168,    23,
      23,    24,    90,    31,    32,    93,    29,    30,    58,    59,
      60,    61,    55,    56,    57,    11,    14,    23,    37,    41,
      41,    14,    37,   111,    37,    37,    40,    37,    37,    37,
      37,    16,    37,    37,    37,    37,    37,    37,    37,    14,
      14,    14,    14,    37,    41,    14,    38,    42,    37,    14,
      14,    14,    14,    14,    14,    42,    33,    41,    38,    38,
      38,    14,    33,   151,   251,    41,    36,     8,   156,    36,
      38,    14,    38,    10,    16,    13,    23,    36,    36,    36,
      36,    33,   256,    38,    38,    36,   174,    36,    38,    33,
      38,   179,    38,    38,    33,   183,   184,   185,    33,   187,
      33,    33,   190,   191,    33,    33,    42,     8,    39,    36,
       5,    36,    42,    39,    38,    38,    38,   227,    38,    38,
      38,    33,    33,    33,    33,    33,    33,    40,   238,    14,
      33,    13,    18,    39,    38,    40,    33,    11,    40,    39,
     224,    40,   179,   253,   232,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,   160,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    65,    14,     0,    66,    39,    67,    68,    14,
      72,    88,     8,    79,    92,    93,    11,    70,   105,    72,
      73,    19,    20,    21,    22,    74,    67,    69,    89,    41,
      94,    12,    74,   106,     4,     6,     7,     9,    14,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    75,    77,    78,    88,    96,    97,    98,   102,   110,
     130,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    70,    71,    41,    80,    86,    23,    14,    15,
      16,    17,    18,    37,   119,   123,   127,   129,    14,    37,
      37,    37,   103,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    40,    75,    76,    16,
      14,    90,    92,   128,    42,   120,   124,    37,   113,   116,
     119,   119,    38,    37,   111,   119,    58,    59,    60,    61,
     131,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    55,    56,    57,   143,    42,    33,    91,    97,   119,
     116,    41,    95,    25,    26,   121,   122,    27,    28,   125,
     126,    74,   107,   108,    38,    31,    32,   114,   115,    23,
      24,    29,    30,   117,   118,    38,    33,   113,    38,    36,
     112,    36,    38,    36,    36,    36,    38,    36,    38,    38,
      36,    36,    38,    41,    87,    33,    38,   119,   119,   123,
      14,    38,    99,   116,    23,   119,    33,    38,    33,   111,
      14,    33,   119,   119,   119,    33,   119,    33,    33,   119,
     119,    33,    16,    42,    36,   109,    39,    39,    10,    38,
      38,    38,    36,    38,    38,    38,    42,   108,    81,    82,
      75,   104,    33,    33,    33,   119,    33,    33,    33,    75,
       8,    84,    40,    39,    38,    13,    74,    81,    83,     5,
     100,    75,    33,   119,    85,    86,   101,    40,    40,    14,
      39,    33,    75,    40
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
#line 157 "sintatico.y"
    {insertProc(&tblProc,&tablaGlobal,(yyvsp[(2) - (2)].string),(yyvsp[(2) - (2)].string));}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 157 "sintatico.y"
    {printf("\n\n%s", strCuadruplos);}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 158 "sintatico.y"
    {alcanceDireccion=1;/*global*/}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 170 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); /*printf("===========tipo: %i\n", tipoOp);*/ }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 171 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); /*printf("===========tipo: %i\n", tipoOp);*/ }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 172 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); /*printf("===========tipo: %i\n", tipoOp);*/}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 173 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); /*printf("===========tipo: %i\n", tipoOp);*/}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 201 "sintatico.y"
    {insert(&tablaGlobal,(yyvsp[(4) - (5)].string),(yyvsp[(4) - (5)].string),tipoOp,generarDireccion(tipoOp,1));}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 206 "sintatico.y"
    {alcanceDireccion=2;/*local*/}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 210 "sintatico.y"
    {insert(&tablaLocal,(yyvsp[(4) - (5)].string),(yyvsp[(4) - (5)].string),tipoOp,generarDireccion(tipoOp,2));}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 221 "sintatico.y"
    {int tipoId = getType(&tablaGlobal,(yyvsp[(1) - (2)].string));
			    if(tipoId==0)
				tipoId = getType(&tablaLocal,(yyvsp[(1) - (2)].string));
			    int direccionVirtual = getDirection(&tablaGlobal,(yyvsp[(1) - (2)].string));
			    if(direccionVirtual==0)
				direccionVirtual = getDirection(&tablaLocal,(yyvsp[(1) - (2)].string));
			    push(&pilaOperadores, (yyvsp[(1) - (2)].string), tipoId, direccionVirtual); 
				printf("\n\nHIzo pussh: tipo %i, direcicn %i\n\n",tipoId,direccionVirtual);}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 229 "sintatico.y"
    { push(&pilaOperando, (yyvsp[(4) - (4)].string), -1, -1);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 230 "sintatico.y"
    {checarOperando3();}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 233 "sintatico.y"
    {hacerPush=0; /*no meter a la pila las EXP de los arreglos*/}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 233 "sintatico.y"
    {hacerPush=1;}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 243 "sintatico.y"
    {secuenciaIf1();}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 243 "sintatico.y"
    {secuenciaIf2();}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 245 "sintatico.y"
    {secuenciaElse();}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 250 "sintatico.y"
    {secuenciaWhile1();}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 250 "sintatico.y"
    {secuenciaWhile2();}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 250 "sintatico.y"
    {secuenciaWhile3();}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 254 "sintatico.y"
    {insertProc(&tblProc,&tablaGlobal,(yyvsp[(3) - (12)].string),(yyvsp[(3) - (12)].string));}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 261 "sintatico.y"
    {insert(&tablaLocal,(yyvsp[(2) - (3)].string),(yyvsp[(2) - (3)].string),tipoOp,generarDireccion(tipoOp,2));}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 280 "sintatico.y"
    {  checarOperando3();   }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 281 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 282 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 283 "sintatico.y"
    {push(&pilaOperando, (yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 284 "sintatico.y"
    {char* str = (yyvsp[(1) - (2)].string);
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, (yyvsp[(2) - (2)].string) ); 
				      push(&pilaOperando, str, -1, -1);}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 291 "sintatico.y"
    {  checarOperando2();   }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 294 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 295 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 297 "sintatico.y"
    { checarOperando1();   }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 300 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 301 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 303 "sintatico.y"
    { push(&pilaOperando,(yyvsp[(1) - (1)].string),-1,-1); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 303 "sintatico.y"
    {pop(&pilaOperando);}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 305 "sintatico.y"
    {int tipoId = getType(&tbl,(yyvsp[(1) - (2)].string));
				int direccionVirtual = generarDireccion(tipoId, alcanceDireccion);
				if(hacerPush==1) push(&pilaOperadores, (yyvsp[(1) - (2)].string), tipoId, direccionVirtual); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 311 "sintatico.y"
    {if(hacerPush==1) push(&pilaOperadores, (yyvsp[(1) - (1)].string), 3, generarDireccion(3, alcanceDireccion));}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 312 "sintatico.y"
    {if(hacerPush==1) push(&pilaOperadores, (yyvsp[(1) - (1)].string), 1, generarDireccion(1, alcanceDireccion));}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 313 "sintatico.y"
    {if(hacerPush==1) push(&pilaOperadores, (yyvsp[(1) - (1)].string), 2, generarDireccion(2, alcanceDireccion));}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 314 "sintatico.y"
    {if(hacerPush==1) push(&pilaOperadores, (yyvsp[(1) - (1)].string), 4, generarDireccion(4, alcanceDireccion));}
    break;



/* Line 1806 of yacc.c  */
#line 2048 "sintatico.tab.c"
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
#line 350 "sintatico.y"

int main()
{
	inicializarMatriz();
	inicializarVectores();

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
		//printf(">>>>>>>>>>>>>>>>>>ALCANCE GLOBAL\n");
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
		//printf(">>>>>>>>>>>>>>>>>>ALCANCE LOCAL\n");
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
		//printf(">>>>>>>>>>>>>>>>>>ALCANCE TEMPORAL\n");
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
		printf("--------------Semantica No Valida!!\n");
		return 0;	//Error: no se puede hacer operacion de esos tipos
	}
	else {
		printf("--------------Semantica Valida!! tipo: %i. \n " , matrizSemantica[op1-1][op2-1][op]);
		return matrizSemantica[op1-1][op2-1][op];
	}
	
}

void checarOperando1(){
	ptr op= malloc (sizeof(p_Nodo)); 
	ptr operador1= malloc (sizeof(p_Nodo)); 
	ptr operador2= malloc (sizeof(p_Nodo)); 
	int semanticaValida=-1;
	int numOp=-1;
	int dirTemp=0;
	int res=0;
	char nombreT[10];

	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='*' || *pilaOperando->valor=='/' ){ 

				if(*pilaOperando->valor=='*' ) numOp=2;
				else if (*pilaOperando->valor=='/' ) numOp=3;

				//printf("Operandoooo  %c",*pilaOperando->valor);
				pop(&pilaOperando);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				operador2->direccion = pilaOperadores->direccion; 
				pop(&pilaOperadores);

				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				operador1->direccion = pilaOperadores->direccion; 
				pop(&pilaOperadores);

				//printf("TIPO op1: %i, direccion: %i | op2: %i, direccion:%i \n", operador1->tipo, operador1->direccion, operador2->tipo, operador2->direccion);
				
			    sprintf(nombreT, "t%i", contT++);
			   
				semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
				res = generarDireccion(semanticaValida,3); //3:direccion temporal
				
				insert(&tablaTemporal,nombreT,nombreT,semanticaValida,res);

				generarCuadruplo(numOp ,operador1->direccion, operador2->direccion, res);
				push(&pilaOperadores,nombreT,semanticaValida,res);//3: direccion temporal
				
			}
		}
	}

}

	
void checarOperando2(){

	ptr op= malloc (sizeof(p_Nodo)); 
	ptr operador1= malloc (sizeof(p_Nodo)); 
	ptr operador2= malloc (sizeof(p_Nodo)); 
	int semanticaValida=-1;
	int numOp=-1;
	int dirTemp=0;
	int res=0;
	char nombreT[10];

	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='+' || *pilaOperando->valor=='-' ){ 

				if(*pilaOperando->valor=='+' ) numOp=0;
				else if (*pilaOperando->valor=='-' ) numOp=1;

				/*printf("Operandoooo  %c",*pilaOperando->valor);*/
				pop(&pilaOperando);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				operador2->direccion = pilaOperadores->direccion; 
				pop(&pilaOperadores);

				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				operador1->direccion = pilaOperadores->direccion; 
				pop(&pilaOperadores);

				//printf("TIPO op1: %i, direccion: %i | op2: %i, direccion:%i \n", operador1->tipo, operador1->direccion, operador2->tipo, operador2->direccion);
				
			    	sprintf(nombreT, "t%i", contT++);
			
				semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
				res = generarDireccion(semanticaValida,3); //3:direccion temporal

				insert(&tablaTemporal,nombreT,nombreT,semanticaValida,res);

				generarCuadruplo(numOp ,operador1->direccion, operador2->direccion, res);
				push(&pilaOperadores,nombreT,semanticaValida,res);//3: direccion temporal
				
			}
		}
	}

}


void checarOperando3(char *operando){
	ptr op= malloc (sizeof(p_Nodo)); 
	ptr operador1= malloc (sizeof(p_Nodo)); 
	ptr operador2= malloc (sizeof(p_Nodo)); 
	int semanticaValida=-1;
	int numOp=-1;
	int res=0;
	char nombreT[10];

	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='>'||*pilaOperando->valor=='<'||*pilaOperando->valor=='='||pilaOperando->valor=="=="||pilaOperando->valor=="!=" ){ 

				if(*pilaOperando->valor=='=' ) {numOp=10; printf("\n\nIGUAAL\n\n");} 
				else if (pilaOperando->valor=="!=") numOp=5;
				else if (*pilaOperando->valor=='>') numOp=6;
				else if (*pilaOperando->valor=='<') numOp=7;
				else if (pilaOperando->valor=="==") numOp=4;

				if(numOp==10){
					pop(&pilaOperando);
					
					operador2->valor = pilaOperadores->valor;
					operador2->tipo = pilaOperadores->tipo; 
					operador2->direccion = pilaOperadores->direccion;
					pop(&pilaOperadores);
					
					operador1->valor = pilaOperadores->valor;
					operador1->tipo = pilaOperadores->tipo; 
					operador1->direccion = pilaOperadores->direccion;
					pop(&pilaOperadores);
					
					imprimirPila(pilaOperadores);
					sprintf(nombreT, "t%i", contT++);

					semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
					res = operador1->direccion; //3:direccion temporal

					insert(&tablaTemporal,nombreT,nombreT,semanticaValida,res);

					generarCuadruplo(numOp ,operador2->direccion, -1, res);
					//printf("operando3 semantica %i\n", semanticaValida);
					push(&pilaOperadores,nombreT,semanticaValida,res);//3: direccion temporal
				}
				
				else{
					pop(&pilaOperando);

					operador1->valor = pilaOperadores->valor;
					operador1->tipo = pilaOperadores->tipo; 
					operador1->direccion = pilaOperadores->direccion;
					pop(&pilaOperadores);

					operador2->valor = pilaOperadores->valor;
					operador2->tipo = pilaOperadores->tipo; 
					operador2->direccion = pilaOperadores->direccion;
					pop(&pilaOperadores);

					//printf("TIPO op1: %i , op2: %i \n", operador1->tipo, operador2->tipo);
					//push(&pilaOperadores,"t",1, 3);//3: direccion temporal
				
					sprintf(nombreT, "t%i", contT++);

					semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
					res = generarDireccion(semanticaValida,3); //3:direccion temporal

					insert(&tablaTemporal,nombreT,nombreT,semanticaValida,res);

					generarCuadruplo(numOp ,operador1->direccion, operador2->direccion, res);
					//printf("operando3 semantica %i\n", semanticaValida);
					push(&pilaOperadores,nombreT,semanticaValida,res);//3: direccion temporal
				}
			}
		}
	}
}


void generarCuadruplo(int numOp ,int tipo1, int tipo2, int res){
	
	//Reajustar el tamano de los vectores 
	vectorTemporal=realloc(vectorOp,(contS+2)*sizeof(int));
	if(vectorTemporal != NULL) vectorOp = vectorTemporal;
	vectorTemporal=realloc(vectorOp1,(contS+2)*sizeof(int));
	if(vectorTemporal != NULL) vectorOp1 = vectorTemporal;
	vectorTemporal=realloc(vectorOp2,(contS+2)*sizeof(int));
	if(vectorTemporal != NULL) vectorOp2 = vectorTemporal;
	vectorTemporal=realloc(vectorRes,(contS+2)*sizeof(int));
	if(vectorTemporal != NULL) vectorRes = vectorTemporal;
	
		
	/*El cuadruplo se guarda en la casilla del contador que le toco.*/
	vectorOp[contS]=numOp;
	vectorOp1[contS]=tipo1;
	vectorOp2[contS]=tipo2;
	vectorRes[contS]=res;
	
	/*imprimir para checar si se meten los valores*/
	printf("\nCuadruplo # %i ---(%i,%i,%i,%i)\n", contS,vectorOp[contS],vectorOp1[contS],vectorOp2[contS],vectorRes[contS]);
	
	char intemporal[25];

	sprintf(intemporal, "Cuadruplo # %i --- %i -", contS,numOp);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i - ", tipo1);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i - ", tipo2);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i\n", res);
	strcat(strCuadruplos, intemporal); 

	contS++;/*suma contador de saltos*/
}

void secuenciaIf1(){
	
	ptr aux= malloc (sizeof(p_Nodo)); 
	aux->tipo = pilaOperadores->tipo;
	aux->direccion = pilaOperadores->direccion;

	if(aux->tipo != 4)//dif de boolean
		printf("Error semantico!! tipo: %i, %i\n", aux->tipo, aux->direccion);
	else		
	{	
		//pop(&pilaTipos);
		ptr resultado= malloc (sizeof(p_Nodo)); 
		resultado->direccion = pilaOperadores->direccion;
		pop(&pilaOperadores);  //ultima Dirección de la pila, la cual tiene el resultado del estatuto
		generarCuadruplo(12, resultado->direccion, -1,-1);// gotoF,12
		push(&pilaSaltos, "t", -1, contS-1);	//usar el tipo direccion como contador
	}
	
}
void secuenciaIf2(){
	
	ptr fin= malloc (sizeof(p_Nodo)); 
	//usar direccion como el salto
	fin->direccion = pilaSaltos->direccion; 	
	pop(&pilaSaltos);
	rellenar(fin->direccion,contS);
	
}
void secuenciaElse(){
	
	generarCuadruplo(11 ,-1,-1,-1); // goto ,11
	ptr falso=malloc(sizeof(p_Nodo));
	falso->direccion=pilaSaltos->direccion;

	pop(&pilaSaltos);
	rellenar(falso->direccion,contS);
	push(&pilaSaltos, "t", -1, contS-1);
		

}
void secuenciaWhile1(){
	
	push(&pilaSaltos, "t", -1, contS-1);
	
}
void secuenciaWhile2(){
	
	ptr aux= malloc (sizeof(p_Nodo)); 
	aux->tipo = pilaTipos->tipo;

	if(aux->tipo != 4)//dif de boolean
		printf("Error semantico!!");
	else{	
		ptr resultado= malloc (sizeof(p_Nodo)); 
		resultado->direccion = pilaOperadores->direccion;
		pop(&pilaOperadores);  //ultima Dirección de la pila, la cual tiene el resultado del estatuto
		
		generarCuadruplo(12, resultado->direccion, -1, -1); //12 : GoToF
		push(&pilaSaltos, "t", -1, contS-1);
		}
	
}

void secuenciaWhile3(){
	
	ptr falso= malloc (sizeof(p_Nodo)); 
	falso->direccion = pilaTipos->direccion;
	pop(&pilaSaltos);

	ptr retorno= malloc (sizeof(p_Nodo)); 
	retorno->direccion = pilaTipos->direccion;
	pop(&pilaSaltos); 

	generarCuadruplo(11, retorno->direccion,-1,-1); //11 : Go To
	rellenar(falso->direccion,contS);
	
}
	
void rellenar(int goTo, int contador){
	/* poner numeros en espacios en blanco anteriores   */
	vectorRes[goTo]=contador;
	//printf("~~~~~GO TO~~[%i]~~  contador ~~~ : %i\n", goTo, contador);
	printf("\nCuadruplo # %i ---(%i,%i,%i,%i)\n", goTo,vectorOp[goTo],vectorOp1[goTo],vectorOp2[goTo],vectorRes[goTo]);
	char intemporal[25];

	sprintf(intemporal, "Cuadruplo # %i --- %i -", goTo,vectorOp[goTo]);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i - ", vectorOp1[goTo]);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i - ", vectorOp2[goTo]);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i\n", vectorRes[goTo]);
	strcat(strCuadruplos, intemporal); 

}

void inicializarVectores(){
	 vectorTemporal=(int*) malloc(sizeof(int));
	 vectorOp=(int*) malloc(sizeof(int));
	 vectorOp1=(int*) malloc(sizeof(int));
	 vectorOp2=(int*) malloc(sizeof(int));
	 vectorRes=(int*) malloc(sizeof(int));
}

void inicializarMatriz(){
	//Tipos: entero: 1, doble:2, texto:3, booleano:4	

	//Z=0 (SUMA)
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

	//Z=4 (IGUAL IGUAL)
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


