#include "counter.h"

Counter::Counter()       : value(1)   {}
Counter::Counter(int v)  : value(v)   {}

void Counter::increment() { ++value; }
void Counter::decrement() { --value; }
int  Counter::get() const { return value; }
