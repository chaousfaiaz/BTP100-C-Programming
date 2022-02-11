/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*
*****************************************************************************
<assessment name example: Workshop - #5 (Part-1)>
Full Name : MD Faiaz
Student ID#: 164899213
Email : mfaiaz@myseneca.ca
Section : NBB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>
#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#define LOG_DAYS 3


int main() {
    int year, month, day = 1;
    double morning, evening;
    double sum_morning = 0, sum_evening = 0;
   
    printf("General Well-being Log\n");
    printf("======================\n"); 
    
    // setting year and month
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &year, &month);
        if ((year > MAX_YEAR || year < MIN_YEAR) && (month < 1 || month > 12)) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if (year > MAX_YEAR || year < MIN_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if (month < 1 || month > 12) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else {
            printf("\n");printf("*** Log date set! ***\n\n");
        }
    } while (year > MAX_YEAR || year < MIN_YEAR || month < 1 || month > 12);
    
    // setting morning and evening ratings
    do{
        switch (month) {
            case 1:
                printf("%d-JAN-0%d\n", year,day);
                break;
            case 2:
                printf("%d-FEB-0%d\n", year,day);
                break;
            case 3:
                printf("%d-MAR-0%d\n", year,day);
                break;
            case 4:
                printf("%d-APR-0%d\n", year,day);
                break;
            case 5:
                printf("%d-MAY-0%d\n", year,day);
                break;
            case 6:
                printf("%d-JUN-0%d\n", year,day);
                break;
            case 7:
                printf("%d-JUL-0%d\n", year,day);
                break;
            case 8:
                printf("%d-AUG-0%d\n", year,day);
                break;
            case 9:
                printf("%d-SEP-0%d\n", year,day);
                break;
            case 10:
                printf("%d-OCT-0%d\n", year,day);
                break;
            case 11:
                printf("%d-NOV-0%d\n", year,day);
                break;
            case 12:
                printf("%d-DEC-0%d\n", year,day);
                break;
        }
                
        do {
            printf("   Morning rating (0.0-5.0): "); 
            scanf("%lf", &morning);
            if (morning < 0 || morning > 5){
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while(morning < 0 || morning > 5);
        sum_morning += morning;
  
        do {
            printf("   Evening rating (0.0-5.0): "); 
            scanf("%lf", &evening);
            if (evening < 0 || evening > 5){
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while(evening < 0 || evening > 5);
        sum_evening += evening;
        
        printf("\n");
        day++;
    } while(day <= LOG_DAYS);

  
 //double sum_morning = countMornings(morning);
 // double sum_evening = countEvenings(evening);
    double overall = sum_morning + sum_evening;
    double average_morning = sum_morning/LOG_DAYS;
    double average_evening = sum_evening/LOG_DAYS;
    double average_overall = (average_morning + average_evening)/2;

    printf("Summary\n"); 
    printf("=======\n");
    if (sum_morning < 10) {
        printf("Morning total rating:  %.3lf\n", sum_morning);
    } else {
        printf("Morning total rating: %.3lf\n", sum_morning); 
    } 
    if (sum_evening < 10) {
        printf("Evening total rating:  %.3lf\n", sum_evening);
    } else {
        printf("Evening total rating: %.3lf\n", sum_evening); 
    }
    printf("----------------------------\n");
    if (overall < 10) {
        printf("Overall total rating:  %.3lf\n\n", overall); 
    } else {
        printf("Overall total rating: %.3lf\n\n", overall); 
    }
    printf("Average morning rating:  %.1lf\n", average_morning);
    printf("Average evening rating:  %.1lf\n", average_evening);
    printf("----------------------------\n"); 
    printf("Average overall rating:  %.1lf\n", average_overall);
    return 0;
}

