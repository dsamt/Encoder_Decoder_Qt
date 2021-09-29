#pragma once
#include "CoderStrategy.h"

// PalindromeCoder.cpp	Creed Jones		VT	ECE4574 FA21	Sept 15, 2021
// This class implements a stupid front-to-back flip of the text and calls it an encoding

class PalindromeCoder :
    public CoderStrategy
{
private:

public:
    PalindromeCoder()
    {
    }

    std::wstring encode(std::wstring ptext)
    {
        std::wstring result;
        for (size_t index = 0; index < ptext.length(); index++)
        {
            result.push_back((ptext[ptext.length()-index-1]));
        }
        return result;
    }
    std::wstring decode(std::wstring ctext)
    {
        return encode(ctext);
    }
};



