

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
struct Customer* createCustomer(int theID, /*in*/char *theName, int theTotal, int theSize);
struct Order* createOrder(int theID, char *theName, int theCost, int theAmount);


int main() {
    
    printf("Enter the name of the file containing purchases: ");
    
    char nameFile[100];
    scanf("%s", nameFile);
    
    printf("scanned in %s\n file", nameFile);
    
    FILE* input = fopen(nameFile, "r");
    
    
    if( input == NULL ) {
        printf("Program was not able to open the file\n");
        fclose(input);
        return 0; //end of main run.
    }
    
    printf("the input file is not null");
    
    
    
    FILE* output1 = fopen("orders.txt", "w");
    FILE* output2 = fopen("revenue.txt", "w");
    
    
    
    CustomerList* cList = createCList();
    OrderList* oList = createOList();
    
    
    int id;
    char last_name[25];
    char first_name[25];
    char item_name[20];
    float item_price;
    int item_quantity;
    
    
    while (fscanf (input, "%d %s %s %s %f %d",
                   &id, last_name, first_name, item_name, &item_price, &item_quantity) != '\n') {
        
        char combine_name[50];
        strcpy(combine_name, last_name);
        strcat(combine_name, " ");
        strcat(combine_name, first_name);
        
        
        if (containsCust(cList, id)) { //check if customer is already in CustomerList.
            addToCust(cList, id, item_price, item_quantity);
            
            //Add to list of orders
            Order* ord = createOrder(id, item_name, item_price, item_quantity);
            pushOList(oList, ord);
            //TODO free ord?
            
        } else {
            
            Customer* cust = createCustomer(id, combine_name, item_price, item_quantity);
            pushCList(cList, cust);
            //TODO free cust?

            //Add to list of orders
            Order* ord = createOrder(id, item_name, item_price, item_quantity);
            pushOList(oList, ord);
            //TODO free ord?
        }
    
    }

    
    
    
    
    //TODO read below
    //First print out orders.txt because that file needs the customers to be in order of input.
    //Then sort customerlist (with customer who has highest totalSpent coming first)
    //Then print out revenue.txt which will need to be sorted by customer's spending (high to low)
    
    fclose(input);
    fclose(output1);
    fclose(output2);
    
    printf("Reach end of main function");
    return 0;
}



/* Creates and returns a customer struct.
 *
 */
struct Customer* createCustomer(int theID, /*in*/char *theName, int theTotal,  int theSize) {

    Customer* cust = (Customer*) malloc(sizeof(Customer));
    
    cust->custID = theID;
    strcpy(cust->name, theName);
    cust->orderSize = theSize;
    cust->totalSpent = theTotal;

    return cust;
}



/* Creates and returns an order struct.
 *
 */
struct Order* createOrder(int theID, char *theName, int theCost, int theAmount) {
    
    Order* ord = (Order*) malloc(sizeof(Order));
    
    ord->custID = theID;
    strcpy(ord->itemName , theName);
    ord->perCost = theCost;
    ord->quantity = theAmount;
    
    return ord;
}



//put the methods down here



































