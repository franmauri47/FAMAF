#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(){
    stack test = stack_empty();
    for (int i = 0; i <= 2; i++){
        test = stack_push(test,47);
    }
    test = stack_push(test,5);

    stack_elem *array = stack_to_array(test);

    printf("[");
    for( unsigned int i = 0; i < stack_size(test); i++){
        printf(" %u ", array[i]);
    }
    printf("]\n");

    test = stack_destroy(test);
    free(array);
    return 0;
}