#include <string>

#include "test.hpp"
#include "stack.hpp"

int main()
{
    Queue<int>* s = new Queue<int>();
    Test<std::string>("", s->ToString());

    s->Push(4);
    Test<std::string>("4 | ", s->ToString());

    s->Push(5);
    Test<std::string>("4 | 5 | ", s->ToString());

    s->Push(7);
    s->Push(6);
    Test<std::string>("4 | 5 | 6 | 7 | ", s->ToString());

    s->Pop();
    Test<std::string>("5 | 6 | 7 | ", s->ToString());
    s->Pop();
    s->Pop();
    Test<std::string>("7 | ", s->ToString());
    s->Pop();
    Test<std::string>("", s->ToString());


    return 0;
}
