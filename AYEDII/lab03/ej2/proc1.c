#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if(x>=0) {
        y = x;
    }        
    else {
        y = (-1)*x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a,res);
    printf("%d\n", res);
    return EXIT_SUCCESS;
}

/*En pantalla se muestra el valor 0, lo cual no coincide con el lenguaje teórico, 
ya que debería mostrar 10*/

