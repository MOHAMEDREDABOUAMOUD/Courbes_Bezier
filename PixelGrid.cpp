/*!
 * \file PixelGrid.cpp
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#include "PixelGrid.h"
#include <stdio.h>

/**
 * @brief Constructor for PixelGrid class.
 * @param width Width of the pixel grid.
 * @param height Height of the pixel grid.
 * @throw Throws an exception if width or height is non-positive.
 */
PixelGrid::PixelGrid(const int width, const int height) : width_(width), height_(height)
{
    if (width <= 0 || height <= 0)
    {
        throw "Taille incorrecte du PixelGrid";
    }
    grid_ = new int *[width];
    for (int i = 0; i < width; i++)
    {
        grid_[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            grid_[i][j] = 0;
        }
    }
}

/**
 * @brief Copy constructor for PixelGrid class.
 * @param v Reference to another PixelGrid object.
 */
PixelGrid::PixelGrid(const PixelGrid &v) : width_(v.get_width()), height_(v.get_height())
{
    grid_ = new int *[width_];
    for (int i = 0; i < width_; i++)
    {
        grid_[i] = new int[height_];
        for (int j = 0; j < height_; j++)
        {
            grid_[i][j] = v.grid_[i][j];
        }
    }
}

/**
 * @brief Destructor for PixelGrid class.
 */
PixelGrid::~PixelGrid()
{
    for (int i = 0; i < width_; i++)
    {
        delete[] grid_[i];
    }
    delete[] grid_;
}

/**
 * @brief Getter function for width.
 * @return Width of the pixel grid.
 */
int PixelGrid::get_width() const
{
    return width_;
}

/**
 * @brief Getter function for height.
 * @return Height of the pixel grid.
 */
int PixelGrid::get_height() const
{
    return height_;
}

/**
 * @brief Getter function for a specific pixel value at position (i, j).
 * @param i X-coordinate of the pixel.
 * @param j Y-coordinate of the pixel.
 * @return Pixel value at position (i, j).
 */
int PixelGrid::get_pixel(const int i, const int j) const
{
    return grid_[i][j];
}

/**
 * @brief Setter function for a specific pixel value at position (i, j).
 * @param i X-coordinate of the pixel.
 * @param j Y-coordinate of the pixel.
 * @param value Value to be set at position (i, j).
 */
void PixelGrid::set_pixel(const int i, const int j, const int value)
{
    grid_[i][j] = value;
}

/**
 * @brief Fill a specific point in the pixel grid using FillData.
 * @param x The X coordinate of the point.
 * @param y The Y coordinate of the point.
 * @return Reference to the modified PixelGrid.
 */
PixelGrid &PixelGrid::fill_point(const int x, const int y)
{
    int radius = std::min(width_ / 40, height_ / 40); 
    for (int i = -radius; i <= radius; i++)
    {
        for (int j = -radius; j <= radius; j++)
        {
            if (abs(i) + abs(j) <= radius)
            {
                set_pixel(x + i, y + j, 1);
            }
        }
    }
    return *this;
}

/**
 * @brief Creates a red contour around the filled area in the pixel grid.
 * @return Reference to the modified PixelGrid object.
 */
PixelGrid& PixelGrid::add_red_contour() 
{
    int w = get_width();
    int h = get_height();

    for (int x = 2; x < w - 2; ++x) {
        for (int y = 2; y < h - 2; ++y) {
            if (get_pixel(x, y) == 1) {
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if ((dx || dy) && get_pixel(x + dx, y + dy) == 0) {
                            set_pixel(x + dx, y + dy, 2); // Red contour
                        }
                    }
                }
            }
        }
    }

    return *this;
}