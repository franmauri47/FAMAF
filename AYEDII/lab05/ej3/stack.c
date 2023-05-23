#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack{
    unsigned int size;
    struct  node * first;   
};

struct node{
    stack_elem elem;
    struct node *next;
};

bool invrep(stack s){
    return(s != NULL);
}

stack stack_empty(){
    stack s = malloc(sizeof(struct _s_stack));
    s->size = 0;
    s->first = NULL;
    return (s);
}

stack stack_push(stack s, stack_elem e){
    assert(invrep(s));
    struct node *new = malloc(sizeof(struct node));
    new->elem = e;
    new->next = s->first;
    s->first = new;    
    s->size++;
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s));
    struct node *aux = s->first;
    s->first = s->first->next;
    s->size--;
    free(aux);          
    assert(invrep(s));
    return s;
}

unsigned int stack_size(stack s){
    return s->size;
}

stack_elem stack_top(stack s){
    assert(invrep(s));
    stack_elem elem;
    elem = s->first->elem;
    assert(invrep(s));
    return elem;
}

bool stack_is_empty(stack s){
    return (s->size == 0);
}

stack_elem *stack_to_array(stack s){
    assert(invrep(s));
    unsigned int size = stack_size(s);
    stack_elem *array = NULL;
    struct node *aux = s->first;
    
    if (size != 0) {
        array = calloc(size,sizeof(stack_elem));
        unsigned int i = size;
        while (i > 0){
            array[i-1] = aux->elem;
            aux = aux->next;
            i--;
        }
    }    
    assert(invrep(s));
    return array;    
}

stack stack_destroy(stack s){
    while (!stack_is_empty(s)){
        s = stack_pop(s);
    }
    free(s);
    return s;
}


