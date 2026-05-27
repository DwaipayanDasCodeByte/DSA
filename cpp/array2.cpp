#include <iostream>
using namespace std;

int main()
{
    char message[6]{'H', 'e', 'l', 'l', 'o','\0'};

    for(auto c : message){
        cout << "The letter is :" << c << endl;
    }

    cout<<endl;

  
    for (int i = 0; i < 5; i++)
    {
        cout << message[i] << endl;
    }
    cout << message << endl;
    cout << sizeof(message) << endl;
    return 0;
}