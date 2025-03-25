#include<iostream>
#include<unordered_map>
using namespace std;
// so in unordered map to check if a value exist we do 


int main(){
    int arr[5] = {2,3,4,4,6};
    unordered_map<int,int> ump;
    // for frequency 
    for(int i = 0;i<5;++i){
        ump[arr[i]]++;
    }
    // iterating ump
    for(auto &pair: ump){
        cout<< "value is-> "<< pair.first<< "frequency-> "<<pair.second<<endl;
    }
    // for indices
    unordered_map<int,int> up;
    for(int i = 0;i<5;i++){
        up[arr[i]] = i;
           }
    for(auto &pair: up){
        cout<< "value is-> "<< pair.first<< "index-> "<<pair.second<<endl;
    }
    // for(auto it = up.begin();it!=up.end();++it){
    //     cout<<"value is-> "<<it->first<<"index-> "<<it->second<<endl;
    // }
    // to check if a value is there
    for(int i = 0;i<5;i++){
        if(ump[arr[i]]==2){
            cout<<arr[i]<<" ";
        }
    }
    //  there is also if(ump.find(nums[i])!= ump.end()) you can use that's all;
}
