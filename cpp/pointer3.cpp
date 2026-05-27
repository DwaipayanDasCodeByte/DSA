#include <iostream>
using namespace std;

int main()
{
    // Dynamic memory allocation
    int number{22};
    int *p_number = &number;
    cout << number << endl;
    cout << p_number << endl; // address stored in the pointer
    cout << *p_number << endl;
    cout << &number << endl;

    // bad practice
    cout << endl;
    // int *p_number2;
    // *p_number2 = 55;

    // dynamic heap memory
    int *p_number4{nullptr}; //pointing to the null
    p_number4 = new int; // dynamically allocate space for a single int on heap , the memory is allocated now no value is initialized in the allocated memory till now
    *p_number4 = 77; //value initialized in heap
    cout << *p_number4 << endl;

    delete p_number4;
    p_number4 = nullptr;
    return 0;
}