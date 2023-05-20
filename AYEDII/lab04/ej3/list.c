#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

struct s_node{
    list_elem element;
    struct s_node * next;
};

void destroy(list l){
    struct s_node *p;
    struct s_node *q;

    if(!is_empty(l)){
        p = l;
        q = p->next;
        l = q;
        free(p);
        destroy(l);
    }
}

/*CONSTRUCTORS*/

list empty_list(){
    list l = NULL;
    return l;
}

list addl(list l, list_elem e){
    struct s_node *p = malloc(sizeof(struct s_node));
    p->element = e;
    p->next = l;
    l = p;
    return l;
}

/*OPERATIONS*/
bool is_empty(list l){
    bool res = l == NULL;
    return res;
}

list_elem head(list l){
    assert(!is_empty(l));
    list_elem res = l->element;
    return res;
}

list tail(list l){
    assert(!is_empty(l));
    struct s_node * a = l;
    l = l->next;
    destroy(a);
    return l;
}

list addr(list l, list_elem e){
    struct s_node *p;
    struct s_node *q = malloc(sizeof(struct s_node));
    q->element = e;
    q->next = NULL;
    if (!is_empty(l)){
        p = l;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }
    else {
        l = q;
    }
    return l;
}

unsigned int length(list l){
    struct s_node *p = l;
    unsigned int n = 0;
    while(p != NULL){
        n++;
        p = p->next;
    }
    return n;
}

list concat(list l, list x){
    struct s_node *p = l;
    while (p != NULL){
        p = p->next;
    }
    p->next = x;
    return l;
}

list_elem index(list l, unsigned int n){
    assert(length(l) > n);

    struct s_node *p = l;
    unsigned int counter = 0;

    while (counter != n) {
        p = p->next;
        counter++;
    }

    return p->element;
}

list take(list l, unsigned int n){
    assert(length(l) >= n);
    struct s_node *p = l;
    struct s_node *q = NULL;
    unsigned int i = 0u;

    while (i != n) {
        p = p->next;
        i++;
    }
    q = p->next;
    destroy(q);
    
    return p;
}

list drop(list l, unsigned int n){
    unsigned int i = 0u;

    while (i != n) {
        l = tail(l);
        i++;
    }
    return l;
}

list copy_list(list l){
    list copy = empty_list();
    struct s_node *p = l;
    while(p != NULL){
        addr(copy,p->element);
        p = p->next;
    }
    return copy;
}
