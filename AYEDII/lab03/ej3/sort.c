#include "sort.h"

void sort_letters(unsigned int indexes[], char letters[], char sorted[],  unsigned int length) {
    for (unsigned int i = 0; i < length; i++){
        sorted[indexes[i]] = letters[i];
    }
}