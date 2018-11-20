#ifndef TORPEDO_H
#define TORPEDO_H
#include <uno.h>


class Torpedo: public Uno
{
public:
    Torpedo(string);
private:
    string heading;
};

#endif // TORPEDO_H
