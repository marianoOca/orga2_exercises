#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "checkpoints.h"

void test_ejemplo(){
	//Esta función contiene ejemplos de inicialización estática
	//simple_item_static_initialization();
	//Esta función contiene ejemplos de inicialización dinámica
	//simple_item_dynamic_initialization();
	//esta función evalúa el checkpoint 1, quiten el modificador de comentario // para correrla
	//checkpoint_1();
	/*
	char* source = "hola";

	char* destination;
	
	set_string_at_location(&destination, source);
	 //*/
	checkpoint_2();
}

int main (void){
	test_ejemplo();
	return 0;    
}
