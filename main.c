
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Data organization
struct Customer{
    int customer_ID;
    char name[100];
    float credit_limit;
    float current_balance;
};


//customers pointer
struct Customer *customer = NULL;
int customer_count = 0;

//adding new customer
void addcustomer(){
    struct Customer new_customer;

    new_customer .customer_ID = customer_count + 1;
    printf("Enter customer.name");
    getchar();
}

// showing records
void showrecords(){
  FILE *file=fopen("customer_data.txt","rb");

}
int main(){

    //program initialization

    printf("======CREDIT MANAGEMENT SYSTEM======\n\n");
    printf("Press any key to continue.\n\n");
    getchar();
    printf("continuing the program......\n ");

    printf("****Choose one option.****\n");

    printf("1.Add customer.\n");
    printf("2.Record payment\n");
    printf("3.View outstanding balance\n");
    
    int option;
    scanf("%d",&option);

    //option conditions
    if(option==1){
        //printf("");
    }
    else if(option==2){
        //recordpayment();

    }
    else if(option==3){
        //showrecords(customer,size);
    }

    else{
        printf("Invalid option!! Please try again.");
    }



        return 0;
}
