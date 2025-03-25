#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
   cout<< s.top();
}
