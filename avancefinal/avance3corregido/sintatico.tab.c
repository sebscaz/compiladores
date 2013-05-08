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
void generarReturn();
void generarDimension1();
void generarDimension2();
void generarVerifica();
void generarEnd();

void generarDibujarFigura();
void generarBorrarFigura();
void generarHablarFigura();
void generarMoverFigura();
void generarObtenerX();
void generarObtenerY();
void generarGirarD();
void generarGirarI();
void generarObtenerAnchura();
void generarObtenerAltura();
void generarCambiarAnchura();
void generarCambiarAltura();
void generarColorFondo();

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
int apuntadorParametro;		//indica el numero de parametro que se enviara a la funcion 

int arg;
int tipoArg;

//ARREGLOS

void dimensionesArreglos1(int cantidadElementos);
void dimensionesArreglos2(int cantidadElementos);
void operacionesArreglos();
int esArreglo;		//determina si la variables es normal o un arreglo
int r; 			//usada en la formula de arreglos
int m0=1;		//indica la cantidad de elementos en el arreglo, en todas sus dimensiones
int direccionAux=1;	//direccion que se sumara a la direccion base en caso de ser necesario	
int numeroDimension;	//indica la dimension actual del arreglo (1 o 2)
dimensionArreglo dimensiones[2];	//almacenar las dimensiones de un arreglo (1 o 2)



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
#line 238 "sintatico.tab.c"

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
     prototipo = 260,
     si = 261,
     no = 262,
     imprimir = 263,
     leer = 264,
     crear = 265,
     mientras = 266,
     hacer = 267,
     funcion = 268,
     neutral = 269,
     regresar = 270,
     id = 271,
     ctetexto = 272,
     cteentero = 273,
     ctedecimal = 274,
     ctebooleano = 275,
     entero = 276,
     decimal = 277,
     texto = 278,
     booleano = 279,
     igual = 280,
     diferente = 281,
     mas = 282,
     menos = 283,
     multiplicacion = 284,
     division = 285,
     mayor = 286,
     menor = 287,
     and = 288,
     or = 289,
     ptocoma = 290,
     dospuntos = 291,
     punto = 292,
     coma = 293,
     parentesisa = 294,
     parentesisc = 295,
     llavea = 296,
     llavec = 297,
     corchetea = 298,
     corchetec = 299,
     dibujarFigura = 300,
     borrarFigura = 301,
     girarIzquierda = 302,
     girarDerecha = 303,
     mover = 304,
     obtenerPosicion = 305,
     hablar = 306,
     obtenerAltura = 307,
     obtenerAnchura = 308,
     cambiarAltura = 309,
     cambiarAnchura = 310,
     colorFondo = 311,
     rojo = 312,
     azul = 313,
     verde = 314,
     carro = 315,
     persona = 316,
     perro = 317,
     gato = 318,
     verdadero = 319,
     falso = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 168 "sintatico.y"
int cteint; float ctefloat; int cteboolean; char *string;


/* Line 293 of yacc.c  */
#line 343 "sintatico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 355 "sintatico.tab.c"

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
#define YYLAST   250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNRULES -- Number of states.  */
#define YYNSTATES  321

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    19,    22,    24,    25,
      29,    34,    35,    39,    41,    42,    45,    47,    48,    51,
      53,    54,    56,    58,    60,    62,    63,    64,    74,    77,
      79,    80,    82,    84,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   104,   106,   108,   110,   112,   114,   116,
     118,   124,   126,   127,   128,   132,   134,   135,   136,   143,
     145,   146,   147,   153,   154,   159,   160,   161,   162,   170,
     172,   174,   175,   178,   179,   180,   186,   187,   192,   193,
     199,   203,   204,   214,   215,   221,   222,   223,   224,   235,
     236,   237,   238,   239,   256,   258,   260,   261,   263,   264,
     269,   270,   273,   274,   281,   282,   286,   287,   291,   292,
     295,   296,   299,   301,   303,   306,   307,   310,   312,   314,
     316,   319,   320,   324,   325,   328,   330,   332,   333,   337,
     338,   341,   343,   345,   346,   351,   353,   354,   358,   360,
     362,   364,   366,   367,   376,   378,   380,   382,   384,   385,
     392,   393,   402,   403,   414,   415,   422,   423,   432,   433,
     442,   443,   450,   451,   458,   459,   468,   469,   478,   479,
     486,   488,   490
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      67,     0,    -1,    -1,    -1,    -1,    68,     3,    16,    69,
      41,    70,    71,    75,    80,    78,    83,    42,    -1,    73,
      72,    -1,    71,    -1,    -1,     5,    74,    35,    -1,    16,
      39,    18,    40,    -1,    -1,    76,    90,    77,    -1,    75,
      -1,    -1,   121,    79,    -1,    78,    -1,    -1,   102,    81,
      -1,    80,    -1,    -1,    23,    -1,    21,    -1,    22,    -1,
      24,    -1,    -1,    -1,     4,    84,    39,    40,    41,    85,
      92,    86,    42,    -1,    88,    87,    -1,    86,    -1,    -1,
     102,    -1,   114,    -1,   112,    -1,   113,    -1,   118,    -1,
      89,    -1,   131,    -1,   155,    -1,   158,    -1,   160,    -1,
     162,    -1,   168,    -1,   166,    -1,   170,    -1,   174,    -1,
     172,    -1,   176,    -1,   178,    -1,   164,    -1,    10,    82,
      16,    91,    35,    -1,    98,    -1,    -1,    -1,    93,    95,
      94,    -1,    92,    -1,    -1,    -1,    10,    82,    16,    96,
      97,    35,    -1,    98,    -1,    -1,    -1,    43,    18,    99,
      44,   100,    -1,    -1,    43,    18,   101,    44,    -1,    -1,
      -1,    -1,    16,   106,   103,    25,   104,   105,    35,    -1,
     113,    -1,   143,    -1,    -1,   107,   108,    -1,    -1,    -1,
      43,   143,   109,    44,   110,    -1,    -1,    43,   143,   111,
      44,    -1,    -1,     8,    39,   143,    40,    35,    -1,     9,
      39,    40,    -1,    -1,     6,    39,   137,    40,   115,    41,
      86,    42,   116,    -1,    -1,     7,   117,    41,    86,    42,
      -1,    -1,    -1,    -1,    11,   119,    39,   137,    40,    12,
     120,    41,    86,    42,    -1,    -1,    -1,    -1,    -1,    13,
     126,    16,   122,    39,   127,    40,   123,    41,    92,   124,
      86,    15,   143,   125,    42,    -1,    82,    -1,    14,    -1,
      -1,   128,    -1,    -1,    82,    16,   129,   130,    -1,    -1,
      38,   128,    -1,    -1,    16,   132,    39,   133,    40,    35,
      -1,    -1,   143,   134,   135,    -1,    -1,    38,   136,   133,
      -1,    -1,   140,   138,    -1,    -1,   139,   140,    -1,    33,
      -1,    34,    -1,   143,   141,    -1,    -1,   142,   143,    -1,
      32,    -1,    31,    -1,    25,    -1,    26,    25,    -1,    -1,
     147,   144,   145,    -1,    -1,   146,   143,    -1,    27,    -1,
      28,    -1,    -1,   151,   148,   149,    -1,    -1,   150,   147,
      -1,    29,    -1,    30,    -1,    -1,    39,   152,   140,    40,
      -1,   154,    -1,    -1,    16,   153,   106,    -1,    17,    -1,
      18,    -1,    19,    -1,    20,    -1,    -1,    45,    39,   157,
      38,    16,   156,    40,    35,    -1,    62,    -1,    61,    -1,
      63,    -1,    60,    -1,    -1,    46,    39,    16,   159,    40,
      35,    -1,    -1,    51,    39,    16,    38,   143,   161,    40,
      35,    -1,    -1,    49,    39,    16,    38,   143,    38,   143,
     163,    40,    35,    -1,    -1,    50,    39,    16,   165,    40,
      35,    -1,    -1,    48,    39,    16,    38,   143,   167,    40,
      35,    -1,    -1,    47,    39,    16,    38,   143,   169,    40,
      35,    -1,    -1,    52,    39,    16,   171,    40,    35,    -1,
      -1,    53,    39,    16,   173,    40,    35,    -1,    -1,    54,
      39,    16,    38,   143,   175,    40,    35,    -1,    -1,    55,
      39,    16,    38,   143,   177,    40,    35,    -1,    -1,    56,
      39,   180,   179,    40,    35,    -1,    57,    -1,    58,    -1,
      59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   245,   245,   246,   249,   245,   259,   261,   262,   264,
     267,   284,   284,   285,   286,   287,   289,   290,   292,   293,
     294,   297,   298,   299,   300,   302,   302,   302,   310,   311,
     312,   314,   315,   316,   317,   318,   319,   320,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     336,   345,   346,   349,   349,   350,   351,   353,   353,   371,
     372,   375,   375,   376,   376,   377,   380,   389,   380,   391,
     392,   393,   393,   394,   395,   395,   396,   396,   397,   399,
     401,   403,   403,   405,   405,   406,   410,   410,   410,   412,
     427,   430,   434,   412,   437,   438,   439,   440,   441,   441,
     450,   451,   453,   453,   462,   462,   463,   463,   464,   467,
     468,   469,   470,   471,   474,   475,   476,   477,   478,   479,
     480,   487,   487,   488,   489,   490,   491,   493,   493,   494,
     495,   496,   497,   499,   499,   500,   503,   501,   525,   538,
     553,   566,   580,   580,   582,   583,   584,   585,   587,   587,
     589,   589,   592,   592,   594,   594,   596,   596,   598,   598,
     600,   600,   602,   602,   604,   604,   606,   606,   608,   608,
     610,   611,   612
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "programa", "principal", "prototipo",
  "si", "no", "imprimir", "leer", "crear", "mientras", "hacer", "funcion",
  "neutral", "regresar", "id", "ctetexto", "cteentero", "ctedecimal",
  "ctebooleano", "entero", "decimal", "texto", "booleano", "igual",
  "diferente", "mas", "menos", "multiplicacion", "division", "mayor",
  "menor", "and", "or", "ptocoma", "dospuntos", "punto", "coma",
  "parentesisa", "parentesisc", "llavea", "llavec", "corchetea",
  "corchetec", "dibujarFigura", "borrarFigura", "girarIzquierda",
  "girarDerecha", "mover", "obtenerPosicion", "hablar", "obtenerAltura",
  "obtenerAnchura", "cambiarAltura", "cambiarAnchura", "colorFondo",
  "rojo", "azul", "verde", "carro", "persona", "perro", "gato",
  "verdadero", "falso", "$accept", "PROGRAMA", "$@1", "$@2", "$@3",
  "PROTOTIPOCICLO", "PROTOTIPOCICLO2", "PROTOTIPO", "PROTOTIPOFUNCION",
  "PROGRAMA1", "$@4", "PROGRAMA12", "PROGRAMA2", "PROGRAMA22",
  "PROGRAMASIG", "PROGRAMASIG2", "TIPO", "PRINCIPAL", "$@5", "$@6",
  "BLOQUE", "BLOQUE1", "ESTATUTO", "FUNCIONESPECIAL", "DECLARACION",
  "DECLARACION2", "DECLARACIONFUNCIONCICLO", "$@7",
  "DECLARACIONFUNCIONCICLO2", "DECLARACIONFUNCION", "$@8",
  "DECLARACIONFUNCION2", "ARREGLOS", "$@9", "ARREGLOS2", "$@10",
  "ASIGNACION", "$@11", "$@12", "ASIGNACION3", "ASIGNACION2", "$@13",
  "ARREGLOSASIG", "$@14", "ARREGLOSASIG2", "$@15", "ESCRITURA", "LECTURA",
  "CONDICION", "$@16", "CONDICION2", "$@17", "CICLO", "$@18", "$@19",
  "CREARFUNCION", "$@20", "$@21", "$@22", "$@23", "CREARFUNCION2",
  "CREARFUNCION3", "CREARFUNCION4", "$@24", "CREARFUNCION5",
  "LLAMARFUNCION", "$@25", "LLAMARFUNCION2", "$@26", "LLAMARFUNCION3",
  "$@27", "SUPEREXPRESION", "SUPEREXPRESION2", "SUPEREXPRESION3",
  "EXPRESION", "EXPRESION2", "EXPRESION3", "EXP", "$@28", "EXP2", "EXP3",
  "TERMINO", "$@29", "TERMINO2", "TERMINO3", "FACTOR", "$@30", "$@31",
  "VARCTE", "DIBUJARFIGURA", "$@32", "FIGURA", "BORRARFIGURA", "$@33",
  "HABLAR", "$@34", "MOVER", "$@35", "OBTENERPOSICION", "$@36", "GIRARDER",
  "$@37", "GIRARIZQ", "$@38", "OBTENERALTURA", "$@39", "OBTENERANCHURA",
  "$@40", "CAMBIARALTURA", "$@41", "CAMBIARANCHURA", "$@42", "COLORFONDO",
  "$@43", "COLOR", 0
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
     315,   316,   317,   318,   319,   320
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    68,    69,    70,    67,    71,    72,    72,    73,
      74,    76,    75,    77,    77,    78,    79,    79,    80,    81,
      81,    82,    82,    82,    82,    84,    85,    83,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    91,    91,    93,    92,    94,    94,    96,    95,    97,
      97,    99,    98,   101,   100,   100,   103,   104,   102,   105,
     105,   107,   106,   106,   109,   108,   111,   110,   110,   112,
     113,   115,   114,   117,   116,   116,   119,   120,   118,   122,
     123,   124,   125,   121,   126,   126,   127,   127,   129,   128,
     130,   130,   132,   131,   134,   133,   136,   135,   135,   137,
     138,   138,   139,   139,   140,   141,   141,   142,   142,   142,
     142,   144,   143,   145,   145,   146,   146,   148,   147,   149,
     149,   150,   150,   152,   151,   151,   153,   151,   154,   154,
     154,   154,   156,   155,   157,   157,   157,   157,   159,   158,
     161,   160,   163,   162,   165,   164,   167,   166,   169,   168,
     171,   170,   173,   172,   175,   174,   177,   176,   179,   178,
     180,   180,   180
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,    12,     2,     1,     0,     3,
       4,     0,     3,     1,     0,     2,     1,     0,     2,     1,
       0,     1,     1,     1,     1,     0,     0,     9,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     0,     0,     3,     1,     0,     0,     6,     1,
       0,     0,     5,     0,     4,     0,     0,     0,     7,     1,
       1,     0,     2,     0,     0,     5,     0,     4,     0,     5,
       3,     0,     9,     0,     5,     0,     0,     0,    10,     0,
       0,     0,     0,    16,     1,     1,     0,     1,     0,     4,
       0,     2,     0,     6,     0,     3,     0,     3,     0,     2,
       0,     2,     1,     1,     2,     0,     2,     1,     1,     1,
       2,     0,     3,     0,     2,     1,     1,     0,     3,     0,
       2,     1,     1,     0,     4,     1,     0,     3,     1,     1,
       1,     1,     0,     8,     1,     1,     1,     1,     0,     6,
       0,     8,     0,    10,     0,     6,     0,     8,     0,     8,
       0,     6,     0,     6,     0,     8,     0,     8,     0,     6,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,     4,     0,     0,
      11,     8,     0,     0,     0,     0,     7,     6,     0,     9,
      71,     0,    20,     0,    11,     0,    66,     0,     0,     0,
      17,    19,    18,    22,    23,    21,    24,     0,    13,    12,
      10,     0,     0,    72,    95,    94,     0,    25,     0,    16,
      15,    52,    67,   136,   138,   139,   140,   141,   133,    74,
     121,   127,   135,    89,     0,     5,     0,     0,    51,     0,
      73,     0,     0,   123,   129,     0,     0,    61,    50,     0,
       0,    69,    70,   137,     0,   115,    78,   125,   126,   122,
       0,   131,   132,   128,     0,    96,     0,     0,     0,    68,
     134,   119,     0,   118,   117,   114,     0,     0,    75,   124,
     130,     0,     0,    97,    26,    65,    80,   120,   116,    76,
      98,    90,    53,     0,    62,     0,   100,     0,     0,     0,
      63,    77,     0,    99,    53,     0,     0,    86,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    36,    31,    33,    34,    32,    35,    37,
      38,    39,    40,    41,    49,    43,    42,    44,    46,    45,
      47,    48,     0,    56,     0,   101,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    29,    28,     0,    55,    54,    64,
       0,     0,   110,     0,     0,     0,   147,   145,   144,   146,
       0,   148,     0,     0,     0,   154,     0,   160,   162,     0,
       0,   170,   171,   172,   168,    57,     0,    81,   112,   113,
     109,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,   111,    79,     0,     0,   108,   142,     0,   158,   156,
       0,     0,   150,     0,     0,   164,   166,     0,     0,    59,
      92,     0,    87,   103,   106,   105,     0,   149,     0,     0,
       0,   155,     0,   161,   163,     0,     0,   169,    58,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
      93,    85,     0,   107,   143,   159,   157,     0,   151,   165,
     167,    83,    82,     0,     0,     0,    88,   153,     0,     0,
      84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     8,    10,    17,    11,    13,    14,
      15,    39,    29,    50,    21,    32,   111,    48,    64,   122,
     151,   195,   152,   153,    24,    67,   128,   129,   198,   173,
     248,   268,    68,    97,   124,   174,   154,    41,    69,    80,
      26,    27,    43,    72,   108,   125,   155,   156,   157,   250,
     312,   315,   158,   179,   291,    30,    75,   127,   200,   289,
      46,   112,   113,   126,   133,   159,   180,   234,   255,   275,
     292,   201,   230,   231,   202,   105,   106,    85,    73,    89,
      90,    60,    74,    93,    94,    61,    71,    70,    62,   160,
     276,   210,   161,   237,   162,   282,   163,   307,   164,   241,
     165,   279,   166,   278,   167,   243,   168,   244,   169,   285,
     170,   286,   171,   247,   224
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -181
static const yytype_int16 yypact[] =
{
    -181,     7,     2,  -181,    -6,  -181,   -29,  -181,    39,    46,
    -181,    39,    24,    36,    63,    70,  -181,  -181,    64,  -181,
      56,    71,    63,    51,    67,    45,  -181,    43,    14,    83,
      71,  -181,  -181,  -181,  -181,  -181,  -181,    72,  -181,  -181,
    -181,    65,    50,  -181,  -181,  -181,    75,  -181,    52,  -181,
    -181,    49,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,    54,  -181,    77,    61,  -181,     6,
      55,    50,    53,    -9,    12,    60,    62,  -181,  -181,    66,
      68,  -181,  -181,  -181,    69,     8,    57,  -181,  -181,  -181,
      50,  -181,  -181,  -181,    50,    51,    73,    74,    76,  -181,
    -181,  -181,    79,  -181,  -181,  -181,    50,    50,  -181,  -181,
    -181,    85,    81,  -181,  -181,    80,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,    88,  -181,    78,    86,    84,     5,    97,
    -181,  -181,    51,  -181,  -181,    87,    89,  -181,   -19,    90,
      91,    92,    93,    94,    95,    96,    98,    99,   100,   101,
     102,   103,     5,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,    51,   105,   104,  -181,  -181,    50,    50,   107,
     108,   -31,   111,   126,   127,   128,   133,   134,   137,   138,
     139,   140,    19,  -181,  -181,  -181,   141,  -181,  -181,  -181,
       5,   118,    13,   119,    50,    50,  -181,  -181,  -181,  -181,
     122,  -181,   123,   130,   131,  -181,   132,  -181,  -181,   135,
     136,  -181,  -181,  -181,  -181,  -181,   149,  -181,  -181,  -181,
    -181,    50,    82,   125,   142,  -181,   150,   143,    50,    50,
      50,   144,    50,   145,   146,    50,    50,   147,    49,    50,
     148,  -181,  -181,   159,   153,   152,  -181,   156,  -181,  -181,
     154,   158,  -181,   160,   164,  -181,  -181,   166,   167,  -181,
    -181,     5,  -181,  -181,  -181,  -181,   165,  -181,   168,   169,
      50,  -181,   170,  -181,  -181,   171,   172,  -181,  -181,   173,
     174,   176,    50,   178,   179,   183,  -181,   184,   185,   186,
    -181,   106,     5,  -181,  -181,  -181,  -181,   182,  -181,  -181,
    -181,  -181,  -181,   181,   189,   187,  -181,  -181,     5,   188,
    -181
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,  -181,  -181,   161,  -181,  -181,  -181,   151,
    -181,  -181,   195,  -181,   155,  -181,   -20,  -181,  -181,  -181,
    -151,  -181,  -181,  -181,  -181,  -181,  -130,  -181,  -181,  -181,
    -181,  -181,  -140,  -181,  -181,  -181,    -5,  -181,  -181,  -181,
      40,  -181,  -181,  -181,  -181,  -181,  -181,    42,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,   -13,  -181,  -181,  -181,  -181,  -180,  -181,  -181,
    -181,   -28,  -181,  -181,   -69,  -181,  -181,   -42,  -181,  -181,
    -181,   112,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -103
static const yytype_int16 yytable[] =
{
      59,   194,    84,    37,   176,     4,   -73,     3,    45,    22,
       5,   135,     7,   136,    79,    79,   137,    22,    87,    88,
    -102,   138,    53,    54,    55,    56,    57,    82,    44,   206,
     207,   208,   209,   101,   102,    33,    34,    35,    36,   103,
     104,    91,    92,   197,     9,    58,   228,   229,   109,   226,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    12,    18,   118,   119,    53,    54,    55,    56,
      57,    19,    33,    34,    35,    36,   221,   222,   223,    20,
      23,   -73,    25,   -14,    28,    40,    42,    47,    51,    58,
      52,    63,    66,    76,    65,    77,    78,    86,   -71,    95,
     107,   120,    96,    99,   117,    98,   130,   172,   269,   100,
      83,    81,   303,   311,   114,   -53,   116,   252,   115,   175,
     290,   121,   131,   123,   132,   134,   177,   211,   178,   181,
     182,   183,   184,   185,   186,   187,   203,   188,   189,   190,
     191,   192,   212,   213,   214,   193,   204,   205,   199,   215,
     216,   313,   196,   217,   218,   219,   220,   225,   227,   232,
     236,   238,   251,   235,   249,   253,   256,   319,   239,   240,
     242,   272,    16,   245,   246,    38,   233,    31,     0,     0,
       0,     0,   254,   257,   261,   263,   264,   267,   273,   271,
     274,   277,   280,   281,     0,   283,   258,   259,   260,   284,
     262,   287,   288,   265,   266,   293,   110,   270,   294,   295,
     297,   298,   299,   304,   305,   300,   301,   302,   306,   308,
     309,   310,   314,   316,   317,    49,     0,     0,   318,     0,
     320,     0,     0,     0,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     235
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-181))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      42,   152,    71,    23,   134,     3,    25,     0,    28,    14,
      16,     6,    41,     8,     9,     9,    11,    22,    27,    28,
      39,    16,    16,    17,    18,    19,    20,    69,    14,    60,
      61,    62,    63,    25,    26,    21,    22,    23,    24,    31,
      32,    29,    30,   173,     5,    39,    33,    34,    90,   200,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    16,    39,   106,   107,    16,    17,    18,    19,
      20,    35,    21,    22,    23,    24,    57,    58,    59,    16,
      10,    25,    18,    16,    13,    40,    43,     4,    16,    39,
      25,    16,    43,    39,    42,    18,    35,    44,    43,    39,
      43,    16,    40,    35,    25,    39,    18,    10,   248,    40,
      70,    69,   292,     7,    41,    10,    40,    35,    44,   132,
     271,    40,    44,    43,    38,    41,    39,    16,    39,    39,
      39,    39,    39,    39,    39,    39,   178,    39,    39,    39,
      39,    39,    16,    16,    16,    42,    39,    39,    44,    16,
      16,   302,   172,    16,    16,    16,    16,    16,    40,    40,
      38,    38,   231,   205,    15,    40,    16,   318,    38,    38,
      38,    12,    11,    38,    38,    24,   204,    22,    -1,    -1,
      -1,    -1,    40,    40,    40,    40,    40,    40,    35,    41,
      38,    35,    38,    35,    -1,    35,   238,   239,   240,    35,
     242,    35,    35,   245,   246,    40,    94,   249,    40,    40,
      40,    40,    40,    35,    35,    42,    42,    41,    35,    35,
      35,    35,    40,    42,    35,    30,    -1,    -1,    41,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     292
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,     3,    16,    69,    41,    70,     5,
      71,    73,    16,    74,    75,    76,    71,    72,    39,    35,
      16,    80,   102,    10,    90,    18,   106,   107,    13,    78,
     121,    80,    81,    21,    22,    23,    24,    82,    75,    77,
      40,   103,    43,   108,    14,    82,   126,     4,    83,    78,
      79,    16,    25,    16,    17,    18,    19,    20,    39,   143,
     147,   151,   154,    16,    84,    42,    43,    91,    98,   104,
     153,   152,   109,   144,   148,   122,    39,    18,    35,     9,
     105,   113,   143,   106,   140,   143,    44,    27,    28,   145,
     146,    29,    30,   149,   150,    39,    40,    99,    39,    35,
      40,    25,    26,    31,    32,   141,   142,    43,   110,   143,
     147,    82,   127,   128,    41,    44,    40,    25,   143,   143,
      16,    40,    85,    43,   100,   111,   129,   123,    92,    93,
      18,    44,    38,   130,    41,     6,     8,    11,    16,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    86,    88,    89,   102,   112,   113,   114,   118,   131,
     155,   158,   160,   162,   164,   166,   168,   170,   172,   174,
     176,   178,    10,    95,   101,   128,    92,    39,    39,   119,
     132,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    42,    86,    87,    82,    92,    94,    44,
     124,   137,   140,   143,    39,    39,    60,    61,    62,    63,
     157,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      16,    57,    58,    59,   180,    16,    86,    40,    33,    34,
     138,   139,    40,   137,   133,   143,    38,   159,    38,    38,
      38,   165,    38,   171,   173,    38,    38,   179,    96,    15,
     115,   140,    35,    40,    40,   134,    16,    40,   143,   143,
     143,    40,   143,    40,    40,   143,   143,    40,    97,    98,
     143,    41,    12,    35,    38,   135,   156,    35,   169,   167,
      38,    35,   161,    35,    35,   175,   177,    35,    35,   125,
      86,   120,   136,    40,    40,    40,   143,    40,    40,    40,
      42,    42,    41,   133,    35,    35,    35,   163,    35,    35,
      35,     7,   116,    86,    40,   117,    42,    35,    41,    86,
      42
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
#line 245 "sintatico.y"
    {file = fopen("cuadruplos.txt","w+"); generarMain();}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 246 "sintatico.y"
    {struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
		     insertProc(&tblProc,&tablaGlobal,&tablaParametros,(yyvsp[(3) - (3)].string),(yyvsp[(3) - (3)].string), 0,0,0);
 numeroFunciones++;}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 249 "sintatico.y"
    {
	strcpy(nombreFuncion, "main"); 
		numeroParametros=0; 
		struct StrHashTable tablaLocalFuncion = {{0},NULL,NULL,foo_strhash,strcmp};
		struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
		insertProc(&tblProc,&tablaLocalFuncion,&tablaParametros,nombreFuncion,nombreFuncion,0,0,0);	
}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 257 "sintatico.y"
    {generarEnd();}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 267 "sintatico.y"
    {
			
			numeroParametros=0;
			strcpy(nombreFuncion, (yyvsp[(1) - (4)].string)); 
			int cantidadParametros = atoi((yyvsp[(3) - (4)].string));
			printf("\n++++++++++Nombe Funcion:%s\n\n", nombreFuncion);
			struct StrHashTable tablaLocalFuncion = {{0},NULL,NULL,foo_strhash,strcmp};
			struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
			insertProc(&tblProc,&tablaLocalFuncion,&tablaParametros,nombreFuncion,nombreFuncion,cantidadParametros,0,0);
			numeroFunciones++;
				 
		}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 284 "sintatico.y"
    {alcanceDireccion=1;/*global*/}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 297 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroStringLocales++;/*printf("===========tipo: %i\n", tipoOp);*/ }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 298 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroIntLocales++; /*printf("===========tipo: %i\n", tipoOp);*/ }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 299 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); numeroFloatLocales++;/*printf("===========tipo: %i\n", tipoOp);*/}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 300 "sintatico.y"
    {tipoOp = generarTipo((yyvsp[(1) - (1)].string)); /*printf("===========tipo: %i\n", tipoOp);*/}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 302 "sintatico.y"
    {llenarMain(); strcpy(nombreFuncion, "main"); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 302 "sintatico.y"
    {
			direccionEnteroLocal=11000;
			direccionDobleLocal=21000;
			direccionTextoLocal=31000;
			direccionBooleanoLocal=41000;
}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 336 "sintatico.y"
    {insert(&tablaGlobal,(yyvsp[(3) - (5)].string),(yyvsp[(3) - (5)].string),tipoOp,generarDireccion(tipoOp,1),dimensiones[0], dimensiones[1]);
			
				direccionAux=m0;			   
				if(esArreglo==1) {
				    	esArreglo=0; /*la siguiente direccion base sera normal*/
				    } else {m0=1; 
					direccionAux=m0;
					}
				     }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 349 "sintatico.y"
    {alcanceDireccion=2;/*local*/}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 353 "sintatico.y"
    {



				numeroDimension=0;
				dimensionArreglo dimensionNueva = {0,0,0};
				dimensiones[0]= dimensionNueva;
				dimensiones[1]= dimensionNueva;}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 362 "sintatico.y"
    {insert(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(3) - (6)].string),(yyvsp[(3) - (6)].string),tipoOp,generarDireccion(tipoOp,2),dimensiones[0], dimensiones[1]);
			direccionAux=m0;			
			if(esArreglo==1) {
				esArreglo=0; /*la siguiente direccion base sera normal*/
			} else {m0=1;
				direccionAux=m0;
				}
			numeroVarLocales++;}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 371 "sintatico.y"
    {operacionesArreglos();}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 375 "sintatico.y"
    {dimensionesArreglos1(atoi((yyvsp[(2) - (2)].string)));}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 376 "sintatico.y"
    {{dimensionesArreglos2(atoi((yyvsp[(2) - (2)].string)));}}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 380 "sintatico.y"
    {int tipoId = getType(&tablaGlobal,(yyvsp[(1) - (2)].string));
			    if(tipoId==0)
				tipoId = getType(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(1) - (2)].string));
			    int direccionVirtual = getDirection(&tablaGlobal,(yyvsp[(1) - (2)].string));
			    if(direccionVirtual==-1)
				direccionVirtual = getDirection(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(1) - (2)].string));
			    push(&pilaOperadores, (yyvsp[(1) - (2)].string), tipoId, direccionVirtual); 
				printf("\n\nHIzo pussh: tipo %i, direcicn %i\n\n",tipoId,direccionVirtual);
}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 389 "sintatico.y"
    { push(&pilaOperando, (yyvsp[(4) - (4)].string), -1, -1);}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 390 "sintatico.y"
    {checarOperando3();}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 393 "sintatico.y"
    {numeroDimension=1;}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 393 "sintatico.y"
    {hacerPush=1;}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 395 "sintatico.y"
    {generarDimension1();}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 396 "sintatico.y"
    {generarDimension2();}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 399 "sintatico.y"
    {generarImprimir();}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 401 "sintatico.y"
    {generarLectura();}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 403 "sintatico.y"
    {secuenciaIf1();}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 403 "sintatico.y"
    {secuenciaIf2();}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 405 "sintatico.y"
    {secuenciaElse();}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 410 "sintatico.y"
    {secuenciaWhile1();}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 410 "sintatico.y"
    {secuenciaWhile2();}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 410 "sintatico.y"
    {secuenciaWhile3();}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 412 "sintatico.y"
    {
				direccionEnteroLocal=11000;
				direccionDobleLocal=21000;
				direccionTextoLocal=31000;
				direccionBooleanoLocal=41000;

					strcpy(nombreFuncion, (yyvsp[(3) - (3)].string)); 
					/*numeroParametros=0;
					strcpy(nombreFuncion, $3); 
					printf("\n++++++++++Nombe Funcion:%s\n\n", nombreFuncion);
					struct StrHashTable tablaLocalFuncion = {{0},NULL,NULL,foo_strhash,strcmp};
					struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
					insertProc(&tblProc,&tablaLocalFuncion,&tablaParametros,nombreFuncion,nombreFuncion,0,0,0);
					numeroFunciones++;*/
					}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 427 "sintatico.y"
    {
					setNumberParameters(&tblProc,nombreFuncion,numeroParametros);
					 }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 430 "sintatico.y"
    {setNumberLocalVars(&tblProc,nombreFuncion,numeroVarLocales);
					 
					setCuadruploInicial(&tblProc,nombreFuncion,contS);
					 }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 434 "sintatico.y"
    {generarReturn();}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 434 "sintatico.y"
    {generarRetorno();}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 441 "sintatico.y"
    {int direccion = generarDireccion(tipoOp,2);
			char numeroParametrosString[3];
			numeroParametros++;
			sprintf(numeroParametrosString, "%i", numeroParametros);
			//insert(getPointerParTbl(&tblProc,nombreFuncion),numeroParametrosString,$2,tipoOp,direccion,dimensiones[0], dimensiones[1]);
			insert(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(2) - (2)].string),(yyvsp[(2) - (2)].string),tipoOp,generarDireccion(tipoOp,2),dimensiones[0], dimensiones[1]);
			printf("\n\nDIRECCION PARAMETRO %i, %i,%s\n\n", direccion, getType(getPointerParTbl(&tblProc,nombreFuncion),numeroParametrosString), numeroParametrosString);
			}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 453 "sintatico.y"
    {	strcpy(nombreFuncion, (yyvsp[(1) - (1)].string)); 
			if(getProc(&tblProc,(yyvsp[(1) - (1)].string))==1){
				printf("\n______Llamada EXISTENTE!!__ \"%s, %i\"\n", nombreFuncion,getNumberParameters(&tblProc,(yyvsp[(1) - (1)].string)) );
				 generarEra(getNumberLocalVars(&tblProc,(yyvsp[(1) - (1)].string)));
				
			}
			else printf("\nLlamada a un procedimiento que no existe: \"%s\"\n", nombreFuncion );
			
		}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 461 "sintatico.y"
    {generarGoSub();}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 462 "sintatico.y"
    {generarParametro();}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 463 "sintatico.y"
    {apuntadorParametro++;}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 476 "sintatico.y"
    {  checarOperando3();   }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 477 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 478 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 479 "sintatico.y"
    {push(&pilaOperando, (yyvsp[(1) - (1)].string), -1, -1);}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 480 "sintatico.y"
    {char* str = (yyvsp[(1) - (2)].string);
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, (yyvsp[(2) - (2)].string) ); 
				      push(&pilaOperando, str, -1, -1);}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 487 "sintatico.y"
    {  checarOperando2();   }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 490 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 491 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 493 "sintatico.y"
    { checarOperando1();   }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 496 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 497 "sintatico.y"
    {push(&pilaOperando,(yyvsp[(1) - (1)].string),-1, -1);}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 499 "sintatico.y"
    { push(&pilaOperando,(yyvsp[(1) - (1)].string),-1,-1); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 499 "sintatico.y"
    {pop(&pilaOperando);}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 503 "sintatico.y"
    {/*int tipoId = getType(&tbl,$1);

				int direccionVirtual = generarDireccion(tipoId, alcanceDireccion);
				push(&pilaOperadores, $1, tipoId, direccionVirtual); */
	//////////////////
				int tipoId = getType(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(1) - (1)].string));
				int direccion= getDirection(getPointerTbl(&tblProc,nombreFuncion),(yyvsp[(1) - (1)].string));
				if (direccion == -1) 
					printf("\nVariable %s\n no declarada", (yyvsp[(1) - (1)].string));
				else{
					//direccion=generarDireccion(tipoId, alcanceDireccion);
					printf("\n\n\n´´´´´´´´USAARR Variable %s\n\n", (yyvsp[(1) - (1)].string));
 					push(&pilaOperadores, (yyvsp[(1) - (1)].string), tipoId, direccion);
				}
			
				 
}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 525 "sintatico.y"
    {if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
							int direccion= getDirection(&tablaConstantes,(yyvsp[(1) - (1)].string));
							if (direccion == -1)direccion=generarDireccion(3, 5);
						  push(&pilaOperadores, (yyvsp[(1) - (1)].string), 3, direccion);
						  if(insert(&tablaConstantes,(yyvsp[(1) - (1)].string),(yyvsp[(1) - (1)].string),3,direccion,dimensiones[0], dimensiones[1])!= -1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, (yyvsp[(1) - (1)].string)); strcat(strDirecciones,"\n");
						   }
					}}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 538 "sintatico.y"
    {if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						   	int direccion= getDirection(&tablaConstantes,(yyvsp[(1) - (1)].string));
							if (direccion == -1)direccion=generarDireccion(1, 5);
						   push(&pilaOperadores, (yyvsp[(1) - (1)].string), 1, direccion);
						  // printf("\n\nHIzo pussh: tipo %i, direcicn %i\n\n",1,direccion);
	   
						   if(insert(&tablaConstantes,(yyvsp[(1) - (1)].string),(yyvsp[(1) - (1)].string),1,direccion,dimensiones[0], dimensiones[1])!= -1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string); 
							  strcat(strDirecciones,(yyvsp[(1) - (1)].string)); strcat(strDirecciones,"\n"); 
					          }
					}}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 553 "sintatico.y"
    {if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						  	int direccion= getDirection(&tablaConstantes,(yyvsp[(1) - (1)].string));
							if (direccion == -1)direccion=generarDireccion(2, 5);
						   push(&pilaOperadores, (yyvsp[(1) - (1)].string), 2, direccion);
						   if(insert(&tablaConstantes,(yyvsp[(1) - (1)].string),(yyvsp[(1) - (1)].string),2,direccion,dimensiones[0], dimensiones[1])!=-1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, (yyvsp[(1) - (1)].string)); strcat(strDirecciones,"\n");  
						   }
					}}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 566 "sintatico.y"
    {if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						  	int direccion= getDirection(&tablaConstantes,(yyvsp[(1) - (1)].string));
							if (direccion == -1)direccion=generarDireccion(4, 5);
						  push(&pilaOperadores, (yyvsp[(1) - (1)].string), 4, direccion);
						  if(insert(&tablaConstantes,(yyvsp[(1) - (1)].string),(yyvsp[(1) - (1)].string),4,direccion, dimensiones[0], dimensiones[1])!=-1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, (yyvsp[(1) - (1)].string)); strcat(strDirecciones,"\n"); 
						  }
					}}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 580 "sintatico.y"
    {generarDibujarFigura();}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 587 "sintatico.y"
    {generarBorrarFigura();}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 589 "sintatico.y"
    {generarHablarFigura();}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 592 "sintatico.y"
    {generarMoverFigura();}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 594 "sintatico.y"
    {/* generarObtenerPosicion();*/ }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 596 "sintatico.y"
    {generarGirarD();}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 598 "sintatico.y"
    {generarGirarI();}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 600 "sintatico.y"
    {generarObtenerAltura();}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 602 "sintatico.y"
    {generarObtenerAnchura();}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 604 "sintatico.y"
    {generarCambiarAltura();}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 606 "sintatico.y"
    {generarCambiarAnchura();}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 608 "sintatico.y"
    {generarColorFondo();}
    break;



/* Line 1806 of yacc.c  */
#line 2569 "sintatico.tab.c"
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
#line 614 "sintatico.y"


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

	int cantidadDirecciones;	//saber si sumar una direccion o la cantidad necesaria para arreglos

	//Checar si hay direccion auxiliar para arreglos
	if(direccionAux != 1)
		cantidadDirecciones = direccionAux;
	else
		cantidadDirecciones = 1;

	//printf("\n***************CANTIDAD DIRECCIONSSS!!! %i**************\n", cantidadDirecciones );

	//global	
	if(alcance==1){ 
		//printf(">>>>>>>>>>>>>>>>>>ALCANCE GLOBAL\n");
		if(tipo==1) //entero
			{ contEnteroGlobal++;
			direccionEnteroGlobal += cantidadDirecciones;
			return direccionEnteroGlobal;}
		else if(tipo==2){ //doble
			contDobleGlobal++;
			direccionDobleGlobal += cantidadDirecciones;
			return direccionDobleGlobal;}
		else if(tipo==3) {//texto
			contTextoGlobal++;
			direccionTextoGlobal += cantidadDirecciones;
			return direccionTextoGlobal;}
		else if(tipo==4){ //booleano
			contBooleanoGlobal++;
			direccionBooleanoGlobal += cantidadDirecciones;
			return direccionBooleanoGlobal;}
	}
	 //local
	else if(alcance==2){
		//printf(">>>>>>>>>>>>>>>>>>ALCANCE LOCAL\n");
		if(tipo==1) {//entero
			contEnteroLocal++;
			direccionEnteroLocal += cantidadDirecciones;
			return direccionEnteroLocal;}
		else if(tipo==2){ //doble
			contDobleLocal++;
			direccionDobleLocal += cantidadDirecciones;
			return direccionDobleLocal;}
		else if(tipo==3) {//texto
			contTextoLocal++;
			direccionTextoLocal += cantidadDirecciones;
			return direccionTextoLocal;}
		else if(tipo==4) {//booleano
			contBooleanoLocal++;
			direccionBooleanoLocal += cantidadDirecciones;
			return direccionBooleanoLocal;}
	}
	//temp
	else if (alcance==3){ 
		//printf(">>>>>>>>>>>>>>>>>>ALCANCE TEMPORAL\n");
		if(tipo==1){// entero
			contEnteroTemp++;
			direccionEnteroTemp += cantidadDirecciones;
			return direccionEnteroTemp;}
		else if(tipo==2) {//doble
			contDobleTemp++;
			direccionDobleTemp += cantidadDirecciones;
			return direccionDobleTemp;}
		else if(tipo==3){ //texto
			contTextoTemp++;
			direccionTextoTemp += cantidadDirecciones;
			return direccionTextoTemp;}
		else if(tipo==4){ //booleano
			contBooleanoTemp++;
			direccionBooleanoTemp += cantidadDirecciones;
			return direccionBooleanoTemp;}
	}
	//Constante
	else if (alcance==5){ 
		if(tipo==1){// entero
			contEnteroConstante++;
			direccionEnteroConstante += cantidadDirecciones;
			return direccionEnteroConstante;}
		else if(tipo==2) {//doble
			contDobleConstante++;
			direccionDobleConstante += cantidadDirecciones;
			return direccionDobleConstante;}
		else if(tipo==3){ //texto
			contTextoConstante++;
			direccionTextoConstante += cantidadDirecciones;
			return direccionTextoConstante;}
		else if(tipo==4) {//booleano
			contBooleanoConstante++;
			direccionBooleanoConstante += cantidadDirecciones;
			return direccionBooleanoConstante;}
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
				
				insert(&tablaTemporal,nombreT,nombreT,semanticaValida,res,dimensiones[0], dimensiones[1]);

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

				insert(&tablaTemporal,nombreT,nombreT,semanticaValida,res,dimensiones[0], dimensiones[1]);

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

					insert(&tablaTemporal,nombreT,nombreT,semanticaValida,res,dimensiones[0], dimensiones[1]);

					generarCuadruplo(numOp ,operador2->direccion, -1, res);
					//printf("operando3 semantica %i\n", semanticaValida);
					push(&pilaOperadores,nombreT,semanticaValida,res);//3: direccion temporal
				}
				
				else{
					pop(&pilaOperando);

					operador2->valor = pilaOperadores->valor;
					operador2->tipo = pilaOperadores->tipo; 
					operador2->direccion = pilaOperadores->direccion;
					pop(&pilaOperadores);

					operador1->valor = pilaOperadores->valor;
					operador1->tipo = pilaOperadores->tipo; 
					operador1->direccion = pilaOperadores->direccion;
					pop(&pilaOperadores);

					//printf("TIPO op1: %i , op2: %i \n", operador1->tipo, operador2->tipo);
					//push(&pilaOperadores,"t",1, 3);//3: direccion temporal
				
					sprintf(nombreT, "t%i", contT++);

					semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
					res = generarDireccion(semanticaValida,3); //3:direccion temporal

					insert(&tablaTemporal,nombreT,nombreT,semanticaValida,res,dimensiones[0], dimensiones[1]);

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

void generarReturn(){

	int numeroReturn = 24;
	
	ptr regresar= malloc (sizeof(p_Nodo)); 
	
	regresar->valor = pilaOperadores->valor;
	regresar->tipo = pilaOperadores->tipo; 
	regresar->direccion = pilaOperadores->direccion; 
	
	pop(&pilaOperadores);
	
	generarCuadruplo(numeroReturn,regresar->direccion,-1,-1);// param=23
}

void generarEnd(){

	int numeroEnd = 30;
	generarCuadruplo(numeroEnd,-1,-1,-1);// param=23
}

void generarDimension1(){
	

	int numeroVerifica = 27;
	char nombreT[10];

	ptr operador1= malloc (sizeof(p_Nodo)); 
	ptr id= malloc (sizeof(p_Nodo)); 

	//dimension 1
	operador1->valor = pilaOperadores->valor;
	operador1->tipo = pilaOperadores->tipo; 
	operador1->direccion = pilaOperadores->direccion; 
	pop(&pilaOperadores);

	//id
	id->valor = pilaOperadores->valor;
	id->tipo = pilaOperadores->tipo; 
	id->direccion = pilaOperadores->direccion; 

	dimensionArreglo d = getDimension1(getPointerTbl(&tblProc,nombreFuncion),id->valor);
	int limInf=0;
	int limSup= d.cantidad-1;

	printf("\n\n\n\n-########## ### # ### ### ## # ##    CANTIDADD %i, DIRECCION %i\n\n", d.cantidad, id->direccion );
	
	generarCuadruplo(numeroVerifica,atoi(operador1->valor),limInf,limSup);// param=23

	//verificar si hay otra dimension
	dimensionArreglo d2 = getDimension2(getPointerTbl(&tblProc,nombreFuncion),id->valor);
	if(d2.cantidad == 0){	//la dimension 2 esta vacia

		pop(&pilaOperadores);	//Quitar el id 

		sprintf(nombreT, "t%i", contT++);

		int res = generarDireccion(1,3); //3:direccion temporal entera
		insert(&tablaTemporal,nombreT,nombreT,1,res,dimensiones[0], dimensiones[1]);
		generarCuadruplo(0, atoi(operador1->valor),operador1->direccion, res);	// multiplocacion	
		push(&pilaOperadores,nombreT,1,res);//3: direccion temporal

	} else {	//si hay una segunda dimension

		//ptr operador1= malloc (sizeof(p_Nodo)); 
		//ptr operador2= malloc (sizeof(p_Nodo)); 
		
		/*
		operador1->valor = pilaOperadores->valor;
		operador1->tipo = pilaOperadores->tipo; 
		operador1->direccion = pilaOperadores->direccion; 
		pop(&pilaOperadores);
		
		operador2->valor = pilaOperadores->valor;
		operador2->tipo = pilaOperadores->tipo; 
		operador2->direccion = pilaOperadores->direccion; 
		pop(&pilaOperadores);
		*/
		sprintf(nombreT, "t%i", contT++);

		int res = generarDireccion(1,3); //3:direccion temporal entera
		insert(&tablaTemporal,nombreT,nombreT,1,res,dimensiones[0], dimensiones[1]);
		generarCuadruplo(2, atoi(operador1->valor), d.m, res);	// multiplocacion	
		push(&pilaOperadores,nombreT,1,res);//3: direccion temporal
	}

}

void generarDimension2(){

		char nombreT[10];
		int numeroVerifica = 27;
		
		ptr operador1= malloc (sizeof(p_Nodo)); 
		ptr aux= malloc (sizeof(p_Nodo)); 
		ptr id= malloc (sizeof(p_Nodo)); 
		
		//Indice Segunda dimension
		operador1->valor = pilaOperadores->valor;
		operador1->tipo = pilaOperadores->tipo; 
		operador1->direccion = pilaOperadores->direccion; 
		pop(&pilaOperadores);
			
		//M almacenada
		aux->valor = pilaOperadores->valor;
		aux->tipo = pilaOperadores->tipo; 
		aux->direccion = pilaOperadores->direccion; 
		pop(&pilaOperadores);

		//id
		id->valor = pilaOperadores->valor;
		id->tipo = pilaOperadores->tipo; 
		id->direccion = pilaOperadores->direccion; 
		pop(&pilaOperadores);
			
		dimensionArreglo d = getDimension2(getPointerTbl(&tblProc,nombreFuncion),id->valor);
		int limInf=0;
		int limSup= d.cantidad-1;
	
		generarCuadruplo(numeroVerifica,atoi(operador1->valor),limInf,limSup);// param=23
	
		sprintf(nombreT, "t%i", contT++);

		int res = generarDireccion(1,3); //3:direccion temporal entera
		insert(&tablaTemporal,nombreT,nombreT,1,res,dimensiones[0], dimensiones[1]);
		generarCuadruplo(0, atoi(operador1->valor),aux->direccion, res);	// multiplocacion	
		push(&pilaOperadores,nombreT,1,res);//3: direccion temporal
	
}

void generarVerifica(){

	
}

//funciones especiales

void generarDibujarFigura()
{
	int numDibujaFigura=40;
	
	//generaCuadruplo(numDibujaFigura,dirID ,numPersonaje ,-1);
	

}

void generarBorrarFigura(){

	int borrar=41;

	//generarCuadruplo(borrar, dirID  ,-1,-1);

}


void generarHablarFigura(){
	int hablar=42;

	//generarCuadruplo(hablar,dirEXP   ,-1,-1);

}


void generarMoverFigura(){
	
	//generarCuadruplo(43,idDir,x,y)

}

void generarObtenerX(){
	
	//generarCuadruplo(44,idDir,-1,-1)

}

void generarObtenerY(){
	
	//generarCuadruplo(45,idDir,-1,-1)

}

void generarGirarD(){
	
	//generarCuadruplo(46,idDir,-1,-1)

}

void generarGirarI(){
	
	//generarCuadruplo(47,idDir,-1,-1)

}

void generarObtenerAnchura(){
	
	//generarCuadruplo(48,idDir,-1,-1)

}

void generarObtenerAltura(){
	
	//generarCuadruplo(49,idDir,-1,-1)

}

void generarCambiarAnchura(){
	
	//generarCuadruplo(50,idDir,EXP,-1)

}

void generarCambiarAltura(){
	
	//generarCuadruplo(51,idDir,EXP,-1)

}

void generarColorFondo(){
	
	//generarCuadruplo(52,idDir,-1,-1)

}


/*
   ###    ########  ########  ########  ######   ##        #######   ######  
  ## ##   ##     ## ##     ## ##       ##    ##  ##       ##     ## ##    ## 
 ##   ##  ##     ## ##     ## ##       ##        ##       ##     ## ##       
##     ## ########  ########  ######   ##   #### ##       ##     ##  ######  
######### ##   ##   ##   ##   ##       ##    ##  ##       ##     ##       ## 
##     ## ##    ##  ##    ##  ##       ##    ##  ##       ##     ## ##    ## 
##     ## ##     ## ##     ## ########  ######   ########  #######   ######  

*/
void dimensionesArreglos1(int cantidadElementos){

	esArreglo=1;	//la variable si es un arreglo'
	numeroDimension = 1;
	r = 1;
	r = r * cantidadElementos;
	m0=r;

	dimensionArreglo dimensionNueva = {numeroDimension,cantidadElementos,0};
	dimensiones[0] = dimensionNueva;
	printf("\nDIMENSION 1 !!! %i\n", cantidadElementos);
}

void dimensionesArreglos2(int cantidadElementos){

	esArreglo=1;	//la variable si es un arreglo
	numeroDimension = 2;
	r = r * cantidadElementos;
	m0=r;

	printf("\nDIMENSION 2 !!! %i\n", cantidadElementos);

	dimensionArreglo dimensionNueva = {numeroDimension,cantidadElementos,0};
	dimensiones[1] = dimensionNueva;

}

void operacionesArreglos(){

	int i; //para recorrer el arreglo de dimensiones
	int m=r;

	for (i=0; i<numeroDimension; i++){
		dimensiones[i].m = m / dimensiones[i].cantidad;
		m = dimensiones[i].m;
	}
}




/*
 ######  ######## ##     ##    ###    ##    ## ######## ####  ######     ###    
##    ## ##       ###   ###   ## ##   ###   ##    ##     ##  ##    ##   ## ##   
##       ##       #### ####  ##   ##  ####  ##    ##     ##  ##        ##   ##  
 ######  ######   ## ### ## ##     ## ## ## ##    ##     ##  ##       ##     ## 
      ## ##       ##     ## ######### ##  ####    ##     ##  ##       ######### 
##    ## ##       ##     ## ##     ## ##   ###    ##     ##  ##    ## ##     ## 
 ######  ######## ##     ## ##     ## ##    ##    ##    ####  ######  ##     ## 
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


