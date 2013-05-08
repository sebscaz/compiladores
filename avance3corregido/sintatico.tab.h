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
     prototipo = 260,
     si = 261,
     no = 262,
     imprimir = 263,
     leer = 264,
     crear = 265,
     mientras = 266,
     hacer = 267,
     funcion = 268,
     neutral = 269,
     regresar = 270,
     id = 271,
     ctetexto = 272,
     cteentero = 273,
     ctedecimal = 274,
     ctebooleano = 275,
     entero = 276,
     decimal = 277,
     texto = 278,
     booleano = 279,
     igual = 280,
     diferente = 281,
     mas = 282,
     menos = 283,
     multiplicacion = 284,
     division = 285,
     mayor = 286,
     menor = 287,
     and = 288,
     or = 289,
     ptocoma = 290,
     dospuntos = 291,
     punto = 292,
     coma = 293,
     parentesisa = 294,
     parentesisc = 295,
     llavea = 296,
     llavec = 297,
     corchetea = 298,
     corchetec = 299,
     dibujarFigura = 300,
     borrarFigura = 301,
     girarIzquierda = 302,
     girarDerecha = 303,
     mover = 304,
     obtenerPosicion = 305,
     hablar = 306,
     obtenerAltura = 307,
     obtenerAnchura = 308,
     cambiarAltura = 309,
     cambiarAnchura = 310,
     colorFondo = 311,
     rojo = 312,
     azul = 313,
     verde = 314,
     carro = 315,
     persona = 316,
     perro = 317,
     gato = 318,
     verdadero = 319,
     falso = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 168 "sintatico.y"
int cteint; float ctefloat; int cteboolean; char *string;


/* Line 2068 of yacc.c  */
#line 119 "sintatico.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


