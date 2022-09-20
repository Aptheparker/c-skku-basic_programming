# include <stdio.h> //including input/output library
# include <stdlib.h> //including strlib library
# include <string.h> //including string library
# define Store1 "G25 Store 1" //define names of the stores.
# define Store2 "G25 Store 2"
# define max 100

struct info /*structure: info
             to make a basic structure of info to receive information from data
             name: name of the product
             price: price of the product in won
             quantity: the amount of products in the store
             date: the expire date of the product*/
{
    char name[30];
    int price;
    int quantity;
    int date;
}product[max]; //the variable product to receive information from the data with size 100.

void line(void) /*Function: line
             To create a break horizontal line to design the program
             Return: the long horizontal line*/
{
    printf("======================================================================================================== \n");
}

void welcome(void) /*Function: welcome
                To print the messages to show the list of the choices at the beginning
                Return: the welcome message and the three choices*/
{
    printf("*** Welcome to SKKU Stores Management *** (๑❛ᴗ❛๑) \n");
    line();
    printf("    1. Login as shopkeeper (˶˚ ᗨ ˚˶) \n");
    printf("    2. Search products (⸝⸝ᵕᴗᵕ⸝⸝)♡ \n");
    printf("    3. Exit \n");
    line();
}

int shopkeeper(int *user) /*Function: shopkeeper
                           to receive login and password until they are correct
                           login[30]: the name of the login
                           password[30]: the password received
                           n: the number of trials of login, while loop breaks when it exceeds 3.
                           Return: to give the value of 1 or 2 to the pointer 'user'*/
{
    char login[30], password[30];
    int n=1;
    
    printf("\n*** Shopkeeper Page *** (˶˚ ᗨ ˚˶) \n");
    line();
    while(n!=4)
    {
        printf("Login: ");
        scanf("%s",login);
        printf("Password: ");
        scanf("%s",password);
        if(strcmp(login, "firuz")==0 && strcmp(password, "p@assw0rd")==0)
        {
            *user=1;
            break;
        }
        else if(strcmp(login,"eldor")==0 && strcmp(password, "pAsswOrd")==0)
        {
            *user=2;
            break;
        }
        else
        {
            printf("You have entered wrong login or password (%d/3 trials) \n", n);
            n++;
            continue;
        }
    }
    return 0;
}

void shop(char store[], char keeper[]) /*Function: shop
                                        to print the choices that a shopkeeper can do
                                        Return: printing out the 7 choices.*/
{
    printf("\n*** %s *** \n", store);
    printf("Shopkeeper: %s \n", keeper);
    line();
    printf("    1. Show my products \n");
    printf("    2. Sort products by expire date \n");
    printf("    3. Sort products by price \n");
    printf("    4. Add products \n");
    printf("    5. Remove products \n");
    printf("    6. Edit products \n");
    printf("    7. Log out \n");
    line();
}

void customer(void) /*Function: customer
                 to print the choices that a user can do
                 Return: print out the 4 messages*/
{
    printf("\n*** Customer Page *** (⸝⸝ᵕᴗᵕ⸝⸝)♡ \n");
    line();
    printf("    1. Show all products \n");
    printf("    2. Show all products in dollar \n");
    printf("    3. Search for specific product \n");
    printf("    4. Go to start page \n");
    line();
}

void show(int nproduct) /*Function: show
                         to show the lists of products
                         v: the number for loop
                         c: variable for any key
                         Return: the lists of products in the store.*/
{
    int v;
    char c;
    printf("Product Name             Price                    Quantity                Expire Date \n");
    for(v=0;v<nproduct;v++)
    {
        printf("%-15s          %-15d          %-15d         %d-%d-%d\n",product[v].name, product[v].price, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);
    }
    line();
    printf("\nPress any key to continue");
    scanf("%s",&c);
}

void datesort(int nproduct) /*Function: datesort
                             to sort by expire dates
                             tmp: for the selection sort, to store the temperary arrary
                             v: the number for loop
                             c: variable for any key
                             Return: the lists of proudcts sorted by expire dates.*/
{
    struct info tmp;
    int v;
    char c;
    printf("Products List by Expire Date: \n");
    printf("Product Name             Price                    Quantity                Expire Date \n");
    for (int i = 0; i < nproduct; i++) {
        for (int j = 0; j < nproduct - i - 1; j++)
        {
            if (product[j].date > product[j + 1].date)
            {
                tmp = product[j + 1];
                product[j + 1] = product[j];
                product[j] = tmp;
            }
        }
    }
    for(v=0;v<nproduct;v++)
        printf("%-15s          %-15d          %-15d         %d-%d-%d\n",product[v].name, product[v].price, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);
    printf("\nPress any key to continue");
    scanf("%s",&c);
}

void pricesort(int nproduct) /*Function: pricesort
                              to sort the list of products by price
                              tmp: for the selection sort, to store the temperary arrary
                              v: the number for loop
                              c: variable for any key
                              Return: the lists of proudcts sorted by prices.*/
{
    struct info tmp;
    int v;
    char c;
    printf("Products List by Expire Date: \n");
    printf("Product Name             Price                    Quantity                Expire Date \n");
    for (int i = 0; i < nproduct; i++) {
        for (int j = 0; j < nproduct - i - 1; j++)
        {
            if (product[j].price > product[j + 1].price)
            {
                tmp = product[j + 1];
                product[j + 1] = product[j];
                product[j] = tmp;
            }
        }
    }
    for(v=0;v<nproduct;v++)
        printf("%-15s          %-15d          %-15d         %d-%d-%d\n",product[v].name, product[v].price, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);
    printf("\nPress any key to continue");
    scanf("%s",&c);
}

void adding(int nproduct, FILE *fp) /*Function: adding
                                     to add a new product and its information
                                     c: variable for any key
                                     Return: to fprintf the new product into the file
                                     */
{
    char c;
    printf("Add New Product: ");
    printf("\nProduct Name : ");
    scanf("%s",product[nproduct].name);
    printf("Price(per item): ");
    scanf("%d",&product[nproduct].price);
    printf("Quantity: ");
    scanf("%d",&product[nproduct].quantity);
    printf("Expire Date (YYYYMMDD): ");
    scanf("%d",&product[nproduct].date);
    fprintf(fp,"\n%s %d %d %d",product[nproduct].name, product[nproduct].price, product[nproduct].quantity, product[nproduct].date);
    fclose(fp);
    printf("\nPress any key to continue");
    scanf("%c",&c);
}

void removing(int nproduct, FILE *fp) /*Function: removing
                                       to remove an existed product and its information
                                       v: the number for loop
                                       c: variable for any key
                                       delete: the variable received by the user to be deleted.
                                       Return: delete the chosen product from the file*/
{
    int v, delete;
    char c;
    printf("Products List: \n");
    printf("Product ID          Product Name\n");
    for(v=1;v<=nproduct;v++)
        printf("%-15d     %-15s\n",v, product[v-1].name);
    line();
    while(1)
    {
    printf("Please enter ID to delete:");
    scanf("%d",&delete);
    if(delete>nproduct||delete==0)
        printf("Please choose from the given IDs\n");
    else
        break;
    }
    for(v=0;v<nproduct;v++)
    {
        if(v==delete-1)
            continue;
        else
            fprintf(fp,"%s %d %d %d\n",product[v].name, product[v].price, product[v].quantity, product[v].date);
    }
    fclose(fp);
    printf("\nPress any key to continue");
    scanf("%s",&c);
}

void editing(int nproduct, FILE *fp) /*Function: editing
                                      to edit the product's information chosen by the user.
                                      v: the number for loop
                                      c: variable for any key
                                      edit: the variable received by the user to be edited.
                                      Return: to fprintf the edited information into the file.
                                      */
{
    int v, edit;
    char c;
    printf("\nProducts List: \n");
    printf("Product ID      Product Name          Price                Quantity             Expire Date \n");
    for(v=0;v<nproduct;v++)
        printf("%-5d           %-11s           %-10d           %-10d           %d-%d-%d\n",v+1, product[v].name, product[v].price, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);
    while(1)
    {
    printf("Please enter ID to edit: ");
    scanf("%d",&edit);
    if(edit>nproduct||edit==0)
        printf("Please choose from the given IDs\n");
    else
        break;
    }
    for(v=0;v<nproduct;v++)
    {
        if(v==edit-1){
            printf("Editing Product: ");
            printf("\nProduct Name : ");
            scanf("%s",product[v].name);
            printf("Price(per item): ");
            scanf("%d",&product[v].price);
            printf("Quantity: ");
            scanf("%d",&product[v].quantity);
            printf("Expire Date (YYYYMMDD): ");
            scanf("%d",&product[v].date);
            fprintf(fp,"%s %d %d %d\n",product[v].name, product[v].price, product[v].quantity, product[v].date);}
        else
            fprintf(fp,"%s %d %d %d\n",product[v].name, product[v].price, product[v].quantity, product[v].date);
    }
    fclose(fp);
    printf("\nPress any key to continue");
    scanf("%s",&c);
}

int main() //the main in int
{
    int choice1,choice2,user,nproduct=0,v, num; /*choice1, choice2, user: for if condition
                                                 nproduct: number of product
                                                 num: the choice chosen by the user*/
    int center1, center2, center3, log; //portals: goto the portals
    char store[30], keeper[30], c; /*store and keeper are for checking whcih user and store
                                    c: for receiving a letter to continue*/
    FILE *fp1,*fp2 = NULL; //two files: firuz.txt and eldor.txt
    
    log:
    welcome(); //welcome page and choices
    printf("Enter Your Choice: ");
    scanf("%d",&choice1);
        if(choice1==1) //when login as a shopkeeper
        {
            shopkeeper(&user); //login page, and the pointer user receives value to check if the user is Firuz or Eldor.
            if(user==1) //when the user is Firuz
            {
                strcpy(keeper, "Firuz");
                strcpy(store, Store1);
                center1:
                nproduct=0;
                fp1 = fopen("firuz.txt","rt");
                while(!feof(fp1))
                {fscanf(fp1,"%s %d %d %d\n", product[nproduct].name, &product[nproduct].price, &product[nproduct].quantity, &product[nproduct].date);
                nproduct++;}
                shop(store, keeper); //show the choics that the keeper cann choose
                printf("Enter Your Choice: ");
                scanf("%d", &num); //recive the choice/function
                switch(num)
                {
                    case 1: //to list the products
                        show(nproduct);
                        goto center1;
                        break;
                    case 2: //sort the products by expire date
                        datesort(nproduct);
                        goto center1;
                        break;
                    case 3: //sort the products by price
                        pricesort(nproduct);
                        goto center1;
                        break;
                    case 4: //add new product
                        fp1 = fopen("firuz.txt","a");
                        adding(nproduct, fp1);
                        goto center1;
                        break;
                    case 5: //remove a product
                        fp1 = fopen("firuz.txt","wt");
                        removing(nproduct, fp1);
                        goto center1;
                        break;
                    case 6: //edit a product
                        fp1 = fopen("firuz.txt","wt");
                        editing(nproduct, fp1);
                        goto center1;
                        break;
                    case 7: //log out
                        printf("\n");
                        goto log;
                        break;
                    default: //if not chosen from the given numbers, try again
                        printf("Please choose from the given numbers. \n");
                        goto center1;
                }
            }
            else if(user==2) //when the user is Eldor
            {
                strcpy(keeper, "Eldor");
                strcpy(store, Store2);
                center2:
                nproduct=0;
                fp2 = fopen("eldor.txt","rt");
                while(!feof(fp2))
                {fscanf(fp2,"%s %d %d %d\n", product[nproduct].name, &product[nproduct].price, &product[nproduct].quantity, &product[nproduct].date);
                nproduct++;}
                shop(store, keeper);
                printf("Enter Your Choice: ");
                scanf("%d", &num);
                switch(num)
                {
                    case 1: //to list the products
                        show(nproduct);
                        goto center2;
                        break;
                    case 2: //sort the products by expire date
                        datesort(nproduct);
                        goto center2;
                        break;
                    case 3: //sort the products by price
                        pricesort(nproduct);
                        goto center2;
                        break;
                    case 4: //add new product
                        fp2 = fopen("eldor.txt","a");
                        adding(nproduct, fp2);
                        goto center2;
                        break;
                    case 5: //remove a product
                        fp2 = fopen("eldor.txt","wt");
                        removing(nproduct, fp2);
                        goto center2;
                        break;
                    case 6: //edit a product
                        fp2 = fopen("eldor.txt","wt");
                        editing(nproduct, fp2);
                        goto center2;
                        break;
                    case 7: //log out
                        goto log;
                        break;
                    default: //if not chosen from the given numbers, try again
                        printf("Please choose from the given numbers. \n");
                        goto center2;
                }
            }
        }
        else if(choice1==2) //when login as a customer
        {
            center3:
            customer(); //to show the choices that a customer can choose
            nproduct=0;
            printf("Enter Your Choice: ");
            scanf("%d",&choice2);
            if(choice2==1) //to show all the products
            {
                printf("\nShow all products:\n");
                printf("Product Name       Store Name         Shopkeeper          Price            Quantity        Expire Date \n");
                fp1 = fopen("firuz.txt","rt");
                while(!feof(fp1))
                {fscanf(fp1,"%s %d %d %d\n", product[nproduct].name, &product[nproduct].price, &product[nproduct].quantity, &product[nproduct].date);
                nproduct++;}
                for(v=0;v<nproduct;v++)
                {printf("%-15s    G25 Store 1        Firuz               %-10d       %-8d        %d-%d-%d\n",product[v].name, product[v].price, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);}
                nproduct=0;
                fp2 = fopen("eldor.txt","rt");
                while(!feof(fp2))
                {fscanf(fp2,"%s %d %d %d\n", product[nproduct].name, &product[nproduct].price, &product[nproduct].quantity, &product[nproduct].date);
                nproduct++;}
                for(v=0;v<nproduct;v++)
                {printf("%-15s    G25 Store 2        Eldor               %-10d       %-8d        %d-%d-%d\n",product[v].name, product[v].price, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);}
                printf("\nPress any key to continue");
                scanf("%s",&c);
                goto center3;
            }
            else if(choice2==2) //show the products with dollor price
            {
                printf("\nShow all products:\n");
                printf("Product Name       Store Name         Shopkeeper          Price(dollar)    Quantity        Expire Date \n");
                fp1 = fopen("firuz.txt","rt");
                while(!feof(fp1))
                {fscanf(fp1,"%s %d %d %d\n", product[nproduct].name, &product[nproduct].price, &product[nproduct].quantity, &product[nproduct].date);
                nproduct++;}
                for(v=0;v<nproduct;v++)
                {printf("%-15s    G25 Store 1        Firuz               %-10.2f       %-8d        %d-%d-%d\n",product[v].name, product[v].price/1116.9, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);}
                nproduct=0;
                fp2 = fopen("eldor.txt","rt");
                while(!feof(fp2))
                {fscanf(fp2,"%s %d %d %d\n", product[nproduct].name, &product[nproduct].price, &product[nproduct].quantity, &product[nproduct].date);
                nproduct++;}
                for(v=0;v<nproduct;v++)
                {printf("%-15s    G25 Store 2        Eldor               %-10.2f       %-8d        %d-%d-%d\n",product[v].name, product[v].price/1116.9, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);}
                printf("\nPress any key to continue");
                scanf("%s",&c);
                goto center3;
            }
            else if(choice2==3) //to find specific product
            {
                char letter[3]; //the letter received by the customer
                printf("Search Product (Enter the first letter): ");
                scanf(" %s", letter);
                printf("Results:\n");
                printf("Product Name       Store Name         Shopkeeper          Price            Quantity        Expire Date \n");
                fp1 = fopen("firuz.txt","rt");
                while(!feof(fp1))
                {fscanf(fp1,"%s %d %d %d\n", product[nproduct].name, &product[nproduct].price, &product[nproduct].quantity, &product[nproduct].date);
                nproduct++;}
                for(v=0;v<nproduct;v++)
                {
                    if(strstr(product[v].name, letter))
                       printf("%-15s    G25 Store 1        Firuz               %-10d       %-8d        %d-%d-%d\n",product[v].name, product[v].price, product[v].quantity, product[v].date/10000, product[v].date/100%100,product[v].date%100);
                    else
                       continue;
                }
                nproduct=0;
                fp2 = fopen("eldor.txt","rt");
                while(!feof(fp2))
                {fscanf(fp2,"%s %d %d %d\n", product[nproduct].name, &product[nproduct].price, &product[nproduct].quantity, &product[nproduct].date);
                nproduct++;}
                for(v=0;v<nproduct;v++)
                {
                    if(strstr(product[v].name, letter))
                        printf("%-15s    G25 Store 2        Eldor               %-10d       %-8d        %d-%d-%d\n",product[v].name, product[v].price, product[v].quantity, product[v].date/10000,product[v].date/100%100,product[v].date%100);
                    else
                        continue;
                }
                printf("\nPress any key to continue");
                scanf("%s",&c);
                goto center3;
            }
            else if(choice2==4) //to go back to the main page
            {
                goto log;
            }
            else //when not chosen from the given choices
                printf("Choose from the given numbers!");
                goto center3;
        }
        else if(choice1==3) //exit from the service
        {
            printf("Thank you for using our service! \n");
            exit(0);
        }
        else //when not chosen from choice 1 to 3
        {
            printf("Choose from 1 to 3! \n\n");
            goto log;
        }
    
}
