#include <iostream>
using namespace std;

int powerOf(int n,int k){
    if(k == 0){
        return 1;
    }
    return n * powerOf(n,k-1);
   
}

int main(){
    int n;
    int k;

    cout<< "Enter the number: ";
    cin>> n;

    cout<< "Enter the power: ";
    cin >> k;

    cout<< powerOf(n,k);
    



}
