#include <stdio.h>
#include <stdlib.h> 

static const int I = 1;
static const int V = 5;
static const int X = 10;
static const int L = 50;
static const int C = 100;
static const int D = 500;
static const int M = 1000;

int romanCharToInt(char romanChar)
{
    switch (romanChar)
    {
        case 'I': return I;
        case 'V': return V;
        case 'X': return X;
        case 'L': return L;
        case 'C': return C;
        case 'D': return D;
        case 'M': return M;

        case '\0': return 0;
    }

    return 0; // Becaue I cannot throw exceptions
}

int roman_to_int(const char *numeral)
{
    // Converts a roman number to an integer

    int res = 0;

    for (const char *charIter = numeral; *charIter; ++charIter)
    {
        const char *nextIter = charIter + 1;

        const int currInt = romanCharToInt(*charIter);
        const int nextInt = romanCharToInt(*nextIter);
        
        if (currInt >= nextInt)
            res += currInt; // If next number is smaller or equal, just keep adding current
        else
            res -= currInt; // If next number is larger, we now we need to substract the current number, from the next (e.g. IX = 10-1)
    }

    return res;
}

char *int_to_roman(int val)
{
    // Converts an integer to a roman number
    // NOTE: The result is a malloced string, which needs to be freed

    char *result = malloc(4000);

    char *p = result;
    int integerIter = val;
    
    // The whole function is a repeated pattern (substract 9 if any (e.g IX) then 5 if any, then 4 if any (e.g. IV) then 1s, and append to output string)

    // Add M's representing 1000 each, if any
    while (integerIter >= M)
    {
        integerIter -= M;
        *p++ = 'M';
    }

    // Add CM representing 900 (1000-100) if any
    if (integerIter >= (M-C))
    {
        integerIter -= (M-C);
        *p++ = 'C';
        *p++ = 'M';
    }

    // Then add D representings 500, if any
    if (integerIter >= D)
    {
        integerIter -= D;
        *p++ = 'D';
    }

    // Then add CD representings 400, if any
    if (integerIter >= (D-C))
    {
        integerIter -= (D-C);
        *p++ = 'C';
        *p++ = 'D';
    }

    // Then repeat for  100s, 10s, down to 1s...

    // 100s
    while (integerIter >= C)
    {
        integerIter -= C;
        *p++ = 'C';
    }

    // 90
    if (integerIter >= (C-X))
    {
        integerIter -= (C-X);
        *p++ = 'X';
        *p++ = 'C';
    }

    // 50
    if (integerIter >= L)
    {
        integerIter -= L;
        *p++ = 'L';
    }

    // 40
    if (integerIter >= (L-X))
    {
        integerIter -= (L-X);
        *p++ = 'X';
        *p++ = 'L';
    }

    // 10s
    while (integerIter >= X)
    {
        integerIter -= X;
        *p++ = 'X';
    }

    // 9
    if (integerIter >= (X-I))
    {
        integerIter -= (X-I);
        *p++ = 'I';
        *p++ = 'X';
    }

    // 5
    if (integerIter >= V)
    {
        integerIter -= V;
        *p++ = 'V';
    }

    // 4
    if (integerIter >= (V-I))
    {
        integerIter -= (V-I);
        *p++ = 'I';
        *p++ = 'V';
    }
    
    // 1s
    while (integerIter >= I)
    {
        integerIter -= I;
        *p++ = 'I';
    }

    *p = '\0';
    return result;
}

int main()
{
    for (int i = 1; i < 4000; ++i)
    {
        char *roman = int_to_roman(i);
        const int integer = roman_to_int(roman);
        printf("integer: %d    roman: %s\n", integer, roman);
        
        free(roman);
    }

    return 0;
}
