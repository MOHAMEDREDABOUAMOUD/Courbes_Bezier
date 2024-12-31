/*!
 * \file PixelGrid.h
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#ifndef PixelGrid_h
#define PixelGrid_h

#include <iostream>
#include "CurveDataset.h"
#include "Curve.h"

/**
 * @brief Class representing a pixel grid (bitmap) for managing image data.
 */
class PixelGrid {
protected:
    int width_;          /*!< Width of the pixel grid. */
    int height_;         /*!< Height of the pixel grid. */
    int **grid_;         /*!< 2D array representing the pixel grid. */

public:
    /**
     * @brief Constructor for the PixelGrid class.
     * @param width The width of the pixel grid.
     * @param height The height of the pixel grid.
     */
    PixelGrid(const int width, const int height);

    /**
     * @brief Copy constructor for the PixelGrid class.
     * @param other The PixelGrid object to copy from.
     */
    PixelGrid(const PixelGrid & other);

    /** Destructor for the PixelGrid class. */
    ~PixelGrid();

    /** @return The width of the pixel grid. */
    int get_width() const;

    /** @return The height of the pixel grid. */
    int get_height() const;

    /** @return The 2D array representing the pixel grid. */
    int** get_grid() const { return grid_; };

    /**
     * @brief Get the value of a pixel at a specific position.
     * @param i Row index.
     * @param j Column index.
     * @return The value of the pixel at position (i, j).
     */
    int get_pixel(const int i, const int j) const;

    /**
     * @brief Set the value of a pixel at a specific position.
     * @param i Row index.
     * @param j Column index.
     * @param value The value to set for the pixel (default is 1).
     */
    void set_pixel(const int i, const int j, const int value = 1);

    /**
     * @brief Fill a specific point in the pixel grid using FillData.
     * @param x The X coordinate of the point.
     * @param y The Y coordinate of the point.
     * @return Reference to the modified PixelGrid.
     */
    PixelGrid & fill_point(const int x, const int y);

    /**
     * @brief Add a red contour around the pixel grid.
     * @return Reference to the modified PixelGrid.
     */
    PixelGrid & add_red_contour();
};

#endif /* PixelGrid_h */

