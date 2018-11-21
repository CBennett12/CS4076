#ifndef WRECKAGE_H
#define WRECKAGE_H
#include <uno.h>
#include <iostream>
using namespace std;

class Wreckage : public Uno
{
public:
    Wreckage();

private:
    string toString();
};

#endif // WRECKAGE_H
