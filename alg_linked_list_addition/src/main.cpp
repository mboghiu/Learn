#include <iostream>
#include <cstddef>
#include <sstream>

#include "tester.hpp"
#include "linked.hpp"

int main()
{
    Node* c1 = (new Node(3))->Add(1); // 13
    Node* c2 = (new Node(3))->Add(1)->Add(5); // 513
    Test<bool>(false, *c1 == *c2);

    Node* d1 = (new Node(3))->Add(1)->Add(5); // 513
    Node* d2 = (new Node(3))->Add(1)->Add(5); // 513
    Test<bool>(true, *d1 == *d2);

    Node* e1 = (new Node(3)); // 3
    Node* e2 = (new Node(3)); // 3
    Test<bool>(true, *e1 == *e2);

    // 513 + 295 = 808
    Node* x1 = (new Node(3))->Add(1)->Add(5); // 513
    Node* y1 = (new Node(5))->Add(9)->Add(2); // 295
    Node* r1 = (new Node(8))->Add(0)->Add(8); // 808
    x1->Print(); y1->Print(); r1->Print();
    Test<bool>(true, *r1 == (*x1 + *y1));

    // 999 + 111 = 1110
    Node* x2 = (new Node(9))->Add(9)->Add(9);
    Node* y2 = (new Node(1))->Add(1)->Add(1);
    Node* r2 = (new Node(0))->Add(1)->Add(1)->Add(1);
    x2->Print(); y2->Print(); r2->Print();
    Test<bool>(true, *r2 == (*x2 + *y2));

    // 13 + (-1) = 12
    Node* x3 = (new Node(3))->Add(1);
    Node* y3 = (new Node(-1));
    Node* r3 = (new Node(2))->Add(1);
    x3->Print(); y3->Print(); r3->Print();
    Test<bool>(true, *r3 == (*x3 + *y3));

    return 0;
}
