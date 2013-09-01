#include <iostream>
#include <string>
#include <algorithm>

void perm(const std::string& prefix, const std::string& str)
{
    if (str.size() == 1)
    {
        std::cout << prefix << str << ";" << std::endl;
        return;
    }

    for (char c : str)
    {
        std::string save = str;
        perm(prefix + c, save.erase(save.find_first_of(c), 1));
    }
}

void inplaceperm(std::string& str)
{
    for (size_t put = 0; put < str.size(); put++)
        for (size_t get = (put == str.size() - 1 ? 0 : put + 1);
             get < put or get > put and get < str.size();
             get = (put < str.size() and get == str.size() - 1 ? 0 : get + 1))
        {
            std::cout << "put:" << put << " get:" << get << "   ";
            std::swap<char>(str.at(put), str.at(get));
            std::cout << str << ";" << std::endl;
            std::swap<char>(str.at(get), str.at(put));
        }
}

int main(int argc, char** argv)
{
    std::string stringToPermute;
    if (argc == 2)
        stringToPermute = argv[1];
    else
        stringToPermute = "bla";

    perm("", stringToPermute);

    std::cout << "====" << std::endl;

    inplaceperm(stringToPermute);
}
