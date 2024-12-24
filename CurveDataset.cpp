/*!
 * \file CurveDataset.cpp
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#include <stdio.h>
#include "CurveDataset.h"
#include <stdexcept>

/**
 * @brief Constructor for the CurveDataset class.
 * @param size The number of data points to allocate.
 */
CurveDataset::CurveDataset(int size) : points_(size){
}

/**
 * @brief Copy constructor for the CurveDataset class.
 * @param other Another CurveDataset to copy from.
 */
CurveDataset::CurveDataset(const CurveDataset& other) : points_(other.points_) {
}

/**
 * @brief Overloaded index operator for accessing/modifying the data points.
 * @param index The index of the element to access/modify.
 * @return Reference to the data point at the specified index.
 */
Point& CurveDataset::operator[](int index) {
    return points_[index];
}

/**
 * @brief Overloaded constant index operator for accessing the data points.
 * @param index The index of the element to access.
 * @return The data point at the specified index (read-only).
 */
Point CurveDataset::operator[](int index) const {
    return points_[index];
}

/**
 * @brief Accessor method to get the first data point in the dataset.
 * @return The first data point.
 */
Point& CurveDataset::front() {
    return points_.front();
}

/**
 * @brief Accessor method to get the first data point (constant).
 * @return The first data point.
 */
const Point& CurveDataset::front() const {
    return points_.front();
}

/**
 * @brief Accessor method to get the last data point in the dataset.
 * @return The last data point.
 */
Point& CurveDataset::back() {
    return points_.back();
}

/**
 * @brief Accessor method to get the last data point (constant).
 * @return The last data point.
 */
const Point& CurveDataset::back() const {
    return points_.back();
}

/**
 * @brief Accessor method to get a data point safely by index.
 * @param index Index of the data point.
 * @return The data point at the specified index.
 */
Point& CurveDataset::at(int index) {
    return points_.at(index);
}

/**
 * @brief Accessor method to retrieve a data point safely (constant).
 * @param index Index of the data point.
 * @return The data point at the specified index.
 */
const Point& CurveDataset::at(int index) const {
    return points_.at(index);
}

/** @return The total number of data points in the dataset. */
int CurveDataset::size() const {
    return points_.size();
}

/**
 * @brief Computes the point on the Bezier curve for a given parameter.
 * @param curve Bezier curve.
 * @param t Parameter of the curve (within the interval [0, 1]).
 * @throw std::out_of_range if the value of t is invalid.
 * @return Point on the Bezier curve for the given parameter t.
 */
Point DeCasteljauAlgorithm(const Curve& controlPoints, const double t) {
    if(t >= 0 && t <= 1){
        int length = controlPoints.getCurveLength();
        Curve newCurve(controlPoints);  // Create a copy of the control points

        Point point;
        for (int j = 1; j < length; ++j) {
            for (int i = 0; i < length - j; ++i) {
                // Perform linear interpolation between control points
                point = (1 - t) * newCurve[i] + t * newCurve[i + 1];
                newCurve[i] = point;  // Update the control point after interpolation
            }
        }

        // Return the computed point after all iterations
        return newCurve[0];
    }
    else throw std::out_of_range("Invalid value of t!");
    
}

/**
 * @brief Function to process a Bezier curve and populate the CurveDataset with corresponding points.
 * @param curve The Bezier curve to process.
 * @param dataset The CurveDataset to fill.
 */
void PopulateDatasetFromCurve(Curve curve, CurveDataset& dataset) {
    int size = dataset.size();
    
    // Set the first and last points of the dataset directly
    dataset.front() = curve[0];
    dataset.back() = curve[1];

    // Compute and populate intermediate points
    for (int i = 1; i < size ; ++i) {
        double t = static_cast<double>(i) / (size - 1);  // Calculate t for the current position
        Point computedPoint = DeCasteljauAlgorithm(curve, t);
        dataset.at(i) = computedPoint;  // Use at() for safety in accessing elements
    }
}
