#include <iostream>
using namespace std;

int main(){
    int a {7};
    int b {6};
    int c {15};
    c +=5;

    cout << "the value is " << a++ << endl; //post increment
    cout << "the value is " << a << endl;
    cout << "the value is " << ++b << endl; // pre increment
    cout << "the value is " << b << endl;

    cout << "the value is " << a-- << endl; //post increment
    cout << "the value is " << a << endl;
    cout << "the value is " << --b << endl; // pre increment
    cout << "the value is " << b << endl;

    cout << "c+=5: " << c << endl; // c = c + 5 , can be done for same * , - , / , % 
    return 0;
}