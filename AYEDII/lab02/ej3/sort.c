#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {    
    unsigned int pivot = izq;
    unsigned int i = izq+1;
    unsigned int j = der;
    while (i <= j) {
        if (a[j] >= a[pivot]) {
            j--;
        } 
        else if (a[i] <= a[pivot]) {
            i++;
        }
        else if (a[i] > a[pivot] && a[j] < a[pivot]) {
            swap(a,i,j);
            i++;
            j--;
        }
    }
    swap(a,pivot,j);
    pivot = j;
    return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 if (der > izq) {
    unsigned int pivot = partition(a,izq,der);
    if (pivot != 0) {
        quick_sort_rec(a,izq,pivot);
    }    
    quick_sort_rec(a,(pivot+1),der);
 }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
