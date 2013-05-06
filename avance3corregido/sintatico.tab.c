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
int checarSemantica(int op, int op1, int op2);
int generarDireccion(int tipo, int alcance);
//Funciones para generar cuadruplos
void checarOperando1();
void checarOperando2(); 
void checarOperando3(); 
void generarImprimir();
void generarLectura();
void generarMain();
void llenarMain(); //llenar el cuadruplo del main
void generarRetorno();
void rellenar(int goTo, int contador);
void generarCuadruplo(int numOp ,int tipo1, int tipo2, int res);
void generarEra(int tamano);
void generarParametro();
void generarGoSub();
void generarEnd();

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
char strCuadruplos[2000];
char strDirecciones[2000];
char nombreFuncion[20];

//contadores 

int contEnteroGlobal=0;
int contEnteroLocal=0;
int contEnteroTemp=0;
int contEnteroConstante=0;

int contDobleGlobal=0;
int contDobleLocal=0;
int contDobleTemp=0;
int contDobleConstante=0;

int contTextoGlobal=0;
int contTextoLocal=0;
int contTextoTemp=0;
int contTextoConstante=0;

int contBooleanoGlobal=0;
int contBooleanoLocal=0;
int contBooleanoTemp=0;
int contBooleanoConstante=0;

//Direcciones Virtuales
int alcanceDireccion=0; // 1: global, 2: local, 3: temp, 5:constante

int direccionEnteroGlobal=10000;
int direccionEnteroLocal=11000;
int direccionEnteroTemp=12000;
int direccionEnteroConstante=13000;


int direccionDobleGlobal=20000;
int direccionDobleLocal=21000;
int direccionDobleTemp=22000;
int direccionDobleConstante=23000;

int direccionTextoGlobal=30000;
int direccionTextoLocal=31000;
int direccionTextoTemp=32000;
int direccionTextoConstante=33000;

int direccionBooleanoGlobal=40000;
int direccionBooleanoLocal=41000;
int direccionBooleanoTemp=42000;
int direccionBooleanoConstante=43000;

//Tabla de vatiables y procedimientos
struct StrHashTable tbl = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTableProc tblProc = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashNodeProc nodeProc;


struct StrHashTable tablaGlobal = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTable tablaLocal = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTable tablaTemporal = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTable tablaConstantes = {{0},NULL,NULL,foo_strhash,strcmp};

int tipoOp=-1;
int numeroParametros=0;
int numeroFunciones =0;
int numeroVarLocales = 0;
int numeroIntLocales = 0;
int numeroFloatLocales = 0;
int numeroStringLocales = 0;
int idProc;
int apuntadorParametro;

int arg;
int tipoArg;

struct DimensionArreglo {
    int numeroDimension;
    int cantidad;
    int m;
    struct DimensionArreglo *next;
};

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

FILE *file; 
int i; //contador
int contadorConstantes =0;



/* Line 268 of yacc.c  */
#line 215 "sintatico.tab.c"

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
     principal = 259,
     si = 260,
     no = 261,
     imprimir = 262,
     leer = 263,
     crear = 264,
     mientras = 265,
     hacer = 266,
     funcion = 267,
     neutral = 268,
     regresar = 269,
     id = 270,
     ctetexto = 271,
     cteentero = 272,
     ctedecimal = 273,
     ctebooleano = 274,
     entero = 275,
     decimal = 276,
     texto = 277,
     booleano = 278,
     igual = 279,
     diferente = 280,
     mas = 281,
     menos = 282,
     multiplicacion = 283,
     division = 284,
     mayor = 285,
     menor = 286,
     and = 287,
     or = 288,
     ptocoma = 289,
     dospuntos = 290,
     punto = 291,
     coma = 292,
     parentesisa = 293,
     parentesisc = 294,
     llavea = 295,
     llavec = 296,
     corchetea = 297,
     corchetec = 298,
     dibujarFigura = 299,
     borrarFigura = 300,
     girarIzquierda = 301,
     girarDerecha = 302,
     mover = 303,
     obtenerPosicion = 304,
     hablar = 305,
     obtenerAltura = 306,
     obtenerAnchura = 307,
     cambiarAltura = 308,
     cambiarAnchura = 309,
     colorFondo = 310,
     rojo = 311,
     azul = 312,
     verde = 313,
     carro = 314,
     persona = 315,
     perro = 316,
     gato = 317,
     verdadero = 318,
     falso = 319
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 145 "sintatico.y"
int cteint; float ctefloat; int cteboolean; char *string;


/* Line 293 of yacc.c  */
#line 319 "sintatico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 331 "sintatico.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNRULES -- Number of states.  */
#define YYNSTATES  288

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    16,    17,    21,    23,    24,
      27,    29,    30,    33,    35,    36,    38,    40,    42,    44,
      45,    53,    56,    58,    59,    61,    63,    65,    67,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    89,
      91,    93,    95,    97,   103,   105,   106,   107,   111,   113,
     114,   120,   122,   123,   128,   132,   133,   134,   135,   143,
     145,   147,   148,   151,   152,   157,   161,   162,   168,   172,
     173,   183,   184,   190,   191,   192,   193,   204,   205,   206,
     207,   223,   225,   227,   228,   230,   231,   236,   237,   240,
     241,   248,   249,   253,   254,   258,   259,   262,   263,   266,
     268,   270,   273,   274,   277,   279,   281,   283,   286,   287,
     291,   292,   295,   297,   299,   300,   304,   305,   308,   310,
     312,   313,   318,   320,   323,   325,   327,   329,   331,   339,
     341,   343,   345,   347,   353,   361,   371,   377,   385,   393,
     399,   405,   413,   421,   427,   429,   431
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      66,     0,    -1,    -1,    -1,    67,     3,    15,    68,    40,
      69,    74,    72,    77,    41,    -1,    -1,    70,    83,    71,
      -1,    69,    -1,    -1,   109,    73,    -1,    72,    -1,    -1,
      92,    75,    -1,    74,    -1,    -1,    22,    -1,    20,    -1,
      21,    -1,    23,    -1,    -1,     4,    78,    38,    39,    40,
      79,    41,    -1,    81,    80,    -1,    79,    -1,    -1,    92,
      -1,   102,    -1,   100,    -1,   101,    -1,   106,    -1,    82,
      -1,   118,    -1,   141,    -1,   143,    -1,   144,    -1,   145,
      -1,   148,    -1,   147,    -1,   149,    -1,   151,    -1,   150,
      -1,   152,    -1,   153,    -1,   146,    -1,     9,    76,    15,
      84,    34,    -1,    90,    -1,    -1,    -1,    86,    88,    87,
      -1,    85,    -1,    -1,     9,    76,    15,    89,    34,    -1,
      90,    -1,    -1,    42,    17,    43,    91,    -1,    42,    17,
      43,    -1,    -1,    -1,    -1,    15,    96,    93,    24,    94,
      95,    34,    -1,   101,    -1,   130,    -1,    -1,    97,    98,
      -1,    -1,    42,   130,    43,    99,    -1,    42,   130,    43,
      -1,    -1,     7,    38,   130,    39,    34,    -1,     8,    38,
      39,    -1,    -1,     5,    38,   124,    39,   103,    40,    79,
      41,   104,    -1,    -1,     6,   105,    40,    79,    41,    -1,
      -1,    -1,    -1,    10,   107,    38,   124,    39,    11,   108,
      40,    79,    41,    -1,    -1,    -1,    -1,    12,   113,    15,
     110,    38,   114,    39,   111,    40,    85,   112,    79,    14,
     130,    41,    -1,    76,    -1,    13,    -1,    -1,   115,    -1,
      -1,    76,    15,   116,   117,    -1,    -1,    37,   115,    -1,
      -1,    15,   119,    38,   120,    39,    34,    -1,    -1,   130,
     121,   122,    -1,    -1,    37,   123,   120,    -1,    -1,   127,
     125,    -1,    -1,   126,   127,    -1,    32,    -1,    33,    -1,
     130,   128,    -1,    -1,   129,   130,    -1,    31,    -1,    30,
      -1,    24,    -1,    25,    24,    -1,    -1,   134,   131,   132,
      -1,    -1,   133,   130,    -1,    26,    -1,    27,    -1,    -1,
     138,   135,   136,    -1,    -1,   137,   134,    -1,    28,    -1,
      29,    -1,    -1,    38,   139,   127,    39,    -1,   140,    -1,
      15,    96,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    44,    38,   142,    37,    15,    39,    34,    -1,    61,
      -1,    60,    -1,    62,    -1,    59,    -1,    45,    38,    15,
      39,    34,    -1,    50,    38,    15,    37,   130,    39,    34,
      -1,    48,    38,    15,    37,   130,    37,   130,    39,    34,
      -1,    49,    38,    15,    39,    34,    -1,    47,    38,    15,
      37,   130,    39,    34,    -1,    46,    38,    15,    37,   130,
      39,    34,    -1,    51,    38,    15,    39,    34,    -1,    52,
      38,    15,    39,    34,    -1,    53,    38,    15,    37,   130,
      39,    34,    -1,    54,    38,    15,    37,   130,    39,    34,
      -1,    55,    38,   154,    39,    34,    -1,    56,    -1,    57,
      -1,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   221,   221,   222,   221,   224,   224,   225,   226,   227,
     228,   229,   231,   232,   233,   236,   237,   238,   239,   241,
     241,   243,   244,   245,   247,   248,   249,   250,   251,   252,
     253,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   269,   270,   271,   274,   274,   275,   276,
     278,   280,   281,   284,   285,   286,   289,   297,   289,   299,
     300,   301,   301,   302,   303,   304,   305,   307,   309,   311,
     311,   313,   313,   314,   318,   318,   318,   320,   328,   331,
     320,   337,   338,   339,   340,   341,   341,   350,   351,   353,
     353,   361,   361,   362,   362,   363,   366,   367,   368,   369,
     370,   373,   374,   375,   376,   377,   378,   379,   386,   386,
     387,   388,   389,   390,   392,   392,   393,   394,   395,   396,
     398,   398,   399,   400,   406,   419,   432,   445,   459,   461,
     462,   463,   464,   466,   468,   471,   473,   475,   477,   479,
     481,   483,   485,   487,   489,   490,   491
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "programa", "principal", "si", "no",
  "imprimir", "leer", "crear", "mientras", "hacer", "funcion", "neutral",
  "regresar", "id", "ctetexto", "cteentero", "ctedecimal", "ctebooleano",
  "entero", "decimal", "texto", "booleano", "igual", "diferente", "mas",
  "menos", "multiplicacion", "division", "mayor", "menor", "and", "or",
  "ptocoma", "dospuntos", "punto", "coma", "parentesisa", "parentesisc",
  "llavea", "llavec", "corchetea", "corchetec", "dibujarFigura",
  "borrarFigura", "girarIzquierda", "girarDerecha", "mover",
  "obtenerPosicion", "hablar", "obtenerAltura", "obtenerAnchura",
  "cambiarAltura", "cambiarAnchura", "colorFondo", "rojo", "azul", "verde",
  "carro", "persona", "perro", "gato", "verdadero", "falso", "$accept",
  "PROGRAMA", "$@1", "$@2", "PROGRAMA1", "$@3", "PROGRAMA12", "PROGRAMA2",
  "PROGRAMA22", "PROGRAMASIG", "PROGRAMASIG2", "TIPO", "PRINCIPAL", "$@4",
  "BLOQUE", "BLOQUE1", "ESTATUTO", "FUNCIONESPECIAL", "DECLARACION",
  "DECLARACION2", "DECLARACIONFUNCIONCICLO", "$@5",
  "DECLARACIONFUNCIONCICLO2", "DECLARACIONFUNCION", "DECLARACIONFUNCION2",
  "ARREGLOS", "ARREGLOS2", "ASIGNACION", "$@6", "$@7", "ASIGNACION3",
  "ASIGNACION2", "$@8", "ARREGLOSASIG", "ARREGLOSASIG2", "ESCRITURA",
  "LECTURA", "CONDICION", "$@9", "CONDICION2", "$@10", "CICLO", "$@11",
  "$@12", "CREARFUNCION", "$@13", "$@14", "$@15", "CREARFUNCION2",
  "CREARFUNCION3", "CREARFUNCION4", "$@16", "CREARFUNCION5",
  "LLAMARFUNCION", "$@17", "LLAMARFUNCION2", "$@18", "LLAMARFUNCION3",
  "$@19", "SUPEREXPRESION", "SUPEREXPRESION2", "SUPEREXPRESION3",
  "EXPRESION", "EXPRESION2", "EXPRESION3", "EXP", "$@20", "EXP2", "EXP3",
  "TERMINO", "$@21", "TERMINO2", "TERMINO3", "FACTOR", "$@22", "VARCTE",
  "DIBUJARFIGURA", "FIGURA", "BORRARFIGURA", "HABLAR", "MOVER",
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
     315,   316,   317,   318,   319
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    67,    68,    66,    70,    69,    71,    71,    72,
      73,    73,    74,    75,    75,    76,    76,    76,    76,    78,
      77,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    84,    84,    86,    85,    87,    87,
      88,    89,    89,    90,    91,    91,    93,    94,    92,    95,
      95,    97,    96,    96,    98,    99,    99,   100,   101,   103,
     102,   105,   104,   104,   107,   108,   106,   110,   111,   112,
     109,   113,   113,   114,   114,   116,   115,   117,   117,   119,
     118,   121,   120,   123,   122,   122,   124,   125,   125,   126,
     126,   127,   128,   128,   129,   129,   129,   129,   131,   130,
     132,   132,   133,   133,   135,   134,   136,   136,   137,   137,
     139,   138,   138,   138,   140,   140,   140,   140,   141,   142,
     142,   142,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   154,   154
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    10,     0,     3,     1,     0,     2,
       1,     0,     2,     1,     0,     1,     1,     1,     1,     0,
       7,     2,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     0,     0,     3,     1,     0,
       5,     1,     0,     4,     3,     0,     0,     0,     7,     1,
       1,     0,     2,     0,     4,     3,     0,     5,     3,     0,
       9,     0,     5,     0,     0,     0,    10,     0,     0,     0,
      15,     1,     1,     0,     1,     0,     4,     0,     2,     0,
       6,     0,     3,     0,     3,     0,     2,     0,     2,     1,
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
       2,     0,     0,     1,     0,     3,     0,     5,     0,     0,
      61,     0,    14,     0,     5,    56,     0,     0,     0,    11,
      13,    12,    16,    17,    15,    18,     0,     7,     6,     0,
       0,    62,    82,    81,     0,    19,     0,    10,     9,    45,
      57,    63,   124,   125,   126,   127,   120,     0,   108,   114,
     122,    77,     0,     4,     0,     0,    44,     0,   123,     0,
      66,   110,   116,     0,     0,     0,    43,     0,     0,    59,
      60,     0,   102,     0,    64,   112,   113,   109,     0,   118,
     119,   115,     0,    83,     0,    55,     0,    58,   121,   106,
       0,   105,   104,   101,     0,     0,   111,   117,     0,     0,
      84,     0,     0,    53,    68,   107,   103,    65,    85,    78,
       0,     0,    74,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    29,    24,
      26,    27,    25,    28,    30,    31,    32,    33,    34,    42,
      36,    35,    37,    39,    38,    40,    41,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    22,    21,    54,
       0,    86,    46,     0,    97,     0,     0,     0,   132,   130,
     129,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,   146,     0,    88,    79,     0,
      69,    99,   100,    96,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,    98,    67,     0,     0,    95,
       0,   133,     0,     0,     0,   136,     0,   139,   140,     0,
       0,   143,     0,     0,    48,    47,     0,    75,    90,    93,
      92,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,   128,   138,   137,     0,   134,   141,   142,
       0,     0,    51,    73,     0,    94,     0,    80,    50,    71,
      70,     0,   135,     0,    76,     0,     0,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     8,     9,    28,    18,    38,    11,
      21,    98,    36,    52,   126,   168,   127,   128,    14,    55,
     198,   199,   245,   223,   271,    56,   103,   129,    29,    57,
      68,    15,    16,    31,    74,   130,   131,   132,   224,   280,
     283,   133,   152,   261,    19,    63,   149,   221,    34,    99,
     100,   148,   171,   134,   153,   207,   229,   250,   262,   173,
     203,   204,   174,    93,    94,    72,    61,    77,    78,    48,
      62,    81,    82,    49,    59,    50,   135,   182,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   196
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -151
static const yytype_int16 yypact[] =
{
    -151,    32,     3,  -151,    22,  -151,     7,  -151,    52,    65,
      51,    64,    52,     8,    62,  -151,    36,    13,    75,    64,
    -151,  -151,  -151,  -151,  -151,  -151,    66,  -151,  -151,    56,
      23,  -151,  -151,  -151,    67,  -151,    42,  -151,  -151,    43,
    -151,    44,  -151,  -151,  -151,  -151,  -151,    41,  -151,  -151,
    -151,  -151,    49,  -151,    71,    55,  -151,     6,  -151,    23,
      48,   -18,    17,    53,    54,    57,  -151,    58,    60,  -151,
    -151,    59,    38,    23,  -151,  -151,  -151,  -151,    23,  -151,
    -151,  -151,    23,     8,    61,    50,    63,  -151,  -151,  -151,
      79,  -151,  -151,  -151,    23,    68,  -151,  -151,    80,    69,
    -151,     5,    82,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
      72,    74,  -151,   -22,    76,    77,    78,    81,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     5,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,    70,    83,    95,
      23,    23,    94,    98,    11,   102,   103,   116,   118,   122,
     123,   124,   125,   126,   127,   -39,  -151,  -151,  -151,  -151,
       8,  -151,  -151,   104,    33,   105,    23,    23,  -151,  -151,
    -151,  -151,   108,   107,   111,   114,   115,   117,   120,   119,
     121,   128,   129,  -151,  -151,  -151,   130,  -151,  -151,    96,
    -151,  -151,  -151,  -151,    23,    73,   131,   132,  -151,   138,
     133,    23,    23,    23,   134,    23,   139,   140,    23,    23,
     141,     5,     8,    97,   136,  -151,  -151,   143,   144,   135,
     145,  -151,   147,   148,   142,  -151,   151,  -151,  -151,   152,
     153,  -151,   149,   162,  -151,  -151,     5,  -151,  -151,  -151,
    -151,   146,   159,   160,    23,   161,   163,   164,    23,    43,
     155,   165,    23,  -151,  -151,  -151,   167,  -151,  -151,  -151,
     158,   166,  -151,   156,     5,  -151,   168,  -151,  -151,  -151,
    -151,   170,  -151,   169,  -151,     5,   171,  -151
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,  -151,   150,  -151,  -151,   182,  -151,   191,
    -151,   -12,  -151,  -151,  -124,  -151,  -151,  -151,  -151,  -151,
    -119,  -151,  -151,  -151,  -151,  -150,  -151,    -1,  -151,  -151,
    -151,   172,  -151,  -151,  -151,  -151,   157,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
     -15,  -151,  -151,  -151,  -151,  -103,  -151,  -151,  -151,    28,
    -151,  -151,   -55,  -151,  -151,   -30,  -151,  -151,  -151,   137,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -90
static const yytype_int16 yytable[] =
{
      47,    26,   -63,   167,    71,    33,     4,    12,    75,    76,
     110,    12,   111,    67,    67,   112,   -89,   193,   194,   195,
     113,    41,    42,    43,    44,    45,    32,    70,    22,    23,
      24,    25,     3,    22,    23,    24,    25,     5,    41,    42,
      43,    44,    45,    95,    46,    79,    80,     7,    96,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    46,    89,    90,   106,   201,   202,    10,    91,    92,
     178,   179,   180,   181,    13,   -63,    17,    -8,    30,    35,
      40,    39,    51,    53,    60,    54,   -61,    64,    65,    66,
      73,    83,   102,    84,    87,   108,    86,   242,    88,   147,
      85,   101,   104,   105,   244,   222,   -46,   226,   109,   272,
     150,   107,   151,   169,   154,   155,   156,   183,   184,   157,
     170,   175,   260,   158,   159,   160,   161,   162,   163,   164,
     165,   185,   176,   186,   166,   172,   177,   187,   188,   189,
     190,   191,   192,   200,   205,   209,   210,   208,   211,   225,
     281,   212,   213,   230,   247,   197,   214,   215,   216,   275,
     217,   286,   279,   258,    27,   218,   219,   231,   235,   220,
     227,   228,   249,   237,   238,   241,   246,   259,   248,   254,
     263,   232,   233,   234,   251,   236,   252,   253,   239,   240,
     255,   256,   257,   264,   265,   267,   273,   268,   269,   277,
     278,    37,   282,    20,   206,   274,   276,     0,     0,   285,
     243,   284,   287,    58,    69,     0,     0,     0,     0,    97,
       0,     0,     0,     0,   266,     0,     0,     0,   270,     0,
       0,     0,   208
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-151))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      30,    13,    24,   127,    59,    17,     3,     8,    26,    27,
       5,    12,     7,     8,     8,    10,    38,    56,    57,    58,
      15,    15,    16,    17,    18,    19,    13,    57,    20,    21,
      22,    23,     0,    20,    21,    22,    23,    15,    15,    16,
      17,    18,    19,    73,    38,    28,    29,    40,    78,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    38,    24,    25,    94,    32,    33,    15,    30,    31,
      59,    60,    61,    62,     9,    24,    12,    15,    42,     4,
      24,    15,    15,    41,    43,    42,    42,    38,    17,    34,
      42,    38,    42,    39,    34,    15,    38,   221,    39,    17,
      43,    40,    39,    24,   223,     9,     9,    34,    39,   259,
      38,    43,    38,    43,    38,    38,    38,    15,    15,    38,
      37,   151,   246,    38,    38,    38,    38,    38,    38,    38,
      38,    15,    38,    15,    41,    40,    38,    15,    15,    15,
      15,    15,    15,    39,    39,    37,    39,   177,    37,   204,
     274,    37,    37,    15,    11,   170,    39,    37,    39,   262,
      39,   285,     6,    14,    14,    37,    37,    34,    34,    39,
      39,    39,    37,    34,    34,    34,    40,    15,    34,    37,
      34,   211,   212,   213,    39,   215,    39,    39,   218,   219,
      39,    39,    39,    34,    34,    34,    41,    34,    34,    41,
      34,    19,    34,    12,   176,    40,    39,    -1,    -1,    40,
     222,    41,    41,    41,    57,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,   258,    -1,
      -1,    -1,   262
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,     3,    15,    68,    40,    69,    70,
      15,    74,    92,     9,    83,    96,    97,    12,    72,   109,
      74,    75,    20,    21,    22,    23,    76,    69,    71,    93,
      42,    98,    13,    76,   113,     4,    77,    72,    73,    15,
      24,    15,    16,    17,    18,    19,    38,   130,   134,   138,
     140,    15,    78,    41,    42,    84,    90,    94,    96,   139,
      43,   131,   135,   110,    38,    17,    34,     8,    95,   101,
     130,   127,   130,    42,    99,    26,    27,   132,   133,    28,
      29,   136,   137,    38,    39,    43,    38,    34,    39,    24,
      25,    30,    31,   128,   129,   130,   130,   134,    76,   114,
     115,    40,    42,    91,    39,    24,   130,    43,    15,    39,
       5,     7,    10,    15,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    79,    81,    82,    92,
     100,   101,   102,   106,   118,   141,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    17,   116,   111,
      38,    38,   107,   119,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    41,    79,    80,    43,
      37,   117,    40,   124,   127,   130,    38,    38,    59,    60,
      61,    62,   142,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    56,    57,    58,   154,   115,    85,    86,
      39,    32,    33,   125,   126,    39,   124,   120,   130,    37,
      39,    37,    37,    37,    39,    37,    39,    39,    37,    37,
      39,   112,     9,    88,   103,   127,    34,    39,    39,   121,
      15,    34,   130,   130,   130,    34,   130,    34,    34,   130,
     130,    34,    79,    76,    85,    87,    40,    11,    34,    37,
     122,    39,    39,    39,    37,    39,    39,    39,    14,    15,
      79,   108,   123,    34,    34,    34,   130,    34,    34,    34,
     130,    89,    90,    41,    40,   120,    39,    41,    34,     6,
     104,    79,    34,   105,    41,    40,    79,    41
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
#line 221 "sintatico.y"
    {file = fopen("cuadruplos.txt","w+"); generarMain();}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 222 "sintatico.y"
    {struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
		     insertProc(&tblProc,&tablaGlobal,&tablaParametros,(yyvsp[(3) - (3)].string),(yyvsp[(3) - (3)].string), 0,0,0); numeroFunciones++;}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 223 "sintatico.y"
    {generarEnd();}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 224 "sintatico.y"
    {alcanceDireccion=1;/*global*/}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 236 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroStringLocales++;/*printf("===========tipo: %i\n", tipoOp);*/ }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 237 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroIntLocales++; /*printf("===========tipo: %i\n", tipoOp);*/ }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 238 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroFloatLocales++;/*printf("===========tipo: %i\n", tipoOp);*/}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 239 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); /*printf("===========tipo: %i\n", tipoOp);*/}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 241 "sintatico.y"
    {llenarMain();}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 269 "sintatico.y"
    {insert(&tablaGlobal,(yyvsp[(3) - (5)].string),(yyvsp[(3) - (5)].string),tipoOp,generarDireccion(tipoOp,1));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 274 "sintatico.y"
    {alcanceDireccion=2;/*local*/}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 278 "sintatico.y"
    {insert(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(3) - (5)].string),(yyvsp[(3) - (5)].string),tipoOp,generarDireccion(tipoOp,2)); numeroVarLocales++;}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 289 "sintatico.y"
    {int tipoId = getType(&tablaGlobal,(yyvsp[(1) - (2)].string));
			    if(tipoId==0)
				tipoId = getType(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(1) - (2)].string));
			    int direccionVirtual = getDirection(&tablaGlobal,(yyvsp[(1) - (2)].string));
			    if(direccionVirtual==-1)
				direccionVirtual = getDirection(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(1) - (2)].string));
			    push(&pilaOperadores, (yyvsp[(1) - (2)].string), tipoId, direccionVirtual); 
				printf("\n\nHIzo pussh: tipo %i, direcicn %i\n\n",tipoId,direccionVirtual);}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 297 "sintatico.y"
    { push(&pilaOperando, (yyvsp[(4) - (4)].string), -1, -1);}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 298 "sintatico.y"
    {checarOperando3();}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 301 "sintatico.y"
    {hacerPush=1; /*no meter a la pila las EXP de los arreglos*/}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 301 "sintatico.y"
    {hacerPush=1;}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 307 "sintatico.y"
    {generarImprimir();}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 309 "sintatico.y"
    {generarLectura();}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 311 "sintatico.y"
    {secuenciaIf1();}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 311 "sintatico.y"
    {secuenciaIf2();}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 313 "sintatico.y"
    {secuenciaElse();}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 318 "sintatico.y"
    {secuenciaWhile1();}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 318 "sintatico.y"
    {secuenciaWhile2();}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 318 "sintatico.y"
    {secuenciaWhile3();}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 320 "sintatico.y"
    {numeroParametros=0;
					strcpy(nombreFuncion, (yyvsp[(3) - (3)].string)); 
					printf("\n++++++++++Nombe Funcion:%s\n\n", nombreFuncion);
					struct StrHashTable tablaLocalFuncion = {{0},NULL,NULL,foo_strhash,strcmp};
					struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
					insertProc(&tblProc,&tablaLocalFuncion,&tablaParametros,nombreFuncion,nombreFuncion,0,0,0);	
					numeroFunciones++;
					}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 328 "sintatico.y"
    {
					setNumberParameters(&tblProc,nombreFuncion,numeroParametros);
					 }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 331 "sintatico.y"
    {setNumberLocalVars(&tblProc,nombreFuncion,numeroVarLocales);
					 
					setCuadruploInicial(&tblProc,nombreFuncion,contS);
					 }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 335 "sintatico.y"
    {generarRetorno();}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 341 "sintatico.y"
    {int direccion = generarDireccion(tipoOp,2);
			char numeroParametrosString[3];
			printf("\n-----Nombe Funcion:%s\n\n", nombreFuncion);
			numeroParametros++;
			sprintf(numeroParametrosString, "%i", numeroParametros);
			insert(getPointerParTbl(&tblProc,nombreFuncion),numeroParametrosString,(yyvsp[(2) - (2)].string),tipoOp,direccion);
			printf("\n\nDIRECCION PARAMETRO %i, %i,%s\n\n", direccion, getType(getPointerParTbl(&tblProc,nombreFuncion),numeroParametrosString), numeroParametrosString);
			}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 353 "sintatico.y"
    {	strcpy(nombreFuncion, (yyvsp[(1) - (1)].string)); 
			if(getProc(&tblProc,(yyvsp[(1) - (1)].string))==1){
				 printf("\n @@@@@@@@@@Ya existe PROC %s ... Local vars: %i\n", (yyvsp[(1) - (1)].string), getNumberLocalVars(&tblProc,(yyvsp[(1) - (1)].string)));
				 generarEra(getNumberLocalVars(&tblProc,(yyvsp[(1) - (1)].string)));
			}
			else printf("\n @@@@@@@@@@ NO existe PROC");
			
		}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 360 "sintatico.y"
    {generarGoSub();}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 361 "sintatico.y"
    {generarParametro();}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 362 "sintatico.y"
    {apuntadorParametro++;}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 375 "sintatico.y"
    {  checarOperando3();   }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 376 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 377 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 378 "sintatico.y"
    {push(&pilaOperando, (yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 379 "sintatico.y"
    {char* str = (yyvsp[(1) - (2)].string);
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, (yyvsp[(2) - (2)].string) ); 
				      push(&pilaOperando, str, -1, -1);}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 386 "sintatico.y"
    {  checarOperando2();   }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 389 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 390 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 392 "sintatico.y"
    { checarOperando1();   }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 395 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 396 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 398 "sintatico.y"
    { push(&pilaOperando,(yyvsp[(1) - (1)].string),-1,-1); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 398 "sintatico.y"
    {pop(&pilaOperando);}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 400 "sintatico.y"
    {int tipoId = getType(&tbl,(yyvsp[(1) - (2)].string));
				int direccionVirtual = generarDireccion(tipoId, alcanceDireccion);
				if(hacerPush==1) push(&pilaOperadores, (yyvsp[(1) - (2)].string), tipoId, direccionVirtual); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 406 "sintatico.y"
    {if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
							int direccion= getDirection(&tablaConstantes,(yyvsp[(1) - (1)].string));
							if (direccion == -1)direccion=generarDireccion(3, 5);
						  push(&pilaOperadores, (yyvsp[(1) - (1)].string), 3, direccion);
						  if(insert(&tablaConstantes,(yyvsp[(1) - (1)].string),(yyvsp[(1) - (1)].string),3,direccion)!= -1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, (yyvsp[(1) - (1)].string)); strcat(strDirecciones,"\n");
						   }
					}}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 419 "sintatico.y"
    {if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						   	int direccion= getDirection(&tablaConstantes,(yyvsp[(1) - (1)].string));
							if (direccion == -1)direccion=generarDireccion(1, 5);
						   push(&pilaOperadores, (yyvsp[(1) - (1)].string), 1, direccion);
						   if(insert(&tablaConstantes,(yyvsp[(1) - (1)].string),(yyvsp[(1) - (1)].string),1,direccion)!= -1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string); 
							  strcat(strDirecciones,(yyvsp[(1) - (1)].string)); strcat(strDirecciones,"\n"); 
					          }
					}}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 432 "sintatico.y"
    {if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						  	int direccion= getDirection(&tablaConstantes,(yyvsp[(1) - (1)].string));
							if (direccion == -1)direccion=generarDireccion(2, 5);
						   push(&pilaOperadores, (yyvsp[(1) - (1)].string), 2, direccion);
						   if(insert(&tablaConstantes,(yyvsp[(1) - (1)].string),(yyvsp[(1) - (1)].string),2,direccion)!=-1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, (yyvsp[(1) - (1)].string)); strcat(strDirecciones,"\n");  
						   }
					}}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 445 "sintatico.y"
    {if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						  	int direccion= getDirection(&tablaConstantes,(yyvsp[(1) - (1)].string));
							if (direccion == -1)direccion=generarDireccion(4, 5);
						  push(&pilaOperadores, (yyvsp[(1) - (1)].string), 4, direccion);
						  if(insert(&tablaConstantes,(yyvsp[(1) - (1)].string),(yyvsp[(1) - (1)].string),4,direccion)!=-1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, (yyvsp[(1) - (1)].string)); strcat(strDirecciones,"\n"); 
						  }
					}}
    break;



/* Line 1806 of yacc.c  */
#line 2276 "sintatico.tab.c"
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
#line 493 "sintatico.y"


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
			{ contEnteroGlobal++;
			  return direccionEnteroGlobal++;}
		else if(tipo==2){ //doble
			contDobleGlobal++;
			return direccionDobleGlobal++;}
		else if(tipo==3) {//texto
			contTextoGlobal++;			
			return direccionTextoGlobal++;}
		else if(tipo==4){ //booleano
			contBooleanoGlobal++;
			return direccionBooleanoGlobal++;}
	}
	 //local
	else if(alcance==2){
		//printf(">>>>>>>>>>>>>>>>>>ALCANCE LOCAL\n");
		if(tipo==1) {//entero
			contEnteroLocal++;
			return direccionEnteroLocal++;}
			
		else if(tipo==2){ //doble
			contDobleLocal++;
			return direccionDobleLocal++;}
		else if(tipo==3) {//texto
			contTextoLocal++;
			return direccionTextoLocal++;}
		else if(tipo==4) {//booleano
			contBooleanoLocal++;
			return direccionBooleanoLocal++;}
	}
	//temp
	else if (alcance==3){ 
		//printf(">>>>>>>>>>>>>>>>>>ALCANCE TEMPORAL\n");
		if(tipo==1){// entero
			contEnteroTemp++;
			return direccionEnteroTemp++;}
		else if(tipo==2) {//doble
			contDobleTemp++;
			return direccionDobleTemp++;}
		else if(tipo==3){ //texto
			contTextoTemp++;
			return direccionTextoTemp++;}
		else if(tipo==4){ //booleano
			contBooleanoTemp++;
			return direccionBooleanoTemp++;}
	}
	//Constante
	else if (alcance==5){ 
		printf(">>>>>>>>>>>>>>>>>>ALCANCE: COnstante\n");
		if(tipo==1){// entero
			contEnteroConstante++;
			return direccionEnteroConstante++;}
		else if(tipo==2) {//doble
			contDobleConstante++;
			return direccionDobleConstante++;}
		else if(tipo==3){ //texto
			contTextoConstante++;
			return direccionTextoConstante++;}
		else if(tipo==4) {//booleano
			contBooleanoConstante++;
			return direccionBooleanoConstante++;}
	}

}


/*
 ######  ##     ##    ###    ########  ########  ##     ## ########  ##        #######   ######  
##    ## ##     ##   ## ##   ##     ## ##     ## ##     ## ##     ## ##       ##     ## ##    ## 
##       ##     ##  ##   ##  ##     ## ##     ## ##     ## ##     ## ##       ##     ## ##       
##       ##     ## ##     ## ##     ## ########  ##     ## ########  ##       ##     ##  ######  
##       ##     ## ######### ##     ## ##   ##   ##     ## ##        ##       ##     ##       ## 
##    ## ##     ## ##     ## ##     ## ##    ##  ##     ## ##        ##       ##     ## ##    ## 
 ######   #######  ##     ## ########  ##     ##  #######  ##        ########  #######   ######  
*/


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

				if(*pilaOperando->valor=='=' ) {numOp=10; } 
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
	//printf("\nCuadruplo # %i ---(%i,%i,%i,%i)\n", contS,vectorOp[contS],vectorOp1[contS],vectorOp2[contS],vectorRes[contS]);
	
	char intemporal[25];

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
	//printf("\nCuadruplo # %i ---(%i,%i,%i,%i)\n", goTo,vectorOp[goTo],vectorOp1[goTo],vectorOp2[goTo],vectorRes[goTo]);
	char intemporal[25];
}

void inicializarVectores(){
	 vectorTemporal=(int*) malloc(sizeof(int));
	 vectorOp=(int*) malloc(sizeof(int));
	 vectorOp1=(int*) malloc(sizeof(int));
	 vectorOp2=(int*) malloc(sizeof(int));
	 vectorRes=(int*) malloc(sizeof(int));
}

void generarImprimir(){
	int numeroPrint = 26;

	int direccionImprimir = pilaOperadores->direccion;
	pop(&pilaOperadores);

	generarCuadruplo(numeroPrint ,direccionImprimir, -1, -1);
}

void generarLectura(){
	int numeroRead = 25;
	direccionTextoTemp++;
	generarCuadruplo(numeroRead ,direccionTextoTemp, -1, -1);
}

void generarMain(){
	int numeroGoTo = 11;
	generarCuadruplo(numeroGoTo ,-1, -1, -1);
}

void llenarMain(){
	vectorRes[0]=contS;
}

void generarRetorno(){
	int numeroRet=22;
	generarCuadruplo(numeroRet ,-1, -1, -1);
}

void generarEra(int tamano){

	int numeroEra = 20;
	generarCuadruplo(numeroEra,tamano,-1,-1); //era=20 tamaño= bonche de memoria
	apuntadorParametro=1; //inicializar el contador de parametros

	//Apuntar al primer parametro de nomProcesimiento

}


void generarParametro(){
	
	if(apuntadorParametro > getNumberParameters(&tblProc,nombreFuncion))
		printf("ERROR: Demasiados Parametros en la llamada a la funcion \"%s\"\n", nombreFuncion);
	else{
		ptr arg= malloc (sizeof(p_Nodo)); 
	
		arg->valor = pilaOperadores->valor;
		arg->tipo = pilaOperadores->tipo; 
		arg->direccion = pilaOperadores->direccion; 

		pop(&pilaOperadores); 
	
		char apuntadorParametroString[3];
		sprintf(apuntadorParametroString, "%i", apuntadorParametro);

		//Checar si los tipos son consistentes
		if(arg->tipo != getType(getPointerParTbl(&tblProc,nombreFuncion), apuntadorParametroString) ){
			printf("\nEl tipo del parametro es inconsistente con la definicion del procedimiento\n:%s, %i, %i, %s\n",nombreFuncion, arg->tipo, getType(getPointerParTbl(&tblProc,nombreFuncion), apuntadorParametroString), apuntadorParametroString);
		}
		else{
			int numeroParam = 23;
			generarCuadruplo(numeroParam,arg->direccion,-1,apuntadorParametro);// param=23
		}
	}
}

void generarGoSub(){

	int numeroGoSub = 21;
	generarCuadruplo(numeroGoSub,getCuadruploInicial(&tblProc,nombreFuncion),-1,-1);// param=23
}

void generarEnd(){

	int numeroEnd = 30;
	generarCuadruplo(numeroEnd,-1,-1,-1);// param=23
}

/*
##     ##    ###    ######## ########  #### ######## 
###   ###   ## ##      ##    ##     ##  ##       ##  
#### ####  ##   ##     ##    ##     ##  ##      ##   
## ### ## ##     ##    ##    ########   ##     ##    
##     ## #########    ##    ##   ##    ##    ##     
##     ## ##     ##    ##    ##    ##   ##   ##      
##     ## ##     ##    ##    ##     ## #### ######## 
*/

int checarSemantica(int op, int op1, int op2){

	if( matrizSemantica[op1-1][op2-1][op] == 0 ){
		/*printf("--------------Semantica No Valida!!\n");*/
		return 0;	//Error: no se puede hacer operacion de esos tipos
	}
	else {
		/*printf("--------------Semantica Valida!! tipo: %i. \n " , matrizSemantica[op1-1][op2-1][op]);*/
		return matrizSemantica[op1-1][op2-1][op];
	}
	
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
	matrizSemantica[0][0][3]= 2;	//Entero / entero = doble
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


/*
##     ##    ###    #### ##    ## 
###   ###   ## ##    ##  ###   ## 
#### ####  ##   ##   ##  ####  ## 
## ### ## ##     ##  ##  ## ## ## 
##     ## #########  ##  ##  #### 
##     ## ##     ##  ##  ##   ### 
##     ## ##     ## #### ##    ## 
		
*/

int main()
{
	inicializarMatriz();
	inicializarVectores();

	if (yyparse()==0){
		printf("Sintaxis Correctaa\n");

		//Generar cuadruplos.txt
		for(i=0; i<contS; i++){	
			char intemporal[25];
			sprintf(intemporal, "%i/%i/", i,vectorOp[i]);
			strcat(strCuadruplos, intemporal); 
			sprintf(intemporal, "%i/", vectorOp1[i]);
			strcat(strCuadruplos, intemporal); 
			sprintf(intemporal, "%i/", vectorOp2[i]);
			strcat(strCuadruplos, intemporal); 
			sprintf(intemporal, "%i\n", vectorRes[i]);
			strcat(strCuadruplos, intemporal); 
		}
		
		fprintf(file, "%i\n", contadorConstantes);
		fprintf(file, "%i\n", contEnteroGlobal);
		fprintf(file, "%i\n", contEnteroLocal);
		fprintf(file, "%i\n", contEnteroTemp);
		fprintf(file, "%i\n", contEnteroConstante);
		fprintf(file, "%i\n", contDobleGlobal);
		fprintf(file, "%i\n", contDobleLocal);
		fprintf(file, "%i\n", contDobleTemp);
		fprintf(file, "%i\n", contDobleConstante);
		fprintf(file, "%i\n", contTextoGlobal);
		fprintf(file, "%i\n", contTextoLocal);
		fprintf(file, "%i\n", contTextoTemp);
		fprintf(file, "%i\n", contTextoConstante);
		fprintf(file, "%i\n", contBooleanoGlobal);
		fprintf(file, "%i\n", contBooleanoLocal);
		fprintf(file, "%i\n", contBooleanoTemp);
		fprintf(file, "%i\n", contBooleanoConstante);
		
			
		fprintf(file, "%s", strDirecciones);
		fprintf(file, "%s", strCuadruplos);
	}
	else
		printf("Sintaxis Incorrecta\n");

	fclose(file); 

return 0;
}


yyerror(s)
char *s;
	{
		fprintf(stderr, "%s\n",s);
	}


