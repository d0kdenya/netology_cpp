#ifndef QUAD_H
#define QUAD_H

#include "Figure.h"
#include "FigureError.h"

class Quadrangle : public Figure
{
protected:
    int a_, b_, c_, d_, A_, B_, C_, D_;

public:
    Quadrangle(const std::string& n,
               int a,int b,int c,int d,
               int A,int B,int C,int D);

    void print() const override;
};

#endif
