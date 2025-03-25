#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n = 5;
    vector<int> input(n);
    input[0] = 1;
    vector<int> prefix(n);
    prefix[0] = 1;
    for(int i = 1;i<5;i++){
        input[i] = i*2;
    }
    for(int i = 0;i<5;i++){
        cout<< input[i]<<" ";
    }
    cout<<endl;
    for(int i = 1;i<n;i++){
        prefix[i] = prefix[i-1]* input[i-1];
        cout<< "multiplying "<<prefix[i-1] << " and "<<input[i-1]<<" we get -> "<< prefix[i]<<endl;
    }

    
    for(int i = 0;i<n;i++){
        cout<< prefix[i]<<" ";
    }
}
