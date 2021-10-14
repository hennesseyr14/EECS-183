/**
 * cupcakes.cpp
 *
 * Ryan Hennessey
 * rjhenn
 *
 * EECS 183: Project 1
 * Fall 2017
 *
 * Calculates the number of batches of cupcakes, ingredient amounts, and cost.
 */
 
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Pluralizes a word if needed.
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 1.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);

int main() {
    int numPeople;
    const int NUM_CUPCAKES_IN_BATCH = 12;
    int numBatches;

    // Batter ingredients per batch
    const double CUPS_FLOUR_PER_BATCH = 1.5;
    const double CUPS_GRANULATED_SUGAR_PER_BATCH = 1.0;
    const double TSP_BAKING_POWDER_PER_BATCH = 1.5;
    const double TSP_SALT_PER_BATCH = 0.5;
    const double CUPS_BUTTER_PER_BATCH_BATTER = 0.5;
    const double CUPS_SOUR_CREAM_PER_BATCH = 0.5;
    const int NUM_WHOLE_EGGS_PER_BATCH = 1;
    const int NUM_EGG_YOLKS_PER_BATCH = 2;
    const double TSP_VANILLA_PER_BATCH_BATTER = 1.5;

    // Frosting ingredients per batch
    const double CUPS_BUTTER_PER_BATCH_FROSTING = 1.0;
    const double CUPS_POWDERED_SUGAR_PER_BATCH = 2.5;
    const double TSP_VANILLA_PER_BATCH_FROSTING = 3.0;

    // Ingredient costs
    const double COST_BAG_FLOUR = 3.09;
    const double COST_BAG_GRANULATED_SUGAR = 2.98;
    const double COST_LB_BUTTER = 2.50;
    const double COST_CONTAINER_SOUR_CREAM = 1.29;
    const double COST_DOZEN_EGGS = 2.68;
    const double COST_BAG_POWDERED_SUGAR = 1.18;
    const double COST_BOTTLE_VANILLA = 4.12;

    // Conversions
    const double CUPS_PER_BAG_FLOUR = 20.0;
    const double CUPS_PER_BAG_GRANULATED_SUGAR = 10.0;
    const double CUPS_PER_LB_BUTTER = 2.0;
    const double CUPS_PER_CONTAINER_SOUR_CREAM = 1.0;
    const int NUM_EGGS_PER_DOZEN = 12;
    const double CUPS_PER_BAG_POWDERED_SUGAR = 5.5;
    const double TSP_PER_BOTTLE_VANILLA = 12.0;

    // Total ingredient amounts needed
    int numBagsFlour;
    int numBagsGranulatedSugar;
    int numLbButter;
    int numContainersSourCream;
    int numDozenEggs;
    int numBagsPowderedSugar;
    int numBottlesVanilla;

    // Total cost of ingredients
    double totalCost = 0.00;
    
    // Prompt user for number of people, calculate number of batches
    cout << "How many people do you need to serve? ";
    cin  >> numPeople;
    numBatches = ceil(static_cast<double>(numPeople) / NUM_CUPCAKES_IN_BATCH);
    cout << endl << endl << "You need to make: " << numBatches << " "
         << pluralize("batch", "batches", numBatches) << " of cupcakes"
         << endl << endl;
    
    // Ingredient list
    cout << "Shopping List for \"Best Ever\" Vanilla Cupcakes" << endl
         << "----------------------------------------------" << endl;

    // Calculate, print number of bags of flour; update total cost
    numBagsFlour = ceil(numBatches * CUPS_FLOUR_PER_BATCH / CUPS_PER_BAG_FLOUR);
    cout << "   " << numBagsFlour << " "
         << pluralize("bag", "bags", numBagsFlour)
         << " of flour" << endl;
    totalCost += numBagsFlour * COST_BAG_FLOUR;

    // Calculate, print number of bags of granulated sugar; update total cost
    numBagsGranulatedSugar = ceil(numBatches * CUPS_GRANULATED_SUGAR_PER_BATCH
                                               / CUPS_PER_BAG_GRANULATED_SUGAR);
    cout << "   " << numBagsGranulatedSugar << " "
         << pluralize("bag", "bags", numBagsGranulatedSugar)
         << " of granulated sugar" << endl;
    totalCost += numBagsGranulatedSugar * COST_BAG_GRANULATED_SUGAR;

    // Calculate, print number of pounds of butter; update total cost
    numLbButter = ceil(numBatches * (CUPS_BUTTER_PER_BATCH_BATTER
                       + CUPS_BUTTER_PER_BATCH_FROSTING) / CUPS_PER_LB_BUTTER);
    cout << "   " << numLbButter << " "
         << pluralize("pound", "pounds", numLbButter)
         << " of butter" << endl;
    totalCost += numLbButter * COST_LB_BUTTER;

    // Calculate, print number of containers of sour cream; update total cost
    numContainersSourCream = ceil(numBatches * CUPS_SOUR_CREAM_PER_BATCH
                                        / CUPS_PER_CONTAINER_SOUR_CREAM);
    cout << "   " << numContainersSourCream << " "
         << pluralize("container", "containers", numContainersSourCream)
         << " of sour cream" << endl;
    totalCost += numContainersSourCream * COST_CONTAINER_SOUR_CREAM;

    // Calculate, print number of dozen eggs; update total cost
    numDozenEggs = ceil(static_cast<double>(numBatches) * 
                        (NUM_WHOLE_EGGS_PER_BATCH + NUM_EGG_YOLKS_PER_BATCH)
                                                        / NUM_EGGS_PER_DOZEN);
    cout << "   " << numDozenEggs << " dozen eggs" << endl;
    totalCost += numDozenEggs * COST_DOZEN_EGGS;

    // Calculate, print number of bags of powdered sugar; update total cost
    numBagsPowderedSugar = ceil(numBatches * CUPS_POWDERED_SUGAR_PER_BATCH
                                            / CUPS_PER_BAG_POWDERED_SUGAR);
    cout << "   " << numBagsPowderedSugar << " "
         << pluralize("bag", "bags", numBagsPowderedSugar)
         << " of powdered sugar" << endl;
    totalCost += numBagsPowderedSugar * COST_BAG_POWDERED_SUGAR;

    // Calculate, print number of bottles of vanilla; update total cost
    numBottlesVanilla = ceil(numBatches * (TSP_VANILLA_PER_BATCH_BATTER
                                  + TSP_VANILLA_PER_BATCH_FROSTING) 
                                           / TSP_PER_BOTTLE_VANILLA);
    cout << "   " << numBottlesVanilla << " "
         << pluralize("bottle", "bottles", numBottlesVanilla)
         << " of vanilla" << endl;
    totalCost += numBottlesVanilla * COST_BOTTLE_VANILLA;

    // Print total cost and goodbye message
    cout << endl << "Total expected cost of ingredients: $" << totalCost
         << endl << endl << "Have a great party!";

    return 0;
}

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}


