#ifndef CODERSTRATEGY_H
#define CODERSTRATEGY_H

#include <iostream>
#include <string>

class CoderStrategy{
public:
    virtual std::wstring encode(std::wstring ptext) = 0;

};

#endif // CODERSTRATEGY_H
