#ifndef _PHRASE_HELPERS_H
#define _PHRASE_HELPERS_H

char *parse_filepath (int argc, char *argv[]);
/*abre el documento pasado por linea de comando*/

unsigned int data_from_file(const char *path,unsigned int indexes[],char letters[],unsigned int max_size);
/*Llena los arreglos indexes y letters con los datos del archivo indicado por path, además,
devuelve cuantos elementos contiene el archivo */

#endif