#include <iostream>
using namespace std;

int main()
{
    int *p_number{};        // can only store an address of a variable of type int
    double *p_fractional{}; // can only store an address of a variable of type double
    cout << "size of pointer(int type) : " << sizeof(p_number) << endl;
    cout << "size of pointer(int double) : " << sizeof(p_fractional) << endl;
    cout << endl;
    int int_var{62};
    int *pointer{&int_var};
    cout << pointer << endl;  // returns a garbage value
    cout << *pointer << endl; // de-referencing

    int *p;
    int a = 54;
    p = &a;
    cout<< *p << endl;
    cout<< p << endl;
    return 0;
}