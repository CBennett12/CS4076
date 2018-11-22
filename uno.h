#ifndef UNO_H
#define UNO_H

#include <string>

using std::string;

enum class UnoType{Player,Enemy,Torpedo,Mine};

class Uno //Unidentified Nautical Object, and there can only be one at a time
{
public:
    virtual string toString()=0;
    virtual ~Uno();
    //template<typename t>
    bool checkMove(int moveIndex);

protected:
    UnoType type;
    bool valid;
};

#endif // UNO_H
