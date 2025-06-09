/* ** por compatibilidad se omiten tildes **
================================================================================
 TALLER System Programming - ORGANIZACION DE COMPUTADOR II - FCEN
================================================================================
  Definicion de la tabla de descriptores globales
*/

#include "gdt.h"

/* Aca se inicializa un arreglo de forma estatica
GDT_COUNT es la cantidad de líneas de la GDT y esta definido en defines.h */

gdt_entry_t gdt[GDT_COUNT] = {
    /* Descriptor nulo*/
    /* Offset = 0x00 */
    [GDT_IDX_NULL_DESC] =
        {
            // El descriptor nulo es el primero que debemos definir siempre
            // Cada campo del struct se matchea con el formato que figura en el manual de intel
            // Es una entrada en la GDT.
            .limit_15_0 = 0x0000,
            .base_15_0 = 0x0000,
            .base_23_16 = 0x00,
            .type = 0x0,
            .s = 0x00,
            .dpl = 0x00,
            .p = 0x00,
            .limit_19_16 = 0x00,
            .avl = 0x0,
            .l = 0x0,
            .db = 0x0,
            .g = 0x00,
            .base_31_24 = 0x00,
        },
    [GDT_IDX_CODE_0] = {
            .limit_15_0 = 0x30FF,
            .base_15_0 = 0x0000,
            .base_23_16 = 0x00,
            .type = 0xA, 
            .s = 0x01,
            .dpl = 0x00,
            .p = 0x01,
            .limit_19_16 = 0x03,
            .avl = 0x1,
            .l = 0x0,
            .db = 0x1,
            .g = 0x01,
            .base_31_24 = 0x00, 
        },
    [GDT_IDX_CODE_3] =
        {
            // <COMPLETAR>  con el segmento de codigo nivel 3
            // Pueden tomar el descriptor nulo como ejemplo y completar cada uno de los campos
            // con lo correspondiente acorde a lo solicitado en el enunciado
            .limit_15_0 = 0x30FF,
            .base_15_0 = 0x0000,
            .base_23_16 = 0x00,
            .type = 0xA,
            .s = 0x01,
            .dpl = 0x03,
            .p = 0x01,
            .limit_19_16 = 0x03,
            .avl = 0x1,
            .l = 0x0,
            .db = 0x1,
            .g = 0x01,
            .base_31_24 = 0x00,
        },
    [GDT_IDX_DATA_0] =
        {
            // <COMPLETAR> con el segmento de datos nivel 0
            // Pueden tomar el descriptor nulo como ejemplo y completar cada uno de los campos
            // con lo correspondiente acorde a lo solicitado en el enunciado
            .limit_15_0 = 0x30FF,
            .base_15_0 = 0x0000,
            .base_23_16 = 0x00,
            .type = 0x2,
            .s = 0x01,
            .dpl = 0x00,
            .p = 0x01,
            .limit_19_16 = 0x03,
            .avl = 0x1,
            .l = 0x0,
            .db = 0x1,
            .g = 0x01,
            .base_31_24 = 0x00,
        },
    [GDT_IDX_DATA_3] =
        {
            // <COMPLETAR> con el segmento de datos nivel 3
            // Pueden tomar el descriptor nulo como ejemplo y completar cada uno de los campos
            // con lo correspondiente acorde a lo solicitado en el enunciado
            .limit_15_0 = 0x30FF,
            .base_15_0 = 0x0000,
            .base_23_16 = 0x00,
            .type = 0x2,
            .s = 0x01,
            .dpl = 0x03,
            .p = 0x01,
            .limit_19_16 = 0x03,
            .avl = 0x1,
            .l = 0x0,
            .db = 0x1,
            .g = 0x01,
            .base_31_24 = 0x00,
        },
    [GDT_IDX_VIDEO] =
       {
            // <COMPLETAR> con el segmento para ser usado por el video
            // Pueden tomar el descriptor nulo como ejemplo y completar cada uno de los campos
            // con lo correspondiente acorde a lo solicitado en el enunciado
            .limit_15_0 = 0x1F3F, //8000-1 en hexa
            .base_15_0 = 0x8000,
            .base_23_16 = 0x0B,
            .type = 0x2, // O PUEDE SER 3, NO??
            .s = 0x01, //?
            .dpl = 0x00, //si, no?
            .p = 0x01,
            .limit_19_16 = 0x00,
            .avl = 0x1, //OJO, ME FIJE EN LAS SLIDES DE LA TEO Y EL EL LIBRO DE INTEL Y ESTE BIT NO TIENE FUNCION (ES PARA QUE SE PUEDA IMPLEMENTAR ALGO) HAY Q DEJARLO EN 1? O ES LO MISMO?
            .l = 0x0,
            .db = 0x1, //?
            .g = 0x00,
            .base_31_24 = 0x00,
            //tener en cuenta q empieza en  0x000B8000 y ocupa 8000bytes (80*50*2bytes)
            //la base va a ser eso, creo q no hace falta G=1
       }
};

// Aca hay una inicializacion estatica de una structura que tiene su primer componente el tamano 
// y en la segunda, la direccion de memoria de la GDT. Observen la notacion que usa. 
gdt_descriptor_t GDT_DESC = {sizeof(gdt) - 1, (uint32_t)&gdt}; //Pregunta: aca q paso??
