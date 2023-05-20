#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

//region Logica para obtener maximo, minimo y si existe (Hasta linea 47)
struct maxOmin_y_pos{
    int max;
    int min;
    int posicion;
};

//Devuelve el maximo elemento de un arreglo y su posición
struct maxOmin_y_pos max_elem(int a[], unsigned int length){
    struct maxOmin_y_pos res;
    res.max = a[0];    
    res.posicion = 0;
    for (int i = 1; i <= length; i++){
        if (a[i] > res.max){
            res.max = a[i];
            res.posicion = i;
        }
    }
    return res;
}

//Devuelve el minimo elemento de un arreglo y su posición
struct maxOmin_y_pos min_elem(int a[], unsigned int length){
    struct maxOmin_y_pos res;
    res.min = a[0];
    res.posicion = 0;
    for (int i = 1; i <= length; i++){
        if (a[i] < res.min){
            res.min = a[i];
            res.posicion = i;
        }
    }
    return res;
}

//Si un elemento existe en el array, devuelve la posición del elemento
int exist(int num, int a[], unsigned int length){
    int res = -1; //-1 significaría que no existe
    for (int i = 0; i <= length; i++){
        if (num == a[i]){
            res = a[i];
        }
    }
    return res;
}

struct bound_data check_bound(int value, int arr[], unsigned int length){
    struct bound_data res;
    struct maxOmin_y_pos auxMax = max_elem(arr,length);
    struct maxOmin_y_pos auxMin = min_elem(arr,length);
    int arrMax = auxMax.max;
    // int arrMaxPos = auxMax.posicion;
    int arrMin = auxMin.min;
    // int arrMinPos = auxMin.posicion;

    ///Chequea si el valor ingresado es mayor que todos los elementos del arreglo
    if (value >= arrMax){
        res.is_upperbound = true;
    } else if (value < arrMax){
        res.is_upperbound = false;
    }
    ///Chequea si el valor ingresado es menor que todos los elementos del arreglo
    if (value <= arrMin){
        res.is_lowerbound = true;
    } else if (value > arrMin){
        res.is_lowerbound = false;
    }

    if (exist(value, arr, length) != -1){
        res.exists = true;
    } else {
        res.exists = false;
    }

    res.where = exist(value, arr, length);

    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;

    printf("Debera ingresar 4 elementos\nPor favor, ingrese el primer elemento: ");
    scanf("%d\n", &a[0]);
    printf("Por favor, ingrese el segundo elemento: ");
    scanf("%d\n", &a[1]);
    printf("Por favor, ingrese el tercer elemento: ");
    scanf("%d\n", &a[2]);
    printf("Por favor, ingrese el ultimo elemento: ");
    scanf("%d\n", &a[3]);
    
    printf("Por favor, ingrese un valor para ser evaluado \n");
    scanf("%d\n", &value);
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("Es mayor o igual que todos los elementos? %d \n", result.is_upperbound); // Imprime 1
    printf("Es menor o igual que todos los elementos? %d \n", result.is_lowerbound); // Imprime 0
    printf("Existe en el arreglo? %u\n", result.exists);        // Imprime 1
    if(result.exists){
        printf("Esta en la posición %u\n", result.where);         // Imprime 2
    }

    return EXIT_SUCCESS;
}