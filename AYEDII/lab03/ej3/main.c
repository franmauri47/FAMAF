#include <stdlib.h>
#include <stdio.h>
#include "phrase-helpers.h"
#include "sort.h"

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char *argv[]) {    
    char *path = NULL;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo

    path = parse_filepath(argc,argv);

    length = data_from_file(path, indexes, letters, MAX_SIZE);

    sort_letters(indexes, letters, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

