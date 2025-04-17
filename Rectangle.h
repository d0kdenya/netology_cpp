#ifndef RECT_H
#define RECT_H

#include "Parallelogram.h"

class Rectangle : public Parallelogram
{
public:
    Rectangle(int a,int b);
    bool check() const override;
};

#endif
