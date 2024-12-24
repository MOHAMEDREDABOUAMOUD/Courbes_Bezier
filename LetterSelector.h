/*!
 * \file LetterSelector.h
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#ifndef LetterSelector_h
#define LetterSelector_h

#include <iostream>
#include "PixelGrid.h"
#include "LetterPrinter.h"

/**
 * @brief Class responsible for selecting and displaying the chosen letter by the user.
 */

class LetterSelector {
public:

    /**
     * @brief Prints a letter on the pixel grid using Curve curves.
     * @param grid PixelGrid object to be modified.
     * @param Curves A number of curves that can vary depending on the letter
     */
    template <typename... Curves>
    static void printLetter(PixelGrid &grid, Curves&... curves);

    /**
     * @brief Function to colorize the pixel grid using FillData.
     * @param grid The PixelGrid to colorize.
     * @param dataset The FillData containing the points to be used for coloring.
     */
    static void colorize(PixelGrid &grid, const CurveDataset &dataset);

    /**
     * @brief Function to select a letter by ASCII value and print it onto the pixel grid.
     * @param grid The PixelGrid to print the letter onto.
     * @param asciiValue The ASCII value of the letter to print (default is 65 for 'A').
     */
    static void selectLetter(PixelGrid &grid, int asciiValue = 65);
    
};

/**
 * @note Template functions must be defined in the header file because they 
 * are instantiated at compile-time. Defining `printLetter` in the header 
 * ensures that the compiler can generate the required code for each type.
 */
template <typename... Curves>
void LetterSelector::printLetter(PixelGrid &grid, Curves&... curves) {
    int size = std::max(grid.get_width(), grid.get_height());
    CurveDataset points(size);

    // Fold expression to process each curve
    (void)std::initializer_list<int>{(
        (curves.getCurveLength() > 0 ? (PopulateDatasetFromCurve(curves, points), colorize(grid, points)) : void()), 
        0)...};

    grid.add_red_contour();
}

#endif /* LetterSelector_h */