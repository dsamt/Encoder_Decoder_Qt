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
    {
       std::wstring result;

       //char result2[512];


        for (int i = 0; i < ptext.length(); i++){
            //strcpy_s(result2, sizeof(result2), roman->digitstoRoman(result1, ptext.size())[i]);
            int* result1 = roman->texttodigits((char*)&ptext[i], 1);
            result.push_back(roman->digitstoRoman(result1, 1)[i]);
        }
        return result;
    }
    std::wstring decode(std::wstring ctext)
    {
        std::wstring result;
        for (int i = 0; i < ctext.length(); i++){
            result.push_back((wchar_t)(roman->digitsfromRoman((char*)&ctext[i], ctext.length())));
        }
        return result;
    }
};

#endif // LEGACYCODER_H
