
#include<stdio.h>
//Data organization
struct main
{
    int customerID;
    char name[100];
    float balance;
};


//function prototypes

//void addcustomer();
void showrecords(struct main customer[],int size){
    for(int i=0;i<size;i++){
    printf("CustomerID: %d\n",customer[i].customerID);
    printf("Customer Name: %s\n",customer[i].name);
    printf("Customer balance: %.2f\n----------------\n",customer[i].balance);
     }
}
//void recordpayment(struct main customer1){
    
//void increaselimit();

int main(){
    //
    int option;
    struct main customer[] = {
        {100, "F. Scott Fitzgerald",10.99},
        {1984, "George Orwell",  8.99},
        {567 ,"Harper Lee",7.99}
    };
    int size= sizeof(customer)/sizeof(customer[0]);

    //program initialization

    printf("======CREDIT MANAGEMENT SYSTEM======\n\n");
    printf("Press any key to continue.\n\n");
    getchar();
    printf("continuing the program......\n ");

    printf("****Choose one option.****\n");

    printf("1.Add customer.\n");
    printf("2.Record payment\n");
    printf("3.View outstanding balance\n");

    scanf("%d",&option);

    //option conditions
    if(option==1){
        printf("23");
    }
    else if(option==2){
        //recordpayment();

    }
    else if(option==3){
        showrecords(customer,size);
    }

    else{printf("Invalid option!! Please try again.");}



        return 0;
}
