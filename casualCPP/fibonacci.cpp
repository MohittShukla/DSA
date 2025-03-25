#include <iostream>
using namespace std;

int main(){
    int n;
    cin>> n;
    int a = 0;
    int b = 1;
    int next = a+b;
    while(a<n){
        a  = b;
        b = next;
        next = a+b;
    }
    cout<<"your value is -> "<< a<< endl;
}
