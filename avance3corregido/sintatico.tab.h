/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     programa = 258,
     principal = 259,
     si = 260,
     no = 261,
     imprimir = 262,
     leer = 263,
     crear = 264,
     mientras = 265,
     hacer = 266,
     funcion = 267,
     neutral = 268,
     regresar = 269,
     id = 270,
     ctetexto = 271,
     cteentero = 272,
     ctedecimal = 273,
     ctebooleano = 274,
     entero = 275,
     decimal = 276,
     texto = 277,
     booleano = 278,
     igual = 279,
     diferente = 280,
     mas = 281,
     menos = 282,
     multiplicacion = 283,
     division = 284,
     mayor = 285,
     menor = 286,
     and = 287,
     or = 288,
     ptocoma = 289,
     dospuntos = 290,
     punto = 291,
     coma = 292,
     parentesisa = 293,
     parentesisc = 294,
     llavea = 295,
     llavec = 296,
     corchetea = 297,
     corchetec = 298,
     dibujarFigura = 299,
     borrarFigura = 300,
     girarIzquierda = 301,
     girarDerecha = 302,
     mover = 303,
     obtenerPosicion = 304,
     hablar = 305,
     obtenerAltura = 306,
     obtenerAnchura = 307,
     cambiarAltura = 308,
     cambiarAnchura = 309,
     colorFondo = 310,
     rojo = 311,
     azul = 312,
     verde = 313,
     carro = 314,
     persona = 315,
     perro = 316,
     gato = 317,
     verdadero = 318,
     falso = 319
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 156 "sintatico.y"
int cteint; float ctefloat; int cteboolean; char *string;


/* Line 2068 of yacc.c  */
#line 118 "sintatico.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


