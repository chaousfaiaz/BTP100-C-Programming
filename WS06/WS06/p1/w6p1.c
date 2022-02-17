/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main () {
   
    double income, cost, sum;
    int important, forecast;
    char finance;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
   
    // compare your output to assignment output and fix spacing

    do{
        printf ("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < 500) {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        } else if (income > 400000) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
    } while (income < 500 || income > 400000);
        printf("\n");


    do{
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d",&forecast);
        if (forecast < 1 || forecast > 10) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
    } while(forecast < 1 || forecast > 10);
        printf("\n");

    // these need to be declared AFTER you have a value for forecast, why would you put these at the top. C isn't dynamic
    int priority[forecast];
    char financed[forecast];
    double costs[forecast];
    
    int i;
    for (i = 0; i < forecast; i++) {
        printf("Item-%d Details:\n", i+1);
       
        do {
            printf("   Item cost: $");
            scanf("%lf", &cost);
            if (cost < 100) {
                printf("      ERROR: Cost must be at least $100.00\n"); // the $100 should be an unmodifiable variable that you define
            } else {
                costs[i] = cost;
            }
        } while (cost < 100);


        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &important);
            if (important < 1 || important > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            } else {
                priority[i] = important;
            }
        } while (important < 1 || important > 3);
 
 
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance); 
            // The %c won't automatically skip any leading whitespace, so if there's a stray newline in the input stream (from a previous entry) the scanf call will consume it immediately.
            if (finance != 'y' && finance != 'n') { 
                //  (finance != 'y' || finance != 'n')
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            } else {
                financed[i] = finance;
            }
        } while (finance != 'y' && finance != 'n'); // (it should be && instead of ||)
            printf("\n");


    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for(i = 0; i < forecast; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", i+1, priority[i], financed[i], costs[i]);
    }
    printf("---- -------- -------- -----------\n");
   
    for(i = 0; i < forecast; i++) {
        sum += costs[i];
    }
    printf("                      $%11.2lf\n\n", sum);
    printf("Best of luck in all your future endeavours!\n");
   
    return 0;
   
}