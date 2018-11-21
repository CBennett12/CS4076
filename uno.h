#ifndef UNO_H
#define UNO_H

#include <string>

using std::string;

enum class UnoType{Player,Enemy,Torpedo,Mine};

class Uno //Unidentified Nautical Object, and there can only be one at a time
{
public:
    virtual void toString()=0;
    virtual ~Uno();

protected:
    UnoType type;
};

#endif // UNO_H
