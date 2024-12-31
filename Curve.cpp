/*!
 * \file Curve.cpp
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 */

#include <stdio.h>
#include "Curve.h"

Curve::Curve(int curveLength) {
    if (curveLength > 0) {
        controlPts_ = new Point[curveLength];
        curveLength_ = curveLength;
    } else {
        std::string errorMsg = "Invalid length";
        throw std::out_of_range(errorMsg);
    }
}

Curve::Curve(const Curve& other) {
    curveLength_ = other.getCurveLength();
    controlPts_ = new Point[curveLength_];
    
    for (int i = 0; i < curveLength_; ++i) {
        controlPts_[i] = other.controlPts_[i];
    }
}

Curve::~Curve() {
    delete[] controlPts_;
}

Point& Curve::operator[](int index) {
    return controlPts_[index];
}

Point Curve::operator[](int index) const {
    return controlPts_[index];
}

int Curve::getCurveLength() const {
    return curveLength_;
}

