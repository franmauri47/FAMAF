#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    c->count = 0;
    return c;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    bool res = c->count == 0;
    return res;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count = c->count - 1;
}

counter counter_copy(counter c) {
    counter p = malloc(sizeof(struct _counter));
    p->count = c->count;
    assert(c->count == p->count);
    return p;
}

void counter_destroy(counter c) {
    free(c);
}
