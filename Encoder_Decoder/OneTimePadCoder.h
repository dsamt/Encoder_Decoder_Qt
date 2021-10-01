#ifndef ONETIMEPADCODER_H
#define ONETIMEPADCODER_H

#include "CoderStrategy.h"
#include <stdlib.h>

class OneTimePad : public CoderStrategy
{
private:
    static int offset;
    static OneTimePad * otpInstance;
protected:
    OneTimePad(){
        OneTimePad::offset = 0;
    }

public:
    static OneTimePad* getInstance(){
        if (otpInstance == NULL){
            otpInstance = new OneTimePad();
        }
        return otpInstance;
    }
    int getRandPrime(){
       // extern unsigned int urand();
        int lower = 1000;
        int upper = 2000;
        int p = rand() % (upper - lower) + lower;
        return p;
    }
    std::wstring encode(std::wstring ptext)
    {
        std::wstring result;
        offset = getRandPrime();
        for (size_t i = 0; i < ptext.size(); i++)
        {
            result.push_back(ptext[i] + offset % 95);
        }
        return result;
    }
    std::wstring decode(std::wstring ctext)
    {
        std::wstring result;
        for (size_t i = 0; i < ctext.size(); i++)
        {
            result.push_back(ctext[i] - offset % 95);
        }
        return result;
    }

};

#endif // ONETIMEPADCODER_H
