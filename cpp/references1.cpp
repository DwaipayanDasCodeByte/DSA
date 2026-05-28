#include <iostream>
using namespace std;

int main()
{
    int original_value = 100;
    int &ref = original_value;

    ref = 200;
    cout << original_value << endl; // Output: 200
    cout << ref << endl;            // Output: 200

    
    int score = 100;
    // Create a read-only nickname for 'score'
    const int &read_only_ref = score;

    std::cout << read_only_ref << std::endl; // LEGAL: You can read it (Outputs 100)

    // read_only_ref = 200; // ERROR! The compiler will block this. You cannot change it!

    return 0;
}