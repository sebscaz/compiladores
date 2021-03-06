#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Valores dentro de la matriz
//int = entero = 1
//float = doble = 2
//string = texto = 3
//bool = booleano = 4
//error/no se puede = 0

/*
int main(){
printf("jajaj");     // = 1;	
//OPERADORES
//X,Y = 0 (int), 1 (float), 2(string), 3 (bool)
//int matrizSemantica[2][2][2]={{{0, 0}, {0,0}},{{0, 0}, {0,0}}};

*/
//Z=0 (SUMA)

//void inicializarMatriz(int[][][] matrizSemantica);
/*
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
}
*/
