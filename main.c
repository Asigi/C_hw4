

//Arshdeep Singh
//TCSS 333, C Programming
//Homework 4

/* Logic explaining my code:
 
 
 
 
 
*/




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
    
    
    //take in customer id,
    //take in customer last name (plus comma) and then take in first name.
        //add first name after last name and a comma and a space
    //take in item name
    //take in item price
    //take in item quantity
    
    
    
    
    
    
    
    
    return 0;
}


struct Customer* createCustomer(/*in*/char *theName, Order *theOrders ,int theSize, theTotal) {

    Customer* cust = (Customer*) malloc(sizeof(Customer));
    cust->name = theName;
    
    //add theOrders to the Customer's order field.
    
    cust->orderSize = theSize;
    cust->totalSpent = theTotal;

    
}



//put the methods down here


