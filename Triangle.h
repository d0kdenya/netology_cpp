#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure
{
protected:
    int a_, b_, c_, A_, B_, C_;
public:
    Triangle(const std::string& name,
             int a, int b, int c,
             int A, int B, int C);

    bool  check() const override;
    void  print_info() const override;
};

#endif