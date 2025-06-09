#ifndef CHECKPOINTS_H
#define CHECKPOINTS_H
/*
Sobre Ifndef
======
ifndef es una construcción de pre compilación que 
sólo incorpora el texto entre "#ifndef SYMBOL ... #endif 
sólo si el símbolo SYMBOL aún no fue definido
se suele utilizar esta combinación de 
#ifndef SYMBOL
#define SYMBOL
para que el pre-procesador sólo evalúe una vez los
encabezados antes de comenzar la compilación

Sobre includes
==============
Recuerden que los include son directivas que incluyen,
en este caso, las definiciones y encabezados de las funciones de uso común que queremos 
utilizar en nuestro programa
*/
#include <stdio.h> 	//encabezado de funciones de entrada y salida fopen, fclose, fgetc, printf, fprintf ...
#include <stdlib.h>	//biblioteca estándar, atoi, atof, rand, srand, abort, exit, system, NULL, malloc, calloc, realloc...
#include <stdint.h>	//contiene la definición de tipos enteros ligados a tamaños int8_t, int16_t, uint8_t,...
#include <ctype.h>	//contiene funciones relacionadas a caracteres, isdigit, islower, tolower...
#include <string.h>	//contiene las funciones relacionadas a strings, memcmp, strcat, memset, memmove, strlen,strstr...
#include <math.h>	//define funciones matemáticas como cos, sin, abs, sqrt, log...
#include <stdbool.h>	//contiene las definiciones de datos booleanos, true (1), false (0)
#include <unistd.h>	//define constantes y tipos standard, NULL, R_OK, F_OK, STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO...
#include <assert.h>	//provee la macro assert que evalúa una condición, y si no se cumple provee información diagnóstica y aborta la ejecución

//*************************************
//Declaración de constantes (directivas de pre-compilación)
//*************************************


//*************************************
//Declaración de funciones de ejemplo
//*************************************
void save_result(char *filename, uint32_t result);

uint32_t alternate_sum_5(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4, uint32_t x5);
uint32_t alternate_sum_9(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4, uint32_t x5, uint32_t x6, uint32_t x7, uint32_t x8, uint32_t x9);

#endif
