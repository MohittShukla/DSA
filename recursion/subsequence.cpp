#include<iostream>
#include<vector>
using namespace std;


 void findSub(vector<int> &arr, vector<vector<int > > &sub,int n){
    vector<int> ans;
    if(n == 0){
        sub.push_back({{}});
        return;
    }
    findSub(arr,sub,n-1);
    sub.push_back(ans);
 }
int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    vector<vector<int > > sub;
    findSub(arr,sub,4);

    for(int i = 0;i<sub.size();i++){
        for(int j = 0;j<sub[0].size();j++){
            cout<< sub[i][j]<<endl;
        }
    }
}
