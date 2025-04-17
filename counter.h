#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
    int value;

public:
    Counter();
    explicit Counter(int init);

    void increment();
    void decrement();
    int  get() const;
};

#endif
