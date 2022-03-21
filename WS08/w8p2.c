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

#define _CRT_SECURE_NO_WARNINGS


// System Libraries


// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *lbs, double *kg) {
    double temp;
    temp = *lbs / LBS_IN_KG;
    if (kg != NULL) {
        *kg = temp;
        return *kg;
    } else {
        return temp;
    }
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *lbs, int *g) {
    int temp;
    temp = (*lbs / LBS_IN_KG) * 1000;
    if (g != NULL) {
        *g = temp;
        return *g;
    } else {
        return temp;
    }
}


// 10. convert lbs: kg and g
void convertLbs(const double *pounds, double *kilograms, int *grams) {
    convertLbsKg(pounds, kilograms);
    convertLbsG(pounds, grams);
}


// 11. calculate: servings based on gPerServ
double calculateServings(const int serving_size, const int total_grams, double *number_of_servings) {
    double temp;
    temp = (double)total_grams / (double)serving_size;
    if (number_of_servings != NULL) {
        *number_of_servings = temp;
        return *number_of_servings;
    } else {
        return temp;
    }
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double *product_price, const double *number_of_servings, double *cost_per_serving) {
    double temp;
    temp = *product_price / *number_of_servings;
    if (cost_per_serving != NULL) {
        *cost_per_serving = temp;
        return *cost_per_serving;
    } else {
        return temp;
    }
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double *product_price, const double *number_of_calories, double *cost_per_cal) {
    double temp;
    temp = *product_price / *number_of_calories;
    if (cost_per_cal!= NULL) {
        *cost_per_cal = temp;
        return *cost_per_cal;
    } else {
        return temp;
    }
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo product) {
    struct ReportData temp;
    temp.sku = product.identifier;
    temp.price = product.price;
    temp.calories_per_serving = product.calories;
    temp.weight_lbs = product.weight; // convertLbs(&temp.weight_lbs, &temp.weight_kg, &temp.weight_g);
    temp.weight_kg = convertLbsKg(&temp.weight_lbs, NULL);
    // convertLbsKg(&temp.weight_lbs, &temp.weight_kgs);
    temp.weight_g = convertLbsG(&temp.weight_lbs, NULL);
    temp.servings = calculateServings(SUGGESTED_SERVING, temp.weight_g, &temp.servings);
    temp.cost_per_serving = calculateCostPerServing(&temp.price, &temp.servings, NULL);
    double total_calories = temp.calories_per_serving * temp.servings;
    temp.cost_per_cal = calculateCostPerCal(&temp.price, &total_calories, NULL);
    return temp;
}

/* struct CatFoodInfo {
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
}; */


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void) {
	printf("Analysis Report (Note: Serving = %dg)\n", SUGGESTED_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}


// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapest) {
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", 
    report.sku, report.price, report.weight_lbs, report.weight_kg, report.weight_g, 
    report.calories_per_serving, report.servings, report.cost_per_serving, report.cost_per_cal);
    if (cheapest) {
        printf(" ***\n");
    } else {
        printf("\n");
    }
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest_CatFood) {
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n", cheapest_CatFood.identifier, cheapest_CatFood.price);
    printf("Happy shopping!\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void) {
    struct CatFoodInfo cat_food[MAX_PRODUCTS];
    struct ReportData cat_food_reports[MAX_PRODUCTS];
    openingMessage(MAX_PRODUCTS);
    
    int i = 0, j = 0, cheapest_index = 0;
    
    for (i = 0; i < MAX_PRODUCTS; ++i) {
        j = i + 1;
        cat_food[i] = getCatFoodInfo(j);


        cat_food_reports[i] = calculateReportData(cat_food[i]); // a report is being made on the cat_food just created and stored in array
        if (i != 0) { // i.e. if this is not the first report in array
            // and if the current product is cheaper than the one before it in the reports array, update cheapest_index:
            if (cat_food_reports[i].cost_per_serving < cat_food_reports[i-1].cost_per_serving) {  
                cheapest_index = i;
            }
        }
        printf("\n");
    }
    
    displayCatFoodHeader();
    for (i = 0; i < MAX_PRODUCTS; ++i) {
        displayCatFoodData(cat_food[i].identifier, &cat_food[i].price, &cat_food[i].weight, cat_food[i].calories);
    }
    printf("\n");
    
    displayReportHeader();
    for (i = 0; i < MAX_PRODUCTS; ++i) {
        if (i == cheapest_index) {
            displayReportData(cat_food_reports[i], 1);
        } else {
            displayReportData(cat_food_reports[i], 0);
        }
    }
    printf("\n");
    
    displayFinalAnalysis(cat_food[cheapest_index]);
}
