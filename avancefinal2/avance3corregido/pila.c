

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estructura de los nodos de la pila*/
struct Nodo{
	char *valor;
	int tipo;
	int direccion;
	struct Nodo *siguienteNodo;
};

typedef struct Nodo p_Nodo;
typedef p_Nodo *ptr;

/*Funcion que mete valores a la pila*/
void push( ptr *cabeza_ptr, char *valor, int tipo, int direccion ){
	ptr nuevo_ptr;
	nuevo_ptr= malloc (sizeof(p_Nodo)); /*Define el espacio de memoria*/

	if (nuevo_ptr!= NULL){ /*Si hay memoria inicializa nuevo_ptr con los valores de la estructura*/
		nuevo_ptr->valor=valor;
		nuevo_ptr->tipo=tipo;
		nuevo_ptr->direccion=direccion;
		nuevo_ptr->siguienteNodo=*cabeza_ptr;

		*cabeza_ptr=nuevo_ptr;

		//printf("\nSe acaba de pushear %s, %i\n", nuevo_ptr->valor, nuevo_ptr->direccion);
	}//end if

	else {
		printf("no hay espacio");
	}
}

/*Funcion que saca los valores de la pila */
char* pop (ptr *cabeza_ptr){
	ptr auxPtr; /*Aux porque podemos perder la pila si trabajamos con el apuntador real*/
	char *val;

	auxPtr= *cabeza_ptr;
	val= (*cabeza_ptr)->valor;
	*cabeza_ptr= ( *cabeza_ptr)->siguienteNodo;

	return val;
}


/*imprime la pila */
void imprimirPila( ptr actual_ptr){

	if (actual_ptr ==NULL) 
		printf("La  Pila esta vacia");
	else{
		while (actual_ptr!= NULL){
			//printf("%c -->", *(actual_ptr->valor));
			//printf("%i -->", (actual_ptr->direccion));
			actual_ptr=actual_ptr->siguienteNodo;
		}//end while
		//printf("NULL\n");
	}//end else
}

/*
int main (void){

	ptr pilaPtr=NULL;
	ptr pilaOP=NULL;

	printf("La pila con dos Push   ");
	push( &pilaPtr, "waaa");
	push( &pilaPtr, "*");
	push( &pilaPtr, "+");
	push( &pilaOP, "+");

	if ( pilaPtr->valor == "+")
	{
		printf("las pilas tienen el mismo valor\n");
		printf("%c -->", *(pilaPtr->valor));
		imprimirPila(pilaPtr);
	}
	imprimirPila(pilaPtr);
	printf("\n");

	//printf("La pila con despues del Pop  ");
	//pop (&pilaPtr);
	//printf("%d -->", pilaPtr->valor);
	printf("\n");

	return 0;


}*/

