#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <sstream>

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

using namespace std;

/* Contadores de Variables*/
int contIntG=0, contIntL=0, contIntT=0, contIntC=0;
int contFloatG=0, contFloatL=0, contFloatT=0, contFloatC=0;
int contStringG=0, contStringL=0, contStringT=0, contStringC=0;
int contBoolG=0, contBoolL=0, contBoolC=0, contBoolT=0;

//Inicializar vectores

//Vector de contadores
//vector<int> contCuadruplos();

vector<int> enterosGlobales(contIntG);
vector<int> enterosLocales(contIntL);
vector<int> enterosTemporales(contIntT);
vector<int> enterosConstantes(contIntC);

vector<double> flotantesGlobales(contFloatG);
vector<double> flotantesLocales(contFloatL);
vector<double> flotantesTemporales(contFloatT);
vector<double> flotantesConstantes(contFloatC);

vector<string> stringGlobales(contStringG);
vector<string> stringLocales(contStringL);
vector<string> stringTemporales(contStringT);
vector<string> stringConstantes(contStringC);

vector<string> booleanoGlobales(contBoolG);
vector<string> booleanoLocales(contBoolL);
vector<string> boolenoTemporales(contBoolT);
vector<string> booleanoConstantes(contBoolC);

void generarMemoria(int direccion, string valor){
    
    //Almacenar enteros 
     if(direccion >= 10000 && direccion <= 10999){
          enterosGlobales[direccion-1000];          
     }
     else if(direccion >= 11000 && direccion <= 11999){
          enterosLocales[direccion-11000];
     }
     else if(direccion >= 12000 && direccion <= 12999){
          enterosTemporales[direccion-12000];
     }
     else if(direccion >= 13000 && direccion <= 13999){
          enterosConstantes[direccion-13000];
     }
     
     //Almacenar floats 
     if(direccion >= 20000 && direccion <= 20999){
          enterosGlobales[direccion-2000];          
     }
     else if(direccion >= 21000 && direccion <= 21999){
          enterosLocales[direccion-21000];
     }
     else if(direccion >= 22000 && direccion <= 22999){
          enterosTemporales[direccion-22000];
     }
     else if(direccion >= 23000 && direccion <= 23999){
          enterosConstantes[direccion-23000];
     }
     
     //Almacenar strings 
     if(direccion >= 30000 && direccion <= 30999){
          enterosGlobales[direccion-3000];          
     }
     else if(direccion >= 31000 && direccion <= 31999){
          enterosLocales[direccion-31000];
     }
     else if(direccion >= 32000 && direccion <= 32999){
          enterosTemporales[direccion-32000];
     }
     else if(direccion >= 33000 && direccion <= 33999){
          enterosConstantes[direccion-33000];
     }
     
     //Almacenar booleans 
     if(direccion >= 40000 && direccion <= 40999){
          enterosGlobales[direccion-4000];          
     }
     else if(direccion >= 41000 && direccion <= 41999){
          enterosLocales[direccion-41000];
     }
     else if(direccion >= 42000 && direccion <= 42999){
          enterosTemporales[direccion-42000];
     }
     else if(direccion >= 43000 && direccion <= 43999){
          enterosConstantes[direccion-43000];
     }
     
     
}

int main(){

   //Lector del archivos de cuiadruplos
   // system("analizador.exe pruebalenguaje"); // no estoy tan seguro como funecione este

	//iniicializar variables
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
		
    string linea;
    int numLinea=0;
    //int numeroConstantes=0;
    ifstream archivo;  // objeto de la clase ofstream
    archivo.open("cuadruplos.txt");
    		
	if (archivo.is_open()) {
		while (!archivo.eof()) {
			numLinea++;
			getline (archivo,linea);

			//Numero de constantes
			if (numLinea==1) numeroConstantes= atoi(linea.c_str());
            else if (numLinea==2) contIntG= atoi(linea.c_str());
            else if (numLinea==3) contIntL= atoi(linea.c_str());
            else if (numLinea==4) contIntT= atoi(linea.c_str());
            else if (numLinea==5) contIntC= atoi(linea.c_str());
            else if (numLinea==6) contFloatG= atoi(linea.c_str());
            else if (numLinea==7) contFloatL= atoi(linea.c_str());
            else if (numLinea==8) contFloatT= atoi(linea.c_str());
            else if (numLinea==9) contFloatC= atoi(linea.c_str());
            else if (numLinea==10) contStringG= atoi(linea.c_str());
            else if (numLinea==11) contStringL= atoi(linea.c_str());
            else if (numLinea==12) contStringT= atoi(linea.c_str());
            else if (numLinea==13) contStringC= atoi(linea.c_str());
            else if (numLinea==14) contBoolG= atoi(linea.c_str());
            else if (numLinea==15) contBoolL= atoi(linea.c_str());
            else if (numLinea==16) contIntT= atoi(linea.c_str());
            else if (numLinea==17) contIntC= atoi(linea.c_str());
            
			//Constantes
			else if (numLinea<=numeroConstantes + 1 && numLinea>17){
				pos = linea.find("/");
				//cout<<"Pos de linea"<<pos<<"\n";
				direccion =  atoi(linea.substr(0,pos).c_str()) ;
				valores= linea.substr(pos+1);  
	
	            //generarMemoria(direccion,valores);
			} 
			//Cuadruplos
            else {
				texto = linea;
				pos = texto.find("/");
				l= texto.substr(0,pos);

				texto = texto.substr(pos+1);
				pos = texto.find("/");
				op = texto.substr(0,pos);   // del principio hasta "/"

				texto = texto.substr(pos+1);
				pos = texto.find("/");
				op1 = texto.substr(0,pos);   // del principio hasta "/"

				texto = texto.substr(pos+1);
				pos = texto.find("/");
				op2 = texto.substr(0,pos);   // del principio hasta "/"

				texto = texto.substr(pos+1);
				pos = texto.find("/");
				temp = texto.substr(0,pos);   // del principio hasta "/"

				cout<<l<<" - ";
				cout<<op<<" - ";
				cout<<op1<<" - ";
				cout<<op2<<" - ";
				cout<<temp<<"\n";  
				
                /*Empieza el Switch*/
                switch(atoi(op.c_str())){
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

			}            
		}//while

	}//if
	archivo.close();
	cout<<" Numero de Lineas "<<numLinea;
	 int acabar;
	cin>>acabar;
	
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



