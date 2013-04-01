/*****************
  SCANNER
  
 Definiciones
 Se colocan las cabeceras, variables y expresiones regulares

********************/

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "sintatico.tab.h"
  int linea=0;
%}

/****************************
    Expresiones Regulares
****************************/

digito 		[0-9]
letra 		[a-z|A-Z]
cteentero 	{digito}+
ctedecimal 	{digito}+"."{digito}+
ctetexto 	"\"".*"\""
id 			[a-z]({letra}|{digito})*
ctebooleano    [v | f]


%%

" "         	{}
\n	    	{linea++;}
[\t\r\f]    	{}

"programa"	{printf("_Palabra reservada programa\n"); return(programa);}
"si"		{printf("_Palabra reservada si\n"); return(si);}
"no"		{printf("_Palabra reservada no\n"); return(no);}
"imprimir"	{printf("_Palabra reservada imprimir\n"); return(imprimir);}
"leer"		{printf("_Palabra reservada leer\n"); return(leer);}
"crear"		{printf("_Palabra reservada crear\n"); return(crear);}
"mientras"	{printf("_Palabra reservada mientras\n"); return(mientras);}
"hacer"		{printf("_Palabra reservada hacer\n"); return(hacer);}
"funcion"	{printf("_Palabra reservada funcion\n"); return(funcion);}
"neutral"		{printf("_Palabra reservada neutral\n"); return(neutral);}
"regresar"	{printf("_Palabra reservada regresar\n"); return(regresar);}

"="         {printf("_igual\n"); yylval.string = strdup(yytext);  return(igual);}
"!"         {printf("_igual\n"); return(diferente);}
"+"         {printf("_mas\n"); yylval.string = strdup(yytext); return(mas);}
"-"         {printf("_menos\n"); yylval.string = strdup(yytext); return(menos);}
"*"         {printf("_multiplicacion\n"); yylval.string = strdup(yytext); return(multiplicacion);}
"/"         {printf("_division\n"); yylval.string = strdup(yytext); return(division);}
">"         {printf("_mayor\n"); yylval.string = strdup(yytext); return(mayor);}
"<"         {printf("_menor\n"); yylval.string = strdup(yytext); return(menor);}
"&"         {printf("and\n"); return(and);}
"|"         {printf("or\n"); return(or);}

{ctetexto}		{printf("_cte texto  \n "); yylval.string = strdup(yytext); return(ctetexto);}
{cteentero}		{printf("_Cte entero\n"); yylval.cteint = atoi(yytext);  return(cteentero);}
{ctedecimal}	{printf("_Cte decimal\n"); yylval.ctefloat = atof(yytext); return(ctedecimal);}
{ctebooleano}	{printf("_Cte booleano\n"); yylval.cteint = atoi(yytext); return(ctebooleano);}
"texto"			{printf("_Palabra reservada texto\n"); yylval.string = strdup(yytext); return(texto);}
"booleano"		{printf("_Palabra reservada booleano\n"); yylval.string = strdup(yytext); return(booleano);}
"entero"		{printf("_Palabra reservada entero\n"); yylval.string = strdup(yytext); return(entero);}
"decimal"		{printf("_Palabra reservada decimal\n"); yylval.string = strdup(yytext); return(decimal);}

";"         {printf("_punto y coma\n");  return(ptocoma);}
":"         {printf("_dos puntos\n"); return(dospuntos);}
"."         {printf("_punto\n"); return(punto);}
","         {printf("_coma\n"); return(coma);}

"("         {printf("_parentesis abierto\n");  yylval.string=strdup(yytext); return(parentesisa);}
")"         {printf("_parentesis cerrado\n"); return(parentesisc);}
"{"         {printf("_llave abierta\n"); return(llavea);}
"}"         {printf("_llave cerrada\n"); return(llavec);}
"["         {printf("_corchete abierto\n"); return(corchetea);}
"]"         {printf("_corchete cerrado\n"); return(corchetec);}

"dibujarFigura"		{printf("_funcion dibujarFigura\n"); return(dibujarFigura);}
"borrarFigura"		{printf("_funcion borrarFigura\n"); return(borrarFigura);}
"girarIzquierda"	{printf("_funcion girarIzquierda\n"); return(girarIzquierda);}
"girarDerecha"		{printf("_funcion girarDerecha\n"); return(girarDerecha);}
"mover"				{printf("_funcion mover\n"); return(mover);}
"obtenerPosicion"	{printf("_funcion obtenerPosicion\n"); return(obtenerPosicion);}
"hablar"			{printf("_funcion hablar\n"); return(hablar);}
"obtenerAltura"		{printf("_funcion obtenerAltura\n"); return(obtenerAltura);}
"obtenerAnchura"	{printf("_funcion obtenerAnchura\n"); return(obtenerAnchura);}
"cambiarAltura"		{printf("_funcion cambiarAltura\n"); return(cambiarAltura);}
"cambiarAnchura"	{printf("_funcion cambiarAnchura\n"); return(cambiarAnchura);}
"colorFondo"		{printf("_funcion cambiarAnchura\n"); return(cambiarAnchura);}

"rojo"		{printf("_Palabra reservada rojo\n"); return(rojo);}
"azul"		{printf("_Palabra reservada azul\n"); return(azul);}
"verde"		{printf("_Palabra reservada verde\n"); return(verde);}
"carro"		{printf("_Palabra reservada carro\n"); return(carro);}
"persona"	{printf("_Palabra reservada persona\n"); return(persona);}
"gato"		{printf("_Palabra reservada gato\n"); return(gato);}
"perro"		{printf("_Palabra reservada perro\n"); return(perro);}

{id}		{printf("_id  \n "); yylval.string = strdup(yytext);  return(id);}
.           	{printf("Error lexico en linea %d",linea);}



%%
