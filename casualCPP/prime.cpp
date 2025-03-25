#include<iostream>
using namespace std;
int main(){
    int n = 10;
    bool isPrime = false;

    for(int i = 2;i<=n/2;i++){
        if(n%i== 0){

            cout<< "not a prime";
            break;

        } 
        else {
            isPrime = true;
        }

        
        
           }
           if(isPrime){
            cout<< "number is prime";
        }
}
