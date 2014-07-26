
struct X
{
    int me;
    X(int i) : me(i) { }
    ~X() { me = 0; }
};

int main()
{
    X x(3);

    return 0;
}
