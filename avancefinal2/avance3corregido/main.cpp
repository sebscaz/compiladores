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
int esRetorno=0;
int esMatriz=0;
/* Contadores de Variables*/
int contIntG=0, contIntL=0, contIntT=0, contIntC=0;
int contFloatG=0, contFloatL=0, contFloatT=0, contFloatC=0;
int contStringG=0, contStringL=0, contStringT=0, contStringC=0;
int contBoolG=0, contBoolL=0, contBoolC=0, contBoolT=0;

//Inicializar vectores\\

//pila de Ejecucion
stack<int> pilaEjecucion;
//std::stack< int, std::vector< int > > pilaLocalEntera;
stack< vector < int > > pilaLocalEntera;
stack< vector < float > > pilaLocalFlotante;
stack< vector < string > > pilaLocalString;
stack< vector < string > > pilaLocalBoolean;

//Temporales
stack< vector < int > > pilaTemporalEntera;
stack< vector < float > > pilaTemporalFlotante;
stack< vector < string > > pilaTemporalString;
stack< vector < string > > pilaTemporalBoolean;


vector<int> funciones(50);
stack<int> pilaFunciones;
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

    if (operando.at(0)=='1'){/* cout<<"....Rango  "<<1<<"\n";*/ return 1;}
    else if (operando.at(0)=='2'){return 2;}
    else if (operando.at(0)=='3'){ return 3; }
	else if (operando.at(0)=='4'){ return 3; }

}

int getValorVectorInt(string operando, int direccion, int base){

    if (operando.at(1)=='0'){ return enterosGlobales[direccion-base];}
    else if (operando.at(1)=='1'){return enterosLocales[direccion-base];}
    else if (operando.at(1)=='2'){return enterosTemporales[direccion-base];}
    else if (operando.at(1)=='3'){
         //cout<<"_-_-_-__- ent const: "<< enterosConstantes[direccion-base]<<"\n";
          return enterosConstantes[direccion-base];}

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
    enterosLocales.resize(20);
    enterosTemporales.resize(20);
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
    cout<<"--GenerarMemora---  >"<<direccion<<" "<<valor<<"\n";
    
     if(direccion >= 10000 && direccion <= 10999){
          enterosGlobales[direccion-10000]=atoi(valor.c_str());
     }
     else if(direccion >= 11000 && direccion <= 11999){
          enterosLocales[direccion-11000]=atoi(valor.c_str());
     }
     else if(direccion >= 12000 && direccion <= 12999){
            // cout<<"\n --INTERSUME..1---  >"<<enterosConstantes[1]<<"\n";
          enterosTemporales[direccion-12000]=atoi(valor.c_str());
             //cout<<"\n --INTERSUME..2---  >"<<enterosConstantes[1]<<"\n";
          //cout<<"\nDIRECCION!! " <<direccion<< ",, valor : "<< enterosTemporales[direccion-12000]<<"\n";
     }
     else if(direccion >= 13000 && direccion <= 13999){
          enterosConstantes[direccion-13000]=atoi(valor.c_str());
          //cout<<"\nDIRECCION!! " <<direccion<< ",, valor : "<< enterosConstantes[direccion-13000]<<"\n";
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
    int valorRetorno;
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
	//	cout << "______op1:" << op1 << " valor real: " << op1ValorReal <<"base: "<<base1<< "\n"; 
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
                    // cout<<"\n --PRESUMA---  >"<<enterosConstantes[1]<<"\n";
        //Checar que tipo sera el resultado
        if(checarRango(temp)==1){
                                 
        	resultadoInt = (int)(op1ValorReal + op2ValorReal);
        //	cout<<"\n --PRESUMA2---  >"<<enterosConstantes[1]<<"\n";
        	//Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());
           // cout<<"\n --PRESUMA3---  >"<<enterosConstantes[1]<<"\n";
         	//
          cout<<"sumaInt "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoInt<<"\n";
        } else if (checarRango(temp)==2){
            resultadoFloat = op1ValorReal + op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	cout<<"sumaF "<<"op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
        }
        
        // cout<<"\n --POSTSUMA---  >"<<enterosConstantes[1]<<"\n";
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
    else if (operacion==4){
         
            //resultadoFloat = op1ValorReal / op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            //generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	
            cout<<"mayor op:"<<operacion <<" op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
     
            if(op1ValorReal  == op2ValorReal){
                              generarMemoria(atoi(temp.c_str()), "v");
                              }
            else{
                              printf("what");
                              generarMemoria(atoi(temp.c_str()), "f"); 
                              }
           
    }
    
        else if (operacion==5){
         
            //resultadoFloat = op1ValorReal / op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            //generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	
            cout<<"mayor op:"<<operacion <<" op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
     
            if(op1ValorReal  != op2ValorReal){
                              generarMemoria(atoi(temp.c_str()), "v");
                              }
            else{
                              printf("what");
                              generarMemoria(atoi(temp.c_str()), "f"); 
                              }
           
    }
    

    // MAYOR
    else if (operacion==6){
         
            //resultadoFloat = op1ValorReal / op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            //generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	
            cout<<"mayor op:"<<operacion <<" op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
     
            if(op1ValorReal  > op2ValorReal){
                              generarMemoria(atoi(temp.c_str()), "v");
                              }
            else{
                              printf("what");
                              generarMemoria(atoi(temp.c_str()), "f"); 
                              }
           
    }
    
        else if (operacion==7){
         
            //resultadoFloat = op1ValorReal / op2ValorReal;
            //Meter valor del temporal en memoria, hay que convertir a string el resultado
            //generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoFloat) )->str());
        	
            cout<<"mayor op:"<<operacion <<" op1 "<<op1ValorReal<<" op2 "<<op2ValorReal<<" temp " << temp <<" Resultado: " <<resultadoFloat<<"\n";
     
            if(op1ValorReal  < op2ValorReal){
                              generarMemoria(atoi(temp.c_str()), "v");
                              }
            else{
                              printf("what");
                              generarMemoria(atoi(temp.c_str()), "f"); 
                              }
           
    }
    
    else if (operacion==10){
         /*
             if(esMatriz==1){
    
                    cout <<"\nAntes Asifg temp: "<< temp <<", tempString "<< atoi(temp.c_str())<<"\n";
                    int tempdir= getValorVectorInt(temp, atoi(temp.c_str()), 12000);
                    cout << "tempdir:" << tempdir << "\n";
                   temp = static_cast<ostringstream*>( &(ostringstream() << tempdir) )->str();
                   /*op1dir = getValorVectorInt(static_cast<ostringstream*>( &(ostringstream() << direccionMatriz) )->str(), direccionMatriz, base1);
                   op1 =  static_cast<ostringstream*>( &(ostringstream() << op1dir) )->str();
                   cout <<"\n Despues Asig op1dir: "<< op1dir <<", op1: \n"<< op1;
                   */
   /* }*/
                    cout<<"= ASIG op:"<<operacion <<" op1 "<<op1ValorReal<<" se guardara en"<<" temp "<<temp  <<" Resultado: " <<"\n";
   
         if (esRetorno==1){
                     valorRetorno=pilaFunciones.top();  
                           
                    generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << valorRetorno) )->str());       
                     esRetorno=0;    
         }
            
			
     
      		//Asignar valor si op1 es una constante
			 else if(op1dir >= 13000 && op1dir <= 13999 ){
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
			
			//esMatriz=0;
		
           
    }
    
       
    
         
    
    
}

void hacerPrint(int operacion, string op1, string op2 , string temp){

    int base1, baseInception;			 //varaible para mapear direccion;
    int op1dir=0;

    op1dir = atoi(op1.c_str());
    base1 = getBase(op1dir);


    cout<<"op1-----"<< op1;

    if(esMatriz==1){
    
                    cout <<"\nAntes temp: "<< op1 <<", op1:"<< op1;
                   // int direccionMatriz 
                   
                    op1dir= getValorVectorInt(op1, atoi(op1.c_str()), 12000);
                    base1=getBase(op1dir);
                    cout <<"\nDirecon matiz: "<< op1dir <<", base:"<< base1;
                    /*
                    base1=getBase(direccionMatriz);
                      
                   op1dir = getValorVectorInt(static_cast<ostringstream*>( &(ostringstream() << direccionMatriz) )->str(), direccionMatriz, base1);
                  //temp =  static_cast<ostringstream*>( &(ostringstream() << temp) )->str();*/
                   cout <<"\n Despues temp: "<< op1dir <<", op1:"<< op1dir;
                   
    }
    
    //ChecarRango
   if (checarRango(op1)==1)  {	//es int
         cout<< "\nPrint "<< getValorVectorInt(static_cast<ostringstream*>( &(ostringstream() << op1dir) )->str(), op1dir, base1)<<"\n";
    }
    else if (checarRango(op1)==2){	//es float
         cout<<"\nPrint " <<getValorVectorFloat(static_cast<ostringstream*>( &(ostringstream() << op1dir) )->str(), op1dir, base1)<<"\n";
    }
     else if (checarRango(op1)==3){	//es float
         cout<<"\nPrint "<< getValorVectorString(static_cast<ostringstream*>( &(ostringstream() << op1dir) )->str(), op1dir, base1)<<"\n";
    }
    
    esMatriz=0;
}




void sumaVector(int operacion, string op1, string op2 , string temp){

    int base1, base2;			 //varaible para mapear direccion;
    int op1dir, op2dir;			 //almacena en forma de entero la direccion virtual
    int resultadoInt;
    float resultadoFloat;

    op1dir = atoi(op1.c_str());
    op2dir = atoi(op2.c_str());
     
    base1 = getBase(op1dir);
    
     //Realizar suma dirBase + (s1*m1)                    
        	resultadoInt =  getValorVectorInt(op1, op1dir, base1) + op2dir;
        	
            cout<<"Suma VEctor "<< getValorVectorInt(op1, op1dir, base1)<< "+++++++" << op2dir   << "\n"; 
            cout << " suma vector REsultado "<< resultadoInt<<"\n";
        
        	//Meter valor del temporal en memoria, hay que convertir a string el resultado
            generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());
           	generarMemoria(resultadoInt, static_cast<ostringstream*>( &(ostringstream() << 0) )->str());
			
    

}

void multiplicaVector(int operacion, string op1, string op2 , string temp){

    int base1, base2;			 //varaible para mapear direccion;
    int op1dir, op2dir;			 //almacena en forma de entero la direccion virtual
    int resultadoInt;
    float resultadoFloat;

    op1dir = atoi(op1.c_str());
    op2dir = atoi(op2.c_str());
     
    base1 = getBase(op1dir);
    
            //cout<<"op1: "<<op1<<", op1dor:"<<op1dir<<", base1: "<<base1;
            cout<<"Multiplica "<< getValorVectorInt(op1, op1dir, base1)<< "*****" << op2dir   << "\n"; 
        
                    //Realizar la operacion s1*m1                 
        	resultadoInt =  getValorVectorInt(op1, op1dir, base1) * op2dir;
        	cout << " multplica vector REsultado "<< resultadoInt<<"\n";
        
        	//Meter valor del temporal en memoria, hay que convertir a string el resultado
           generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());

    

}

void verifica(int operacion, string op1, string op2 , string temp){

    int base1, base2;			 //varaible para mapear direccion;
    int op1dir, tempInt;			 //almacena en forma de entero la direccion virtual
    int resultadoInt;
    float resultadoFloat;

    op1dir = atoi(op1.c_str());
    tempInt = atoi(temp.c_str());
     
      base1 = getBase(op1dir);
        
    if (getValorVectorInt(op1, op1dir, base1)<=tempInt){
    //cout<<"Verifica Correcto!! \n";
    }
    else cout<<"El valor es mayot al numero de casillas asignadas \n";

    

}
void retorno(string op1, string temp){

    int base1;			 //varaible para mapear direccion;
    int op1dir	;		 //almacena en forma de entero la direccion virtual
    int resultadoInt;
    

    op1dir = atoi(op1.c_str());
    base1 = getBase(op1dir);
        
    resultadoInt=getValorVectorInt(op1, op1dir, base1);
    generarMemoria(atoi(temp.c_str()), static_cast<ostringstream*>( &(ostringstream() << resultadoInt) )->str());

    cout<<"Meter a la pila de funciones "<<resultadoInt<< "\n ";
    pilaFunciones.push(resultadoInt);
    esRetorno=1;

    
}

void param(string op1, string param){

    int base1;			 //varaible para mapear direccion;
    int op1dir	;		 //almacena en forma de entero la direccion virtual
    int resultadoInt;
    float resultadoFloat;
    string resultadoString;
    int numParam=atoi(param.c_str());
        
    op1dir = atoi(op1.c_str());
    base1 = getBase(op1dir);
        
     


         //ChecarRango
    if (checarRango(op1)==1)  {	//es int
          resultadoInt=getValorVectorInt(op1, op1dir, base1);
          
          enterosLocales[numParam]=resultadoInt;
          
    }
    else if (checarRango(op1)==2){	//es float
        resultadoFloat=getValorVectorFloat(op1,op1dir,base1);
        flotantesLocales[numParam]=resultadoFloat;
    }
     else if (checarRango(op1)==3){	//es striing
       resultadoString= getValorVectorString(op1,op1dir,base1);
       stringLocales[numParam]=resultadoString;
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
	  int base1;			 //varaible para mapear direccion;
      int op1dir	;		 //almacena en forma de entero la direccion virtual
       string resultadoString;

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
            else if (numLinea==16) contBoolT= atoi(linea.c_str());
            else if (numLinea==17) {contBoolC= atoi(linea.c_str()); generarVectores();}

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
for(int x=0;x<=numCuadruplos;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<5;y++)  // loop for the three elements on the line
        {
            cout<<cuadruplos[x][y]<<",";  // display the current element out of the array
        }
    cout<<endl;  // when the inner loop is done, go to a new line
    }
*/
int i=0;


while (i<numCuadruplos){
      i++;
     
     cout<<"---Numero i "<<i<<", num cuadruplo  "<<cuadruplos[i][0]<<", op  "<<cuadruplos[i][1]<<", op1  "<<cuadruplos[i][2]<<", op2  "<<cuadruplos[i][3]<<", temp  "<<cuadruplos[i][4]<<"\n";
    
      //Empieza el Switch
                switch(atoi(cuadruplos[i][1].c_str())){


              		case 0 :{ //Suma instrucciones
              		      // cout<<i<<"<<<<cuadruplo \n";
              		
         		       hacerOperacion(0, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    }
                	break;

                	case 1:{//resta instrucciones
                	 //cout<<i<<"<<<<cuadruplo \n";
                    	 hacerOperacion(1, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    }
                	break;

                	case 2:{// multipliacion instrucciones
                	 //cout<<i<<"<<<<cuadruplo \n";
                         hacerOperacion(2, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    }
                	break;

                	case 3:{// division  instrucciones
                	 //cout<<i<<"<<<<cuadruplo \n";
                	       hacerOperacion(3, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    }
                	break;

                	case 4 ://==  instrucciones
                	break;

                	case 5 :// !=  instrucciones
                	break;

                	case 6: { /// >  instrucciones
                    
                          hacerOperacion(6, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                    
                    }
                	break;

                	case 7 ://<  instrucciones
                	      hacerOperacion(7, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                	break;

                	case 8 :// and  instrucciones
                	break;

                	case 9 ://or  instrucciones
                	break;

                	case 10 ://=  instrucciones
                  // cout<<i<<"<<<<cuadruplo \n";
                    // cout<<"\n ASIGNACION >"<<cuadruplos[i][2]<<" ->" <<cuadruplos[i][4] <<"\n";
                            
					  hacerOperacion(10, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                       //hacerIgual(cuadruplos[i][2] ,cuadruplos[i][4] , atoi(cuadruplos[i][4].c_str()) );

                	break;

                	case 11 :// gootoo   instrucciones
                   //  dirGoto = atoi(l.c_str());
                   // cout<<i<<"<<<<cuadruplo \n";
                      cout<<"\n Goto >"<<cuadruplos[i][4]<<"\n";
                       i=atoi(cuadruplos[i][4].c_str());


                	break;


                	case 12 ://gotoooF   instrucciones
                
                    	
                       op1dir = atoi(cuadruplos[i][2].c_str());
                       base1 = getBase(op1dir);
                       resultadoString=getValorVectorBoolean(cuadruplos[i][2], op1dir, base1);
             	       cout<<"\n Goto Falso >"<<cuadruplos[i][4]<<"\n";
                 	   
                 	   //Checar si es falso o verdadero
                 	    if (resultadoString=="f")
                       i=atoi(cuadruplos[i][4].c_str());
                    	else cout<<" Verdadero\n";
                	
                	break;
                	
                	

                	case 13 :// gotoooT   instrucciones
                	break;

                

                	case 19://ver
                	
                	//Verificar que el valor sea el correcto 
                	
                        break;

                	case 20 ://ERAA  ERAAA E EE E  instrucciones
                    //salvar la base actual previa a la llamada
                    	
                        
                        //Guardar la memoria local actual en una pila
                	pilaLocalEntera.push(enterosLocales);
                	pilaLocalFlotante.push(flotantesLocales);
                	pilaLocalString.push(stringLocales);
                	pilaLocalBoolean.push(booleanoLocales);
                   	//Guardar la memoria Temporal en pila
                	pilaTemporalEntera.push(enterosTemporales);
                	pilaTemporalFlotante.push(flotantesTemporales);
                	pilaTemporalString.push(stringTemporales);
                	pilaTemporalBoolean.push(booleanoTemporales);
                	
                    
                	//Definir el tamaño de la memoria
                	//Actualizar la base local
                	//Generar el espacio de memoria

                	break;

                	case 21 :// gpooSUb   instrucciones
                	
                	
                
                	
                	     //Meter la direccion de retorno en la pila de ejecución
                	     
                	    // cout<<"\n prewhaat  >"<<enterosConstantes[1]<<"\n";
                	      //cout<<i<<"<<<<cuadruplo \n";

                	     dirRetorno = atoi( cuadruplos[i][1].c_str());

                	     pilaEjecucion.push(i);

                	    cout<< "\n Pila de Ejecucion " << i;

                	    //Transferir el control de hecucion a la direccion donde inicia el procedimiento
                	       cout<<"\n GO SUB >"<<cuadruplos[i][2]<<"\n";
                         i=atoi(cuadruplos[i][2].c_str());

                          

                	break;

                	case 22 : // ret instrucciones
                	    //actualizar la base local(previa a la llamada)
                	    enterosLocales= pilaLocalEntera.top();
                	    flotantesLocales=pilaLocalFlotante.top();
                	    stringLocales=pilaLocalString.top();
                        booleanoLocales=pilaLocalBoolean.top();
                        
                        enterosTemporales=pilaTemporalEntera.top();
                        flotantesTemporales=pilaTemporalFlotante.top();
                        stringTemporales=pilaTemporalString.top();
                        booleanoTemporales=pilaTemporalBoolean.top();
                        
                        cout<<"Casilla num1 = "<<enterosLocales[1] <<"\n";
                        cout<<"Casilla num1 = "<<enterosTemporales[1] <<"\n";
                	    
                	    
                	    //destruir el registro de activación del proc d ememoria local
                	    //Recuperar la dirección de rerono y transeferir el control de ejeciucpin
                	   
                        // cout<<"\n RET >"<<pilaEjecucion.top();
                	     i= pilaEjecucion.top();//Regresa a donde estaba 
                	    
                	    
                	break;

                	case 23 ://param    instrucciones
                //	cout<<"\n supeerwhaat  >"<<enterosConstantes[1]<<"\n";
                	
                          //cout<<i<<"<<<<cuadruplo \n";
                          cout<<"PARAM\n";
                	    //Meter los valores al amemoria local
                	  param(cuadruplos[i][2],cuadruplos[i][4]);
                	    

                	break;

                	case 24 : //rtetuurnn instrucciones
                	
                	retorno( cuadruplos[i][2], cuadruplos[i][4]);
                	
                	break;

                	case 25 :// read  instrucciones
                	 //cout<<i<<"<<<<cuadruplo \n";
                	 //cout<<"READ\n";
                	break;


                	case 26 ://print   instrucciones
                //	 cout<<i<<"<<<<cuadruplo \n";
                       hacerPrint(26, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                	break;

                   case 27 :// VERifica  instrucciones
                	
                		//Verificar que el valor sea el correcto 
                	verifica(27, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                	
                	break;

                	case 30 : //end 
                	
                //	 cout<<i<<"<<<<cuadruplo \n";
                	 cout<<"END\n";
                	break;
                	
                	
                		case 40 : //instrucciones suma vecto
           		     //esMatriz=1;
                	 sumaVector(40, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                	 
                	 //cout<<"SUMA VECTOR\n";
                	break;
                	
                		case 41 : //instrucciones
                	 multiplicaVector(41, cuadruplos[i][2], cuadruplos[i][3] ,cuadruplos[i][4]);
                	 
                	// cout<<"\nMultiplicacion "<<41<<" ,"<<cuadruplos[i][2]<<" ,"<< cuadruplos[i][3]<<" ,"<<cuadruplos[i][4];
                	break;

                }///termina swuitx
                
                

      
      
      
      }//termina whilw
      
      
      //pruebas
    
    /*  pilaLocalEntera.push(enterosLocales);
      vector < int > local = pilaLocalEntera.top();
       cout<<"0 " <<local[1]<<"\n";
      cout<<"1  " <<local[2]<<"\n";
       cout<<"2  " <<local[3]<<"\n";
        cout<<",,, " <<enterosLocales[1]<<"\n";
      cout<<",,,  " <<enterosLocales[2]<<"\n";
       cout<<",,,  " <<enterosLocales[3]<<"\n";
      */

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

