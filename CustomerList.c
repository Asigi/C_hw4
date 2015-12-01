

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:

 
 

 
*/


#include "CustomerList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
struct list_type {
    ItemType* data;
    int size;
    int capacity;
};
 */

struct CustomerList {
    
    Customer* data;
    int size;
    int capacity;
    
};


// returns the pointer to the list; NULL if list not created
ListType create() {
    // allocate memory for a structure variable containing all
    // list components
    ListType l = malloc(sizeof(struct list_type));
    // if allocation was succesfull
    if (l != NULL) {
        l->size = 0;
        l->capacity = 10;
        // allocate memory for the actual array
        l->data = malloc(10*sizeof(ItemType));
        // if array not created, deallocate the list too
        if (l->data == NULL) {
            free(l);
            l = NULL;
        }
    }
    return l;
}

void destroy(ListType l) {
    free(l->data);
    free(l);
    l = NULL;
}

// adds a component to the array, if enough memory available
void push(ListType l, ItemType item) {
    if (l->size >= l->capacity) {
        ItemType * temp = malloc(sizeof(ItemType) * (l->capacity + 100));
        if (temp != NULL) {
            l->capacity += 100;
            memcpy(temp, l->data,sizeof(ItemType) * (l->size));
            free(l->data);
            l->data = temp;
            l->data[l->size] = item;
            l->size++;
        }
    }
    else {
        l->data[l->size] = item;
        l->size++;
    }
}

void printl(ListType l) {
    int i;
    for(i = 0; i < l->size; i++)
        printf("%d ", l->data[i]);
    printf("\n");
}

int size_is(ListType l) {
    return l->size;
}

int is_empty(ListType l) {
    return l->size == 0;
}

void make_empty(ListType l) {
    // if list is larger than 200 elements, create a smaller one
    if (l->size > 200)
        l->data = realloc(l->data, sizeof(ItemType) * 100);
    
    l->size = 0;
    l->capacity = 100;
}

int is_full(ListType l) {
    if (l->size >= l->capacity) {
        ItemType * temp = malloc(sizeof(ItemType) * (l->capacity + 100));
        if (temp != NULL) {
            free(temp);
            return 0;
        }
        else
            return 1;
    }
    return 0;
}

void delete(ListType l, ItemType item) {
    
    int idx = -1, i;
    
    for (i = 0; i < l->size; i++ ) {
        if (l->data[i] == item) {
            idx = i;
            break;
        }
    }
    if (idx >= 0) 
        l->data[idx] = l->data[--l->size];
    
}





















