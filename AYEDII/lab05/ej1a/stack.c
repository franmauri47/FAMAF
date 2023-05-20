#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack{
    stack_elem elem;
    struct  _s_stack * next;   
};

bool invrep(stack s){
    return(s != NULL);
}

stack stack_empty(){
    stack s = NULL;
    return (s);
}

stack stack_push(stack s, stack_elem e){
    stack p = malloc(sizeof(struct _s_stack));
    p->elem = e;
    p->next = s;
    s = p;
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s));
    stack p = s;
    s = s->next;
    free(p);
    if (s != NULL){
        assert(invrep(s));
    }        
    return s;
}

unsigned int stack_size(stack s){
    stack p = s;
    unsigned int counter = 0;
    while(p != NULL){
        counter++;
        p = p->next;
    }
    return counter;
}

stack_elem stack_top(stack s){
    assert(invrep(s));
    stack_elem elem;
    elem = s->elem;
    assert(invrep(s));
    return elem;
}

bool stack_is_empty(stack s){
    return (s == NULL);
}

stack_elem *stack_to_array(stack s){
    unsigned int size = stack_size(s);
    stack_elem *array = calloc(size,sizeof(struct _s_stack));
    
    if (size != 0) {
        int i = 0;
        while (!stack_is_empty(s)){
            array[i] = stack_top(s);
            s = stack_pop(s);
            i++;
        }
    }    
    else{
        array = NULL;
    }
    return array;    
}

stack stack_destroy(stack s){
    stack aux;
    if(s != NULL){
        aux = s;
        s = s->next;
        free(aux);
        stack_destroy(s);
    }
    return s;
}



