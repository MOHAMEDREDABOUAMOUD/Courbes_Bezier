/*!
 * \file Curve.h
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#ifndef Curve_h
#define Curve_h

#include "Point.h"


/**
 * @brief Class representing a Bezier curve.
 */
class Curve {
private:
    int curveLength_; /**< Length of the curve. */
    Point* controlPts_; /**< Array of control points. */

public:
    /**
     * @brief Constructor of Curve.
     * @param curveLength Length of the curve.
     * @throw std::out_of_range if the length is invalid.
     */
    Curve(int curveLength);

    /**
     * @brief Copy constructor of Curve.
     * @param other Bezier curve to copy.
     */
    Curve(const Curve& other);

    /** Destructor of Curve. */
    ~Curve();

    /**
     * @brief Overload of the constant indexing operator to access control points.
     * @param index Index of the element to access.
     * @return Control point at the specified index (read-only).
     */
    Point operator[](int index) const;

    /**
     * @brief Overload of the indexing operator to access/modify control points.
     * @param index Index of the element to access/modify.
     * @return Reference to the control point at the specified index.
     */
    Point& operator[](int index);

    /** @return Length of the Bezier curve. */
    int getCurveLength() const;
};

#endif /* Curve_h */
