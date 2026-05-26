#include <iostream>
using namespace std;

int main(){
    for(int i{};i<10;i++){
        cout << "I love C++ !" << endl;
    }

    cout << endl;

    for(int i = 0;i<10;i++){
        cout << "I love C++ !" << endl;
    }

    cout << endl;
    //using size_t
    for(size_t i{0}; i<10 ; i++){
        cout << "i love C++" << endl;
    }
    cout << "the loop is done here "<< endl;

    cout << endl;

    // const size_t COUNT {10};
    // for(size_t i{0};i<COUNT;i++){
    //   cout << "I love C++ !" << endl;  
    // }

    cout << endl;
                             
    const unsigned int COUNT{10};
    unsigned int i{0};

    while(i<COUNT){
        cout << "I love C++ !" << endl;
        i++;
    }

    cout << endl;

    const unsigned int COUNT1{10};
    unsigned int j{11};
    do{
        cout << "[" << j << "] : " << "I Love C++" << endl;
    }while (j < COUNT1);


    return 0;
}
