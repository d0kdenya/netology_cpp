#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure
{
protected:
    std::string name_;
    int         sides_count_;

    Figure(const std::string& n, int s);

public:
    Figure();
    virtual ~Figure() = default;

    virtual bool  check() const;
    virtual void  print_info() const;
};

#endif