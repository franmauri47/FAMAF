#include "phrase-helpers.h"
#include <stdlib.h>
#include <stdio.h>

char *parse_filepath (int argc, char *argv[]) {
    char *result = NULL;
    if (argc < 2) {
        printf("Debe ingresar una dirección hacia el archivo que quiere leer\n");
        exit(EXIT_FAILURE);
    }
    else {
        result = argv[1];        
    }
    return result;
}

unsigned int data_from_file(const char *path,unsigned int indexes[],char letters[],unsigned int max_size) {
    FILE *file = NULL;
    file = fopen(path,"r");
    unsigned int i = 0;
    char char_value;

    if (file == NULL) {
        printf("El archivo indicado no existe\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(file) && i < max_size) {
        fscanf(file,"%u -> *%c*\n", &indexes[i], &char_value);
        if (indexes[i] > max_size){
            printf("Arreglo invalido, supera el tamaño máximo de %u\n", max_size);
            exit(EXIT_FAILURE);
        }
        else {
            letters[i] = char_value;
        }
        i++;
    }

    return i;
}