/*!
 * \file Point.cpp
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#include "Point.h"
#include <cmath>

Point::Point(double coordX, double coordY) : coordX_(coordX), coordY_(coordY) {}

Point::Point(const Point& other) : coordX_(other.coordX_), coordY_(other.coordY_) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        coordX_ = other.coordX_;
        coordY_ = other.coordY_;
    }
    return *this;
}

Point& Point::convertToIntegerCoords() {
    coordX_ = std::round(coordX_);
    coordY_ = std::round(coordY_);
    return *this;
}

Point operator*(double scalar, const Point& p) {
    return Point(scalar * p.getCoordX(), scalar * p.getCoordY());
}

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.getCoordX() + p2.getCoordX(), p1.getCoordY() + p2.getCoordY());
}

Point operator-(const Point& p1, const Point& p2) {
    return Point(p1.getCoordX() - p2.getCoordX(), p1.getCoordY() - p2.getCoordY());
}
