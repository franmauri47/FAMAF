#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if(x>=0) {
        *y = x;
    }        
    else {
        *y = (-1) * x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    int *p = NULL;
    
    p = &res;

    a = -10;

    absolute(a,p);
    printf("%d\n", res);
    return EXIT_SUCCESS;
}

/*El parametro int *y de absolute() es de tipo out, ya que no utiliza su valor en ningún momento 
de la ejecución, solo se le asigna el valor de salida
C tiene solamente parametros de tipo in, pudiendo devolver valores a traves de return, pero
solamente tiene parametros de tipo in a los cuales les modifica su valor de memoria o lo que esta
contenido en ese valor de memoria*/ 

