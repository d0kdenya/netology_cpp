#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include "FigureError.h"

class Triangle : public Figure
{
protected:
    int a_, b_, c_, A_, B_, C_;

public:
    Triangle(const std::string& n,
             int a, int b, int c,
             int A, int B, int C);

    void print() const override;
};

#endif
