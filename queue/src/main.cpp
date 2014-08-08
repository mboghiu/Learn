#include <string>

#include "test.hpp"
#include "queue.hpp"

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
    Test<std::string>("4 | 5 | 7 | 6 | ", s->ToString());

    s->Pop();
    Test<std::string>("5 | 7 | 6 | ", s->ToString());
    s->Pop();
    s->Pop();
    Test<std::string>("6 | ", s->ToString());
    s->Pop();
    Test<std::string>("", s->ToString());


    return 0;
}
