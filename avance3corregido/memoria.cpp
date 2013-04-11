

#include <iostream>  
#include <string>
#include <vector>
#include"Pila.cpp"
using namespace std;


class Memoria{

// Apuntadores públicos que llevan al inicio del segmento de memoria
public:
int *entero;
float *flotante;
string *texto;
bool *boleano;

};

class MemoriaGlobal: Memoria 
{
/**/
};

class MemoriaLocal : Memoria 
{
/**/
};

class MemoriaConstantes : Memoria 
{
/**/
};



 
int main()
{

//Indice de Memoria 

/*Dir. Globales*/
int enteroGlobal_I=5000, enteroGlobal_F=5999;
int flotanteGlobal_I=6000, flotanteGlobal_F=6999;
int stringGlobal_I=7000, stringGlobal_F=7999;
int boleanoGlobal_I=8000, boleanoGlobal_F=8999;

 /*Dir Locales*/
int enteroLocal_I=9000, enteroLocal_F=9999;
int flotanteLocal_I=10000, flotanteLocal_F=10999;
int stringLocal_I=11000, stringLocal_F=11999;
int boleanoLocal_I=12000, boleanoLocal_F=12999; 
 
 
 /*Dir Contantes*/
 int enteroConstante_I=13000, enteroConstante_F=13500;
 int flotanteConstante_I=13501, flotanteConstante_F=13999;
 int stringConstante_I=14000, stringConstante_F=14500;
 int boleanoConstante_I=14501, boleanoConstante_F=14999; 
 
 
 
    return 0;
}

 
