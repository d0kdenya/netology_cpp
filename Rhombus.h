#ifndef RHOMB_H
#define RHOMB_H

#include "Parallelogram.h"

class Rhombus : public Parallelogram
{
public:
    Rhombus(int a,int A,int B);
    bool check() const override;
};

#endif
