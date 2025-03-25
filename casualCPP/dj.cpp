#include<iostream>
using namespace std;

int solution(string &S, string &T) {
    // Implement your solution here
    int n = S.size();
    int i = 0;
   
    int num1 = stoi(S);
    int num2 = stoi(T);

    string big;
    string small;
    

    while(S[i] == T[i]){
        i++;
    }

    if(S.substr(0,i+1)>T.substr(0,i+1)){
        big = S;
        small = T;
    }   
    else{
      big = T;
        small = S;
    }
     int swapCount = 0;
        i++;
    while(i<n){
        if(big[i]>small[i]){
            swap(big[i],small[i]);
            swapCount++;
            }
            i++;
 } 
   return swapCount;  
}

int main(){
    string S = "19000";
    string T = "19000";
    cout<< solution(S,T);
}
