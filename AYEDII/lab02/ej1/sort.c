#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    unsigned int j = i;    
    while (j >= 1 && goes_before(a[j],a[j-1])) {
        swap(a,(j-1),j);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    int copy[length];
    array_copy(copy,a,length);
    for (unsigned int i = 1u; i < length; ++i) {
        array_is_permutation_of(copy,a,length);
        insert(a, i);
    }
}
