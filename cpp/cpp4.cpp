#include <iostream>
using namespace std;

int main(){
    char character1 {'a'};
    char character2 {'r'};
    char character3 {'r'};
    char character4 {'o'};
    char character5 {'w'};

    cout << "the letter is " << character1 << endl;
    cout << "the letter is " << character2 << endl;
    cout << "the letter is " << character3 << endl;
    cout << "the letter is " << character4 << endl;
    cout << "the letter is " << character5 << endl;
    cout << "the word is " << character1 << character2 << character3 << character4 << character5  << endl;
    cout << "value " << static_cast<int>(character1) << endl;

    bool red_light {true};
    bool green_light {false};
    if(red_light == true){
        cout << "please stop " << endl;
    }else{
        cout << "you can go " << endl;
    }
    return 0;
}