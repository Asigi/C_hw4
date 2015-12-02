

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 
 
 
 
*/

#include "CustomerList.h"
#include "OrderList.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



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
    
    
    
    CustomerList* cList = creatCList();
    
    
    
    int id;
    char last_name[25];
    char first_name[25];
    char item_name[20];
    float item_price;
    int item_quantity;
    
    
    while (fscanf (input, "%d %s %s %s %f %d",
                   &id, last_name, first_name, item_name, item_price, item_quantity) != EOF) {
        
        char combine_name[50];
        strcpy(combine_name, last_name);
        strcat(combine_name, " ");
        strcat(combine_name, first_name);
        
        
        if (containsCust(clist, id)) { //check if customer is already in CustomerList.
            addToCust(id, item_price, item_quantity)
            
        } else {
            
            Customer* cust = createCustomer(id, combine_name, item_price, item_quantity);
            
        
        }
    
    }

    
    
    
    
    
    
    
    
    return 0;
}



//Note that theTotal is the total cost of the order (or item_price)
struct Customer* createCustomer(int theID, /*in*/char *theName,
                                int theTotal, theSize) {

    Customer* cust = (Customer*) malloc(sizeof(Customer));
    
    cust->custID = theID;
    cust->name = theName;
    cust->orderSize = theSize;
    cust->totalSpent = theTotal;

    return cust;
}



//put the methods down here


