#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    stack new = malloc(sizeof(struct _s_stack));
    new->capacity = 0;
    new->size = 0;
    new->elems = malloc(new->capacity * sizeof(int *));
    return new;
}

void increase_capacity (stack s){
    if (s->size == s->capacity){
        s->capacity = (s->capacity == 0) ?  2 : s->capacity * 2;
        s->elems = realloc(s->elems,2 * (sizeof(s->elems)));
    }
}

stack stack_push(stack s, stack_elem e){
    increase_capacity(s);
    s->elems[s->size] = e;
    s->size++;   
    return s; 
}

stack stack_pop(stack s){
    assert(s->size != 0);
    s->size--;
    return s;
}

unsigned int stack_size(stack s){
    return (s->size);
}

stack_elem stack_top(stack s){
    assert(s->size != 0);
    return (s->elems[s->size-1]);
}

bool stack_is_empty(stack s){
    return (s->size == 0);
}

stack_elem *stack_to_array(stack s){
    unsigned int last_position = s->size-1;
    unsigned int i=0;
    int aux;
    while (i < last_position){
        aux = s->elems[i];
        s->elems[i] = s->elems[last_position];
        s->elems[last_position] = aux;
        i++;
        last_position--;
    }
    return s->elems;
}

stack stack_destroy(stack s){
    free(s);
    return s;
}


