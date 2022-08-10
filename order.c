#include <stdio.h>
#include <stdlib.h>
#define N 30
#define menu2 printf("\nPizza\n1. cheese    7000\n2. seafood   10000\n\nPasta\n3. tomato   5000\n4. cream    5500\n\nDrink\n5. Coke    1000\n6. sprite  1000\n");
/*
void dash: it is used when there is error (enter wrong number)


void line: emphasize letter by -.it can control length

void cal: calculate rest and print them.
           it is used when paid money is less than charge to know how much the money have to be paid.
void rush: calculating money of order menu.it is used in making bill
void main: main code in this assignment i will explain this code in under"//"   */
void dash();
void line(int len);
void cal(int P,int Q,int R);
void rush(int A,int B);
void main()
{
    int c,num,menu,bill,exit,main,r1,re2;//num is number which is chosen in first decision(order,bill,exit),menu,bill,exit,main,r1,r2  is loop point in goto function.
    int lc = 1;
    int arr;
    int a[30];
    int b[30];
    int k = 0;
    int p = 0;
    int mon,rest;
    int next;
    int tn = 1;
    int wn ;
    int sum[N];
    int price[7] = {0,7000,10000,5000,5500,1000,1000};//array of price char
    char food[7][20] ={"x","cheese ","seefood","tomato "," cream ","Coke","sprite"} ;//array of menu char

    main:
    line(7);
    printf("1.Create new order.\n\n\n2.Show bill.\n\n\n3.Exit\n\n");// first choose option
    line(7);
    printf("enter number:   ");
    scanf("%d",&num);
   switch(num)// if you choose 1 or 2 goto loop point
   {
   case 1:
    goto menu;
   case 2:
    goto bill;
   case 3:

    while(lc<=tn){


    if(sum[lc]!=0){
        printf("\n\Here is unpaid table number %d \n the cost to be paid for table %d : %d",lc,lc,sum[lc]);// case 3 is end of order. if there are table which is unpaid it will announce to you



    }
    if(lc=tn){if(sum[lc]!=0){
        printf("\n\Here is unpaid table number %d \n the cost to be paid for table %d : %d",lc,lc,sum[lc]);
    printf("\n\n\ Thank you for visiting!!\n\n");}
}
    lc=lc+1;}


   }
if(num>=4){
    if(num!=0){
        dash();
        goto main;
    }}




    menu:// this is loop point when you choose 1 in first option.


    sum[1]=0;

    for(tn=1;tn<<20;tn++)// using for function we can divide table number> table1,table2,table3....table 20
    {menu2
         printf("\n\if you want to end order, please enter\'\ 0 \'\ \n ");
        while(3) //because of while function. it will repeatedly take your order. when you enter 0 because of break; it will go to next step.
    {k=k+1;
        printf("\n\please  input food number what you want:   ");
    scanf("%d",&a[k]);
    fflush(stdin);

    if(a[k]==0){break;}//when you enter 0 because of break; it will go to next step.

    printf("\n\please input quantity what you want   ");
    scanf("%d",&b[k]);
    fflush(stdin);
     printf("\n\your order is \"\%s\"\ and quantity is  \"\%d\"\n",food[a[k]],b[k]);// check order what you entered.
    sum[tn] = sum[tn] + price[a[k]]*b[k];}

            printf("\n\n\n\ your table number is \'\%d\'\.use table number while paying bill.\n",tn);// they announce table number. it is used in paying cost.
            line(5);
            printf("menu         quantity     price\n\n");// they announce what you ordered in form of receipt
            while(p<k-1){p=p+1;

    printf("%s ",food[a[p]]);
    //arr =  strlen(food[a[p]]);
     while(arr<12){// it is used  when i make form.Because the letter array was different,it was used to all order be arranged.
            arr=arr+1;
    printf(" ");
    }
    rush(price[a[p]],b[p]);


        fflush(stdin);
    }
    printf("\n\Total cost:  \'\%d\'\n",sum[tn]);// announce money to be paid.
    re2:
            line(5);
            printf("\nFurther option\n\n1. check your bill\n\n2. go to main menu \n");
            line(5);
            scanf("%d",&c);






    if(c==1){
        while(c==1)
       {bill://loop point if you want take a bill
           line(7);
        printf("  please enter the table number to see bill\n\n  (if you want to back main please enter 0)");
        line(7);
        scanf("%d",&wn);
        if(wn==0){goto main;}
        else if(tn<wn){printf("There is no charge for table\n please input table number again");// if there are no charge in table.We should enter number again.
                        continue;}


        printf("the cost is : %d \n please enter the money:  ",sum[wn]);
        r1:
        scanf("%d",&mon);
        printf("%d",mon);
        if(mon==sum[wn]){sum[wn]= 0;
                printf("\nThank you! The order is paid successfully.\n");
                          }// ordered successfully


        if(mon>=sum[wn]){printf("\nhere is your change\n");}// if paid money is more than charge, change is exist
        else{line(5);
                printf("Alert!!\n\nn\money is short to make a charge.\n\please enter rest money  please!!\'\n");// if paid money is less than bill, you have to pay rest of money
        line(5);
        cal(rest,sum[wn],mon);
            sum[wn]=sum[wn]-mon;
            printf("you have to enter %d to make order\n\please enter money  :",sum[wn]);


        goto r1;
        }

        }

    }
    if(c==2){sum[tn+1]=0;
    p=0;
    k=0;
            continue;}//if you want go to menu and take order again. table number will change


    else{dash();
    goto re2;}}


}
void dash(){
line(5);
printf("Alret!!\n\n\there is a error\n");
line(5);
}
void rush(int A,int B){
    int C;

    C=A*B;

    printf("%d            %d\n",B,C);
}
void cal(int P,int Q, int R){
    P= Q - R;
   }

void line(int len){
int K;
printf("\n");

for(K=0;K<len;K++)
    {
        printf("----");
    }
    printf("\n");
}
