#include <iostream>
using namespace std;
int main()
{
    // dynamic arrays
    const size_t size{10};
    double *p_salaries{new double[size]};      // will contain garbage value in the indices of the array
    int *p_student{new (nothrow) int[size]{}}; // all values in array are initialized to zero same as new int[5];//nothrow if an error do not throw
    double *p_scores{new (nothrow) double[size]{2.0, 6.5, 7.1, 1.5, 1.22}};

    if (p_scores)
    {
        std::cout << "size of scores (it's a regular pointer) : " << sizeof(p_scores) << std::endl;
        std::cout << "Successfully allocated memory for scores." << std::endl;

        // Print out elements. Can use regular array access notation, or pointer arithmetic
        for (size_t i{}; i < size; ++i)
        {
            std::cout << "value : " << p_scores[i] << " : " << *(p_scores + i) << std::endl;
        }
    }

    delete[] p_salaries;
    p_salaries = nullptr;

    delete[] p_student;
    p_student = nullptr;

    delete[] p_scores;
    p_scores = nullptr;
    return 0;
}