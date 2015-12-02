

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 */



#ifndef LISTORDER_H 
#define LISTORDER_H


typedef struct Customer { //HELP Can I also have this exact same thing in main?
    char name[35];
    Order orders[15];
    int orderSize;
    float totalSpent
} Customer;


typedef struct Order { //HELP can I also have this exact same thing in main?
    
    char itemName[25]; //the item's name
    int quantity; //number of items
    float perCost; //this is the cost of each item in this order
} Order;



typedef struct OrderList {
    
    Order* data;
    int size;
    int capacity;
    
} OrderList;



OrderList createOList(void);
void destroyOList(OrderList l);
void make_emptyOList(OrderList l);
int is_emptyOList(OrderList l);
int is_fullOList(OrderList l);
void pushOList(OrderList l, Order item);
void deleteOList(OrderList l, Order item);
void printlOList(OrderList l);

#endif



//OLD CODE BELOW

//typedef struct list_type *ListType;
//typedef int ItemType;

