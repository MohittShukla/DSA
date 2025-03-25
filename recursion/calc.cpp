#include <iostream>
using namespace std;

int addition(int a, int b){
    return a+b;
}

int subtraction(int a,int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int divide(int a,int b){
    return a/b;
}

int main(){
    int a,b;
    cout<< "Ram what is your first number ->  ";
    cin>> a;
    cout<< "Ram what is your second number ->  ";
    cin>> b;

    int result = addition(a,b);
    
    cout<< "your answer is -> "<< result<<endl;
    



}
