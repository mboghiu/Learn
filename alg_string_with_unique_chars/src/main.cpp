#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cassert>
#include <cctype>
#include <bitset>

void AreEqual(bool expected, bool actual, const std::string& input)
{
    if (expected == actual)
        std::cout << "\033[32mPASS\033[0m" << std::endl;
    else
    {
        std::cout << "\033[31mFAIL\033[0m" << std::endl;
        std::cout << "input: " << input << std::endl;
    }
}

bool AllUnique(const std::string& s)
{
    std::bitset<256> have;

    for (char c : s)
        if (have.test((int)tolower(c)))
            return false;
        else
            have.set((int)tolower(c));
    return true;
}

bool AllUnique_Naive(const std::string& s)
{
    for (size_t x = 0; x < s.length(); x++)
        for (size_t y = x+1; y < s.length(); y++)
            if (tolower(s.at(x)) == tolower(s.at(y)))
                return false;

    return true;
}

int main()
{
    AreEqual(true, AllUnique("abc"), "abc");
    AreEqual(false, AllUnique("Aa"), "Aa");
    AreEqual(false, AllUnique("Maria"), "Maria");
    AreEqual(true, AllUnique("Alex"), "Alex");
    AreEqual(true, AllUnique("AlEx"), "EAlex");
    AreEqual(true, AllUnique(""), "<empty string>");

    return 0;
}
