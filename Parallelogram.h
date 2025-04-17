#ifndef PARAL_H
#define PARAL_H

#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a,int b,int A,int B);
    bool check() const override;
};

#endif
