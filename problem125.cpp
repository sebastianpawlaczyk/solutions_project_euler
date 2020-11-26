/**
 * Sebastian Pawlaczyk
 * solution for https://projecteuler.net/problem=125
 **/

#include <cstdio>
#include <cstdint>

bool isPalindrome(uint32_t value)
{
    const uint32_t originalValue = value;
    uint32_t reverseValue = value % 10;
    value = value / 10;
    while (value > 0)
    {
        reverseValue = (reverseValue * 10) + (value % 10);
        value = value / 10;
    }

    return originalValue == reverseValue;
}

uint32_t findPalindromicSums(const uint32_t interval)
{
    // first check for a^2 + b^2
    uint32_t sum = 0;
    for (uint32_t i = 1; i * i + (i + 1) * (i + 1) < interval; ++i)
    {
        uint32_t nextNumber = i + 1;
        uint32_t squareSum = i * i + nextNumber * nextNumber;

        while (squareSum < interval)
        {
            if (isPalindrome(squareSum))
            {
                sum = sum + squareSum;
            }
            ++nextNumber;
            squareSum = squareSum + nextNumber * nextNumber;
        }
    }
    return sum;
}

int main()
{
    const uint32_t interval = 100000000;
    printf("%u\n", findPalindromicSums(interval));
}
