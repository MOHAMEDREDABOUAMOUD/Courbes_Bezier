
#include "LetterSelector.h"

/**
 * @brief Colorizes the pixel grid based on the given FillData.
 * @param grid PixelGrid object to be colorized.
 * @param fillData FillData object representing the points to be filled.
 */
void LetterSelector::colorize(PixelGrid &grid, const CurveDataset &fillData)
{
    for (int i = 0; i < fillData.size(); ++i)
    {
        Point currentPoint = fillData[i];
        int x = int(grid.get_width() * currentPoint.getCoordY());
        int y = int(grid.get_height() * currentPoint.getCoordX());
        grid.fill_point(x, y);
    }
}

// /**
//  * @brief Prints a letter on the pixel grid using Curve curves.
//  * @param grid PixelGrid object to be modified.
//  * @param Curves A number of curves that can vary depending on the letter
//  */
// template <typename... Curves>
// void LetterSelector::printLetter(PixelGrid &grid, Curves&... curves)
// {
//     int size = std::max(grid.get_width(), grid.get_height());
//     CurveDataset points(size);

//     // Fold expression to process each curve
//     (void)std::initializer_list<int>{(
//         (curves.getCurveLength() > 0 ? (PopulateDatasetFromCurve(curves, points), colorize(grid, points)) : void()), 
//         0)...};

//     grid.add_red_contour();
// }



/**
 * @brief Selects and prints a letter on the PixelGrid based on the ASCII code.
 * @param table PixelGrid object to be modified.
 * @param x ASCII code of the letter to be printed.
 * @throw Throws an exception if the ASCII code is not within the range [65, 90].
 */
void LetterSelector::selectLetter(PixelGrid &table, int x) {
    // Check if the input is a valid letter in the range [65, 90]
    if (x < 65 || x > 90) {
        throw "Erreur, lettre non considérée";
    }

    // Array of functions that print letters A to Z
    void (*printLetters[])(PixelGrid&) = {
        LetterPrinter::printLetterA, LetterPrinter::printLetterB, LetterPrinter::printLetterC, LetterPrinter::printLetterD, LetterPrinter::printLetterE,
        LetterPrinter::printLetterF, LetterPrinter::printLetterG, LetterPrinter::printLetterH, LetterPrinter::printLetterI, LetterPrinter::printLetterJ,
        LetterPrinter::printLetterK, LetterPrinter::printLetterL, LetterPrinter::printLetterM, LetterPrinter::printLetterN, LetterPrinter::printLetterO,
        LetterPrinter::printLetterP, LetterPrinter::printLetterQ, LetterPrinter::printLetterR, LetterPrinter::printLetterS, LetterPrinter::printLetterT,
        LetterPrinter::printLetterU, LetterPrinter::printLetterV, LetterPrinter::printLetterW, LetterPrinter::printLetterX, LetterPrinter::printLetterY, LetterPrinter::printLetterZ
    };

    // Convert x (ASCII value) to index (0 for A, 25 for Z)
    int index = x - 65;
    
    // Call the corresponding function from the array
    printLetters[index](table);
}