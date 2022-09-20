# include <stdio.h> //input/output library
# include <stdlib.h> //strlib library
# include <string.h> //string library
# define size 30 //defining the maximum size for the products for each file.

struct delivery/*the struct name is deliver*/
{
    int num;
    char sender[30];
    int amount;
    char city[30];
    char address[50];
    long long contact;
}product[size], product1[size], product2[size]; /*product to receive information  with size 30.
                                                 product: for delivery.txt
                                                 product1: for approved.txt
                                                 product2: for completed.txt*/

void line(void) /*to make the lines automatically, for efficiency*/
{
    printf("==================== \n");
}

void firstpage(void) /*lists the messages and the choices to the user*/
{
    printf("*** Welcome to SKKU Delivery ***\n");
    line();
    printf("    1. Enter as a user\n");
    printf("    2. Login as admin\n");
    printf("    0. Exit \n");
    line();
}

void userpage(void) /*lists the choices that a user can choose*/
{
    printf("\n*** SKKU Delivery Service ***\n");
    line();
    printf("    1. Register new delivery \n");
    printf("    2. Check delivery status \n");
    printf("    3. Information Desk \n");
    printf("    0. Exit \n");
    line();
}

void New(int number, int regisnum, FILE *fp)//to create new deliver order into the delivery.txt
{
    char confirm[2]; //for receiving confirm message
    printf("Registration Number: %d\n", regisnum);
    line();
    printf("Sender Name: "); //to receive the input to the struct
    scanf("%s",product[number].sender);
    printf("Delivery amount (in kg): ");
    scanf("%d",&product[number].amount);
    printf("Destination City: ");
    scanf("%s",product[number].city);
    printf("Detailed address: ");
    scanf("%s",product[number].address);
    printf("Contact of receiving person: ");
    scanf("%lld",&product[number].contact);
    printf("Confirm your request (y/n): ");
    scanf("%s",confirm);
    if(strcmp(confirm, "y")==0)
    {fprintf(fp,"\n%d %s %d %s %s %lld",regisnum, product[number].sender, product[number].amount, product[number].city, product[number].address, product[number].contact);}
    fclose(fp);
}

void Status(FILE *fp1, FILE *fp2, FILE *fp3) //to check if the product delivery is not approved, approved, or completed.
{
    int choice, v, checker=0; //choice: receive from user, v: for loop, checker: to check if there's the input numer in the files
    printf("*** Delivery Status ***\n");
    line();
    printf("Enter registration number of delivery: ");
    scanf("%d",&choice);
    line();
    for(v=0;v<30;v++) //for loop
    {
        if(product[v].num == choice) //in delivery.txt
        {
            printf("Registration Number: %d\n", choice);
            printf("Status: Not Approved\n");
            checker=1; //to check if there's the info in the file
            break;
        }
        else if(product1[v].num == choice) //in approved.txt
        {
            printf("Registration Number: %d\n", choice);
            printf("Status: Approved\n");
            checker=1;
            break;
        }
        else if(product2[v].num == choice) //in completed.txt
        {
            printf("Registration Number: %d\n", choice);
            printf("Status: Completed\n");
            checker=1;
            break;
        }
    }
    if(checker==0) //if not included in any
    {
        printf("There is no such delivery. Sorry (\n");
    }
    line();
}

void infodesk(void) //to print the infodesk message
{
    printf("*** SKKU Delivery Service Info Desk ***\n");
    line();
    printf("For registering new delivery, you will enter kg of the parcel, if your parcel is less than 1kg, enter 1 and if it is less than 2 and more than 1, enter 2 and so on.\n");
    printf("For city and detailed address, please try to give exact and correct information.\n");
    line();
    printf("Checking status of delivery:\n");
    printf("If the status is Not approved, it means the administrator has not seen your request yet.\n");
    printf("If the status is Approved, it means the administrator has seen your request and it is on progress now.\n");
    printf("If the status is Completed, it means your deliver is completed successfully.\n");
    line();
}

int Login(void) //the login page. It will give 3 chances
{
    char id[30], password[30]; //id and password
    int n=1; //for loop
    
    printf("\n*** Administration Page - Login ***\n");
    line();
    while(n!=4) //the trial does not exceed 3 times
    {
        printf("Login: ");
        scanf("%s",id);
        printf("Password: ");
        scanf("%s",password);
        if(strcmp(id, "firuz")==0 && strcmp(password, "p@ssw0rd")==0) //check if the id and password matches
            break;
        else
        {
            printf("You have entered wrong login or password (%d/3 trials) \n", n);
            n++;
            continue;
        }
    }
    if(n==4) //if exceed 3 trials, exit
        exit(0);
    return 0;
}

void adminpage(void) /*to print the adminpage's choices*/
{
    printf("\n*** Administration Page *** \n");
    printf("    Admin: Firuz \n");
    line();
    printf("    1. New requests for delivery\n");
    printf("    2. Not completed deliveries\n");
    printf("    3. Completed deliveries\n");
    printf("    4. Show all deliveries (requested, approved, not pproved)\n");
    printf("    0. Exit\n");
    line();
}

void AdminNew(int number, FILE *fpfirst, FILE *fpsecond) //to show the lists of the delivery.txt and then choose one product to approve
{
    int v, choice, checker=0; //v: for loop, choice: input by user, checker: to check if the input is in the file
    char confirm[2];
    
    line();
    printf("Registration number    Sender    Destination    Receiver contact\n");
    for(v=0;v<number;v++) //for loop to print out the list in the file.
    {
        printf("%-13d          %-5s     %-10s     %-2lld\n", product[v].num, product[v].sender, product[v].city, product[v].contact);
    }
    line();
    while(1)
    {
    choice=0;
    printf("Enter Registration number for processing or 0 to exit: ");
    scanf("%d", &choice);
    if(choice==0) //if choice is 0, break
        break;
    for(v=0;v<number;v++) //check if in the file
    {
        if(product[v].num == choice)
        {
            checker=1;
            break;
        }
        else
            checker=2;
    }
    if(checker==1) //if in the file
    {
        printf("Will you approve request (y/n)?: "); //confirm
        scanf("%s", confirm);
        if(strcmp(confirm, "y")==0)
        {
            for(v=0;v<number;v++)
            {
                if(product[v].num == choice) //the chosen product approved
                {fprintf(fpsecond,"\n%d %s %d %s %s %lld", product[v].num, product[v].sender, product[v].amount, product[v].city, product[v].address, product[v].contact);}
                else //stay
                {fprintf(fpfirst,"%d %s %d %s %s %lld\n", product[v].num, product[v].sender, product[v].amount, product[v].city, product[v].address, product[v].contact);}
            }
        }
        else
        {for(v=0;v<number;v++){fprintf(fpfirst,"%d %s %d %s %s %lld\n", product[v].num, product[v].sender, product[v].amount, product[v].city, product[v].address, product[v].contact);}}
    }
    else //not included in the delivery
        printf("Wrong registration number.\n");
    }
    fclose(fpfirst);
    fclose(fpsecond);
}

void AdminNotCompleted(int number, FILE *fpfirst, FILE *fpsecond) // to show the lists in the approved.txt. Then choose the regisnum to complete the delivery. the program is very similar to the previous function.
{
    int v, choice, checker=0;
    char confirm[2];
    
    line();
    printf("Registration number    Sender    Destination    Receiver contact\n");
    for(v=0;v<number;v++)
    {
        printf("%-13d          %-5s     %-10s     %-2lld\n", product1[v].num, product1[v].sender, product1[v].city, product1[v].contact);
    }
    line();
    while(1)
    {
    choice=0;
    printf("Enter Registration number for processing or 0 to exit: ");
    scanf("%d", &choice);
    if(choice==0)
        break;
    for(v=0;v<number;v++)
    {
        if(product1[v].num == choice)
        {
            checker=1;
            break;
        }
        else
            checker=2;
    }
    if(checker==1)
    {
        printf("Will you complete request (y/n)?: ");
        scanf("%s", confirm);
        if(strcmp(confirm, "y")==0)
        {
            for(v=0;v<number;v++)
            {
                if(product1[v].num == choice)
                {fprintf(fpsecond,"\n%d %s %d %s %s %lld", product1[v].num, product1[v].sender, product1[v].amount, product1[v].city, product1[v].address, product1[v].contact);}
                else
                {fprintf(fpfirst,"%d %s %d %s %s %lld\n", product1[v].num, product1[v].sender, product1[v].amount, product1[v].city, product1[v].address, product1[v].contact);}
            }
        }
        else
        {for(v=0;v<number;v++){fprintf(fpfirst,"%d %s %d %s %s %lld\n", product1[v].num, product1[v].sender, product1[v].amount, product1[v].city, product1[v].address, product1[v].contact);}}
    }
    else
        printf("Wrong registration number.\n");
    }
    fclose(fpfirst);
    fclose(fpsecond);
}

void Completed(int number, FILE *fp) //to show the lists of the completed requests of the delivery, and then show the detailed information of the chosen products.
{
    int choice, v, checker, choice1; //choice: input by user. v: for loop, checker: to check if it is in the list.
    while(1)
    {
        line();
        printf("Registration number    Sender    Destination    Receiver contact\n");
        for(v=0;v<number;v++)
        {
            printf("%-13d          %-5s     %-10s     %-2lld\n", product2[v].num, product2[v].sender, product2[v].city, product2[v].contact);
        }
        line();
        port:
        printf("Enter Registration number for processing or 0 to exit: ");
        scanf("%d", &choice);
        if(choice==0) //if not in the file, break
            break;
        checker=1;
        for(v=0;v<number;v++) //check if in the file
        {
            if(product2[v].num == choice)
            {
                printf("Registration Number: %d\n",product2[v].num);
                line();
                printf("Sender name: %s\n",product2[v].sender);
                printf("Delivery amount(in kg): %d\n",product2[v].amount);
                printf("Destination City: %s\n",product2[v].city);
                printf("Detailed address: %s\n",product2[v].address);
                printf("Contact of receiving person: %lld\n",product2[v].contact);
                line();
                checker=0;
                break;
            }
        }
        if(checker==1) //when input wrong number
            printf("Wrong registration number.\n");
        printf("Enter 0 to go back list of completed deliveries: ");
        scanf("%d", &choice1);
    }
}
void Showall(int number, int number1, int number2,  FILE *fp1, FILE *fp2, FILE *fp3) /*Extra function*/
//to show all the deliveries(requested, approved, completed)
{
    int v, choice; //v: for loop, choice: for receiving message
    line();
    printf("Registration number    Sender    Destination    Receiver contact\n");
    printf("Requested: \n");
    for(v=0;v<number;v++)
    {
        printf("%-13d          %-5s     %-10s     %-2lld\n", product[v].num, product[v].sender, product[v].city, product[v].contact);
    }
    printf("Approved: \n");
    for(v=0;v<number1;v++)
    {
        printf("%-13d          %-5s     %-10s     %-2lld\n", product1[v].num, product1[v].sender, product1[v].city, product1[v].contact);
    }
    printf("Completed: \n");
    for(v=0;v<number2;v++)
    {
        printf("%-13d          %-5s     %-10s     %-2lld\n", product2[v].num, product2[v].sender, product2[v].city, product2[v].contact);
    }
    line();
    printf("Enter 0 to go back to the main menu: ");
    scanf("%d", &choice);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
int main() //the main function
{
    FILE *fp1, *fp2, *fp3; //file pointers
    int choice,userchoice,zero=1,number=0, number1=0, number2=0, num, regisnum=1;
    int port1, port2, main; //portals
    main:
    firstpage(); //the firstpage is printed
    printf("Enter Your Choice: ");
    scanf("%d",&choice);
    if(choice==1) //when login as a customer
    {
        port1:
        number=0;
        number1=0;
        number2=0;
        fp1 = fopen("delivery.txt","rt"); //to read the delivery file into the fp1
        while(!feof(fp1))
        {fscanf(fp1,"%d %s %d %s %s %lld\n",&product[number].num, product[number].sender, &product[number].amount, product[number].city, product[number].address, &product[number].contact);
        number++;}
        fp2 = fopen("approved.txt","rt"); //to read the delivery file into the fp2
        while(!feof(fp2))
        {fscanf(fp2,"%d %s %d %s %s %lld\n",&product1[number1].num, product1[number1].sender, &product1[number1].amount, product1[number1].city, product1[number1].address, &product1[number1].contact);
        number1++;}
        fp3 = fopen("completed.txt","rt"); //to read the delivery file into the fp3
        while(!feof(fp3))
        {fscanf(fp3,"%d %s %d %s %s %lld\n",&product2[number2].num, product2[number2].sender, &product2[number2].amount, product2[number2].city, product2[number2].address, &product2[number2].contact);
        number2++;}
        regisnum=number+number1+number2+1; //counting the registration number.
        number=0;
        userpage(); //show the choices that a user can choose
        printf("Enter Your Choice: ");
        scanf("%d",&userchoice);
        switch(userchoice)
        {
            case 1: //new delivery
                fp1 = fopen("delivery.txt","a");
                New(number, regisnum, fp1); //using the function with the regisnum
                goto port1;
            case 2: //check delivery status
                Status(fp1, fp2, fp3);
                printf("Enter 0 to exit: ");
                scanf("%d",&zero);
                while(zero!=0)
                {
                    printf("Enter 0 to exit: ");
                    scanf("%d",&zero);
                }
                goto port1;
            case 3: //infodesk
                infodesk();
                printf("Enter 0 to exit: ");
                scanf("%d",&zero);
                while(zero!=0)
                {
                    printf("Enter 0 to exit: ");
                    scanf("%d",&zero);
                }
                goto port1;
            case 0: //Exit
                printf("Thank you for choosing us!\n");
                exit(0);
            default: //if not chosen from the given numbers, try again
                printf("Please choose from the given numbers. \n");
                goto port1;
        }
    }
    else if(choice==2) //Login as admin
    {
        Login(); //
        port2:
        number=0; //reset number of lists in fp1.
        number1=0; //reset number of lists in fp2.
        number2=0; //reset number of lists in fp3.
        fp1 = fopen("delivery.txt","rt");
        while(!feof(fp1)) //open the file...
        {fscanf(fp1,"%d %s %d %s %s %lld\n",&product[number].num, product[number].sender, &product[number].amount, product[number].city, product[number].address, &product[number].contact);
        number++;}
        fp2 = fopen("approved.txt","rt");
        while(!feof(fp2))
        {fscanf(fp2,"%d %s %d %s %s %lld\n",&product1[number1].num, product1[number1].sender, &product1[number1].amount, product1[number1].city, product1[number1].address, &product1[number1].contact);
        number1++;}
        fp3 = fopen("completed.txt","rt");
        while(!feof(fp3))
        {fscanf(fp3,"%d %s %d %s %s %lld\n",&product2[number2].num, product2[number2].sender, &product2[number2].amount, product2[number2].city, product2[number2].address, &product2[number2].contact);
        number2++;}
        adminpage();
        printf("Enter Your Choice: ");
        scanf("%d", &num); //recive the choice
        switch(num)
        {
            case 1: //new requests for delivery
                fp1 = fopen("delivery.txt","wt");
                fp2 = fopen("approved.txt","a");
                AdminNew(number, fp1, fp2);
                goto port2;
            case 2: //not completed deliveries
                fp2 = fopen("approved.txt","wt");
                fp3 = fopen("completed.txt","a");
                AdminNotCompleted(number1, fp2, fp3);
                goto port2;
            case 3: //completed deliveries
                Completed(number2, fp3);
                goto port2;
            case 4: //show all
                Showall(number, number1, number2, fp1, fp2, fp3);
                goto port2;
            case 0: //exit
                printf("Thank you for choosing us!\n");
                exit(0);
            default: //if not chosen from the given numbers, try again
                printf("Please choose from the given numbers. \n");
                goto port2;
        }
    }
    else if(choice==0) //exit from the first page
    {
        printf("Thank you for choosing us!\n");
        exit(0);
    }
    else //if not chosen from 1 to 3
    {
        printf("Please choose from 1 or 2 or 0 \n\n");
        goto main;
    }
}
