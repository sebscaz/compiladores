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
#line 207 "sintatico.tab.c"

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
#line 137 "sintatico.y"
int cteint; float ctefloat; int cteboolean; char *string;


/* Line 293 of yacc.c  */
#line 311 "sintatico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 323 "sintatico.tab.c"

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
#define YYLAST   236

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
      -1,   152,    -1,   153,    -1,   146,    -1,     9,    76,    84,
      15,    34,    -1,    90,    -1,    -1,    -1,    86,    88,    87,
      -1,    85,    -1,    -1,     9,    76,    89,    15,    34,    -1,
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
       0,   213,   213,   214,   213,   216,   216,   217,   218,   219,
     220,   221,   223,   224,   225,   228,   229,   230,   231,   233,
     233,   235,   236,   237,   239,   240,   241,   242,   243,   244,
     245,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   261,   262,   263,   266,   266,   267,   268,
     270,   272,   273,   276,   277,   278,   281,   289,   281,   291,
     292,   293,   293,   294,   295,   296,   297,   299,   301,   303,
     303,   305,   305,   306,   310,   310,   310,   312,   320,   323,
     312,   329,   330,   331,   332,   333,   333,   342,   343,   345,
     345,   353,   353,   354,   354,   355,   358,   359,   360,   361,
     362,   365,   366,   367,   368,   369,   370,   371,   378,   378,
     379,   380,   381,   382,   384,   384,   385,   386,   387,   388,
     390,   390,   391,   392,   398,   411,   424,   437,   451,   453,
     454,   455,   456,   458,   460,   463,   465,   467,   469,   471,
     473,   475,   477,   479,   481,   482,   483
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
      13,    12,    16,    17,    15,    18,    45,     7,     6,     0,
       0,    62,    82,    81,     0,    19,     0,    10,     9,     0,
       0,    44,    57,    63,   124,   125,   126,   127,   120,     0,
     108,   114,   122,    77,     0,     4,     0,     0,     0,   123,
       0,    66,   110,   116,     0,     0,    55,    43,     0,     0,
      59,    60,     0,   102,     0,    64,   112,   113,   109,     0,
     118,   119,   115,     0,    83,     0,     0,    53,     0,    58,
     121,   106,     0,   105,   104,   101,     0,     0,   111,   117,
       0,     0,    84,     0,     0,    68,   107,   103,    65,    85,
      78,     0,     0,    74,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    29,
      24,    26,    27,    25,    28,    30,    31,    32,    33,    34,
      42,    36,    35,    37,    39,    38,    40,    41,    54,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    22,    21,
       0,    86,    46,     0,    97,     0,     0,     0,   132,   130,
     129,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,   146,     0,    88,    79,     0,
      69,    99,   100,    96,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,    98,    67,     0,     0,    95,
       0,   133,     0,     0,     0,   136,     0,   139,   140,     0,
       0,   143,     0,    52,    48,    47,     0,    75,    90,    93,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,   128,   138,   137,     0,   134,   141,
     142,     0,     0,    73,     0,    94,     0,    80,    50,    71,
      70,     0,   135,     0,    76,     0,     0,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     8,     9,    28,    18,    38,    11,
      21,   100,    36,    54,   127,   169,   128,   129,    14,    40,
     198,   199,   245,   223,   259,    41,    87,   130,    29,    58,
      69,    15,    16,    31,    75,   131,   132,   133,   224,   280,
     283,   134,   153,   262,    19,    64,   150,   221,    34,   101,
     102,   149,   171,   135,   154,   207,   229,   250,   263,   173,
     203,   204,   174,    95,    96,    73,    62,    78,    79,    50,
      63,    82,    83,    51,    60,    52,   136,   182,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   196
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -127
static const yytype_int16 yypact[] =
{
    -127,    33,     4,  -127,    -3,  -127,    -2,  -127,    50,    66,
      52,    36,    50,     9,    62,  -127,    37,    14,    74,    36,
    -127,  -127,  -127,  -127,  -127,  -127,    38,  -127,  -127,    57,
      24,  -127,  -127,  -127,    67,  -127,    42,  -127,  -127,    68,
      69,  -127,  -127,    44,  -127,  -127,  -127,  -127,  -127,    45,
    -127,  -127,  -127,  -127,    49,  -127,    46,    56,     7,  -127,
      24,    51,   -17,    18,    53,    55,    54,  -127,    59,    58,
    -127,  -127,    60,    39,    24,  -127,  -127,  -127,  -127,    24,
    -127,  -127,  -127,    24,     9,    61,    81,  -127,    63,  -127,
    -127,  -127,    76,  -127,  -127,  -127,    24,    64,  -127,  -127,
      88,    65,  -127,     6,    70,  -127,  -127,  -127,  -127,  -127,
    -127,    71,    72,  -127,   -21,    73,    77,    78,    79,    80,
      83,    85,    86,    87,    89,    90,    91,    92,     6,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,    75,
      94,    24,    24,    93,    97,    12,    99,   104,   111,   115,
     117,   121,   122,   123,   124,   125,   -38,  -127,  -127,  -127,
       9,  -127,  -127,   102,    35,   103,    24,    24,  -127,  -127,
    -127,  -127,   106,   105,   108,   109,   112,   113,   114,   116,
     118,   119,   126,  -127,  -127,  -127,   127,  -127,  -127,    96,
    -127,  -127,  -127,  -127,    24,   120,   128,   129,  -127,   138,
     130,    24,    24,    24,   131,    24,   135,   136,    24,    24,
     137,     6,     9,   149,   132,  -127,  -127,    95,   139,   140,
     141,  -127,   145,   147,   142,  -127,   148,  -127,  -127,   151,
     152,  -127,   146,    38,  -127,  -127,     6,  -127,  -127,  -127,
    -127,   144,   158,   159,    24,   160,   161,   162,    24,   182,
    -127,   133,   163,    24,  -127,  -127,  -127,   165,  -127,  -127,
    -127,   134,   164,   155,     6,  -127,   166,  -127,  -127,  -127,
    -127,   167,  -127,   169,  -127,     6,   170,  -127
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,   185,  -127,  -127,   143,  -127,   189,
    -127,   -12,  -127,  -127,  -126,  -127,  -127,  -127,  -127,  -127,
    -115,  -127,  -127,  -127,  -127,   -67,  -127,    -4,  -127,  -127,
    -127,   171,  -127,  -127,  -127,  -127,   154,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
      32,  -127,  -127,  -127,  -127,   -58,  -127,  -127,  -127,    30,
    -127,  -127,   -54,  -127,  -127,   -30,  -127,  -127,  -127,   153,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -90
static const yytype_int16 yytable[] =
{
      49,    26,   168,   -63,    12,    33,    72,     4,    12,    76,
      77,   111,     5,   112,    68,    68,   113,   -89,   193,   194,
     195,   114,    43,    44,    45,    46,    47,    32,    71,    22,
      23,    24,    25,     3,    22,    23,    24,    25,     7,    43,
      44,    45,    46,    47,    97,    48,    80,    81,    17,    98,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    48,    91,    92,    10,   107,   201,   202,    93,
      94,   178,   179,   180,   181,    13,   -63,    -8,    35,    30,
      39,    42,    53,    55,    57,    56,   -61,    65,    61,    66,
      67,    84,    89,    74,    85,   242,    86,    88,   104,    90,
     106,   103,   105,   109,   110,   222,   247,   108,   244,   151,
     152,   155,   170,   148,   183,   156,   157,   158,   159,   184,
     261,   160,   175,   161,   162,   163,   185,   164,   165,   166,
     186,   176,   187,   167,   172,   177,   188,   189,   190,   191,
     192,   200,   205,   209,   210,   211,   212,   208,   281,   213,
     225,   215,   214,   230,   226,   216,   218,   217,   -46,   286,
     258,   279,    37,   219,   231,   235,   220,   227,   228,   237,
     238,   241,   246,   248,   273,   277,   260,   249,   264,   254,
     251,   232,   233,   234,   252,   236,   253,   255,   239,   240,
     256,   257,   265,   266,   268,   269,   270,   272,   278,    27,
     282,    20,   197,   274,   276,   275,   206,     0,   284,   285,
     243,   287,    70,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,     0,     0,   271,     0,
       0,     0,     0,   208,     0,     0,    99
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-127))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      30,    13,   128,    24,     8,    17,    60,     3,    12,    26,
      27,     5,    15,     7,     8,     8,    10,    38,    56,    57,
      58,    15,    15,    16,    17,    18,    19,    13,    58,    20,
      21,    22,    23,     0,    20,    21,    22,    23,    40,    15,
      16,    17,    18,    19,    74,    38,    28,    29,    12,    79,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    38,    24,    25,    15,    96,    32,    33,    30,
      31,    59,    60,    61,    62,     9,    24,    15,     4,    42,
      42,    24,    15,    41,    15,    17,    42,    38,    43,    43,
      34,    38,    34,    42,    39,   221,    42,    38,    17,    39,
      24,    40,    39,    15,    39,     9,    11,    43,   223,    38,
      38,    38,    37,    43,    15,    38,    38,    38,    38,    15,
     246,    38,   152,    38,    38,    38,    15,    38,    38,    38,
      15,    38,    15,    41,    40,    38,    15,    15,    15,    15,
      15,    39,    39,    37,    39,    37,    37,   177,   274,    37,
     204,    37,    39,    15,    34,    39,    37,    39,     9,   285,
      14,     6,    19,    37,    34,    34,    39,    39,    39,    34,
      34,    34,    40,    34,    41,    41,   243,    37,    34,    37,
      39,   211,   212,   213,    39,   215,    39,    39,   218,   219,
      39,    39,    34,    34,    34,    34,    34,    15,    34,    14,
      34,    12,   170,    40,    39,   263,   176,    -1,    41,    40,
     222,    41,    58,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    83
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,     3,    15,    68,    40,    69,    70,
      15,    74,    92,     9,    83,    96,    97,    12,    72,   109,
      74,    75,    20,    21,    22,    23,    76,    69,    71,    93,
      42,    98,    13,    76,   113,     4,    77,    72,    73,    42,
      84,    90,    24,    15,    16,    17,    18,    19,    38,   130,
     134,   138,   140,    15,    78,    41,    17,    15,    94,    96,
     139,    43,   131,   135,   110,    38,    43,    34,     8,    95,
     101,   130,   127,   130,    42,    99,    26,    27,   132,   133,
      28,    29,   136,   137,    38,    39,    42,    91,    38,    34,
      39,    24,    25,    30,    31,   128,   129,   130,   130,   134,
      76,   114,   115,    40,    17,    39,    24,   130,    43,    15,
      39,     5,     7,    10,    15,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    79,    81,    82,
      92,   100,   101,   102,   106,   118,   141,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    43,   116,
     111,    38,    38,   107,   119,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    41,    79,    80,
      37,   117,    40,   124,   127,   130,    38,    38,    59,    60,
      61,    62,   142,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    56,    57,    58,   154,   115,    85,    86,
      39,    32,    33,   125,   126,    39,   124,   120,   130,    37,
      39,    37,    37,    37,    39,    37,    39,    39,    37,    37,
      39,   112,     9,    88,   103,   127,    34,    39,    39,   121,
      15,    34,   130,   130,   130,    34,   130,    34,    34,   130,
     130,    34,    79,    76,    85,    87,    40,    11,    34,    37,
     122,    39,    39,    39,    37,    39,    39,    39,    14,    89,
      90,    79,   108,   123,    34,    34,    34,   130,    34,    34,
      34,   130,    15,    41,    40,   120,    39,    41,    34,     6,
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
#line 213 "sintatico.y"
    {file = fopen("cuadruplos.txt","w+"); generarMain();}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 214 "sintatico.y"
    {struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
		     insertProc(&tblProc,&tablaGlobal,&tablaParametros,(yyvsp[(3) - (3)].string),(yyvsp[(3) - (3)].string), 0,0,0); numeroFunciones++;}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 216 "sintatico.y"
    {alcanceDireccion=1;/*global*/}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 228 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroStringLocales++;/*printf("===========tipo: %i\n", tipoOp);*/ }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 229 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroIntLocales++; /*printf("===========tipo: %i\n", tipoOp);*/ }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 230 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroFloatLocales++;/*printf("===========tipo: %i\n", tipoOp);*/}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 231 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); /*printf("===========tipo: %i\n", tipoOp);*/}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 233 "sintatico.y"
    {llenarMain();}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 261 "sintatico.y"
    {insert(&tablaGlobal,(yyvsp[(4) - (5)].string),(yyvsp[(4) - (5)].string),tipoOp,generarDireccion(tipoOp,1));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 266 "sintatico.y"
    {alcanceDireccion=2;/*local*/}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 270 "sintatico.y"
    {insert(getPointerParTbl(&tblProc,nombreFuncion),(yyvsp[(4) - (5)].string),(yyvsp[(4) - (5)].string),tipoOp,generarDireccion(tipoOp,2)); numeroVarLocales++;}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 281 "sintatico.y"
    {int tipoId = getType(&tablaGlobal,(yyvsp[(1) - (2)].string));
			    if(tipoId==0)
				tipoId = getType(&tablaLocal,(yyvsp[(1) - (2)].string));
			    int direccionVirtual = getDirection(&tablaGlobal,(yyvsp[(1) - (2)].string));
			    if(direccionVirtual==0)
				direccionVirtual = getDirection(&tablaLocal,(yyvsp[(1) - (2)].string));
			    push(&pilaOperadores, (yyvsp[(1) - (2)].string), tipoId, direccionVirtual); 
				printf("\n\nHIzo pussh: tipo %i, direcicn %i\n\n",tipoId,direccionVirtual);}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 289 "sintatico.y"
    { push(&pilaOperando, (yyvsp[(4) - (4)].string), -1, -1);}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 290 "sintatico.y"
    {checarOperando3();}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 293 "sintatico.y"
    {hacerPush=0; /*no meter a la pila las EXP de los arreglos*/}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 293 "sintatico.y"
    {hacerPush=1;}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 299 "sintatico.y"
    {generarImprimir();}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 301 "sintatico.y"
    {generarLectura();}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 303 "sintatico.y"
    {secuenciaIf1();}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 303 "sintatico.y"
    {secuenciaIf2();}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 305 "sintatico.y"
    {secuenciaElse();}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 310 "sintatico.y"
    {secuenciaWhile1();}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 310 "sintatico.y"
    {secuenciaWhile2();}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 310 "sintatico.y"
    {secuenciaWhile3();}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 312 "sintatico.y"
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
#line 320 "sintatico.y"
    {
					setNumberParameters(&tblProc,nombreFuncion,numeroParametros);
					 }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 323 "sintatico.y"
    {setNumberLocalVars(&tblProc,nombreFuncion,numeroVarLocales);
					 
					setCuadruploInicial(&tblProc,nombreFuncion,contS);
					 }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 327 "sintatico.y"
    {generarRetorno();}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 333 "sintatico.y"
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
#line 345 "sintatico.y"
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
#line 352 "sintatico.y"
    {generarGoSub();}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 353 "sintatico.y"
    {generarParametro();}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 354 "sintatico.y"
    {apuntadorParametro++;}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 367 "sintatico.y"
    {  checarOperando3();   }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 368 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 369 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 370 "sintatico.y"
    {push(&pilaOperando, (yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 371 "sintatico.y"
    {char* str = (yyvsp[(1) - (2)].string);
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, (yyvsp[(2) - (2)].string) ); 
				      push(&pilaOperando, str, -1, -1);}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 378 "sintatico.y"
    {  checarOperando2();   }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 381 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 382 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 384 "sintatico.y"
    { checarOperando1();   }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 387 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 388 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 390 "sintatico.y"
    { push(&pilaOperando,(yyvsp[(1) - (1)].string),-1,-1); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 390 "sintatico.y"
    {pop(&pilaOperando);}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 392 "sintatico.y"
    {int tipoId = getType(&tbl,(yyvsp[(1) - (2)].string));
				int direccionVirtual = generarDireccion(tipoId, alcanceDireccion);
				if(hacerPush==1) push(&pilaOperadores, (yyvsp[(1) - (2)].string), tipoId, direccionVirtual); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 398 "sintatico.y"
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
#line 411 "sintatico.y"
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
#line 424 "sintatico.y"
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
#line 437 "sintatico.y"
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
#line 2261 "sintatico.tab.c"
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
#line 485 "sintatico.y"


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


