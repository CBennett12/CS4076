#ifndef UNO_H
#define UNO_H

#include <string>

using std::string;

class Uno //Unidentified Nautical Object, and there can only be one at a time
{
public:
    virtual string toString();
    virtual ~Uno();
};

#endif // UNO_H
