%{
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
void generarCuadruplo(int numOp ,int tipo1, int tipo2, int res);
int hacerPush = 1;	//bool para saber si meter variables a la pila - 1:hacer push, 0:no hacer push

void secuenciaIf1();
void secuenciaIf2();
void secuenciaElse();
void secuenciaWhile1();
void secuenciaWhile2();	

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
struct StrHashTableProc tblprocs = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashNodeProc nodeProc;

int tipoOp=-1;

//PILAS
ptr pilaOperadores=NULL;
ptr pilaOperando=NULL;
ptr pilaTipos=NULL;
ptr pilaSaltos=NULL;



%}


%union {int cteint; float ctefloat; int cteboolean; char *string;} 

%token programa
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

PROGRAMA: programa id {insert(&tbl,$2,$2,-1); puts(get(&tbl,$2)); }  llavea PROGRAMA1 PROGRAMASIG PROGRAMA2 BLOQUE llavec {printf("\n\n%s", strCuadruplos);};
PROGRAMA1: {alcanceDireccion=1;/*global*/}DECLARACION PROGRAMA12;
PROGRAMA12: PROGRAMA1
		  | /*vacio*/;
PROGRAMA2: CREARFUNCION PROGRAMA22;
PROGRAMA22: PROGRAMA2
		  | /*vacio*/;

PROGRAMASIG: ASIGNACION PROGRAMASIG2;
PROGRAMASIG2: PROGRAMASIG
	| /*vacio*/


TIPO: texto		{tipoOp = generarTipo($1); printf("===========tipo: %i\n", tipoOp); }
	| entero	{tipoOp = generarTipo($1); printf("===========tipo: %i\n", tipoOp);}
	| decimal	{tipoOp = generarTipo($1); printf("===========tipo: %i\n", tipoOp);}
	| booleano	{tipoOp = generarTipo($1); printf("===========tipo: %i\n", tipoOp);};	
	
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

				
DECLARACION: crear TIPO DECLARACION2 id	ptocoma  {insert(&tbl,$4,$4,tipoOp); printf("El tipo eeeeeeessssss: %i\n", getType(&tbl,$4));} ;
DECLARACION2: ARREGLOS
		| /*vacio*/;


DECLARACIONFUNCIONCICLO: {alcanceDireccion=2;/*local*/}DECLARACIONFUNCION DECLARACIONFUNCIONCICLO2;
DECLARACIONFUNCIONCICLO2: DECLARACIONFUNCIONCICLO
			| /*vacio*/;

DECLARACIONFUNCION: crear TIPO DECLARACIONFUNCION2 id	ptocoma  


	//{nodeProc.vartable = {{0},NULL,NULL,foo_strhash,strcmp};
	//insert(nodeProc.vartable,$4,$4); } 
	;




DECLARACIONFUNCION2: ARREGLOS
		| /*vacio*/;


ARREGLOS: corchetea cteentero corchetec ARREGLOS2;
ARREGLOS2: corchetea cteentero corchetec 
	| /*vacio*/;
	

ASIGNACION: id ASIGNACION2 igual ASIGNACION3 ptocoma;
ASIGNACION3: LECTURA
		| EXP;
ASIGNACION2: {hacerPush=0; /*no meter a la pila las EXP de los arreglos*/}  ARREGLOSASIG  {hacerPush=1;} 
	|/*vacio*/;
ARREGLOSASIG: corchetea EXP corchetec ARREGLOSASIG2;
ARREGLOSASIG2: corchetea EXP corchetec 
	| /*vacio*/;
	
	

				

				
ESCRITURA: imprimir parentesisa EXP parentesisc ptocoma;

LECTURA: leer parentesisa parentesisc ptocoma;

CONDICION: si parentesisa SUPEREXPRESION parentesisc {/*secuenciaIf();*/}  llavea BLOQUE llavec CONDICION2 {/*secuenciaIf2();*/};

CONDICION2: no {/*secuenciaElse();*/} llavea BLOQUE llavec 
		| /*vacio*/;
		


CICLO: mientras {/*secuenciaWhile1();*/} parentesisa SUPEREXPRESION parentesisc hacer {/*secuenciaWhile2();*/}  llavea BLOQUE llavec {/*secuenciaWhile3();*/} ;

CREARFUNCION: funcion CREARFUNCION2 id parentesisa CREARFUNCION3 parentesisc llavea DECLARACIONFUNCIONCICLO BLOQUE regresar EXP llavec 

	//{insertProc(&tblprocs,$3,$3);
	//nodeProc=getProcNode(&tblprocs,$3,$3);}
	;

CREARFUNCION2: TIPO
			| neutral; 	
CREARFUNCION3: /*vacio*/
		| CREARFUNCION4;
CREARFUNCION4: TIPO id CREARFUNCION5 {insert(&tbl,$2,$2,tipoOp);};
CREARFUNCION5: /*vacio*/
		| coma CREARFUNCION4;
				
LLAMARFUNCION: id parentesisa LLAMARFUNCION2 parentesisc ptocoma ;
LLAMARFUNCION2: EXP LLAMARFUNCION3;
LLAMARFUNCION3: coma LLAMARFUNCION2
			  | /*vacio*/;
			  
			  
SUPEREXPRESION: EXPRESION SUPEREXPRESION2;
SUPEREXPRESION2: /*vacio*/
			| SUPEREXPRESION3 EXPRESION;
SUPEREXPRESION3: and 
	  |  or;
	

EXPRESION: EXP EXPRESION2;
EXPRESION2: /*vacio*/
			| EXPRESION3 EXP {/*  checaroperando3();   */}  ;
EXPRESION3: menor 	{push(&pilaOperando,$1,-1, -1);}
			| mayor {push(&pilaOperando,$1, -1, -1);}
			| igual igual {char* str = $1;
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, $2 ); 
				      push(&pilaOperando, str, -1, -1);}
		 	| diferente igual {char* str = $1;
				      char dest[2];
				      strcpy( dest, str );
				      strcat( dest, $2 ); 
				      push(&pilaOperando, str, -1, -1);} 
			| igual {push(&pilaOperando, $1, -1, -1);} ;
			
			
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
	| id  ASIGNACION2	{int tipoId = getType(&tbl,$1);
				int direccionVirtual = generarDireccion(tipoId, alcanceDireccion);
				printf("........................DireccionVirtual %i\n", direccionVirtual);
				if(hacerPush==1) push(&pilaOperadores, $1, tipoId, direccionVirtual); }	;/*Meter en pilaTipos el tipo de id que es*/					

 	

VARCTE: ctetexto			{if(hacerPush==1) push(&pilaOperadores, $1, 3, generarDireccion(3, alcanceDireccion));}
		|cteentero 		{if(hacerPush==1) push(&pilaOperadores, $1, 1, generarDireccion(1, alcanceDireccion));}
		| ctedecimal 		{if(hacerPush==1) push(&pilaOperadores, $1, 2, generarDireccion(2, alcanceDireccion));}
		| ctebooleano		{if(hacerPush==1) push(&pilaOperadores, $1, 4, generarDireccion(4, alcanceDireccion));};
		
DIBUJARFIGURA: dibujarFigura parentesisa FIGURA coma id parentesisc ptocoma;

FIGURA: perro
		|persona
		|gato
		|carro;

BORRARFIGURA: borrarFigura parentesisa id parentesisc ptocoma;

HABLAR: hablar parentesisa id coma EXP parentesisc ptocoma;

		
MOVER: mover parentesisa id coma EXP coma EXP parentesisc ptocoma;

OBTENERPOSICION: obtenerPosicion parentesisa id parentesisc ptocoma ;

GIRARDER: girarDerecha parentesisa id coma EXP parentesisc ptocoma;

GIRARIZQ: girarIzquierda parentesisa id coma EXP parentesisc ptocoma;

OBTENERALTURA: obtenerAltura parentesisa id parentesisc ptocoma;

OBTENERANCHURA: obtenerAnchura parentesisa id parentesisc ptocoma;

CAMBIARALTURA: cambiarAltura parentesisa id coma EXP parentesisc ptocoma;

CAMBIARANCHURA: cambiarAnchura parentesisa id coma EXP parentesisc ptocoma;

COLORFONDO: colorFondo parentesisa COLOR parentesisc ptocoma ;

COLOR: rojo
		| azul 	
		| verde;
	
%%
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
		printf("--------------Semantica No Valida!!\n");
		return 0;	//Error: no se puede hacer operacion de esos tipos
	}
	else {
		printf("--------------Semantica Valida!! tipo: %i. \n " , matrizSemantica[op1-1][op2-1][op]);
		return 1;
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

				printf("Operandoooo  %c",*pilaOperando->valor);
				pop(&pilaOperando);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				operador2->direccion = pilaOperadores->direccion; 
				pop(&pilaOperadores);

				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				operador1->direccion = pilaOperadores->direccion; 
				pop(&pilaOperadores);

				printf("TIPO op1: %i, direccion: %i | op2: %i, direccion:%i \n", operador1->tipo, operador1->direccion, operador2->tipo, operador2->direccion);
				
			    strcpy( nombreT, "t" );
			    //itoa(10, nombreT, contT++);
			
				semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
				res = generarDireccion(semanticaValida,3); //3:direccion temporal
				generarCuadruplo(numOp ,operador1->direccion, operador2->direccion, res);
				push(&pilaOperadores,nombreT,semanticaValida,res);//3: direccion temporal
				
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
	int dirTemp=0;
	int res=0;
	char nombreT[10];

	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='+' || *pilaOperando->valor=='-' ){ 

				if(*pilaOperando->valor=='+' ) numOp=0;
				else if (*pilaOperando->valor=='-' ) numOp=1;

				printf("Operandoooo  %c",*pilaOperando->valor);
				pop(&pilaOperando);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				operador2->direccion = pilaOperadores->direccion; 
				pop(&pilaOperadores);

				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				operador1->direccion = pilaOperadores->direccion; 
				pop(&pilaOperadores);

				printf("TIPO op1: %i, direccion: %i | op2: %i, direccion:%i \n", operador1->tipo, operador1->direccion, operador2->tipo, operador2->direccion);
				
			    strcpy( nombreT, "t" );
			    //itoa(10, nombreT, contT++);
			
				semanticaValida = checarSemantica(numOp ,operador1->tipo, operador2->tipo);
				res = generarDireccion(semanticaValida,3); //3:direccion temporal
				generarCuadruplo(numOp ,operador1->direccion, operador2->direccion, res);
				push(&pilaOperadores,nombreT,semanticaValida,res);//3: direccion temporal
				
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


void generarCuadruplo(int numOp ,int tipo1, int tipo2, int res){

	//Crear vectores para ir almacenado dinameicamente los cuadruplos
	//Algo masomenos asi:::
	//vectorOp.add(numOp);	//agregar un nuevo elemento al final...
	//vectorOp1.add(tipo1);
	//vectorOp2.add(tipo2);
	//vectorRes.add(res);
	
	contS++;/*suma contador de saltos*/
	char intemporal[6];
	printf("@@@@@@@@@@@@@@@@@Cuadruplo generado: %i \n", res);

	sprintf(intemporal, "%i - ", numOp);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i - ", tipo1);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i - ", tipo2);
	strcat(strCuadruplos, intemporal); 
	sprintf(intemporal, "%i\n", res);
	strcat(strCuadruplos, intemporal); 

}

void secuenciaIf1(){
	/*
	aux = pop(&pilaTipos);
	if(aux->tipo != 4)//dif de boolean
		printf("Error semantico!!");
	else	
		
	{	
		resultado= pop(&pilaO);  //ultima Dirección de la pila, la cual tiene el resultado del estatuto
		generarCuadruplo(12, resultado, __,-1); gotoF,12
		push(&pilaSaltos, contS-1, -1, contS-1);	//usar el tipo direccion como contador
	}
	*/
}
void secuenciaIf2(){
	/*
	ptr fin= malloc (sizeof(p_Nodo)); 
	fin->direccion = &pilaSaltos; 	//Contador del cuadruplo
	pop(&pilaSaltos)
	
	rellenar(fin->direccion,contS);
	*/
}
void secuenciaElse(){
	/*
	generarCuadruplo(10 ,_,-1,-1); goto ,10
	rellenar(pop(&pilaSaltos),contS);
	push(&pilaSaltos, contS-1, -1, contS-1);
		
	*/
}
void secuenciaWhile1(){
	/*
	push(&pilaSaltos, contS-1, -1, contS-1)	;
	*/
}
void secuenciaWhile2(){
	/*
	aux = pop(&pilaTipos);
	if(aux->tipo != 4)//dif de boolean
		printf("Error semantico!!");
	else{	
		resultado= pop(&pilaO);  //ultima Dirección de la pila la cual tiene el resultado del estatuto
		generarCuadruplo(GoToF 12, resultado, __);
		push(&pilaSaltos, contS-1, -1, contS-1);
		}
	*/
}

void secuenciaWhile3(){
	/*
	falso = pop(&pilaSaltos);
	retorno = pop(&pilaSaltos); direccion
	generar(goto 10, retorno);
	rellenar(falso 13,contS);
	*/
}
	
void rellenar(int goTo, int contador){
	/* poner numeros en espacios en blanco anteriores   */
	//Usar los vectors globales, algo asi::
	//vectorRes[goTo].set(contador);

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

