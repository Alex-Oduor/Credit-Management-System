#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

//Data organization
struct Customer{
    int customer_ID;
    char first_name[50];
    char second_name[50];
    float credit_limit;
    float current_balance;
};



//adding new customer
int addcustomer(){
    char choice;
    struct Customer new_customer;

  do{
    //prompt user to enter customer details
      printf("Enter customer first name:");
     scanf("%s", new_customer.first_name);

      printf("Enter customer second name: ");
     scanf("%s", new_customer.second_name);

      printf("Enter customer ID:");
      scanf("%d",&new_customer.customer_ID);

     printf("Enter credit limit:");
     scanf("%f",&new_customer.credit_limit);

     printf("Enter Debt amount:");
     scanf("%f",&new_customer.current_balance);
    
     FILE *file=fopen("customer_data.txt","ab");
     if(file==NULL){
        printf("Error writing to file.....creating new file");
        file=fopen("customer_data.txt","wb");

     }
     else{
    
        printf("...........writing to file\n\n");
     }
     fwrite(&new_customer, sizeof(struct Customer),1,file);
     fclose(file);

     printf("Would you like to add another customer?[Y/N]");
     scanf(" %c", &choice);
    }while (choice== 'y'|| choice== 'Y');

}

// function to show all records
int showrecords(){
  
  char main;
  struct Customer all_customers;
  FILE *file=fopen("customer_data.txt","rb");
     if(file==NULL){
      printf("Error! file not found");
      return 0;
     }
 
//move file pointer to the start of the file
  rewind(file);

  printf("----------All CUSTOMER RECORDS-------------\n\n");
  while (fread(&all_customers,sizeof(struct Customer),1,file)==1)
  {
    printf("\nCustomer ID:%d\n",all_customers.customer_ID);
    printf("Name:%s %s\n",all_customers.first_name,all_customers.second_name);
    printf("Balance:%.2f\n",all_customers.current_balance);
    printf("[credit limit:%.2f]\n",all_customers.credit_limit);
    printf("\n");
    printf("----------------------------------------");

  }
  printf("\n\nWould you like to continue to main menu?[Y/N]");
 scanf(" %c", &main);

     if(main=='y'|| main == 'Y'){
        printf("just a sec.......\n\n");
     }
     else{
        printf("Thank you......program ended");
        exit(0);
     }

}
int main(){

    //program initialization
    int option;


 do{

     printf("\n\n======CREDIT MANAGEMENT SYSTEM======\n\n");
     printf("Press any key to continue.\n\n");
     while((getchar())!='\n');
     getchar();
     printf("continuing the program......\n\n ");
 
     

     printf("\n1.Add customer.\n");
     printf("2.Record payment\n");
     printf("3.View outstanding balance\n");
     printf("4.EXIT\n\n");
     printf("-----Choose one option.-----\n");
    
     
     scanf("%d",&option);

     //option conditions
      if(option==1){
             
             addcustomer();
         }

       else if(option==2){
        //recordpayment();

          }
       else if(option==3){
        showrecords();
         }
       else if(option==4){
        printf("\n\nThank you!.. program ended");
       }

         else{
        printf("Invalid option!! Please try again.");
        }
 
     }while(option!=4);



        return 0;
}