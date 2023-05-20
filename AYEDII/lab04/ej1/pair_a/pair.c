#include <assert.h>
#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t p;
    p.fst = x;
    p.snd = y;
    return p;
}

int pair_first(pair_t p){
    int res = p.fst;
    assert(p.fst == res);
    return (res);
}

int pair_second(pair_t p){
    int res = p.snd;
    assert(p.snd == res);
    return (res);
}

pair_t pair_swapped(pair_t p){
    int tmp1 = p.fst;
    int tmp2 = p.snd;
    p.fst = p.snd;
    p.snd = tmp1;
    assert(tmp2 == p.fst && tmp1 == p.snd);
    return p;
}

pair_t pair_destroy(pair_t p){
    p.fst = 0;
    p.snd = 0;
    return p;
}