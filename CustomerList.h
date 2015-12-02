

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
*/



#ifndef LISTCUSTOMER_H //HELP what is ifndef?
#define LISTCUSTOMER_H


typedef struct Customer { //HELP Can I also have this exact same thing in main?
    char name[35];
    Order orders[15];
    int orderSize;
    float totalSpent
} Customer;




typedef struct CustomerList {
    
    Customer* data;
    int size;
    int capacity;
    
} CustomerList;



CustomerList createCList(void);
void destroyCList(CustomerList l);
void make_emptyCList(CustomerList l);
int is_emptyCList(CustomerList l);
int is_fullCList(CustomerList l);
void pushCList(CustomerList l, Customer item);
void deleteCList(CustomerList l, Customer item);
void printlCList(CustomerList l);

#endif



//OLD CODE BELOW

//typedef struct list_type *ListType;
//typedef int ItemType;

