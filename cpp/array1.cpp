#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int scores [n];
    for(int i =0;i<n;i++){
        cin >> scores[i];
    }

    for(int i =0;i<n;i++){
        cout << "The Element at " << "[" << i << "] : " << scores[i] << endl;
    }

    double salaries [5] ={12.7,5.5,13.7,19.2,2.1};
    for(int i =0;i<n;i++){
        cout << "The Salary of person 1 is  " << "[" << i << "] : " << salaries[i] << endl;
    }

    
   	//Omit the size of the array at declaration
   
    int class_sizes[] {10,12,15,11,18,17,23,56}; 
	
	// Will print this with a range based for loop
	for(auto value : class_sizes){
		std::cout << "value : " << value << std::endl;
	}

    cout << "The size of score array is : " << (sizeof(scores) / sizeof(scores[0])) << endl; //alternate way o find the size of the array 

    return 0;
}

