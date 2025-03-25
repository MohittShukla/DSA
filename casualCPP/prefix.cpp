#include <iostream>
#include <vector>
using namespace std;

vector <int> prefix(vector<int> &arr){

    int n = arr.size();
    vector<int> prefixSum(n);
     prefixSum[0] = arr[0];

     for(int i = 1;i<n;i++){
        prefixSum[i] = prefixSum[i-1]+ arr[i];
     }

     return prefixSum;

}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(7);


   vector< int> prefixx = prefix(arr);
    
    cout<<"{ ";
    for(int i = 0;i<prefixx.size();i++){
        cout<< prefixx[i];
    }
   cout<<"}";
}
