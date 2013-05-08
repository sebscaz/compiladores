#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <stack>

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
VER  	27
END   30
*/

using namespace std;




int getBase(int direccion){
    int base;

     if(direccion >= 10000 && direccion <= 10999){
          base=10000;
     }
     else if(direccion >= 11000 && direccion <= 11999){
          base=11000;
     }
     else if(direccion >= 12000 && direccion <= 12999){
          base=12000;
     }
     else if(direccion >= 13000 && direccion <= 13999){
          base=13000;
     }

     //Almacenar floats
     else if(direccion >= 20000 && direccion <= 20999){
          base=20000;
     }
     else if(direccion >= 21000 && direccion <= 21999){
          base=21000;
     }
     else if(direccion >= 22000 && direccion <= 22999){
          base=22000;
     }
     else if(direccion >= 23000 && direccion <= 23999){
          base=23000;
     }

     //Almacenar strings
     else if(direccion >= 30000 && direccion <= 30999){
          base=30000;
     }
     else if(direccion >= 31000 && direccion <= 31999){
          base=31000;
     }
     else if(direccion >= 32000 && direccion <= 32999){
          base=32000;
     }
     else if(direccion >= 33000 && direccion <= 33999){
          base=33000;
     }

     //Almacenar booleans
     else if(direccion >= 40000 && direccion <= 40999){
          base=40000;
     }
     else if(direccion >= 41000 && direccion <= 41999){
          base=41000;
     }
     else if(direccion >= 42000 && direccion <= 42999){
          base=42000;
     }
     else if(direccion >= 43000 && direccion <= 43999){
          base=43000;
     }

     return base;

}

/* Contadores de Variables*/
int contIntG=0, contIntL=0, contIntT=0, contIntC=0;
int contFloatG=0, contFloatL=0, contFloatT=0, contFloatC=0;
int contStringG=0, contStringL=0, contStringT=0, contStringC=0;
int contBoolG=0, contBoolL=0, contBoolC=0, contBoolT=0;

//Inicializar vectores\\

//pila de Ejecucion
stack<int> pilaEjecucion;

//Vector de contadores
//vector<int> contCuadruplos();

vector<int> enterosGlobales(contIntG);
vector<int> enterosLocales(contIntL);
vector<int> enterosTemporales(contIntT);
vector<int> enterosConstantes(contIntC);

vector<float> flotantesGlobales(contFloatG);
vector<float> flotantesLocales(contFloatL);
vector<float> flotantesTemporales(contFloatT);
vector<float> flotantesConstantes(contFloatC);

vector<string> stringGlobales(contStringG);
vector<string> stringLocales(contStringL);
vector<string> stringTemporales(contStringT);
vector<string> stringConstantes(contStringC);

vector<string> booleanoGlobales(contBoolG);
vector<string> booleanoLocales(contBoolL);
vector<string> booleanoTemporales(contBoolT);
vector<string> booleanoConstantes(contBoolC);

int checarRango(string operando){

    if (operando.at(0)=='1'){ return 1;}
    else if (operando.at(0)=='2'){return 2;}
    else if (operando.at(0)=='3'){ return 3; }
	else if (operando.at(0)=='4'){ return 3; }

}

int getValorVectorInt(string operando, int direccion, int base){

    if (operando.at(1)=='0'){ return enterosGlobales[direccion-base];}
    else if (operando.at(1)=='1'){return enterosLocales[direccion-base];}
    else if (operando.at(1)=='2'){return enterosTemporales[direccion-base];}
    else if (operando.at(1)=='3'){cout<<"_-_-_-__- ent const: "<< enterosConstantes[direccion-base]<<"\n"; return enterosConstantes[direccion-base];}

}

float getValorVectorFloat(string operando, int direccion, int base){

    if (operando.at(1)=='0'){ return flotantesGlobales[direccion-base];}
    else if (operando.at(1)=='1'){return flotantesLocales[direccion-base];}
    else if (operando.at(1)=='2'){return flotantesTemporales[direccion-base];}
    else if (operando.at(1)=='3'){return flotantesConstantes[direccion-base];}

}

string getValorVectorString(string operando, int direccion, int base){

    if (operando.at(1)=='0'){ return stringGlobales[direccion-base];}
    else if (operando.at(1)=='1'){return stringLocales[direccion-base];}
    else if (operando.at(1)=='2'){return stringTemporales[direccion-base];}
    else if (operando.at(1)=='3'){return stringConstantes[direccion-base];}

}

string getValorVectorBoolean(string operando, int direccion, int base){

    if (operando.at(1)=='0'){ return booleanoGlobales[direccion-base];}
    else if (operando.at(1)=='1'){return booleanoLocales[direccion-base];}
    else if (operando.at(1)=='2'){return booleanoTemporales[direccion-base];}
    else if (operando.at(1)=='3'){return booleanoConstantes[direccion-base];}
	
}

void generarVectores(){

    enterosGlobales.resize(contIntG);
    enterosLocales.resize(contIntL);
    enterosTemporales.resize(contIntT);
    enterosConstantes.resize(contIntC);

    flotantesGlobales.resize(contFloatG);
    flotantesLocales.resize(contFloatL);
    flotantesTemporales.resize(contFloatT);
    flotantesConstantes.resize(contFloatC);

    stringGlobales.resize(contStringG);
    stringLocales.resize(contStringL);
    stringTemporales.resize(contStringT);
    stringConstantes.resize(contStringC);

    booleanoGlobales.resize(contBoolG);
    booleanoLocales.resize(contBoolL);
    booleanoTemporales.resize(contBoolT);
    booleanoConstantes.resize(contBoolC);

}

void generarMemoria(int direccion, string valor){
    //cout<<"\n"<<direccion<<"\n";
    //Almacenar enteros
    //cout<<"\n --INTERSUME---  >"<<enterosConstantes[1]<<"\n";
    
     if(direccion >= 10000 && direccion <= 10999){
          enterosGlobales[direccion-10000]=atoi(valor.c_str());
     }
     else if(direccion >= 11000 && direccion <= 11999){
          enterosLocales[direccion-11000]=atoi(valor.c_str());
     }
     else if(direccion >= 12000 && direccion <= 12999){
            // cout<<"\n --INTERSUME..1---  >"<<enterosConstantes[1]<<"\n";
          enterosTemporales[direccion-12000]=atoi(valor.c_str());
          //   cout<<"\n --INTERSUME..2---  >"<<enterosConstantes[1]<<"\n";
          cout<<"\nDIRECCION!! " <<direccion<< ",, valor : "<< enterosTemporales[direccion-12000]<<"\n";
     }
     else if(direccion >= 13000 && direccion <= 13999){
          enterosConstantes[direccion-13000]=atoi(valor.c_str());
          cout<<"\nDIRECCION!! " <<direccion<< ",, valor : "<< enterosConstantes[direccion-13000]<<"\n";
     }

     //Almacenar floats
     else if(direccion >= 20000 && direccion <= 20999){
          flotantesGlobales[direccion-2000]=atof(valor.c_str());
     }
     else if(direccion >= 21000 && direccion <= 21999){
          flotantesLocales[direccion-21000]=atof(valor.c_str());
     }
     else if(direccion >= 22000 && direccion <= 22999){
          flotantesTemporales[direccion-22000]=atof(valor.c_str());
     }
     else if(direccion >= 23000 && direccion <= 23999){
          flotantesConstantes[direccion-23000]=atof(valor.c_str());
     }

     //Almacenar strings
     else if(direccion >= 30000 && direccion <= 30999){
          stringGlobales[direccion-3000]=valor;
     }
     else if(direccion >= 31000 && direccion <= 31999){
          stringLocales[direccion-31000]=valor;
     }
     else if(direccion >= 32000 && direccion <= 32999){
          stringTemporales[direccion-32000]=valor;
     }
     else if(direccion >= 33000 && direccion <= 33999){
          stringConstantes[direccion-33000]=valor;
     }

     //Almacenar booleans
     else if(direccion >= 40000 && direccion <= 40999){
          booleanoGlobales[direccion-4000]=valor;
     }
     else if(direccion >= 41000 && direccion <= 41999){
          booleanoLocales[direccion-41000]=valor;
     }
     else if(direccion >= 42000 && direccion <= 42999){
          booleanoTemporales[direccion-42000]=valor;
     }
     else if(direccion >= 43000 && direccion <= 43999){
          booleanoConstantes[direccion-43000]=valor;
     }

 //       cout<<"\n --INTERSUME2---  >"<<enterosConstantes[1]<<"\n";
}

void hacerOperacion(int operacion, string op1, string op2 , string temp){

    int base1, base2;			 //varaible para mapear direccion;
    int op1dir, op2dir;			 //almacena en forma de entero la direccion virtual
    int op1mapeo, op2mapeo;		 //posicion en el vector
    float op1ValorReal, op2ValorReal;	//Almacenar el valor real del operando, en forma de float y despues se convierte a int si es necesario
    string op1ValorRealString, op2ValorRealString;

    int resultadoInt;
    float resultadoFloat;

    op1dir = atoi(op1.c_str());
    op2dir = atoi(op2.c_str());

    base1 = getBase(op1dir);
    base2 = getBase(op2dir);

    op1mapeo= op1dir-base1;
    op2mapeo= op2dir-base2;

    /*Checar rangos de la direeciones para saber que tipo son*/
    //Checar si op1 es int o float
    if (checarRango(op1)==1)  {	//es int
        op1ValorReal= (float)getValorVectorInt(op1, op1dir, base1);
		cout << "______op1:" << op1 << " valor real: " << op1ValorReal <<"base: "<<base1<< "\n"; 
    }
    else if(checarRango(op1)==2){	//es float
        op1ValorReal= getValorVectorFloat(op1, op1dir, base1);
    }
    else if(checarRango(op1)==3){	//es text
        op1ValorRealString= getValorVectorString(op1, op1dir, base1);
    }
	 else if(checarRango(op1)==4){	//es bool
        op1ValorRealString= getValorVectorBoolean(op1, op1dir, base1);
    }

    //Checar si op2 es int o float
    if (checarRango(op2)==1)  {
        op2ValorReal= (float)getValorVectorInt(op2, op2dir, base2);
        cout << "______op2:" << op2 << " valor real: " << op2ValorReal <<"base: "<<base2<< "\n"; 
    }
    else if(checarRango(op2)==2){
        op2ValorReal= getValorVectorFloat(op2, op2dir, base2);
    }
	 else if(checarRango(op1)==3){	//es text
        op2ValorRealString= getValorVectorString(op2, op2dir, base2);
    }
	 else if(checarRango(op1)==4){	//es bool
        op2ValorRealString= getValorVectorBoolean(op2, op2dir, base2);
    }

    //Hacer operacion
    //SUMA
    if(operacion==0){
                    
        //Checar que tipo sera el resultado
        if(checarRango(temp)==1){
                                 
        	resultadoInt = (int)(op1ValorReal + op2ValorReal);
        	//cout<<"\n --PRESUMA2---  >"<<enterosConstantes[1]<<"\n";
        	//Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());
          //  cout<<"\n --PRESUMA3---  >"<<enterosConstantes[1]<<"\n";
         	cout<<"sumaInt "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoInt<<"\n";
        } else if (checarRango(temp)==2){
            resultadoFloat = op1ValorReal + op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	cout<<"sumaF "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
        }
 
    }
    else if (operacion==1){
        //Checar que tipo sera el resultado
        if(checarRango(temp)==1){
        	resultadoInt = (int)(op1ValorReal - op2ValorReal);
        	//Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());
         	cout<<"resta "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoInt<<"\n";
        } else if (checarRango(temp)==2){
            resultadoFloat = op1ValorReal - op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	cout<<"resta "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
        }
    }
    else if (operacion==2){
        //Checar que tipo sera el resultado
        if(checarRango(temp)==1){
        	resultadoInt = (int)(op1ValorReal * op2ValorReal);
        	//Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());
         	cout<<"multipl "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoInt<<"\n";
        } else if (checarRango(temp)==2){
            resultadoFloat = op1ValorReal * op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	cout<<"multipl "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
        }
    }
    else if (operacion==3){

            resultadoFloat = op1ValorReal / op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	cout<<"divisiooonn "<<" op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";


            /*
        //Checar que tipo sera el resultado
        if(checarRango(temp)==1){

           // resultadoInt = (int)op1ValorReal / op2ValorReal;
        	resultadoFloat = (op1ValorReal / op2ValorReal);
        	//Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());
         	cout<<"divsion "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
        } else if (checarRango(temp)==2){
            resultadoFloat = op1ValorReal / op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());
        	cout<<"division "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoInt<<"\n";
        }
        */
    }

    // MAYOR
    else if (operacion==6){
         
            //resultadoFloat = op1ValorReal / op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            //generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	
            cout<<"mayor op:"<<operacion <<" op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
     
            if(op1ValorReal  > op2ValorReal){
                              //generarMemoria(atoi(temp.c_str()), "v");
                              }
            else{
                              printf("what");
                              //generarMemoria(atoi(temp.c_str()), "f"); 
                              }
           
    }
    
    else if (operacion==10){
         /*
            cout<<"= ASIG op:"<<operacion <<" op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
     
      		//Asignar valor si op1 es una constante
			if(op1dir >= 13000 && op1dir <= 13999){
				generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << op1ValorReal) )->str());
			}
			else if(op1dir >= 23000 && op1dir <= 23999){
				generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << op1ValorReal) )->str());
			} 
			else if (op1dir >= 33000 && op1dir <= 33999){
				generarMemoria(atoi(temp.c_str()),  op1ValorRealString);
			}
			else if (op1dir >= 43000 && op1dir <= 43999){
				generarMemoria(atoi(temp.c_str()),  op1ValorRealString);
			}
           
		   //Asignar lo que hay en el apuntador si es una variable
			if (checarRango(op1)==1)  {	//es int
					op1ValorReal= (float)getValorVectorInt(op1, op1dir, base1);
					generarMemoria(atoi(temp.c_str()),  static_cast<ostringstream*>( &(ostringstream() << op1ValorReal) )->str());
			}
			else if(checarRango(op1)==2){	//es float
					op1ValorReal= getValorVectorFloat(op1, op1dir, base1);
					generarMemoria(atoi(temp.c_str()),  static_cast<ostringstream*>( &(ostringstream() << op1ValorReal) )->str());
			}
			else if(checarRango(op1)==3){	//es text
					string op1ValorRealString= getValorVectorString(op1, op1dir, base1);
					generarMemoria(atoi(temp.c_str()),  op1ValorRealString);
			}
			else if(checarRango(op1)==4){	//es boolean
					string op1ValorRealString= getValorVectorBoolean(op1, op1dir, base1);
					generarMemoria(atoi(temp.c_str()),  op1ValorRealString);
			}
          */ 
    }
    
}

void hacerPrint(string op1){

    int base1;			 //varaible para mapear direccion;
    int op1dir;

    op1dir = atoi(op1.c_str());
    base1 = getBase(op1dir);




                	    //ChecarRango
                	       if (checarRango(op1)==1)  {	//es int
                                 cout<< "Print "<< getValorVectorInt(op1, op1dir, base1)<<"\n";
                            }
                            else if (checarRango(op1)==2){	//es float
                                 cout<<"Print " <<getValorVectorFloat(op1, op1dir, base1)<<"\n";
                            }
                             else if (checarRango(op1)==3){	//es float
                                 cout<<"Print "<< getValorVectorString(op1, op1dir, base1)<<"\n";
                            }
}




void hacerIgual(int op1, int temp, int direccion){

/*
    int base1, base2;			 //varaible para mapear direccion;
    int op1dir;
    int num1;
    string valor;

 base1 = getBase(direccion);
   // base1 = getBase(direccion);
    generarMemoria(direccion, op1);
    
                              //Verificar que la direecion se haya guardado en temporal

                              if (checarRango(temp)==1)  {	//es int
                                 cout<< "Print "<< getValorVectorInt(temp, direccion, base1)<<"\n";
                            }
                            else if (checarRango(temp)==2){	//es float
                                 cout<<"Print " <<getValorVectorFloat(temp, direccion, base1)<<"\n";
                            }
                             else if (checarRango(temp)==3){	//es float
                                 cout<<"Print "<< getValorVectorString(temp, direccion, base1)<<"\n";
                            }


         

			//checar si es constante o variable
			if(direccion >= 13000 && direccion <= 13999){
				generarMemoria(temp, static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
			}
			 */      	  

}


void hacerVerifica(string indiceString, string limInfString, string limSupString){

	int indice = atoi(indiceString.c_str());
	int limInf = atoi(limInfString.c_str());
	int limSup = atoi(limSupString.c_str());
	
	
	cout<<"\nindice: "<<indice<<", limInf: "<<limInf<<",limSup: "<<limSup;
	
	
	if(indice < limInf || indice > limSup){
		cout<<"\nIndice fuera del arreglo\n";
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
	int numCuadruplos=0;
	 string cuadruplos[100][5];
	 int dirRetorno;

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
			if (numLinea==1) {numeroConstantes= atoi(linea.c_str());cout<<numeroConstantes;}
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
            else if (numLinea==17) {contIntC= atoi(linea.c_str()); generarVectores();}

			//Constantes
			else if (numLinea<=numeroConstantes + 17 && numLinea>17){
				pos = linea.find("/");
				//cout<<"Pos de linea"<<pos<<"\n";
				direccion =  atoi(linea.substr(0,pos).c_str()) ;
				valores= linea.substr(pos+1);

	            generarMemoria(direccion,valores);
			}


			//Cuadruplos
            else {
                 numCuadruplos++;
                 
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


				//mete elos cuasruplos a la matriz
				cuadruplos[numCuadruplos][0]= l;
				cuadruplos[numCuadruplos][1]= op;
				cuadruplos[numCuadruplos][2]= op1;
				cuadruplos[numCuadruplos][3]= op2;
				cuadruplos[numCuadruplos][4]= temp;


              

			}


		}//while

	}//if
	archivo.close();


cout<<"num de lineas del archivo"<<numLinea<<"\n";
cout<<"num de cuadruplos del archivo"<<numCuadruplos<<"\n";


/*
//Imprimir matriz
for(int x=0;x<numCuadruplos;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<5;y++)  // loop for the three elements on the line
        {
            //cout<<cuadruplos[x][y]<<",";  // display the current element out of the array
        }
    cout<<endl;  // when the inner loop is done, go to a new line
    }
*/
int i=0;

while (i<numCuadruplos){
      i++;
     
     cout<<"---Numero i "<<i<<", num cuadruplo  "<<cuadruplos[i][0]<<", op  "<<cuadruplos[i][1]<<", op1  "<<cuadruplos[i][2]<<", op2  "<<cuadruplos[i][3]<<", temp  "<<cuadruplos[i][4]<<"\n";
      /*Empieza el Switch*/
                switch(atoi(cuadruplos[i][1].c_str())){


              		case 0 /*Suma*/:{ //instrucciones
              		        cout<<i<<"<<<<cuadruplo \n";
              		
         		       hacerOperacion(0, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    }
                	break;

                	case 1/*Resta*/:{//instrucciones
                	 cout<<i<<"<<<<cuadruplo \n";
                    	 hacerOperacion(1, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    }
                	break;

                	case 2/*multiplicación*/:{//instrucciones
                	 cout<<i<<"<<<<cuadruplo \n";
                         hacerOperacion(2, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    }
                	break;

                	case 3/*división*/:{//instrucciones
                	 cout<<i<<"<<<<cuadruplo \n";
                	       hacerOperacion(3, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    }
                	break;

                	case 4 /*==*/://instrucciones
                	break;

                	case 5 /* !=*/://instrucciones
                	break;

                	case 6: { /*> *///instrucciones
                    
                          hacerOperacion(6, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    
                    }
                	break;

                	case 7 /*<*/://instrucciones
                	break;

                	case 8 /*AND*/://instrucciones
                	break;

                	case 9 /*OR*/://instrucciones
                	break;

                	case 10 /*=*/://instrucciones
                   cout<<i<<"<<<<cuadruplo \n";
                    // cout<<"\n ASIGNACION >"<<cuadruplos[i][2]<<" ->" <<cuadruplos[i][4] <<"\n";
                            
					  hacerOperacion(10, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                       //hacerIgual(cuadruplos[i][2] ,cuadruplos[i][4] , atoi(cuadruplos[i][4].c_str()) );

                	break;

                	case 11 /*GOTO*/://instrucciones
                   //  dirGoto = atoi(l.c_str());
                    cout<<i<<"<<<<cuadruplo \n";
                   cout<<"\n Goto >"<<cuadruplos[i][4]<<"\n";
                   i=atoi(cuadruplos[i][4].c_str());


                	break;


                	case 12 /*GOTOF*/://instrucciones
                
                    	
             	   cout<<"\n Goto Falso >"<<cuadruplos[i][4]<<"\n";
             	    cout<<i<<"<<<<cuadruplo \n";
                  // i=atoi(cuadruplos[i][4].c_str())-1;
                	
                	break;
                	
                	

                	case 13 /*GOTOV*/://instrucciones
                	break;

                	case 14 /*GOTOSUB*/://instrucciones


                	break;

                	case 19://ver
                        break;

                	case 20 /*ERA*/://instrucciones
                    //salvar la base actual previa a la llamada
                    
                    
                	//Definir el tamaño de la memoria
                	//Actualizar la base local
                	//Generar el espacio de memoria

                	break;

                	case 21 /*gosub*/://instrucciones
                	     //Meter la direccion de retorno en la pila de ejecución
                	     
                	     cout<<"\n prewhaat  >"<<enterosConstantes[1]<<"\n";
                	      cout<<i<<"<<<<cuadruplo \n";

                	     dirRetorno = atoi( cuadruplos[i][1].c_str());

                	     pilaEjecucion.push(i);

                	    cout<< "\n Pila de Ejecucion " << i;

                	    //Transferir el control de hecucion a la direccion donde inicia el procedimiento
                	    cout<<"\n GO SUB >"<<cuadruplos[i][2]<<"\n";
                         i=atoi(cuadruplos[i][2].c_str());

                          cout<<"\n whaat  >"<<enterosConstantes[1]<<"\n";

                	break;

                	case 22 /*RET*/: //instrucciones
                	    //actualizar la base local(previa a la llamada)
                	    //destruir el registro de activación del proc d ememoria local
                	    //Recuperar la dirección de rerono y transeferir el control de ejeciucpin
                	   
                        // cout<<"\n RET >"<<pilaEjecucion.top();
                	     i= pilaEjecucion.top();//Regresa a donde estaba 
                	    
                	    
                	break;

                	case 23 /*param*/://instrucciones
                	cout<<"\n supeerwhaat  >"<<enterosConstantes[1]<<"\n";
                	
                          //cout<<i<<"<<<<cuadruplo \n";
                          //cout<<"PARAM\n";
                	    //Meter los valores al amemoria local

                	break;

                	case 24 /*Return*/: //instrucciones
                	break;

                	case 25 /*read*/://instrucciones
                	 //cout<<i<<"<<<<cuadruplo \n";
                	 //cout<<"READ\n";
                	break;

                	case 26 /*PRINT*/:{//instrucciones
                	 cout<<i<<"<<<<cuadruplo \n";
                    hacerPrint(cuadruplos[i][2]);
					
					}
                	break;
					
					case 27 /*PRINT*/:{//instrucciones
          
                     hacerVerifica(cuadruplos[i][2],cuadruplos[i][3],cuadruplos[i][4]);
					
					}
                	break;

                	case 30 /*END*/: //instrucciones
                	
                	 cout<<i<<"<<<<cuadruplo \n";
                	 cout<<"END\n";
                	break;

                }/*Termina el switch*/

      
      
      
      }

	 int acabar;
	cin>>acabar;
/*
	//Indice de Memoria

	//Dir. Globales
	int enteroGlobal_I=5000, enteroGlobal_F=5999;
	int flotanteGlobal_I=6000, flotanteGlobal_F=6999;
	int stringGlobal_I=7000, stringGlobal_F=7999;
	int boleanoGlobal_I=8000, boleanoGlobal_F=8999;

	//Dir Locales
	int enteroLocal_I=9000, enteroLocal_F=9999;
	int flotanteLocal_I=10000, flotanteLocal_F=10999;
	int stringLocal_I=11000, stringLocal_F=11999;
	int boleanoLocal_I=12000, boleanoLocal_F=12999;

	//Dir Contantes
	int enteroConstante_I=13000, enteroConstante_F=13500;
	int flotanteConstante_I=13501, flotanteConstante_F=13999;
	int stringConstante_I=14000, stringConstante_F=14500;
	int boleanoConstante_I=14501, boleanoConstante_F=14999;

	//Dir. temporales
	int enteroTemp_I=15000, enteroTemp_F=15999;
	int flotanteTemp_I=16000, flotanteTemp_F=16999;
	int stringTemp_I=17000, stringTemp_F=17999;
	int boleanoTemp_I=18000, boleanoTemp_F=18999;

*/

    return 0;
} 

