#include <iostream>
using namespace std;

int factorial(int n){
    int i = 0;
    if(n == 0){
        return 1;
    }

    int ans = n * factorial(n-1);
    cout<< "it's working"<<i+1<<endl;
    return ans;
    
}

int main() {
    int n;
  cout<< "Factorial of -> ";
    cin>> n;
    cout<< factorial(n);
}
