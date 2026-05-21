#include <iostream>
#include <string>
using namespace std;

int main(){
    // int age;
    // string name;
    // cin >> name >> age;
    // cout << "Hello My name is " << name << "and my age is " << age << endl;
    // cin.ignore();

    //data with spaces to grab the the last name
    string full_name;
    int age1;
    cout<<"Please enter your full name and age"<< endl;
    getline(cin,full_name);
    cin >> age1; 
    cout << "Hello My name is " << full_name << " and my age is " << age1 << endl;
    return 0;
}