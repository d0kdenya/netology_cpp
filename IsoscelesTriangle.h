#ifndef ISO_TRIANGLE_H
#define ISO_TRIANGLE_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int A, int B);
    bool check() const override;
};

#endif