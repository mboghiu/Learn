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

bool Anagrams(const std::string& s1, const std::string& s2)
{
    std::vector<int> c1, c2;
    c1.resize(256);
    c2.resize(256);

    for (char c : s1)
        if (c != ' ')
            c1.at((int)tolower(c))++;

    for (char c : s2)
        if (c != ' ')
        c2.at((int)tolower(c))++;

    for (size_t i = 0; i < 256; i++)
        if (c1[i] != c2[i])
            return false;

    return true;
}

int main()
{
    AreEqual(true, Anagrams("", ""), "two empty strings");
    AreEqual(true, Anagrams("ab","ba"), "ab : ba");
    AreEqual(true, Anagrams("Ab","ba"), "Ab : ba");
    AreEqual(true, Anagrams("Maria has apples","Im rash as appeal"), "[4]");
    AreEqual(true, Anagrams("Maria Boghiu","Ugh I am a biro"), "[5]");
    AreEqual(false, Anagrams("Santaa","Santa"), "[4]");

    return 0;
}
