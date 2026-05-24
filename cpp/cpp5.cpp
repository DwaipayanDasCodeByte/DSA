#include <iostream>
using namespace std;

int main(){
    auto var1 {12};
    auto var2 {14.0f};
    auto var3  {15.0l};
    auto var4 {123u}; //unsigned

    // cout << "the size is " << sizeof(var1) << endl;
    // cout << "the size is " << sizeof(var2) << endl;
    // cout << "the size is " << sizeof(var3) << endl;
    // cout << "the size is " << sizeof(var4) << endl;

    // basic operation

    int num1 {15};
    int num2 {6};
    int result {num1 + num2};
    
    cout << "The addition of two number " << result << endl;

    int result1 {num1 - num2};

    cout << "The subtraction of two number " << result1 << endl;

    int result2 {num1 * num2};

    cout << "The multiplication of two number " << result2 << endl;

    int result3 {num1 / num2};

    cout << "The division of two number " << result3 << endl;

    int result4 {num1 % num2};

    cout << "The modulus of two number " << result4 << endl;
    return 0;
}