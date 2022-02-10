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
int main(){
    int year, month;
    printf("General Well-being Log\n");
    printf("======================\n"); 

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
            printf("\n");
            switch (month) {
            case 1:
                printf("*** Log date set! ***\n\nLog starting date: %d-JAN-01\n", year);
                break;
            case 2:
                printf("*** Log date set! ***\n\nLog starting date: %d-FEB-01\n", year);
                break;
            case 3:
                printf("*** Log date set! ***\n\nLog starting date: %d-MAR-01\n", year);
                break;
            case 4:
                printf("*** Log date set! ***\n\nLog starting date: %d-APR-01\n", year);
                break;
            case 5:
                printf("*** Log date set! ***\n\nLog starting date: %d-MAY-01\n", year);
                break;
            case 6:
                printf("*** Log date set! ***\n\nLog starting date: %d-JUN-01\n", year);
                break;
            case 7:
                printf("*** Log date set! ***\n\nLog starting date: %d-JUL-01\n", year);
                break;
            case 8:
                printf("*** Log date set! ***\n\nLog starting date: %d-AUG-01\n", year);
                break;
            case 9:
                printf("*** Log date set! ***\n\nLog starting date: %d-SEP-01\n", year);
                break;
            case 10:
                printf("*** Log date set! ***\n\nLog starting date: %d-OCT-01\n", year);
                break;
            case 11:
                printf("*** Log date set! ***\n\nLog starting date: %d-NOV-01\n", year);
                break;
            case 12:
                printf("*** Log date set! ***\n\nLog starting date: %d-DEC-01\n", year);
                break;
            }
        }
    } while ((year > 2022 || year < 2012) || (month < 1 || month > 12));
    
  

    return 0;
}
