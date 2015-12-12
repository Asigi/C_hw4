

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
    header
*/



#ifndef LISTCUSTOMER_H
#define LISTCUSTOMER_H


typedef struct Customer {
    int custID; //the ID of the customer
    char name[50]; //last, first name of customer
    float totalSpent; //total $ spent
    int orderSize; //number of items purchased
} Customer;




typedef struct CustomerList {
    
    Customer* data;
    int size;
    int capacity;
    
} CustomerList;


struct CustomerList* createCList(void);
void destroyCList(CustomerList* l);
void make_emptyCList(CustomerList* l);
int is_emptyCList(CustomerList* l);
int is_fullCList(CustomerList* l);
void pushCList(CustomerList* l, Customer* item);
void deleteCList(CustomerList* l, Customer* item);
void printCList(CustomerList* l);
int containsCust(CustomerList* l, int theID);
void addToCust(CustomerList*, int theID, int price, int quantity);

#endif
