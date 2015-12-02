

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 
 
 
 
*/

#include "CustomerList.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Order {
    char itemName[25]; //the item's name
    int quantity; //number of items
    float perCost; //this is the cost of each item in this order
} Order;



typedef struct Customer {
    char name[25];
    Order orders[15];
    int orderSize;
    float totalSpent
} Customer;



//put the method headers here


int main() {
    
    printf("Enter the name of the file containing purchases: ");
    
    char nameFile[256];
    scanf( "%s" , nameFile);
    
    FILE* input = fopen(nameFile, "r");
    
    FILE* output1 = fopen("orders.txt", "w");
    FILE* output2 = fopen("revenue.txt", "w");
    
    
    if( input == NULL ) {
        printf("Program was not able to open the file\n");
        return 0; //end of main run.
    }
    
    CustomerList cList = creatCList();
    
    int id;
    char last_name[15];
    char first_name[15];
    char item_name[20];
    float item_price;
    int item quantity;
    
    
    while (fscanf (input, "%d %s %s %s %f %d", &id, last_name, first_name, item_name, item_price, quantity) != EOF) {
        
        //check if customer is already in CustomerList.
        
        
        //HELP create a customer object and add it to the list? or plug in these values into a function in CustList which will create the Customer object itself and add it?
        
        //also figure out customer uniqueness. How not to add duplicate customers.
        
    }

    
    
    
    
    
    
    
    
    return 0;
}





//TODO Maybe, instead of putting this here I can put it within the CustomerList class where the customer will be created and added to the list?
struct Customer* createCustomer(/*in*/char *theName, Order *theOrders ,int theSize, theTotal) {

    Customer* cust = (Customer*) malloc(sizeof(Customer));
    cust->name = theName;
    
    //add theOrders to the Customer's order field.
    
    cust->orderSize = theSize;
    cust->totalSpent = theTotal;

    return cust;
}



//put the methods down here


