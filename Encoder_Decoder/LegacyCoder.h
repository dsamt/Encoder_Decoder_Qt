#ifndef LEGACYCODER_H
#define LEGACYCODER_H

#include "CoderStrategy.h"
#include "RomanConverter.h"
#include <iostream>

class LegacyCoder : public CoderStrategy
{
private:
    RomanConverter * roman;

public:
    LegacyCoder()
    {
    }

    std::wstring encode(std::wstring ptext)
    {/*
       std::wstring result;
       int* result1 = roman->texttodigits((char*)ptext.c_str(), ptext.size());
       char* result2 = roman->digitstoRoman(result1, ptext.size());
       result = result2.toStdWString();
       return result;*/
        return ptext;
    }
    std::wstring decode(std::wstring ctext)
    {
        return ctext;
    }
};

#endif // LEGACYCODER_H
