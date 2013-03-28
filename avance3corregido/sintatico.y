%{
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hash.c"
#include "pila.c"

void checarOperando1();
void checarOperando2(); 

int yystopparser=0;

struct StrHashTable tbl = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashTableProc tblprocs = {{0},NULL,NULL,foo_strhash,strcmp};
struct StrHashNodeProc nodeProc;

int tipoOp=-1;

//PILAS
ptr pilaOperadores=NULL;
ptr pilaOperando=NULL;
ptr pilaTipos=NULL;



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

PROGRAMA: programa id llavea PROGRAMA1 PROGRAMA2 BLOQUE llavec	{insert(&tbl,$2,$2,-1); puts(get(&tbl,$2)); } ;
PROGRAMA1: DECLARACION PROGRAMA12;
PROGRAMA12: PROGRAMA1
		  | /*vacio*/;
PROGRAMA2: CREARFUNCION PROGRAMA22;
PROGRAMA22: PROGRAMA2
		  | /*vacio*/;


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


DECLARACIONFUNCION: crear TIPO DECLARACIONFUNCION2 id	ptocoma  

	//{nodeProc.vartable = {{0},NULL,NULL,foo_strhash,strcmp};
	//insert(nodeProc.vartable,$4,$4); } 
	;


DECLARACIONFUNCION2: ARREGLOS
		| /*vacio*/;


ARREGLOS: corchetea cteentero corchetec ARREGLOS2;
ARREGLOS2: corchetea cteentero corchetec 
	| /*vacio*/;
	

ASIGNACION: id ASIGNACION2 dospuntos igual ASIGNACION3 ptocoma;
ASIGNACION3: LECTURA
		| EXP;
ASIGNACION2: ARREGLOSASIG 
	|/*vacio*/;
ARREGLOSASIG: corchetea EXP corchetec ARREGLOSASIG2;
ARREGLOSASIG2: corchetea EXP corchetec 
	| /*vacio*/;
	
	

				

				
ESCRITURA: imprimir parentesisa EXP parentesisc ptocoma;

LECTURA: leer parentesisa parentesisc ptocoma;

CONDICION: si parentesisa SUPEREXPRESION parentesisc llavea BLOQUE llavec CONDICION2;

CONDICION2: no llavea BLOQUE llavec
		| /*vacio*/;
		


CICLO: mientras parentesisa SUPEREXPRESION parentesisc hacer llavea BLOQUE llavec;

CREARFUNCION: funcion CREARFUNCION2 id parentesisa CREARFUNCION3 parentesisc llavea DECLARACIONFUNCION BLOQUE regresar EXP llavec 

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
EXPRESION3: menor 	{push(&pilaOperando,$1,-1);}
			| mayor {push(&pilaOperando,$1, -1);}
			| igual igual {push(&pilaOperando, $1, -1);}
		 	| diferente igual {push(&pilaOperando,$1, -1);} ;
			
EXP: TERMINO  {  checarOperando2();   } EXP2  ;
EXP2 : /*vacio*/
	 | EXP3 EXP;
EXP3: mas				{push(&pilaOperando,$1,-1);}
	 |menos				{push(&pilaOperando,$1,-1);};

TERMINO: FACTOR  {  printf("mmmwgaat"); checarOperando1();   } TERMINO2 ;
TERMINO2 : /*vacio*/
	 | TERMINO3 TERMINO;	
TERMINO3: multiplicacion 	{push(&pilaOperando,$1,-1);}
	 |division		{push(&pilaOperando,$1,-1);};

FACTOR:  parentesisa  { push(&pilaOperando,$1,-1); } EXPRESION parentesisc  /*se queita el fondo falso*/
	| FACTOR2  VARCTE
	| id 	{push(&pilaOperadores, $1, getType(&tbl,$1));}	;/*Meter en pilaTipos el tipo de id que es*/					
FACTOR2: /* vacio */
		|EXP3;
 	

VARCTE: ctetexto			{printf("nose"); push(&pilaOperadores, $1, 3);}
		|cteentero 		{push(&pilaOperadores, $1, 1);}
		| ctedecimal 		{push(&pilaOperadores, $1, 2);}
		| ctebooleano		{push(&pilaOperadores, $1, 4);};
		
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


void checarOperando1(){
	ptr op= malloc (sizeof(p_Nodo)); 
	ptr operador1= malloc (sizeof(p_Nodo)); 
	ptr operador2= malloc (sizeof(p_Nodo)); 


	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='*' || *pilaOperando->valor=='/' ){ 
				printf("Operandoooo  %c",*pilaOperando->valor);
				pop(&pilaOperando);

				
				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				printf("TIPO op1: %i , op2: %i \n", operador1->tipo, operador2->tipo);

				push(&pilaOperadores,"t",1);
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

	if (op!= NULL){
		if(pilaOperando!=NULL){
			op->valor=pilaOperando->valor;
			if(*pilaOperando->valor=='+' || *pilaOperando->valor=='-' ){ 
				printf("Operandoooo  %c",*pilaOperando->valor);
				pop(&pilaOperando);

				operador1->valor = pilaOperadores->valor;
				operador1->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				operador2->valor = pilaOperadores->valor;
				operador2->tipo = pilaOperadores->tipo; 
				pop(&pilaOperadores);

				printf("TIPO op1: %i , op2: %i \n", operador1->tipo, operador2->tipo);
push(&pilaOperadores,"t",1);
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
