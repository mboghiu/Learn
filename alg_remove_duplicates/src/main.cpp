#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cassert>
#include <cctype>
#include <bitset>

void AreEqual(const std::string& expected, const std::string& actual)
{
    if (expected == actual)
        std::cout << "\033[32mPASS\033[0m" << std::endl;
    else
    {
        std::cout << "\033[31mFAIL\033[0m" << std::endl;
        std::cout << "expected: " << expected << std::endl;
        std::cout << "actual: " << actual << std::endl;
    }
}

std::string RemoveDuplicates(const std::string& s)
{
    std::string c(s);

    std::bitset<256> have;

    size_t ow = 0;
    for (size_t x = 0; x < c.length(); x++)
        if (!have.test((int)c.at(x)))
        {
            c.at(ow) = c.at(x);
            have.set((int)c.at(x));
            ow++;
        }
            
    c = c.substr(0, ow);
    return std::move(c);
}

int main()
{
    AreEqual("abc", RemoveDuplicates("aaaabc"));
    AreEqual("a", RemoveDuplicates("aaaa"));
    AreEqual("ab", RemoveDuplicates("aaaabbbbb"));
    AreEqual("Mari", RemoveDuplicates("Maria"));
    AreEqual("ab", RemoveDuplicates("aaaaabbbaaa"));
    AreEqual("abc", RemoveDuplicates("aaaaabbbaaacccc"));
    AreEqual("", RemoveDuplicates(""));
    AreEqual("Aalex", RemoveDuplicates("Aalex"));

    return 0;
}
