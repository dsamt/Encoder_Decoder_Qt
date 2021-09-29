#pragma once

// RomanConvertor,h	Creed Jones		VT	ECE4574 FA21	Sept 15, 2021
// A sample legacy class to convert a string to and from roman numerals
// this is an inline C++ class

#include <stdlib.h>
#include <string.h>

class RomanConverter
{
public:
    RomanConverter() { }

    char* toRoman(int A) {
        const char* m[128];
        for (int i = 0; i < 128; i++)
            m[i] = "";
        m[1] = "I";
        m[2] = "II";
        m[3] = "III";
        m[4] = "IV";
        m[5] = "V";
        m[6] = "VI";
        m[7] = "VII";
        m[8] = "VIII";
        m[9] = "IX";
        m[10] = "X";
        m[20] = "XX";
        m[30] = "XXX";
        m[40] = "XL";
        m[50] = "L";
        m[60] = "LX";
        m[70] = "LXX";
        m[80] = "LXXX";
        m[90] = "XC";
        m[100] = "C";
        char ans[32] = "";
        char tempans[32] = "";
        int j = 1;
        while (A > 0) {
            j = j * 10;
            int k = A % (j);
            strcpy_s(tempans, 32, m[k]);
            strcat_s(tempans, 32, ans);
            strcpy_s(ans, 32, tempans);
            A = A - k;
        }
        return ans;
    }

    int romanval(char c) {
        if (c == 'M' || c == 'm')
            return 1000;
        if (c == 'D' || c == 'd')
            return 500;
        if (c == 'C' || c == 'c')
            return 100;
        if (c == 'L' || c == 'l')
            return 50;
        if (c == 'X' || c == 'x')
            return 10;
        if (c == 'V' || c == 'v')
            return 5;
        if (c == 'I' || c == 'i')
            return 1;
        return 0;
    }

    int  fromRoman(char* B) {
        int ans = 0;
        int thisval = 0;
        int nextval = 0;
        int looplen = strlen(B) - 1;
        for (int i = 0; i < looplen; i++) {
            thisval = romanval(*B++);
            nextval = romanval(*B);
            if (thisval < nextval)
                ans -= thisval;
            else
                ans += thisval;
        }
        ans += romanval(*B);
        return ans;
    }

    int* texttodigits(char* text, int len)
    {
        int* result = (int*)(malloc( 2 * len * sizeof(int)));
        int* resptr = result;
        for (int i = 0; i < len; i++)
        {
            *resptr++ = *text++;
        }
        return result;
    }

    char* digitstoRoman(int* numbers, int len)
    {
        char* result = (char*)(malloc(20 * len * sizeof(char)));
        *result = 0;
        for (int i = 0; i < len; i++)
        {
            strcat_s(result, 20 * len, toRoman(numbers[i]));
            strcat_s(result, 20 * len, "_");
        }
        return result;
    }

    int* digitsfromRoman(char* letters, int len)
    {
        char* inptr = letters;
        int* result = (int*)(malloc(2 * len * sizeof(int)));
        int* resptr = result;
        char* token = strtok(inptr, "_");
        while (token != NULL)
        {
            *resptr++ = fromRoman(token);
            token = strtok(NULL, "_");
        }
        *resptr = 0;
        return result;
    }


};

