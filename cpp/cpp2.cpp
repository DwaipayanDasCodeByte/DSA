#include <iostream>
using namespace std;

int main(){
    int number1 = 15; //Decimal
    int number2 = 017; //octal
    int number3 = 0x0F; //hexa
    int number4 = 0b00001111; //binary
    int number5 {5};
    int number6 {6};

    cout << "the number is " << number1 << endl;
    cout << "the number is " << number2 << endl;
    cout << "the number is " << number3 << endl;
    cout << "the number is " << number4 << endl;
    cout << "the number is " << number5 + number6 << endl; 
    cout << "the size of int " << sizeof(int) << endl;
    cout << "the size of float " << sizeof(float) << endl;
    cout << "the size of bool " << sizeof(bool) << endl;
    return 0;
}