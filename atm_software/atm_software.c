#include <stdio.h> //insert standard input/output library to start coding
#include <string.h> //insert string.h library to use strcmp function
#define Fb 2000 //defined balance for user 'Firuz'
#define Eb 5000 //defined balance for user 'Eldor'

void loginpage(int *a) //assgin a new function 'loginpage' with pointer '*a'. the value '*a' given from this function will be addressed to the main function.
{
    char username[30], password[30]; //assigm char variable username with length of 30 and char variable password with length of 30.
    
    while (1) //infinite lopp. This loop will not end unless there is a break.
    {
        printf("Login \n"); //print the title: Login
        printf("--------------------------------------------------------------------------\n"); //horizontal line
    
        printf("Username: "); //to ask for and receive the username.
        scanf("%s", username);
        printf("--------------------------------------------------------------------------\n"); //horizontal line
    
        printf("Password: "); //to ask for and receive the password.
        scanf("%s", password);
        printf("--------------------------------------------------------------------------\n"); //horizontal line
    
        if(strcmp(username, "firuz")==0 && strcmp(password, "p@assw0rd")==0) //if the username is "firuz" and the passwod is "p@assw0rd", print "Sucess" and '*a' equals 1. Then break from the while loop.
        {
            printf("Success \n\n");
            *a=1;
            break;
        }
        else if(strcmp(username,"eldor")==0 && strcmp(password, "pAsswOrd")==0) //if the username is "eldor" and the passwod is "pAsswOrd", print "Sucess" and '*a' equals 2. Then break from the while loop.
        {
            printf("Success \n\n");
            *a=2;
            break;
        }
        else //if none of the choices above, print "Wrong!" and continue the while loop again.
        {
            printf("Wrong! \n\n");
            continue;
        }
    }
}

void mainpage() //assign a new function 'mainpage' to show the list of the fucntion of the ATM machine.
{
    printf("1. Check balance (Enter 1); \n");
    printf("2. Withdraw money (Enter 2); \n");
    printf("3. Deposit money (Enter 3): \n");
    printf("4. Check balance(in dollar) (Enter 4); \n");
    printf("5. Last Operation (Enter 5); \n");
    printf("0. Exit (Enter 0); \n");
}

void func(float balance, char user[]) //assign a new function 'func' with the float value 'balance' and the string 'user[]'
{
    int num=1, enter=0; //assign int variable 'num'=1 and 'enter'=0.
    float dollar; //assign float variable 'dollar'.
    char last[30]="No operation yet"; //assign string variable 'last' with length of 30. The initial value is "No operation yet"
    while(num!=0) //while loop: if num==0, the loop ends.
    {
        mainpage(); //to call the function 'mainpage' to show the choices first
        
        scanf("%d", &num); //to receive 'num' and update the new value to 'num'
    
        switch(num) //using switch and check the value of the 'num'
        {
            case 1: //if 'num' is 1, show the user's name and the amount of balance. Then update the 'late' to "Check balance" and break.
                printf("User: %s \n", user);
                printf("Balance: %.1f \n\n", balance);
                strcpy(last,"Check balance");
                break;
            case 2: //if 'num' is 2, receive 'enter', the value of the amount of money to withdraw.
                printf("Enter amount: ");
                scanf("%d", &enter);
                if(enter <= balance) //if the value of 'enter' is smaller than 'balance', 'balance' minus the amount of 'enter' and show the amount of balance left. Then update the 'late' to "Withrawal". Else if the value of 'enter' is larger than 'balance'. print "Withdrawal exceeded account balance.". After either choice, break.
                {
                    balance-=enter;
                    printf("Balance: %.1f \n\n", balance);
                    strcpy(last,"Withdrawal");
                }
                else
                {
                    printf("Withdrawal amount exceeded account balance. \n\n");
                }
                break;
            case 3: //if 'num' is 3, receive 'enter', the value of the amount of money to deposit. Then 'balance' plus the amount of 'enter' and print the amount of balance updated. Finally, update the 'late' to "Deposit" and break.
                printf("Enter amount: ");
                scanf("%d", &enter);
                balance+=enter;
                printf("Balance: %.1f \n\n", balance);
                strcpy(last,"Deposit");
                break;
            case 4: //if 'num' is 4, let 'dollar' equals 'balance' divided by 1115.5 and print the amount of 'balance' in dollar. Then update the 'late' to "Check balance in dollar" and break.
                dollar = balance/1115.5;
                printf("balance (in dollar): %.2f \n\n", dollar);
                strcpy(last,"Check balance in dollar");
                break;
            case 5://if 'num' is 5, print the 'user', 'balance', 'last' and break.
                printf("Name: %s \n", user);
                printf("Current Balance: %.1f \n", balance);
                printf("Last Operation: %s \n\n", last);
                break;
            case 0: //if 'num' is 0, print "Thank you for banking with us!" and break. Because 'num' equals 0, end theb while loop(Exit).
                printf("Thank you for banking with us! \n\n");
                break;
            default: //if 'num' is not in the mainpage list, print "Please choose from the given numbers.".
                printf("Please choose from the given numbers. \n\n");
        }
    }
}

int main() //main function
{
    int a, balance; // a: identify user, balance: the amount of balance the user has
    char user[10]; // the name of the user
    
    loginpage(&a); //to call the function 'loginpage', and &a is an address received from the function to identify the user.
    
    if(a==1) //If the identifier a given from the loginpage is 1, then print the  user name "Firuz" and assin balance as 2000. Else the a would be 2, then print the user name "Eldor" and assign balance as 5000.
    {
        strcpy(user, "Firuz");
        balance=Fb;
    }
    else
    {
        strcpy(user, "Eldor");
        balance=Eb;
    }
    
    func(balance, user); //to call the function 'func' with the balance value and the user name.
    return 0; //end of the int main(), returning value to 0
}
