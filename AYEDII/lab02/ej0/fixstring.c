#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int res = (-1);
    for (unsigned int i=0; i<FIXSTRING_MAX;i++) {
        if (s[i] == '\0'){
            res = (i);
            return res;
        }
    }
    return res;
}

bool fstring_eq(fixstring s1, fixstring s2) {    
    int longS1 = fstring_length(s1);
    int longS2 = fstring_length(s2);
    if (longS1 > longS2 || longS1 < longS2) {
        return false;
    }
    else {
        for (int i=0; i<longS1; i++) {
            if (s1[i] != s2[i]) {
                return false;
            }            
        }
        return true;
    }
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    
    int lengthToCompare;
    if (fstring_length(s1) < fstring_length(s2)) {
        lengthToCompare = fstring_length(s1);
    } 
    else {
        lengthToCompare = fstring_length(s2);
    }

    int i = 0;
    while (i < lengthToCompare) {
        if (s1[i] < s2[i]) {
            return true;
        }
        else if (s1[i] > s2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

