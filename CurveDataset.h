/*!
 * \file CurveDataset.h
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#ifndef CurveDataset_h
#define CurveDataset_h

#include "Curve.h"
#include <vector>

/**
 * @brief This class represents a container for storing and managing data points for curves or shapes.
 */
class CurveDataset {
private:
    std::vector<Point> points_; /**< Array of data points. */

public:
    /**
     * @brief Constructor to initialize the CurveDataset with a given size.
     * @param size The number of data points to allocate.
     */
    CurveDataset(int size);

    /** Destructor for the CurveDataset class. */
    ~CurveDataset() = default;

    /**
     * @brief Copy constructor for the CurveDataset class.
     * @param other Another CurveDataset object to copy from.
     */
    CurveDataset(const CurveDataset& other);

    /**
     * @brief Accessor method to get or modify data points.
     * @param index Index of the data point to access/modify.
     * @return Reference to the data point at the specified index.
     */
    Point& operator[](int index);

    /**
     * @brief Accessor method to retrieve data points (constant).
     * @param index Index of the data point.
     * @return The data point at the specified index (read-only).
     */
    Point operator[](int index) const;

    /**
     * @brief Accessor method to get the first data point in the dataset.
     * @return The first data point.
     */
    Point& front();

    /**
     * @brief Accessor method to get the first data point (constant).
     * @return The first data point.
     */
    const Point& front() const;

    /**
     * @brief Accessor method to get the last data point in the dataset.
     * @return The last data point.
     */
    Point& back();

    /**
     * @brief Accessor method to get the last data point (constant).
     * @return The last data point.
     */
    const Point& back() const;

    /**
     * @brief Accessor method to get a data point safely by index.
     * @param index Index of the data point.
     * @return The data point at the specified index.
     */
    Point& at(int index);

    /**
     * @brief Accessor method to retrieve a data point safely (constant).
     * @param index Index of the data point.
     * @return The data point at the specified index.
     */
    const Point& at(int index) const;

    /** @return The total number of data points in the dataset. */
    int size() const;
};

/**
 * @brief Computes the point on the Bezier curve for a given parameter.
 * @param curve Bezier curve.
 * @param t Parameter of the curve (within the interval [0, 1]).
 * @throw std::out_of_range if the value of t is invalid.
 * @return Point on the Bezier curve for the given parameter t.
 */
Point DeCasteljauAlgorithm(const Curve& curve, const double t);

/**
 * @brief This function processes a Bezier curve and fills the CurveDataset with corresponding points.
 * @param curve The Bezier curve to process.
 * @param dataset The CurveDataset object to be populated.
 */
void PopulateDatasetFromCurve(Curve curve, CurveDataset& dataset);

#endif /* CurveDataset_h */
