#ifndef MINE_H
#define MINE_H
#include <iostream>
#include <uno.h>
using namespace std;

class Mine:public Uno
{
public:
    Mine();

private:
    string toString();
};

#endif // MINE_H
