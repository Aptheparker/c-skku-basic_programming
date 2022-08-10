#include <stdio.h>
#include <stdlib.h> //including strlib library
#include <string.h> //including string library
#define size 30

void line(void) /* For design: To create a break horizontal line.
                 To promote efficiency*/
{
    printf("======================= \n");
}

int Login(int *user) /*to receive id and password, if the trials exceed 3, then exit the program*/
{
    char id[size], password[size];
    int trial=1;
    
    printf("\n*** SUBWAY Login *** \n");
    line();
    while(trial!=4) //while loop only for 3 trials
    {
        printf("Login: ");
        scanf("%s",id);
        printf("Password: ");
        scanf("%s",password);
        
        if(strcmp(id, "firuz")==0 && strcmp(password, "p@ssw0rd")==0)
        {
            *user=1; //give the value 1 to pointer user
            break;
        }
        else
        {
            printf("You have entered wrong login or password (%d/3 trials) \n", trial);
            trial++;
            continue;
        }
    }
    return 0;
}

void options(void) /*To show the lists of functions to show the list of the choices at the beginning.*/
{
    printf("*** Welcome to SUBWAY *** \n");
    line();
    printf("    1. New order \n");
    printf("    2. Total revenue\n");
    printf("    3. Recommended Menu\n");
    printf("    0. Exit \n");
    line();
}

int Sandwich(int *sandwich) /*To show lists of sandwiches and let the user choose, and give the price value to the pointer*/
{
    int choice;
    printf("*** New Order - Sandwich *** \n"); //show the lists
    line();
    printf("1. Egg Mayo - 4000\n");
    printf("2. Egg & Cheese - 4500\n");
    printf("3. Chicken Tikka - 5000 \n");
    printf("4. Roasted Chicken - 5500 \n");
    printf("5. Chicken Ham - 5000\n");
    printf("0. Exit \n");
    line();
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            *sandwich=4000;
            break;
        case 2:
            *sandwich=4500;
            break;
        case 3:
            
            *sandwich=5000;
            break;
        case 4:
            *sandwich=5500;
            break;
        case 5:
            *sandwich=5000;
            break;
        case 0:
            break;
        default:
            printf("Error \n");
            break;
    }
    return 0;
}

int Bread(int *bread) /*To show lists of breads and let the user choose, and give the price value to the pointer*/
{
    int choice;
    printf("*** New Order - Bread Type *** \n");
    line();
    printf("1. Honey Oat - (+100)\n");
    printf("2. Italian Bread - (+150)\n");
    printf("3. Flatbread - (+200) \n");
    printf("4. Monterey Cheddar - (+150) \n");
    printf("5. Grain Wheet - free\n");
    printf("0. Exit \n");
    line();
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            *bread=100;
            break;
        case 2:
            *bread=150;
            break;
        case 3:
            *bread=200;
            break;
        case 4:
            *bread=150;
            break;
        case 5:
            *bread=0;
            break;
        case 0:
            break;
        default:
            printf("Error \n");
            break;
    }
    return 0;
}

int Cheese(int *cheese) /*To show lists of cheese and let the user choose, and give the price value to the pointer*/
{
    int choice;
    printf("*** New Order - Cheese Type *** \n");
    line();
    printf("1. American Cheese - (+150)\n");
    printf("2. Cheddar - (+100)\n");
    printf("3. Mozzarella - (+100) \n");
    printf("0. Exit \n");
    line();
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            *cheese=150;
            break;
        case 2:
            *cheese=100;
            break;
        case 3:
            *cheese=100;
            break;
        case 0:
            break;
        default:
            printf("Error \n");
            break;
    }
    return 0;
}

int Extra(int *tomato, int *cucumber, int *mayonnaise) /* show lists of vegetables and extra ingredients and let the user choose(y/n), and give the price value to the pointers*/
{
    char choice1[2], choice2[2], choice3[2];
    printf("*** New Order - Vegetables *** \n");
    line();
    printf("Do you want Tomatoes with 50 won extra charge (y/n)? \n");
    line();
    printf("Enter Your Choice: ");
    scanf("%s", choice1);
    if(strcmp(choice1, "y")==0)
        *tomato=50;
    else
        *tomato=0;
    
    printf("\n*** New Order - Vegetables *** \n");
    line();
    printf("Do you want Cucumberss with 50 won extra charge (y/n)? \n");
    line();
    printf("Enter Your Choice: ");
    scanf("%s", choice2);
    if(strcmp(choice2, "y")==0)
        *cucumber=50;
    else
        *cucumber=0;
    
    printf("\n*** New Order - Extra *** \n");
    line();
    printf("Do you want Mayonnaise with 50 won extra charge (y/n)? \n");
    line();
    printf("Enter Your Choice: ");
    scanf("%s", choice3);
    if(strcmp(choice3, "y")==0)
        *mayonnaise=50;
    else
        *mayonnaise=0;
    return 0;
}

int Reciept(int a, int b, int c, int d, int e, int f, int *total) /*to show the receipt of the ordered menu. and store the total revenue to the pointer: total*/
{
    printf("*** New Order - Reciept *** \n");
    line();
    printf("Sandwich - %d\n", a);
    printf("Bread - %d\n", b);
    printf("Cheese - %d\n", c);
    printf("Tomatoes - %d\n", d);
    printf("Cucumbers - %d\n", e);
    printf("Mayonnaise - %d\n", f);
    *total=a+b+c+d+e+f;
    printf("TOTAL: %d Won\n", *total);
    line();
    
    return 0;
}

void Recommend(void) /*to show the lists of recommended menu and combinations*/
{
    printf("Recommended Menu: \n");
    line();
    printf("Recommended combination: 1. Chicken Ham & Flatbread & Mozarella \n");
    printf("Recommended combination: 2. Chicken Tikka & Honey Oat & Cheddar \n");
    printf("Best Seller: 'CFA(Chicken Ham-Flatbread-American Cheese)' \n");
    line();
}

int main()
{
    int user=0, choice, sandwich=0, bread=0, cheese=0, tomato=0, cucumber=0, mayonnaise=0, total=0, TR=0; //the variables: total=total price, TR= total revenue
    char main[2]; //for receiving value to continue
    Login(&user); //login page
    if(user==0) //when failed to login
        exit(0);
    while(1) //start loop
    {
    options(); //show the lists of function
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    if(choice==1) //new order
    {
        Sandwich(&sandwich);
        Bread(&bread);
        Cheese(&cheese);
        Extra(&tomato, &cucumber, &mayonnaise);
        Reciept(sandwich,bread, cheese, tomato, cucumber, mayonnaise, &total);
        TR=TR+total; //accumulate TR
        printf("Enter 0 to go main menu:");
        scanf("%s", main);
        continue;
    }
    else if(choice==2) //TR
    {
        line();
        printf("Total Revenue (Won): %d\n", TR);
        line();
        printf("Enter 0 to go main menu:");
        scanf("%s", main);
        continue;
    }
    else if(choice==3) //recommended menu
    {
        Recommend();
        printf("Enter 0 to go main menu:");
        scanf("%s", main);
        continue;
    }
    else //exit
        printf("Thank you for using our program!\n");
        break;
    }
    return 0;
}
