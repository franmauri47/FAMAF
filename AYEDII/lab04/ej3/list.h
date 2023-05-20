#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int list_elem;

/* list as a pointer to structs to guarantee encapsulation */
typedef struct s_node * list;

/*Constructors*/
list empty_list();
/*
    Create an empty list
*/

list addl(list l, list_elem e);
/*
    add element e to the left of the list
*/


/*operations*/
bool is_empty(list l);
/*
    Returns wether the list l have none value innit
*/

list_elem head(list l);
/*
    Returns the first element of the list l
    PRECONDITION: !is_empty(l)
*/

list tail(list l);
/*
    Deletes the first element of the list l
    PRECONDITION: !is_empty(l)
*/

list addr(list l, list_elem e);
/*
    add element e to the right of the list
*/

unsigned int length(list l);
/*
    Returns the amount of elements of the list l
*/

list concat(list l, list x);
/*
    At the end of list l, it adds the elements of list x in its order
*/

list_elem index(list l, unsigned int n);
/*
    Returns the nth element of the list l
    PRECONDITION: length(l) > n
*/

list take(list l, unsigned int n);
/*
    In the list l, leaves the first n elements and delete the rest
    PRECONDITION: length(l) >= n
*/

list drop(list l, unsigned int n);
/*
    Delete the first n elements
*/

list copy_list(list l);
/*
    Create a copy list of l
*/


/*Destroy*/
void destroy(list l);
/*
   Frees memory for l.
*/


#endif