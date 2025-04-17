#ifndef QUAD_H
#define QUAD_H

#include "Figure.h"

class Quadrangle : public Figure
{
protected:
    int a_, b_, c_, d_, A_, B_, C_, D_;
public:
    Quadrangle(const std::string& n,
               int a,int b,int c,int d,
               int A,int B,int C,int D);

    bool check() const override;
    void print_info() const override;
};

#endif
