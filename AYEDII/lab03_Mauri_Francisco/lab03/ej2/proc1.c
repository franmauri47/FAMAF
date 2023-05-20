#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0) {
        y = x;
    }
    else {
        y = (-1) * x;
    }
}

int main(void) {
    int a=-10, res=0;
    absolute(a,res);
    printf("res = %d\n", res);
    
    return EXIT_SUCCESS;
}

//El meansaje imprimido en pantalla no es el deseado, no coincide con el esperado (no retorna el valor correcto)

