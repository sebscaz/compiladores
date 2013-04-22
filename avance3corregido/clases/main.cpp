#include <iostream>
#include <vector>
#include <fstream.h>

using namespace std;


int main()
{
  /*

   +
   -
   *
   /
   <
   >
   !=
   ==
   AND
   OR
   (
   )

   GOTO
   GOTOF
   GOTOV
   GOTOSUB

   ERA    20
          21
   RET    22
   param  23
   Return 24
   write  25
   PRINT  26
   END

   */

/* Lector del archivos de cuiadruplos

   ofstream archivo;  // objeto de la clase ofstream

    archivo.open("cuadruplos.txt");

     if (archivo.is_open()) {
 while (!archivo.eof()) {


    archivo>> output;
    cout<<output;


 }
}
archivo.close();
*/



/* Contadores de Variables*/
   int contIntG=0, contIntL=0, contIntT=0, contIntC=0;
   int contFloatG=0, contFloatL=0, contFloatT=0, contFloatC=0;
   int contConstG=0, contConstL=0, contConstT=0, contConstC=0;
   int contBoolG=0, contBoolL=0, contBoolC=0, contBoolT=0;

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


 /*Dir. temporales*/
   int enteroTemp_I=15000, enteroTemp_F=15999;
   int flotanteTemp_I=16000, flotanteTemp_F=16999;
   int stringTemp_I=17000, stringTemp_F=17999;
   int boleanoTemp_I=18000, boleanoTemp_F=18999;
















    return 0;
}
