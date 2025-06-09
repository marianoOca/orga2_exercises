#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "sum.h"


void save_result(char *filename, uint32_t result){
	FILE *fp = fopen(filename, "w");
	fprintf(fp, "[%d]", result);
	fclose(fp);
}

int main (void){
	
	//Ejemplos básicos de interacción
	printf("Ejemplos básicos de interacción.\n");	
	uint32_t x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0, x9 = 0, result = 0;
	x1 = 5;
	x2 = x3 = x4 = x5 = 2;
	result = alternate_sum_5(x1,x2,x3,x4,x5);
	printf("\t alternate_sum_5(%d,%d,%d,%d,%d)=%d\n", x1, x2, x3, x4, x5, result);
	x1 = 12, x2 = 10, x3 = 8, x4 = 6, x5 = 4;
	printf("\t alternate_sum_5(%d,%d,%d,%d,%d)=%d\n", x1, x2, x3, x4, x5, alternate_sum_5(x1,x2,x3,x4,x5));
	x1 = 5;
	x2 = x3 = x4 = x5 = x6 = x7 = x8 = x9 = 2;
	//Uso de parámetros en registros y la pila
	printf("Uso de parámetros en registros y la pila.\n");		
	printf("\t alternate_sum_9(%d,%d,%d,%d,%d,%d,%d,%d,%d)=%d\n", x1, x2, x3, x4, 
		x5, x6, x7, x8, x9, alternate_sum_9(x1,x2,x3,x4,x5,x6,x7,x8,x9));	
	x1 = 18, x2 = 16, x3 = 14, x4 = 12, x5 = 10, x6 = 8, x7 = 6, x8 = 4, x9 = 2;
	printf("\t alternate_sum_9(%d,%d,%d,%d,%d,%d,%d,%d,%d)=%d\n", x1, x2, x3, x4, 
		x5, x6, x7, x8, x9, alternate_sum_9(x1,x2,x3,x4,x5,x6,x7,x8,x9));
	return 0;
}


