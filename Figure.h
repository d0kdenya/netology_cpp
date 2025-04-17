#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure
{
protected:
    std::string name_;
    int sides_;

    Figure(const std::string& n, int s);

public:
    virtual ~Figure() = default;

    virtual void print() const = 0;
};

#endif
