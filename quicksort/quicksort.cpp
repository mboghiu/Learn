#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void parse_arguments(int argc, char** argv, std::vector<int>& v)
{
    if (argc < 2)
    {
        std::cout << "\033[31mYou must give a string of numbers to sort.\033[0m" << std::endl;
        exit(1);
    } for (int arg = 1; arg < argc; arg++)
    {
        v.push_back(atoi(argv[arg])); 
    }
}

void echo(const std::vector<int>& v, const std::string& message, size_t highlight = - 1)
{
    std::cout << message << " --- v: ";

    for (size_t index = 0; index < v.size(); index++)
        if (index == highlight)
            std::cout << "\033[32m" << v.at(index) << "\033[0m ";
        else
            std::cout << v.at(index) << " ";

    std::cout << std::endl;
}

int partition(std::vector<int>& elements, const size_t begin, const size_t end)
{
    int pivotValue = elements.at(begin);

    // Move pivot on the last position
    std::swap(elements.at(begin), elements.at(end - 1));

    size_t currentUnsortedPosition = begin;
    for (size_t iter = begin; iter < end - 1; iter++)
    {
        if (elements.at(iter) <= pivotValue)
        {
            std::swap(elements.at(iter), elements.at(currentUnsortedPosition));
            currentUnsortedPosition++;
        }
    }

    // Move pivot from the last position to the currentUnsortedPosition
    std::swap(elements.at(end - 1), elements.at(currentUnsortedPosition));

    echo(elements, "\033[34mPARTITION\033[0m", currentUnsortedPosition);

    return currentUnsortedPosition;
}

void quicksort(std::vector<int>& elements, const size_t begin, const size_t end)
{
    if (begin < 0 or end > elements.size() or end - begin < 1)
        return;

    int finalPivotPosition = partition(elements, begin, end);

    quicksort(elements, begin, finalPivotPosition);
    quicksort(elements, finalPivotPosition + 1, end);
}

int main(int argc, char** argv)
{
    std::vector<int> v;
    parse_arguments(argc, argv, v);

    quicksort(v, 0, v.size());

    return 0;
}
