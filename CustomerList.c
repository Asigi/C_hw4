

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 c file for array list of customers
 
*/


#include "CustomerList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CUST_LIST_MAX  100




/*creates and returns a list.
 *
 */
struct CustomerList* createCList() {
    
    CustomerList* list = (CustomerList*) malloc( sizeof (CustomerList));
    
    if (list != NULL) {
        list->size = 0;
        list->capacity = CUST_LIST_MAX;
        list->data = malloc( CUST_LIST_MAX * sizeof(Customer));
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
void destroyCList(CustomerList* l) {
    free(l->data);
    free(l);
    l = NULL;
}





/*Adds a component to the array, if enough memory available.
 *If enough memory is not available, then increase the size of the array and then add.
 */
void pushCList(CustomerList* l, Customer* item) {
    if (l->size >= l->capacity) {
        Customer * temp = malloc(sizeof(Customer) * (l->capacity + 100));
        if (temp != NULL) {
            l->capacity += 100;
            memcpy(temp, l->data,sizeof(Customer) * (l->size));
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
int size_isCList(CustomerList* l) {
    return l->size;
}





/* Returns 1 if the list is empty. 0 otherwise.
 *
 */
int is_emptyCList(CustomerList* l) {
    return l->size == 0;
}





/*
 *
 */
void make_emptyCList(CustomerList* l) {
    // if list is larger than 200 elements, create a smaller one
    if (l->size > 200)
        l->data = realloc(l->data, sizeof(Customer) * 100);
    
    l->size = 0;
    l->capacity = 100;
}




/* Tells you if the list is full.
 *
 */
int is_fullCList(CustomerList* l) {
    if (l->size >= l->capacity) {
        Customer * temp = malloc(sizeof(Customer) * (l->capacity + 100));
        if (temp != NULL) {
            free(temp);
            return 0;
        }
        else
            return 1;
    }
    return 0;
}





/* Deletes the given customer from the list.
 *
 */
void deleteCList(CustomerList* list, Customer* item) {
    
    int idx = -1, i;
    
    for (i = 0; i < list->size; i++ ) {
        if (list->data[i].custID == item->custID) {
            idx = i;
            break;
        }
    }
    if (idx >= 0) 
        list->data[idx] = list->data[--list->size];
    
}




/*
 * Prints the contents of the list.
 */
void printCList(CustomerList* l) {
    int i;
    for(i = 0; i < l->size; i++)
        printf("%s ", l->data[i].name);
    printf("\n");
}





/* Checks if the customer is already in the list.
 *
 */
int containsCust(CustomerList* list, int theID) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (list->data[i].custID == theID) {
            return 1;
        }
    }
    
    return 0;
}


/* Adds purchases to an existing customer
 *
 */
void addToCust(CustomerList* l, int theID, int price, int quantity) {
    int i;
    for (i = 0; i < l->size; i++) {
        if (l->data[i].custID == theID) {
            
            l->data[i].totalSpent += price;
            l->data[i].orderSize += quantity;
        }
    }
}












