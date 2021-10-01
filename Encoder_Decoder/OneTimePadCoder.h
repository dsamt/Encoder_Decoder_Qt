#ifndef ONETIMEPADCODER_H
#define ONETIMEPADCODER_H

#include "CoderStrategy.h"

class OneTimePad : public CoderStrategy
{
public:
    OneTimePad(){

    }

    std::wstring encode(std::wstring ptext)
    {
       return ptext;
    }
    std::wstring decode(std::wstring ctext)
    {
        return ctext;
    }

};

#endif // ONETIMEPADCODER_H
