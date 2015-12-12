

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 Now my program is running a lot better.
 I read in using fscanf rather than the token method.
 Then I create a customer and order and add then to the appropriate list
 if they do not already exist in that list.
 
 Then I print to orders.txt.
 Then I sort.
 Then I print to revenue.txt.
 
*/

#include "CustomerList.h"
#include "OrderList.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/* Reads or writes to the files.
 */
void handlefiles(FILE* inputFile, FILE* output1, FILE* output2);

/* Reads and parses input from the input file.
 * Also adds input to the two lists.
 */
void readInput(FILE* inputFile, CustomerList* cList, OrderList* oList);

/* Prints to orders.txt file.
 */
void printToOrders(FILE* outputFile, CustomerList* cList, OrderList* oList);

/* Sorts the customers by the total amount of their order.
 */
void sortCustbyCost(CustomerList* cList);

/* Prints to revenue.txt
 */
void printToRevenue(FILE* outputFile, CustomerList* cList, OrderList* oList);

/* Creates and returns a customer struct.
 */
struct Customer* createCustomer(int theID, char *theName, int theTotal, int theSize);

/* Creates and returns an order struct.
 */
struct Order* createOrder(int theID, char *theName, int theCost, int theAmount);



/* Entry point of program.
 *
 */
int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    
    printf("Enter the name of the file containing purchases: ");
    
    char nameFile[100];
    scanf("%s", nameFile);
    
    
    FILE *inputFile;
    inputFile = fopen(nameFile, "r");

    
    
    if( inputFile == NULL ) {
        printf("Program was not able to open the file\n");
        
        return -1; //end of main run.
    }
    

    
    //create two files for output
    FILE* output1 = fopen("orders.txt", "w");
    FILE* output2 = fopen("revenue.txt", "w");
    
    handlefiles(inputFile, output1, output2);
    
    
    fclose(inputFile);
    fclose(output1);
    fclose(output2);
    
    //Let user know that program is done.
    
    printf("Done. Check files orders.txt and revenue.txt.\n");
    return 0;
}


/* Reads or writes to the files.
 *
 */
void handlefiles(FILE* inputFile, FILE* output1, FILE* output2) {
    
    //fprintf(output1, "hello first 3\n");
    
    CustomerList* cList = createCList();
    OrderList* oList = createOList();


    readInput(inputFile, cList, oList);
    
    
    //First print to orders.txt because that file needs the customers to be in order of input.
    printToOrders(output1, cList, oList);
    
    
    //Then sort customerlist (with customer who has highest totalSpent coming first)
    sortCustbyCost(cList);
    
    
    //Then print to revenue.txt which will need to be sorted by customer's spending (high to low)
    printToRevenue(output2, cList, oList);
}




/* Sorts the customers by the total amount of their order.
 *
 */
void sortCustbyCost(CustomerList* cList) {
    
    struct Customer* temp;
    int c, d;
    
    for (c = 0; c < cList->size - 1; c++) {
        
        for (d = 0; d < cList->size - c - 1; d++) {
            
            if (cList->data[d].totalSpent < cList->data[d+1].totalSpent) {
                
                temp = &cList->data[d];
                cList->data[d] = cList->data[d+1];
                cList->data[d+1] = *temp;
            }
        }
    }
    
}


/* Prints to revenue.txt
 *
 */
void printToRevenue(FILE* outputFile, CustomerList* cList, OrderList* oList) {
    
    int i;
    for (i = 0; i < cList->size; i++) {
        fprintf(outputFile, "%d Total order: %.2f\n",
                cList->data[i].custID, cList->data[i].totalSpent);
        
        int j;
        for (j = 0; j < oList->size; j++) {
            if (oList->data[j].custID == cList->data[i].custID) {
                fprintf(outputFile, "%s $%.2f %d", oList->data[j].itemName,
                        oList->data[j].perCost, oList->data[j].quantity);
                
                fprintf(outputFile, " = %.2f\n", oList->data[j].perCost * oList->data[j].quantity);
                
            }
        }
        
        fprintf(outputFile, "\n");

    }
    
 }

/* Prints to orders.txt file.
 *
 */
void printToOrders(FILE* outputFile, CustomerList* cList, OrderList* oList) {
    
    int i;
    for (i = 0; i < cList->size; i++) {
        fprintf(outputFile, "%d %s\n", cList->data[i].custID, cList->data[i].name);
        
        //loop through oList to find what this person bought
        int j;
        for (j = 0; j < oList->size; j++) {
            if (oList->data[j].custID == cList->data[i].custID) {
                fprintf(outputFile, "%s $%.2f %d\n", oList->data[j].itemName,
                        oList->data[j].perCost, oList->data[j].quantity);
            }
        }
        
        fprintf(outputFile, "\n");
        
    }
    
    
}



/* Reads and parses input from the input file.
 * Also adds input to the two lists.
 */
void readInput(FILE* inputFile, CustomerList* cList, OrderList* oList) {
    
    int id;
    char last_name[25];
    char first_name[25];
    char item_name[20];
    float item_price;
    int item_quantity;
    
    while (1) {
        if( fscanf(inputFile,  "%d %s %s %s $%f %d",
                   &id, last_name, first_name, item_name, &item_price, &item_quantity) == EOF){
            printf("End of file\n");
            break;
        }
        
        /*printf("%d %s %s %s $%.2f %d\n",
                   id, last_name, first_name, item_name, item_price, item_quantity);*/
        
        //check if customer is already in CustomerList.
        if (containsCust(cList, id)) {
            addToCust(cList, id, item_price, item_quantity);
            
            //Add to list of orders
            Order* ord = createOrder(id, item_name, item_price, item_quantity);
            pushOList(oList, ord);
          
            
            
        } else {
            
            char combine_name[50];
            strcpy(combine_name, last_name);
            strcat(combine_name, " ");
            strcat(combine_name, first_name);
            
            //Add to list of customers
            Customer* cust = createCustomer(id, combine_name, item_price, item_quantity);
            pushCList(cList, cust);
            
            //Add to list of orders
            Order* ord = createOrder(id, item_name, item_price, item_quantity);
            pushOList(oList, ord);
           
            
        }
        
    }
}



/* Creates and returns a customer struct.
 *
 */
struct Customer* createCustomer(int theID, char *theName, int theTotal,  int theSize) {

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



























