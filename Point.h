/*!
 *\file Point.h
 *\author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */
#ifndef Point_h
#define Point_h

#include <ostream>

/**
 * @brief Class representing a point.
 *
 * This class represents a point with x and y coordinates.
 */
class Point {
private:
    double coordX_; /// x-coordinate of the point.
    double coordY_; /// y-coordinate of the point.

public:
    /**
     * @brief Default constructor.
     *
     * @param coordX_ x-coordinate (default is 0).
     * @param coordY_ y-coordinate (default is 0).
     */
    Point(double coordX = 0, double coordY = 0);

    /**
     * @brief Default destructor.
     */
    ~Point() = default;

    /**
     * @brief Copy constructor.
     *
     * @param other Point to copy.
     */
    Point(const Point& other);

    /**
     * @brief Get the x-coordinate.
     *
     * @return x-coordinate of the point.
     */
    double getCoordX() const { return coordX_; }

    /**
     * @brief Get the y-coordinate.
     *
     * @return y-coordinate of the point.
     */
    double getCoordY() const { return coordY_; }

    /**
     * @brief Set the x-coordinate.
     *
     * @param coordX New x-coordinate.
     */
    void setCoordX(double coordX) { coordX_ = coordX; }

    /**
     * @brief Set the y-coordinate.
     *
     * @param coordY New y-coordinate.
     */
    void setCoordY(double coordY) { coordY_ = coordY; }

    /**
     * @brief Round coordinates to integers.
     *
     * This method rounds the x and y coordinates to integers.
     *
     * @return Reference to the Point object after rounding.
     */
    Point& convertToIntegerCoords();

    /**
     * @brief Overload of the assignment operator.
     *
     * @param other Point to assign.
     * @return Reference to the Point object after assignment.
     */
    Point& operator=(const Point& other);
};

/**
 * @brief Overload of the multiplication operator.
 *
 * This function overloads the multiplication operator for a scalar on the left.
 *
 * @param scalar Scalar value.
 * @param p Point.
 * @return New Point resulting from the multiplication.
 */
Point operator*(double scalar, const Point& p);

/**
 * @brief Overload of the addition operator.
 *
 * This function overloads the addition operator for two Point objects.
 *
 * @param p1 First Point.
 * @param p2 Second Point.
 * @return New Point resulting from the addition.
 */
Point operator+(const Point& p1, const Point& p2);

/**
 * @brief Overload of the subtraction operator.
 *
 * This function overloads the subtraction operator for two Point objects.
 *
 * @param p1 First Point.
 * @param p2 Second Point.
 * @return New Point resulting from the subtraction.
 */
Point operator-(const Point& p1, const Point& p2);

#endif /* Point_h */
