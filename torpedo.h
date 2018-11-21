#ifndef TORPEDO_H
#define TORPEDO_H
#include <uno.h>
#include <iostream>
using namespace std;

class Torpedo:public Uno
{
public:
    Torpedo();

private:
    string toString();
};

#endif // TORPEDO_H
