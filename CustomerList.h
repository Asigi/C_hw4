

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 
 
 
 
*/



#ifndef LISTADT_H
#define LISTADT_H

typedef struct list_type *ListType;
typedef int ItemType;

ListType create(void);
void destroy(ListType l);
void make_empty(ListType l);
int is_empty(ListType l);
int is_full(ListType l);
void push(ListType l, ItemType item);
void delete(ListType l, ItemType item);
void printl(ListType l);

#endif


