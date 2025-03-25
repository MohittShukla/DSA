#include<iostream>
using namespace std;

int main(){
    int n = 42;
    int i = 0;
    bool prime[43];
    for(int i = 0;i<42;i++){
        prime[i] = true;

    }
    for(int i = 2; i*i<=n;i++){
        if(prime[i]){
            for(int j = i*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i =  2;i<=42;i++){
        if(prime[i]){
            cout<< i<< " ";
        }
    }
    return 0;
}
