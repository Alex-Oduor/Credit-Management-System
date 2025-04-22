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



//function to add new customer
void addcustomer(){
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

//function to search record
void search(){
   int search_id;
   int found=0;
   struct Customer cust;
   printf("Enter Customer ID to search:");
   scanf("%d,&search_id");

   FILE*file=fopen("customer_data.txt","r");
   if(file==NULL){
      printf("Error!Could not open file.\n");
      return ;
   }
   while(fread(&cust,sizeof(struct Customer),1, file) ==1){
      if(cust.customer_ID == search_id){
         printf("\nRecordFound:\n");
         printf("Customer ID: %d\n", cust.customer_ID);
         printf("Name:%s %s\n",cust.first_name, cust.second_name);
         printf("credit Limit:%.2f\n",cust.credit_limit);
         printf("Current Balance: %.2f\n",cust.current_balance);
         found=1;
         break;
      }
   }
   if(!found){
      printf("Customer with ID %d not found.\n",search_id);
   }
   fclose(file);

   char back;
   printf("\nReturn to main menu?[Y/N]");
   scanf("%c",&back);
   if(back=='N' ||back=='n'){
      printf("Program exited.\n");
      exit(0);
   }
   

}

// function to show all records
void showrecords(){
  
  char main;
  struct Customer all_customers;
  FILE *file=fopen("customer_data.txt","rb");
     if(file==NULL){
      printf("Error! file not found");
      return 0;
     }
 

  rewind(file);//move file pointer to the start of the file

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

//function to delete record
void deleterecord(){
   char choice;

do{
       int id;
   
       printf("Enter customer ID you want to remove:");
        scanf("%d",&id);

       struct Customer newcustomer;
       int found=0;
       FILE *file, *temp;
   
       file=fopen("customer_data.txt","rb");
        temp=fopen("tempfile.txt", "wb");

       if(file==NULL || temp==NULL){
        printf("Error: %s",strerror(errno));
        return ;
        }

         while(fread(&newcustomer, sizeof(struct Customer),1,file))
           {
              if(newcustomer.customer_ID !=id){
             fwrite(&newcustomer,sizeof(struct Customer),1,temp);
               }
             else{
              found=1;
             }
            }

       fclose(file);
        fclose(temp);

      if(found){
      remove("customer_data.txt");
      rename("tempfile.txt","customer_data.txt");
       printf("Record deleted successfully\n\n");
       }
        else{
        remove("tempfile.txt");
        printf("Customer with %d not found\n\n",id);
       }

        printf("Would you like to remove another record?[Y/N]");
        scanf(" %c", &choice);


   }while (choice=='y' || choice=='Y');
   
   //function to record payments
}
void recordpayments(){
   int id, found = 0;
   float payment ;
   char again;

   do{
      printf("Enter customer ID to record payments:");
      scanf("%d",&id);

      FILE *file = fopen("customer_data.txt","rb");
      FILE *temp = fopen("tempfile.txt","wb");

      if (file ==NULL || temp == NULL){
         printf("Error opening file .\n");
         return ;
      }
      struct Customer cust;
      while (fread(&cust, sizeof(struct customer),1,file) == 1){
         if (cust . customer_ID == id){
            printf("Customer found :%s %s\n", cust.first_name,cust.second_name);
            printf("Current balance: %.2f\n",cust.current_balance);
            printf("Enter payment amount :");
            scanf("%f", &payment);

            if (payment > cust.current_balance ){
               printf("Payment exceeds current balance .Try again.\n");
            }
            else{
               cust.current_balance  -=payment;
               printf("Payment recorded. New balance:%.2f\n", cust.current_balance);

            }
            found = 1;
         }
         fwrite(&cust, sizeof(struct customer),1,temp);

      }
      fclose(file);
      fclose(temp);

      if (found){
         remove("customer_data.txt");
         rename("tempfile.txt","customer_data.txt");
      }else{
         remove("tempfile.txt");
         rename("customer with ID %d not found.\n", id);
      }
      printf("Record another payment ? [Y/N]: ");
      scanf("%c", &again);
   }while(again == 'y' || again == 'Y');
}


//function to record payment

int main(){

    //program initialization
    int option;


 do{

     printf("\n\n======CREDIT MANAGEMENT SYSTEM======\n\n");
     printf("Press any key to continue.\n\n");
     while((getchar())!='\n');

     printf("continuing the program......\n\n ");
 
     

     printf("\n1.Add customer.\n");
     printf("2.Record payment\n");
     printf("3.View all records\n");
     printf("4.search record\n");
     printf("5.Delete record\n");
     printf("6.EXIT\n\n");
     printf("-----Choose one option.-----\n");
    
     
     scanf("%d",&option);

     //option conditions
      if(option==1){
             
             addcustomer();
         }

       else if(option==2){
         recordpayment();

          }
      else if(option==3){
         showrecords();
    
            }
      else if(option==4){
               search();
       
             }
      else if(option==5){
            deleterecord();
          
            }
       
       else if(option==6){
        printf("\n\nThank you!.. program ended");
       }

         else{
        printf("Invalid option!! Please try again.");
        }
 
     }while(option!=6);



        return 0;
}