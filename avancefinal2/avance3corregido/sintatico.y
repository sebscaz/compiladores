%{
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
char idDelArreglo[20];
int direccionIdArreglo;

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

%}


%union {int cteint; float ctefloat; int cteboolean; char *string;} 

%token programa
%token principal
%token prototipo
%token si
%token no
%token imprimir
%token leer
%token crear
%token mientras
%token hacer
%token funcion
%token neutral
%token regresar

%token <string>id
%token <string>ctetexto
%token <string>cteentero
%token <string>ctedecimal
%token <string>ctebooleano
%token <string>entero
%token <string>decimal
%token <string>texto
%token <string>booleano

%token <string>igual
%token <string>diferente
%token <string>mas
%token <string>menos
%token <string>multiplicacion
%token <string>division
%token <string>mayor
%token <string>menor
%token and
%token or

%token ptocoma
%token dospuntos
%token punto
%token coma

%token <string>parentesisa
%token parentesisc
%token llavea
%token llavec
%token corchetea
%token corchetec

%token dibujarFigura
%token borrarFigura
%token girarIzquierda	
%token girarDerecha
%token mover
%token obtenerPosicion
%token hablar
%token obtenerAltura
%token obtenerAnchura
%token cambiarAltura
%token cambiarAnchura
%token colorFondo

%token rojo
%token azul
%token verde
%token carro
%token persona
%token perro
%token gato

%token verdadero
%token falso

%start PROGRAMA

%%

PROGRAMA: {file = fopen("cuadruplos.txt","w+"); generarMain();}
	 programa id {struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
		     insertProc(&tblProc,&tablaGlobal,&tablaParametros,$3,$3, 0,0,0);
 numeroFunciones++;}  llavea 
{
	printf("\n\n====INSERT MIAN\n");
	strcpy(nombreFuncion, "main"); 
		numeroParametros=0; 
		struct StrHashTable tablaLocalFuncion = {{0},NULL,NULL,foo_strhash,strcmp};
		struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
		insertProc(&tblProc,&tablaLocalFuncion,&tablaParametros,nombreFuncion,nombreFuncion,0,0,0);	

}

PROTOTIPOCICLO PROGRAMA1 PROGRAMASIG PROGRAMA2 PRINCIPAL  llavec {generarEnd();};

PROTOTIPOCICLO:PROTOTIPO PROTOTIPOCICLO2;

PROTOTIPOCICLO2: PROTOTIPOCICLO
	|/**/;

PROTOTIPO: prototipo PROTOTIPOFUNCION ptocoma;


PROTOTIPOFUNCION: id parentesisa cteentero parentesisc {
			
			numeroParametros=0;
			strcpy(nombreFuncion, $1); 
			int cantidadParametros = atoi($3);
			printf("\n++++++++++Nombe Funcion:%s\n\n", nombreFuncion);
			struct StrHashTable tablaLocalFuncion = {{0},NULL,NULL,foo_strhash,strcmp};
			struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
			insertProc(&tblProc,&tablaLocalFuncion,&tablaParametros,nombreFuncion,nombreFuncion,cantidadParametros,0,0);
			numeroFunciones++;
				 
		} 
	;




PROGRAMA1: {alcanceDireccion=1;/*global*/}DECLARACION PROGRAMA12;
PROGRAMA12: PROGRAMA1
		  | /*vacio*/;
PROGRAMA2: CREARFUNCION PROGRAMA22;

PROGRAMA22: PROGRAMA2
		  | /*vacio*/;

PROGRAMASIG: ASIGNACION PROGRAMASIG2;
PROGRAMASIG2: PROGRAMASIG
	| /*vacio*/;


TIPO: texto		{tipoOp = generarTipo($1); numeroStringLocales++;/*printf("===========tipo: %i\n", tipoOp);*/ }
	| entero	{tipoOp = generarTipo($1); numeroIntLocales++; /*printf("===========tipo: %i\n", tipoOp);*/ }
	| decimal	{tipoOp = generarTipo($1); numeroFloatLocales++;/*printf("===========tipo: %i\n", tipoOp);*/}
	| booleano	{tipoOp = generarTipo($1); /*printf("===========tipo: %i\n", tipoOp);*/};	

PRINCIPAL: principal {llenarMain(); strcpy(nombreFuncion, "main"); } parentesisa parentesisc llavea {
			
			//Resetear direcciones locales y temporales
			direccionEnteroLocal=11000;
			direccionDobleLocal=21000;
			direccionTextoLocal=31000;
			direccionBooleanoLocal=41000;

			direccionEnteroTemp=12000;
			direccionDobleTemp=22000;
			direccionTextoTemp=32000;
			direccionBooleanoTemp=42000;

}
DECLARACIONFUNCIONCICLO BLOQUE llavec;
	
BLOQUE: ESTATUTO BLOQUE1;
BLOQUE1: BLOQUE;
BLOQUE1: /*vacio*/;

ESTATUTO: ASIGNACION
		| CONDICION
		| ESCRITURA
		| LECTURA
		| CICLO
		| FUNCIONESPECIAL
		| LLAMARFUNCION;			

FUNCIONESPECIAL: DIBUJARFIGURA
				| BORRARFIGURA
				| HABLAR
				| MOVER
				| GIRARIZQ
				| GIRARDER
				| OBTENERALTURA
				| CAMBIARALTURA
				| OBTENERANCHURA
				| CAMBIARANCHURA
				| COLORFONDO
				| OBTENERPOSICION;

				
DECLARACION: crear TIPO id DECLARACION2 ptocoma  {insert(&tablaGlobal,$3,$3,tipoOp,generarDireccion(tipoOp,1),dimensiones[0], dimensiones[1]);
			
				direccionAux=m0;			   
				if(esArreglo==1) {
				    	esArreglo=0; /*la siguiente direccion base sera normal*/
				    } else {m0=1; 
					direccionAux=m0;
					}
				     } ;
DECLARACION2: ARREGLOS
		| /*vacio*/;


DECLARACIONFUNCIONCICLO: {alcanceDireccion=2;/*local*/}DECLARACIONFUNCION DECLARACIONFUNCIONCICLO2;
DECLARACIONFUNCIONCICLO2: DECLARACIONFUNCIONCICLO
			| /*vacio*/;

DECLARACIONFUNCION: crear TIPO id {

				numeroDimension=0;
				dimensionArreglo dimensionNueva = {0,0,0};
				dimensiones[0]= dimensionNueva;
				dimensiones[1]= dimensionNueva;
} 
			DECLARACIONFUNCION2 ptocoma 
			{
insert(getPointerTbl(&tblProc,nombreFuncion),$3,$3,tipoOp,generarDireccion(tipoOp,2),dimensiones[0], dimensiones[1]);
printf("\n\ndimencion cero %s cant %i, dim uno cant %i\n",$3, dimensiones[0].cantidad, dimensiones[1].cantidad);
struct DimensionArreglo dim =  getDimension1(getPointerTbl(&tblProc,nombreFuncion),$3);
printf("\n\ndimencion cero %s cant %i\n",$3, dim.cantidad);

			direccionAux=m0;			
			if(esArreglo==1) {
				esArreglo=0; /*la siguiente direccion base sera normal*/
			} else {m0=1;
				direccionAux=m0;
				}
			numeroVarLocales++;} ;

DECLARACIONFUNCION2: ARREGLOS {operacionesArreglos();}
		| /*vacio*/;


ARREGLOS: corchetea cteentero {dimensionesArreglos1(atoi($2));} corchetec ARREGLOS2;
ARREGLOS2: corchetea cteentero {{dimensionesArreglos2(atoi($2));}} corchetec 
	| /*vacio*/;
	

ASIGNACION: id 		{ strcpy(idDelArreglo, $1);

			int tipoId = getType(&tablaGlobal,$1);
			    if(tipoId==0)
				tipoId = getType(getPointerTbl(&tblProc,nombreFuncion),$1);
			    int direccionVirtual = getDirection(&tablaGlobal,$1);
			    if(direccionVirtual==-1)
				direccionVirtual = getDirection(getPointerTbl(&tblProc,nombreFuncion),$1);
			  push(&pilaOperadores, $1, tipoId, direccionVirtual); 
			  printf("\nHIzo pussh:%s, tipo %i, direcicn %i\n",$1,tipoId,direccionVirtual);
		
			}
	    ASIGNACION2 	
	    igual 	{ push(&pilaOperando, $4, -1, -1);} 
	    ASIGNACION3 ptocoma {checarOperando3();} ;

ASIGNACION3: LECTURA
		| EXP;
ASIGNACION2: {numeroDimension=1;}  ARREGLOSASIG  {hacerPush=1;} 
	|/*vacio*/;
ARREGLOSASIG: corchetea EXP {generarDimension1();} corchetec ARREGLOSASIG2;
ARREGLOSASIG2: corchetea EXP {generarDimension2();} corchetec 
	| /*vacio*/;
			
ESCRITURA: imprimir parentesisa EXP parentesisc ptocoma {generarImprimir();};

LECTURA: leer parentesisa parentesisc {generarLectura();};

CONDICION: si parentesisa SUPEREXPRESION parentesisc {secuenciaIf1();}  llavea BLOQUE llavec CONDICION2 {secuenciaIf2();};

CONDICION2: no {secuenciaElse();} llavea BLOQUE llavec 
		| /*vacio*/;
		


CICLO: mientras {secuenciaWhile1();} parentesisa SUPEREXPRESION parentesisc hacer {secuenciaWhile2();}  llavea BLOQUE llavec {secuenciaWhile3();} ;

CREARFUNCION: funcion CREARFUNCION2 id {
				direccionEnteroLocal=11000;
				direccionDobleLocal=21000;
				direccionTextoLocal=31000;
				direccionBooleanoLocal=41000;

				direccionEnteroTemp=12000;
				direccionDobleTemp=22000;
				direccionTextoTemp=32000;
				direccionBooleanoTemp=42000;


					strcpy(nombreFuncion, $3); 
					/*numeroParametros=0;
					strcpy(nombreFuncion, $3); 
					printf("\n++++++++++Nombe Funcion:%s\n\n", nombreFuncion);
					struct StrHashTable tablaLocalFuncion = {{0},NULL,NULL,foo_strhash,strcmp};
					struct StrHashTable tablaParametros = {{0},NULL,NULL,foo_strhash,strcmp};
					insertProc(&tblProc,&tablaLocalFuncion,&tablaParametros,nombreFuncion,nombreFuncion,0,0,0);
					numeroFunciones++;*/
					} 
	parentesisa CREARFUNCION3 parentesisc {
					setNumberParameters(&tblProc,nombreFuncion,numeroParametros);
					 } llavea DECLARACIONFUNCIONCICLO
					 {setNumberLocalVars(&tblProc,nombreFuncion,numeroVarLocales);
					 
					setCuadruploInicial(&tblProc,nombreFuncion,contS);
					 }
					BLOQUE regresar EXP {generarReturn();} llavec {generarRetorno();}
;

CREARFUNCION2: TIPO
			| neutral; 	
CREARFUNCION3: /*vacio*/
		| CREARFUNCION4;
CREARFUNCION4: TIPO id  {
		int direccion = generarDireccion(tipoOp,2);
		//Convertir numero de parametros a stirng, para meterlo como indicador en tabla de parametros
		char numeroParametrosString[3];
		numeroParametros++;
		sprintf(numeroParametrosString, "%i", numeroParametros);

		//Insertar a la tabla de parametros, para poder checar el tipo de los argumentos cuando son usados
		insert(getPointerParTbl(&tblProc,nombreFuncion),numeroParametrosString,$2,tipoOp,direccion,dimensiones[0], dimensiones[1]);
		//insertar a la tabla de var locales, para poder ser usadas como vars dentro de la funcion
		insert(getPointerTbl(&tblProc,nombreFuncion),$2,$2,tipoOp,direccion,dimensiones[0], dimensiones[1]);

		} 
		CREARFUNCION5;
CREARFUNCION5: /*vacio*/
		| coma CREARFUNCION4;
				
LLAMARFUNCION: id {	strcpy(nombreFuncion, $1); 
			if(getProc(&tblProc,$1)==1){
				printf("\n____________Llamada EXISTENTE!!__ \"%s, %i\"\n", nombreFuncion,getNumberParameters(&tblProc,$1) );
				 generarEra(getNumberLocalVars(&tblProc,$1));
				
			}
			else printf("\n____________Llamada a un procedimiento que no existe: \"%s\"\n", nombreFuncion );
			
		} parentesisa LLAMARFUNCION2 parentesisc ptocoma {generarGoSub();} ;
LLAMARFUNCION2: EXP {generarParametro();} LLAMARFUNCION3;
LLAMARFUNCION3: coma {apuntadorParametro++;} LLAMARFUNCION2
			  | /*vacio*/;
			  
			  
SUPEREXPRESION: EXPRESION SUPEREXPRESION2;
SUPEREXPRESION2: /*vacio*/
			| SUPEREXPRESION3 EXPRESION;
SUPEREXPRESION3: and 
	  |  or;
	

EXPRESION: EXP EXPRESION2;
EXPRESION2: /*vacio*/
			| EXPRESION3 EXP {  checarOperando3();   }  ;
EXPRESION3: menor 	{push(&pilaOperando,$1,-1, -1);}
			| mayor {push(&pilaOperando,$1, -1, -1);}
			| igual {push(&pilaOperando, $1, -1, -1);} 
		 	| diferente igual {char* str = $1;
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, $2 ); 
				      push(&pilaOperando, str, -1, -1);} ;
			
			
EXP: TERMINO  {  checarOperando2();   } EXP2  ;
EXP2 : /*vacio*/
	 | EXP3 EXP;
EXP3: mas				{push(&pilaOperando,$1,-1, -1);}
	 |menos				{push(&pilaOperando,$1,-1, -1);};

TERMINO: FACTOR  { checarOperando1();   } TERMINO2 ;
TERMINO2 : /*vacio*/
	 | TERMINO3 TERMINO;	
TERMINO3: multiplicacion 	{push(&pilaOperando,$1,-1, -1);}
	 |division		{push(&pilaOperando,$1,-1, -1);};

FACTOR:  parentesisa  { push(&pilaOperando,$1,-1,-1); } EXPRESION parentesisc {pop(&pilaOperando);} /*se queita el fondo falso*/
	| VARCTE
	| id  {		int direccion= getDirection(getPointerTbl(&tblProc,nombreFuncion),$1);
			int tipo = getType(getPointerTbl(&tblProc,nombreFuncion),$1);
			if (direccion == -1) 
				printf("\nVariable %s no declarada", $1);
			else{
				printf("\n\n\n´´´´´´´´USAARR Variable %s\n\n", $1);
				/*Meter en pilaTipos el tipo de id que es*/
	 			push(&pilaOperadores, $1, tipo, direccion);
			}	
	      }
	
	ASIGNACION2;					

 	

VARCTE: ctetexto			{if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
							int direccion= getDirection(&tablaConstantes,$1);
							if (direccion == -1)direccion=generarDireccion(3, 5);
						  push(&pilaOperadores, $1, 3, direccion);
						  if(insert(&tablaConstantes,$1,$1,3,direccion,dimensiones[0], dimensiones[1])!= -1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, $1); strcat(strDirecciones,"\n");
						   }
					}}
		|cteentero 		{if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						   	int direccion= getDirection(&tablaConstantes,$1);
							if (direccion == -1)direccion=generarDireccion(1, 5);
						   push(&pilaOperadores, $1, 1, direccion);
						  // printf("\n\nHIzo pussh: tipo %i, direcicn %i\n\n",1,direccion);
	   
						   if(insert(&tablaConstantes,$1,$1,1,direccion,dimensiones[0], dimensiones[1])!= -1){
							  contadorConstantes++;

							printf("\ndimension[0] del entero %s:%i \n", $1, dimensiones[0].cantidad);
						
						struct DimensionArreglo dim =  getDimension1(getPointerTbl(&tblProc,nombreFuncion),$1);
							printf("\ndimension[0] del entero %s:%i \n", $1, dim.cantidad);
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string); 
							  strcat(strDirecciones,$1); strcat(strDirecciones,"\n"); 
					          }
					}}
		| ctedecimal 		{if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						  	int direccion= getDirection(&tablaConstantes,$1);
							if (direccion == -1)direccion=generarDireccion(2, 5);
						   push(&pilaOperadores, $1, 2, direccion);
						   if(insert(&tablaConstantes,$1,$1,2,direccion,dimensiones[0], dimensiones[1])!=-1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, $1); strcat(strDirecciones,"\n");  
						   }
					}}		  
		| ctebooleano		{if(hacerPush==1) {
							//Generar direccion en tabla de constantes si no existe	
						  	int direccion= getDirection(&tablaConstantes,$1);
							if (direccion == -1)direccion=generarDireccion(4, 5);
						  push(&pilaOperadores, $1, 4, direccion);
						  if(insert(&tablaConstantes,$1,$1,4,direccion, dimensiones[0], dimensiones[1])!=-1){
							  contadorConstantes++;
							  char integer_string[32];
							  sprintf(integer_string, "%d/", direccion);
							  strcat(strDirecciones, integer_string);
							  strcat(strDirecciones, $1); strcat(strDirecciones,"\n"); 
						  }
					}};
		
DIBUJARFIGURA: dibujarFigura parentesisa FIGURA coma id {generarDibujarFigura();} parentesisc ptocoma;

FIGURA: perro
		|persona
		|gato
		|carro;

BORRARFIGURA: borrarFigura parentesisa id {generarBorrarFigura();} parentesisc ptocoma;

HABLAR: hablar parentesisa id coma EXP {generarHablarFigura();} parentesisc ptocoma;

		
MOVER: mover parentesisa id coma EXP coma EXP {generarMoverFigura();} parentesisc ptocoma;

OBTENERPOSICION: obtenerPosicion parentesisa id {/* generarObtenerPosicion();*/ } parentesisc ptocoma ;

GIRARDER: girarDerecha parentesisa id coma EXP {generarGirarD();} parentesisc ptocoma;

GIRARIZQ: girarIzquierda parentesisa id coma EXP {generarGirarI();} parentesisc ptocoma;

OBTENERALTURA: obtenerAltura parentesisa id {generarObtenerAltura();} parentesisc ptocoma;

OBTENERANCHURA: obtenerAnchura parentesisa id {generarObtenerAnchura();} parentesisc ptocoma;

CAMBIARALTURA: cambiarAltura parentesisa id coma EXP {generarCambiarAltura();} parentesisc ptocoma;

CAMBIARANCHURA: cambiarAnchura parentesisa id coma EXP {generarCambiarAnchura();} parentesisc ptocoma;

COLORFONDO: colorFondo parentesisa COLOR {generarColorFondo();} parentesisc ptocoma ;

COLOR: rojo
		| azul 	
		| verde;
	
%%

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
			direccionEnteroTemp ++;
			return direccionEnteroTemp;}
		else if(tipo==2) {//doble
			contDobleTemp++;
			direccionDobleTemp ++;
			return direccionDobleTemp;}
		else if(tipo==3){ //texto
			contTextoTemp++;
			direccionTextoTemp++;
			return direccionTextoTemp;}
		else if(tipo==4){ //booleano
			contBooleanoTemp++;
			direccionBooleanoTemp++;
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

		//Checar si los tipos de los args son consistentes con los de la tabla de param
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

	printf("\nd.cantidad %i\n", d.cantidad);	

	int limInf=0;
	int limSup= d.cantidad -1;
	printf("\n---Direcciiones: op1 %i, id %i ---Valores: op1 %s, id %s, limSup %i",operador1->direccion, id->direccion, operador1->valor,idDelArreglo,limSup);	
	generarCuadruplo(numeroVerifica,operador1->direccion,limInf,limSup);// param=23

	//verificar si hay otra dimension
	dimensionArreglo d2 = getDimension2(getPointerTbl(&tblProc,nombreFuncion),id->valor);

	if(d2.cantidad== 0){	//la dimension 2 esta vacia

		pop(&pilaOperadores);	//Quitar el id 

		sprintf(nombreT, "t%i", contT++);

		int res = generarDireccion(1,3); //3:direccion temporal entera
		insert(&tablaTemporal,nombreT,nombreT,1,res,dimensiones[0], dimensiones[1]);
		generarCuadruplo(40, operador1->direccion,id->direccion, res);	// suma indice + direccion
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
		generarCuadruplo(41, operador1->direccion, d.m, res);	// multiplocacion	
		push(&pilaOperadores,nombreT,1,res);//3: direccion temporal
	}

}

void generarDimension2(){

		char nombreT[10];
		int numeroVerifica = 27;
		
		ptr operador1= malloc (sizeof(p_Nodo)); 
		ptr aux= malloc (sizeof(p_Nodo)); 
		ptr id= malloc (sizeof(p_Nodo)); 
		ptr suma= malloc (sizeof(p_Nodo)); 		

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
			
		dimensionArreglo d2 = getDimension2(getPointerTbl(&tblProc,nombreFuncion),id->valor);
		int limInf=0;
		int limSup= d2.cantidad-1;
	
		generarCuadruplo(numeroVerifica,operador1->direccion,limInf,limSup);// param=23
	
		sprintf(nombreT, "t%i", contT++);

		int res = generarDireccion(1,3); //3:direccion temporal entera
		insert(&tablaTemporal,nombreT,nombreT,1,res,dimensiones[0], dimensiones[1]);
		generarCuadruplo(0, operador1->direccion,aux->direccion, res);	// multiplocacion
		push(&pilaOperadores,nombreT,1,res);//3: direccion temporal
	

	//SUma total que se hara a la dir Base
		sprintf(nombreT, "t%i", contT++);
		res = generarDireccion(1,3); //3:direccion temporal entera
		insert(&tablaTemporal,nombreT,nombreT,1,res,dimensiones[0], dimensiones[1]);
		
	
		suma->valor = pilaOperadores->valor;
		suma->tipo = pilaOperadores->tipo; 
		suma->direccion = pilaOperadores->direccion; 
		pop(&pilaOperadores);

		generarCuadruplo(40, suma->direccion,id->direccion, res);	// multiplocacion	
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

