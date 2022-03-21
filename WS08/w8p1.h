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

#include <stdio.h>
#define MAX_PRODUCTS 3
#define SUGGESTED_SERVING 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int identifier;
    double price;
    int calories;
    double weight;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptrInt);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptrDbl);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_of_products);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int product_sequence);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(int food_id, double *food_price, double *food_weight, int food_calories);


// 7. Logic entry point
void start(void);
