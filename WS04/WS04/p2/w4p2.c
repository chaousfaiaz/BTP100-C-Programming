/*
*****************************************************************************
                          Workshop - #4 (P1)
Full Name  : MD Faiaz
Student ID#: 164899213
Email      : mfaiaz@mysenecacollege.ca
Section    : NBB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>

void apple_picker(int needed) {
    if (needed != 0) {
        int apple, apple_remaining = needed;
        do {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &apple);
            if(apple <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (apple > apple_remaining) {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apple_remaining);
            } else {
                apple_remaining = apple_remaining - apple;
                if (apple_remaining != 0) {
                printf("Looks like we still need some APPLES...\n");
                }
            }
        } while(apple_remaining != 0);
        printf("Great, that's the apples done!\n\n");
    }
}

void orange_picker(int needed) {
    if (needed != 0) {
        int orange, orange_remaining = needed;
        do {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orange);
            if(orange <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (orange > orange_remaining) {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", orange_remaining);
            } else {
                orange_remaining = orange_remaining - orange;
                if (orange_remaining != 0) {
                printf("Looks like we still need some ORANGES...\n");
                }
            }
        } while(orange_remaining != 0);
        printf("Great, that's the oranges done!\n\n");
    }
}

void pear_picker(int needed) {
    if (needed != 0) {
        int pear, pear_remaining = needed;
        do {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pear);
            if(pear <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (pear > pear_remaining) {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pear_remaining);
            } else {
                pear_remaining = pear_remaining - pear;
                if (pear_remaining != 0) {
                printf("Looks like we still need some PEARS...\n");
                }
            }
        } while(pear_remaining != 0);
        printf("Great, that's the pears done!\n\n");
    }
}

void tomato_picker(int needed) {
    if (needed != 0) {
        int tomato, tomato_remaining = needed;
        do {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomato);
            if(tomato <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (tomato > tomato_remaining) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomato_remaining);
            } else {
                tomato_remaining = tomato_remaining - tomato;
                if (tomato_remaining != 0) {
                printf("Looks like we still need some TOMATOES...\n");
                }
            }
        } while(tomato_remaining != 0);
        printf("Great, that's the tomatoes done!\n\n");
    }
}

void cabbage_picker(int needed) {
    if (needed != 0) {
        int cabbage, cabbage_remaining = needed;
        do {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &cabbage);
            if(cabbage <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (cabbage > cabbage_remaining) {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbage_remaining);
            } else {
                cabbage_remaining = cabbage_remaining - cabbage;
                if (cabbage_remaining != 0) {
                printf("Looks like we still need some CABBAGES...\n");
                }
            }
        } while(cabbage_remaining != 0);
        printf("Great, that's the cabbages done!\n\n");
    }
}


// ***** MAIN FUNCTION ****
int main() {
    int apple_quantity, orange_quantity, pear_quantity, tomato_quantity, cabbage_quantity;
    int repeat = 1;
   
    do {
       
    // grocery list maker:
    printf("Grocery Shopping\n");
    printf("================\n");
   
    do{
        printf("How many APPLES do you need? : ");
        scanf("%d", &apple_quantity);
        if(apple_quantity < 0){
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while(apple_quantity < 0);
    printf("\n");
   
    do{
        printf("How many ORANGES do you need? : ");
        scanf("%d", &orange_quantity);
        if(orange_quantity < 0){
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while(orange_quantity < 0);
    printf("\n");
   
    do{
        printf("How many PEARS do you need? : ");
        scanf("%d", &pear_quantity);
        if(pear_quantity < 0){
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while(pear_quantity < 0);
    printf("\n");
   
    do{
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomato_quantity);
        if(tomato_quantity < 0){
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while(tomato_quantity < 0);
    printf("\n");
   
    do{
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbage_quantity);
        if(cabbage_quantity < 0){
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while(cabbage_quantity < 0);
    printf("\n--------------------------\nTime to pick the products!\n--------------------------\n\n");
   
    // shopping:
    apple_picker(apple_quantity);
    orange_picker(orange_quantity);
    pear_picker(pear_quantity);
    tomato_picker(tomato_quantity);
    cabbage_picker(cabbage_quantity);
    printf("All the items are picked!\n\n");
   
    printf("Do another shopping? (0=NO): ");
    scanf("%d", &repeat);
    printf("\n");
   
    } while (repeat);
    printf("Your tasks are done for today - enjoy your free time!\n");
   
    return 0;
}
