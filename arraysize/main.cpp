#include <iostream>
#include <typeinfo>

void f(double* x)
{
    std::cout << "f array: " << sizeof(x) << std::endl;
    std::cout << "f first element: " << sizeof(x[0]) << std::endl;
    std::cout << "f type of x: " << typeid(x).name() << std::endl;
}

void ff(const double(&x)[3], int size)
{
    std::cout << "ff array: " << sizeof(x) << std::endl;
    std::cout << "ff type of x: " << typeid(x).name() << std::endl;
}

int main()
{
    double x[] = { 0.1f, 0.2f, 0.3f };

    std::cout << "array: " << sizeof(x) << std::endl;
    std::cout << "array*x: " << sizeof(*x) << std::endl;
    std::cout << "type of x: " << typeid(x).name() << std::endl;
    std::cout << "size of double: " << sizeof(double) << std::endl;
    std::cout << "size of pointer: " << sizeof(void*) << std::endl;

    std::cout << std::endl;
    std::cout << "first element: " << sizeof(x[0]) << std::endl;
    std::cout << "size of int: " << sizeof(int) << std::endl;

    f(x);

    std::cout << std::endl;

    ff(x, sizeof(x));

    return 0;
}
