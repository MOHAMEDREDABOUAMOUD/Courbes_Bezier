/*!
 * @file main.cpp
 * @author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#include <iostream>
#include "SDLDrawing.h"

/**
 * @brief Main function representing the entry point of the SDL application.
 * 
 * This function initializes the SDLDrawing object, creates an SDL window, 
 * draws a letter in three different windows simultaneously using threads using lettreSDL.Draw
 * or draws all letters one after the other in one window using lettreSDL.Draw2
 *  
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Integer indicating the application's exit status.
 */
int SDL_main(int argc, char* argv[]) {
    try {
        // Create an SDLDrawing object
        SDLDrawing lettreSDL;

        std::cout << "Click Q in any window to exit." << std::endl;
        // Draw the letter in three separate windows using threads
        lettreSDL.Draw('Q', 40, 50);

        // Draw all the letters one after another in one window
        // lettreSDL.Draw2(40, 50);

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
}
