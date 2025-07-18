//diagonal matrice in C++
#include <iostream>
using namespace std;
class Diagonal{
private:
    int n;
    int *A;
public:
    Diagonal(){
        n =2;
        A = new int[2];
    }
    Diagonal(int n){
        this->n = n;
        A = new int[n];
    }
    void set(int i,int j,int x);
    int get(int i, int j);
    void display();
    ~Diagonal(){          // Destructor to free allocated memory
        delete[] A;
    }
};
void Diagonal::set(int i,int j,int x){
    if(i == j && i>=1 && i<=n){
        A[i-1] = x;
    }
}
int Diagonal::get(int i,int j){
    if(i == j && i>=1 && i<=n){
        return A[i-1];
    }
    return 0;
}
void Diagonal::display(){
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<< A[i] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
int main(){
    Diagonal d(4);
    d.set(1, 1, 5);
    d.set(2, 2, 6);
    d.set(3, 3, 7);
    d.set(4, 4, 8);
    d.display();
    cout << "Element at (2,2): " << d.get(2, 2) << endl;
    cout << "Element at (1,2): " << d.get(1,1) << endl;

    return 0;
}