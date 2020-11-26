/**
 * Sebastian Pawlaczyk
 * solution for https://projecteuler.net/problem=225
 **/

#include <cstdio>
#include <cstdint>

uint32_t tribonacciNonDivisor(const uint32_t nth)
{
    uint32_t currentDivisor = 29;
    uint32_t maxDivisor = 27; //  optimization, starting from 1th knownw
    uint32_t counter = 0;
    while (counter != nth - 1)
    {
        int a = 1, b = 1, c = 1;

        while (true)
        {
            uint32_t nextValue = (a + b + c) % currentDivisor; // only modulo value neeeded
            if (nextValue % currentDivisor == 0)
            {
                break;
            }

            a = b;
            b = c;
            c = nextValue;

            if (a == 1 && b == 1 && c == 1)
            {
                maxDivisor = currentDivisor;
                counter++;
                break;
            }
        }
        currentDivisor += 2;
    }
    return maxDivisor;
}

int main()
{
    const uint32_t nth = 124;
    printf("%u\n", tribonacciNonDivisor(nth));
}
