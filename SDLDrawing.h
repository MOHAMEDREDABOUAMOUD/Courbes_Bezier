/**
 * @file SDLDrawing.h
 * @author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#ifndef SDL_DRAWING_H
#define SDL_DRAWING_H

#include <SDL.h>
#include "PixelGrid.h"
#include "LetterSelector.h"

/**
 * @class SDLDrawing
 * @brief Provides functionality to draw on an SDL window using a PixelGrid object.
 */
class SDLDrawing {

private:
    /**
     * @brief Draws a specific window with the selected font.
     * @param title Title of the window.
     * @param table PixelGrid object to be used for drawing.
     * @param drawFunction Pointer to the drawing function to be used.
     */
    void DrawWindow(const char* title, PixelGrid table, void (SDLDrawing::*drawFunction)(SDL_Renderer*, int**, int, int, PixelGrid));

    /**
     * @brief Draws an empty letter on the SDL window at the specified position.
     * @param renderer The SDL renderer used for drawing.
     * @param letterGrid 2D array representing the PixelGrid of the letter.
     * @param j X-coordinate of the starting position.
     * @param i Y-coordinate of the starting position.
     * @param table PixelGrid object on which to draw the letter.
     */
    void EmptyLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table);

    /**
     * @brief Draws a solid black letter on the SDL window at the specified position.
     * @param renderer The SDL renderer used for drawing.
     * @param letterGrid 2D array representing the PixelGrid of the letter.
     * @param j X-coordinate of the starting position.
     * @param i Y-coordinate of the starting position.
     * @param table PixelGrid object on which to draw the letter.
     */
    void SolidBlackLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table);

    /**
     * @brief Draws a red letter on the SDL window at the specified position.
     * @param renderer The SDL renderer used for drawing.
     * @param letterGrid 2D array representing the PixelGrid of the letter.
     * @param j X-coordinate of the starting position.
     * @param i Y-coordinate of the starting position.
     * @param table PixelGrid object on which to draw the letter.
     */
    void RedLetter(SDL_Renderer* renderer, int** letterGrid, int j, int i, PixelGrid table);

public:
    /**
     * @brief Draws the given letter X on three distinct SDL windows in parallel.
     * @param x X-coordinate of the window.
     * @param width Width of the window.
     * @param height Height of the window.
     */
    void Draw(int x, int width, int height);

    /**
     * @brief Draws the 3 fonts from A to Z with a 2-second interval.
     * @param width Width of the window.
     * @param height Height of the window.
     */
    void Draw2(int width, int height);
};

#endif // SDL_DRAWING_H
