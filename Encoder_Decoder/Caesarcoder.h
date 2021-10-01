#ifndef CAESARCODER_H
#define CAESARCODER_H

#include "CoderStrategy.h"

class CaesarCoder : public CoderStrategy
{
private:
    int offset;

public:
    CaesarCoder(int off)
    {
        offset = off;
    }

    std::wstring encode(std::wstring ptext)
    {

        std::wstring result;
        for (size_t i = 0; i < ptext.size(); i++)
        {/*
            if (ptext[i] >= 'A' && ptext[i] <= 'Z') {
                    if (ptext[i] + offset > 'Z'){
                        result.push_back(ptext[i] - 26 + offset);
                    }
                    else{
                    result.push_back(ptext[i] + offset);
                    }
                }
                // The same, for a different range of characters.
            else if (ptext[i] >= 'a' && ptext[i] <= 'z') {
                    if (ptext[i] + offset > 'z'){
                        result.push_back(ptext[i] - 26 + offset);
                    }
                    else{
                        result.push_back(ptext[i] + offset);
                    }
                }
            else{
                result.push_back(ptext[i]);
            }
            */
            result.push_back(ptext[i] + offset % 95);
        }
        return result;
    }
    std::wstring decode(std::wstring ctext)
    {
        //offset = 26 - offset;
        std::wstring result;
        for (size_t i=0; i < ctext.size(); i++){
            result.push_back(ctext[i] - offset % 95);
        }
        return result;
    }
};

#endif // CAESARCODER_H
