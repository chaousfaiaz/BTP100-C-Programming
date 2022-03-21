/*
*****************************************************************************
                          Workshop - #8 (P2)
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

// ----------------------------------------------------------------------------
// defines/macros
#include <stdio.h>
#define MAX_PRODUCTS 3
#define SUGGESTED_SERVING 64
#define LBS_IN_KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int identifier;
    double price;
    int calories;
    double weight;
};

struct ReportData {
    int sku;
    double price;
    int calories_per_serving;
    double weight_lbs;
    double weight_kg;
    int weight_g;
    double servings;
    double cost_per_serving;
    double cost_per_cal;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *lbs, double *kg);


// 9. convert lbs: g
int convertLbsG(const double *lbs, int *g);


// 10. convert lbs: kg / g
void convertLbs(const double *pounds, double *kilograms, int *grams);


// 11. calculate: servings based on gPerServ
double calculateServings(const int serving_size, const int total_grams, double *number_of_servings);


// 12. calculate: cost per serving
double calculateCostPerServing(const double *product_price, const double *number_of_servings, double *cost_per_serving);


// 13. calculate: cost per calorie
double calculateCostPerCal(const double *product_price, const double *number_of_calories, double *cost_per_cal);


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo product);


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);


// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapest);


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest_CatFood);


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);

