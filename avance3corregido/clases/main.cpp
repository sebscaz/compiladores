#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;


int main()
{
  /*

   + 0
   - 1
   * 2
   / 3
   < 7
   > 6
   != 5
   == 4
   AND 8
   OR 9
   (
   )
   = 10
   GOTO 11
   GOTOF 12
   GOTOV  13
   GOTOSUB  14
   ERA    20
          21
   RET    22
   param  23
   Return 24
   write  25
   PRINT  26
   END   30

   */


   /*Inicializar vectores

   //Vector de contadores
   vector<int> contCuadruplos(16);



    vector<int> enterosGlobales(contEnterosGlobales);
    vector<int> enterosLocales(contEnterosLocales);
    vector<int> enterosTemporales(contEnterosTemporales);
    vector<int> enterosConstantes(contEnterosConstantes);


    vector<double> flotantesGlobales(contFlotantesGlobales);
    vector<double> flotantesLocales(contFlotantesLocales);
    vector<double> flotantesTemporales(contFlotantesTemporales);
    vector<double> flotantesConstantes(contFlotantesConstantes);

    vector<string> stringGlobales(contStringGlobales);
    vector<string> stringLocales(contStringLocales);
    vector<string> stringTemporales(contStringTemporales);
    vector<string> stringConstantes(contStringConstantes);

    vector<string> booleanoGlobales(contBooleanoGlobales);
    vector<string> booleanoLocales(contBooleanoLocales);
    vector<string> boolenoTemporales(contBooleanoTemporales);
    vector<string> booleanoConstantes(contBooleanoConstantes);




   */

 //Lector del archivos de cuiadruplos

   // system("analizador.exe pruebalenguaje"); // no estoy tan seguro como funecione este

  string linea;
  int numLinea=0;

   ifstream archivo;  // objeto de la clase ofstream

    archivo.open("cuadruplos.txt");

     //archivo<< "Writing this to a file.\n";






    // lee segunda linea



/*


while(!archivo.eof()){
/*
getline (archivo,linea);

	if(numLinea<=numeroConstantes+1 ){	//+1 porque los constantes empeizan en la linea 2, nomas recorre de linea 2 hasta que haya constantes
		int pos = linea.find("/");

		int direccion =  atoi(linea.substr(0,pos).c_str()) ;  // del principio hasta "/"
		int valor = atoi(linea.substr(pos).c_str()) ;
	}
	else{	// es cuadruplo
		string texto = linea;	//texto para ir cortandolo y encontrar los "/"

		int pos = texto.find("/");
		texto = texto.substr(pos+1);
		int pos2 = texto.find("/");
		texto = texto.substr(pos2+1);
		int pos3 = texto.find("/");
		texto = texto.substr(pos3+1);

		int op = atoi(linea.substr(0,pos).c_str()) ;   // del principio hasta "/"
		int op1 = atoi(linea.substr(pos,pos2).c_str()) ;  // del 1 / al 2 /
		int op2  = atoi(linea.substr(pos2,pos3).c_str()) ; // del 2/ al 3/
		int temp = atoi(linea.substr(pos3).c_str()) ; // del 3/ en adelante
	}




}
*/


/*iniicializar variables*/
        int pos,pos2,pos3,pos4;
        string valores;
        string op;
        string l;
		string op1 ;
		string op2;
		string temp ;
		int numeroConstantes;
		int direccion;
		string texto;


   if (archivo.is_open()) {
 while (!archivo.eof()) {
      numLinea++;
      getline (archivo,linea);

      if (numLinea==1){

          numeroConstantes= atoi(linea.c_str());
          cout<<"Primera Linea "<<numLinea<<"\n";
          cout<<"Numero de constantes"<<numeroConstantes<<"\n"; //imprime 1 Linea

          }






    else if (numLinea<10 && numLinea>1){

        pos = linea.find("/");
        cout<<"Pos de linea"<<pos<<"\n";

        direccion =  atoi(linea.substr(0,pos).c_str()) ;
        valores= linea.substr(pos+1) ;

        cout<< direccion<<" ";
        cout<<valores<<"\n";

}else {
        texto = linea;
        pos = texto.find("/");
        texto = texto.substr(pos+1);

        //empieza cuadruplos
		 pos2 = texto.find("/");
		 texto = texto.substr(pos2+1);

		 pos3 = texto.find("/");
		texto = texto.substr(pos3+1);

		 pos4 = texto.find("/");
		texto = texto.substr(pos4+1);


        l= linea.substr(0,pos);
        op = linea.substr(pos+1,pos2);   // del principio hasta "/"
		op1 = linea.substr(pos2+1,pos3) ;  // del 1 / al 2 /
		op2  = linea.substr(pos3+1,pos4) ; // del 2/ al 3/
		temp =linea.substr(pos4+1) ; // del 3/ en adelante


        cout<<l<<" ";
        cout<<op<<" ";
        cout<<op1<<" ";
        cout<<op2<<" ";
        cout<<temp<<"\n";


}


    //archivo>> output;
    cout<<linea <<"\n" ;



 }
}

archivo.close();
cout<<" Numero de Lineas "<<numLinea;



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


int valor;// primer numero del cuadruplo

/*Empieza el Switch*/

switch(valor){
case 0 /*Suma*/: //instrucciones
break;

case 1/*Resta*/://instrucciones
break;

case 2/*multiplicación*/://instrucciones
break;

case 3/*división*/://instrucciones
break;

case 4 /*==*/://instrucciones
break;

case 5 /* !=*/://instrucciones
break;

case 6 /*> */://instrucciones
break;

case 7 /*<*/://instrucciones
break;

case 8 /*AND*/://instrucciones
break;

case 9 /*OR*/://instrucciones
break;

case 10 /*=*/://instrucciones
break;

case 11 /*GOTO*/://instrucciones
break;

case 12 /*GOTOF*/://instrucciones
break;

case 13 /*GOTOV*/://instrucciones
break;

case 14 /*GOTOSUB*/://instrucciones
break;

case 20 /*ERA*/://instrucciones
break;

case 21 /**/://instrucciones
break;

case 22 /*RET*/: //instrucciones
break;

case 23 /*param*/://instrucciones
break;

case 24 /*Return*/: //instrucciones
break;

case 25 /*write*/://instrucciones
break;

case 26 /*PRINT*/://instrucciones
break;

case 30 /*END*/: //instrucciones
break;

}/*Termina el switch*/









    return 0;
}
