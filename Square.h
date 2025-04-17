#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle
{
public:
    explicit Square(int a);
    bool check() const override;
};

#endif
