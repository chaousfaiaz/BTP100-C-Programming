/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  : MD Faiaz
Student ID#: 164899213
Email      : mfaiaz@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries


// User Libraries
#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptrInt) {
    int temp = 0;
    do {
        scanf("%d", &temp);
        if (temp <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
    } while (temp <= 0);
    // returning:
    if (ptrInt != NULL) { // assigning the entered value to the pointer argument (only if it is NOT NULL)
        *ptrInt = temp;
        return *ptrInt;
    } else { // pointer argument is NULL, so just return entered value (since there is no pointer to assign that value to)
        return temp; 
    }
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptrDbl) {
    double temp;
    do {
        scanf("%lf", &temp);
        if (temp <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
    } while (temp <= 0);
    // returning:
    if (ptrDbl != NULL) { 
        *ptrDbl = temp;
        return *ptrDbl;
    } else { 
        return temp; 
    }
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_of_products) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", num_of_products);
    printf("NOTE: A 'serving' is %dg\n\n", SUGGESTED_SERVING);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int product_sequence) {
    struct CatFoodInfo temp; 
    printf("Cat Food Product #%d\n", product_sequence);
    printf("--------------------\n");
    printf("SKU           : "); getIntPositive(&temp.identifier);
    printf("PRICE         : $"); getDoublePositive(&temp.price);
    printf("WEIGHT (LBS)  : "); getDoublePositive(&temp.weight);
    printf("CALORIES/SERV.: "); getIntPositive(&temp.calories);
    return temp;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void) {
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}


// 6. Display a formatted record of cat food data
void displayCatFoodData(int food_id, double *food_price, double *food_weight, int food_calories) {
    printf("%07d %10.2lf %10.1lf %8d\n", food_id, *food_price, *food_weight, food_calories); 
}


// 7. Logic entry point
void start(void) {
    int i;
    struct CatFoodInfo cat_food[MAX_PRODUCTS];
    openingMessage(MAX_PRODUCTS);
    for ( i = 1; i <= MAX_PRODUCTS; ++i) {
        cat_food[i-1] = getCatFoodInfo(i);
        printf("\n");
    }
    displayCatFoodHeader();
    for ( i = 0; i < MAX_PRODUCTS; ++i) {
        displayCatFoodData(cat_food[i].identifier, &cat_food[i].price, &cat_food[i].weight, cat_food[i].calories);
    }
}
