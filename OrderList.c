

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 c file for array list of orders.
 
 
 */


#include "OrderList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ORD_LIST_MAX  100




/*creates and returns an OrderList.
 *
 */
struct OrderList* createOList() {
    
    OrderList* list = (OrderList*) malloc( sizeof (OrderList));
    
    if (list != NULL) {
        list->size = 0;
        list->capacity = ORD_LIST_MAX;
        list->data = malloc( ORD_LIST_MAX * sizeof(Order));
        if (list->data == NULL) {
            free (list);
            list = NULL;
        }
    }
    return list;
}





/*destroys the data in a list.
 *
 */
void destroyOList(OrderList* l) {
    free(l->data);
    free(l);
    l = NULL;
}





/*Adds a component to the array, if enough memory available.
 *If enough memory is not available, then increase the size of the array and then add.
 */
void pushOList(OrderList*  l, Order* item) {
    if (l->size >= l->capacity) {
        Order * temp = malloc(sizeof(Order) * (l->capacity + 100));
        if (temp != NULL) {
            l->capacity += 100;
            memcpy(temp, l->data,sizeof(Order) * (l->size));
            free(l->data);
            l->data = temp;
            l->data[l->size] = *item;
            l->size++;
        }
    }
    else {
        l->data[l->size] = *item;
        l->size++;
    }
}




/* Returns the size of the list.
 *
 */
int size_isOList(OrderList* l) {
    return l->size;
}





/* Returns 1 if the list is empty. 0 otherwise.
 *
 */
int is_emptyOList(OrderList* l) {
    return l->size == 0;
}




/*
 *
 */
void make_emptyOList(OrderList* l) {
    // if list is larger than 200 elements, create a smaller one
    if (l->size > 200)
        l->data = realloc(l->data, sizeof(Order) * 100);
    
    l->size = 0;
    l->capacity = 100;
}




/* Tells you if the list is full.
 *
 */
int is_fullOList(OrderList* l) {
    if (l->size >= l->capacity) {
        Order * temp = malloc(sizeof(Order) * (l->capacity + 100));
        if (temp != NULL) {
            free(temp);
            return 0;
        }
        else
            return 1;
    }
    return 0;
}





/* Deletes the given order from the list.
 *
 */
void deleteOList(OrderList* l, Order* item) {
    
    int idx = -1, i;
    
    for (i = 0; i < l->size; i++ ) {
        if (l->data[i].custID == item->custID) {
            idx = i;
            break;
        }
    }
    if (idx >= 0)
        l->data[idx] = l->data[--l->size];
    
}




/*
 * Prints the contents of the list.
 */
void printOList(OrderList* l) {
    int i;
    for(i = 0; i < l->size; i++)
        printf("%d ", l->data[i].custID);
    printf("\n");
}










