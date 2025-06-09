#include "checkpoints.h"

/** AUX FUNCTIONS **/

/* Funciones */


/**
	Esta función procesa los elementos un arreglo arr de largo len y asigna el resultado de la suma en la varibale apuntada por ptr_sum y el resultado del producto en ptr_prod.
*/
void sum_product_array(int32_t *arr, uint32_t len, int32_t *ptr_sum, int32_t *ptr_prod){
	//des referenciamos el puntero para limpiar el valor de la variable de destino
	*ptr_sum = 0;
	*ptr_prod = 1;
	uint32_t i;
	for(i = 0; i < len; i++){
		*ptr_sum += arr[i];
		*ptr_prod *= arr[i];
	}
}
/**
   a)
    Recibe un array por referencia con su largo (por copia), y dos punteros a donde se guardan la sumatoria y la productoria de todos
	los elementos del arreglo. La función hace dicha sumatoria y productoria.


   b)
	Se recibe únicamente el array y la longitud (ambas por copia), se crean variables locales para la suma y la productoria y se las
	devuelven ambas por copia como una tupla (usando return make_pair(sum, prod)).
 */

/**
	Esta función copia el contenido de un string a una posición de memoria predefinida.
	Reservar memoria dinámicamente en destination. Si en esa posición se había asignado algo distinto a NULL liberar la estructura anterior.
	Si la fuente es NULL asignar el destino a NULL.
*/
void set_string_at_location(char** destination, char* source){
	//Recuerden que el operador de des-referencia (*p) recupera el valor apuntado por el puntero p
	//El operador de referencia (&x) devuelve la dirección de memoria de la variable x
	if(*destination != NULL) free(*destination);
	if(source != NULL){
		//strlen devuelve el largo de un string sin contar el caracter de cierre
		*destination = malloc(strlen(source) + 1);
		//strcpy copia el contenido de un string en otro, incluyendo el caracter de cierre
		strcpy(*destination, source);
	}else{*destination = NULL;}
}

/**
   c)
    Recibe un puntero de puntero a un char (destination) y un puntero a un char (source). Luego, en caso de que
    destination tenga asignado una direccion de memoria, libera el espacio para poder guardar el puntero source,
    el cual contiene un string.
 */

/**
	Esta función copia el contenido de un arreglo de enteros a una posición de memoria predefinida.
	Reservar memoria dinámicamente en destination. Si en esa posición se había asignado algo distinto a NULL liberar la estructura anterior.
	Si la fuente es NULL asignar el destino a NULL.
*/
void set_int_at_location(int32_t** destination, int32_t* source, uint32_t length){
	if(*destination != NULL) free(*destination);
	if(source != NULL){

		//COMPLETAR:
		 *destination = malloc(sizeof(int32_t) * length);
		uint32_t i;
		//COMPLETAR:
		for(i = 0; i < length; i++) (*destination)[i] = source[i];
	}else{*destination = NULL;}
}
		// destination es [mem] --> [source] --> [valor source]
		// *destination es [source]
		// &destination es dirección([mem])

/**
   e)
    Se debe poner como parametro ya que en el string tenemos el caracter de cierre que permite saber donde termina el string
    y en el arreglo de enteros no existe.
	No, porque no es posible guardar un puntero a puntero a entero en un tipo declarado como puntero a entero, no tipa. Lo que se
	puede hacer es copiar los punteros de source en destination, que a fines prácticos sería lo mismo.
 */


/**
	Checkpoint 2: inicialización estática y dinámica
	Por favor completen la parte del código marcada con ? según lo indicado en el enunciado
*/

#define INT_ARR_SIZE 5

void checkpoint_2(){
	uint32_t i;	
	printf("[Checkpoint 2]:\n========\n");
	printf("Ejercicio utilizando punteros como parámetros\n=======\n");
	int32_t array_to_sum[INT_ARR_SIZE];
	for(i = 0; i < INT_ARR_SIZE; i++)array_to_sum[i]	= (i + 1) * 5;
	int32_t sum_result	= -1;
	int32_t prod_result	= -1;
	//Realizamos una llamada a la función sum_array que almacena el resultado 
	printf("Los valores del arreglo son:\n\t");
	for(i = 0; i < INT_ARR_SIZE; i++)printf("%d ", array_to_sum[i]);
	printf("\nLos valores iniciales de las variables son: \n\tsum_result = %d; sum_prod = %d;\n", sum_result, prod_result);
	sum_product_array(array_to_sum, INT_ARR_SIZE, &sum_result, &prod_result);
	printf("Los valores de las variables luego de la llamada a función son: \n\tsum_result = %d; sum_prod = %d;\n", sum_result, prod_result);

	char msg_source[]	= "Este es el mensaje a copiar en destino";
	char *msg_destination	= NULL;
	printf("Ejercicios con puntero a puntero\n========\n");	
	set_string_at_location(&msg_destination, msg_source);
	printf("El mensaje copiado es:\n\t%s\n", msg_destination);
	
	int32_t int_array_source[INT_ARR_SIZE];	
	int32_t *int_array_destination	= NULL;
	for(i = 0; i < INT_ARR_SIZE; i++)int_array_source[i]	= (int32_t)i << 1;
	
	set_int_at_location(&int_array_destination, int_array_source, INT_ARR_SIZE);
	
	printf("El arreglo de enteros copiado es: ");
	for(i = 0; i < INT_ARR_SIZE; i++)printf("%d ", int_array_destination[i]);
	printf("\n");
	
	free(msg_destination);
	free(int_array_destination);
	
	
	printf("Inicializando estructuras\n========\n");		
	//Inicialización estática de estructuras 
	char name[]	= "'Nombre del item estático'";
	composite_item static_item	= {name, 35};
	
	//Observen que el acceso del atributo es con el operador de punto struct.attr
	printf("El struct estático vale: name:\t%s\tvalue:\t%d\n", static_item.name, static_item.value);	
	
	//Inicialización dinámica de estructuras
	composite_item *dynamic_item	= malloc(sizeof(composite_item));
	//los atributos de un puntero a struct se pueden acceder directamente con el operador struct_ptr->attr
	//equivale a hacer una des-referencia y un acceso por punto (*struct_ptr).attr
	dynamic_item->name	= NULL;
	dynamic_item->value	= 47;
	
	set_string_at_location(&(dynamic_item->name), "'Nombre del item dinámico'");
	
	printf("El struct dinámico vale (usando struct_ptr->attr): \n\tname:\t%s\n\tvalue:\t%d\n", dynamic_item->name, dynamic_item->value);		
	printf("El struct dinámico vale ((*struct_ptr).attr): \n\tname:\t%s\n\tvalue:\t%d\n", (*dynamic_item).name, (*dynamic_item).value);			
	
	//Liberamos las estructuras dinámicas
	//¿Cuándo se creo dynamic_item->name? ¿Dónde se ubica?
	//¿Qué sucede si hacemos sólo esto?: free(dynamic_item);
	//Sin liberar dynamic_item->name
	free(dynamic_item->name);
	//es una buena práctica volver a asignar todos los punteros liberados en NULL
	dynamic_item->name	= NULL;
	free(dynamic_item);
	dynamic_item        = NULL;
}


/**
   f)
    Porque, como es una estructura, es necesario liberar también el espacio de memoria ocupado por el puntero a char "name".
	Se libera primero el más "profundo" (name) y luego el más "superficial" (puntero a name).

   g)
    Se libera primero lo que esta contenido dentro de la estructura (lo más profundo), se lo libera con free y luego le asigna
    NULL. Y luego se hace lo mismo (free y NULL) con el puntero que apunta al que se liberó anteriormente. Y se itera hasta
	terminar con todos los punteros anidados.
 */
