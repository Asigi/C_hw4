

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
    header
 */



#ifndef LISTORDER_H
#define LISTORDER_H




typedef struct Order {
    int custID; //the ID of the customer who placed this order.
    char itemName[50]; //the item's name
    float perCost; //this is the cost of each item in this order
    int quantity; //number of items
} Order;



typedef struct OrderList {
    
    Order* data;
    int size;
    int capacity;
    
} OrderList;



struct OrderList* createOList(void);
void destroyOList(OrderList* l);
void make_emptyOList(OrderList* l);
int is_emptyOList(OrderList* l);
int is_fullOList(OrderList* l);
void pushOList(OrderList* l, Order* item);
void deleteOList(OrderList* l, Order* item);
void printOList(OrderList* l);

#endif

