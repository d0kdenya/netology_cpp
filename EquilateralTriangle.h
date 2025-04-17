#ifndef EQUIL_TRIANGLE_H
#define EQUIL_TRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle
{
public:
    explicit EquilateralTriangle(int a);
    bool check() const override;
};

#endif