#include "array_helpers.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100000

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {    
    FILE *fp;

    fp = fopen(filepath, "r");
    if (filepath == NULL){
        printf("Problema al abrir el archivo. Terminando el programa\n");
        return (-1);
    }

    fscanf(fp, "%u", &max_size);
    if (max_size <= MAX_SIZE){
        for (unsigned int i = 0; i < max_size; i++){
            fscanf(fp, "%d", &array[i]);
        }

        fclose(fp);
        return max_size;
    } else {
        printf("El tamaño del arreglo es mayor al tamaño máximo. Terminando el programa\n");
        return (-1);
    }
    
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i = 0; i < length; i++){
        if (i < (length-1)){
            printf(" %d,", a[i]);
        }
        else{
            printf(" %d ]\n", a[i]);
        }
    }
}

bool array_is_sorted(int a[], unsigned int length) {
    bool res = true;
    for (unsigned int i = 0; i < (length-1); i++) {
        if (a[i] > a[i+1]) {
            res = false;
            break;
        }
    }
    return res;
}

void array_swap(int a[], unsigned int i, unsigned int j) {
    int aux_i = a[i];
    a[i] = a[j];
    a[j] = aux_i;
}

void array_invert(int a[], unsigned int length) {
    unsigned int auxLength = length;
    while (auxLength > 1) {
        for (unsigned int k = 0; (k+1) < auxLength; k++) {
            array_swap(a, k, (k+1));
        }
        auxLength--;
    }
}
