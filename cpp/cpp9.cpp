#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double weight {7.7};
    cout << "weight rounded to floor is " << floor(weight) << endl;
    cout << "weight rounded to ceil is " << ceil(weight) << endl;

    double saving {-5000};
    cout << "abs of weight is " << abs(weight) << endl;
    cout << "abs of saving is " << abs(saving) << endl;

    cout << "3^4 : " << pow(3,4) << endl;
    cout << "2^4 : " << pow(2,4) << endl;

    cout <<"square of 9 is " << sqrt(9) << endl;

    int number1 {20};
    int number2 {25};
    bool result = (number1 < number2);
    cout << boolalpha << result << endl;
    return 0;
}