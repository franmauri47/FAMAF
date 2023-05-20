#include "pair.h"
#include <stdlib.h>
#include <assert.h>

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
    pair_t p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

elem pair_first(pair_t p) {
    elem res = p->fst;
    assert(p->fst == res);
    return res;
}

elem pair_second(pair_t p) {
    elem res = p->snd;
    assert(p->snd == res);
    return res;
}

pair_t pair_swapped(pair_t p) {
    pair_t swapped = malloc(sizeof(struct s_pair_t));
    swapped->fst = p->snd;
    swapped->snd = p->fst;
    assert(swapped->fst == p->snd && swapped->snd == p->fst);
    return swapped;    
}

pair_t pair_destroy(pair_t p) {
    free(p);
    return (p = NULL);
}