/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*****************************************************************************
                             Workshop - #6
Full Name  : MD Faiaz
Student ID#: 164899213
Email      : mfaiaz@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
*******************************************************************************/
#include<stdio.h>
int main () {
   
    double income, cost, sum=0, prior_sum;
    int important, forecast, selection, year, month, prior, note;
    char finance;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

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
            if (finance != 'y' && finance != 'n') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            } else {
                financed[i] = finance;
            }
        } while (finance != 'y' && finance != 'n');
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
    printf("                      $%11.2lf\n", sum);
    
    printf("\n");
   
   
   
   

   
    // PART 2:
   
    do {
        do {
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d",&selection); printf("\n");
            if (selection < 0 || selection > 2) {
                printf("ERROR: Invalid menu selection.\n\n");
            }
        } while (selection < 0 || selection > 2);
       
       
        if (selection == 1) {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", sum);
            year = (int)(sum/income/12);
            if (year == 0) {
                month = ((int)(sum/income)) + 1 ;
            } else {
                month = (((int)(sum/income))%12) + 1;
            }
            printf("Forecast: %d years, %d months\n", year, month);
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n");
            printf("\n");
           
        } else if (selection == 2) {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &prior); printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", prior);
            prior_sum = 0;
            note = 0;
           
            for (i = 0; i < forecast; i++) {
                if (priority[i] == prior) {
                    prior_sum += costs[i];
                    if (financed[i] == 'y') { note = 1; }
                }
            }
            printf("Amount:   $%1.2lf\n", prior_sum);
           
            year = (int)(prior_sum/income/12);
            if (year == 0) {
                month = ((int)(prior_sum/income)) + 1 ;
            } else {
                month = (((int)(prior_sum/income))%12) + 1;
            }
            printf("Forecast: %d years, %d months\n", year , month);
           
               
            if (note) {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            printf("\n");
        }
    } while (selection != 0);
   
    printf("Best of luck in all your future endeavours!\n");
    return 0;
}
