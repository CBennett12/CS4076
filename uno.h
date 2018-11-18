#ifndef UNO_H
#define UNO_H
#include <Room.h>


class uno //Unidentified Nautical Object, and there can only be one at a time
{
public:
    virtual void moveRoom()=0;
    virtual ~uno();
};

#endif // UNO_H
