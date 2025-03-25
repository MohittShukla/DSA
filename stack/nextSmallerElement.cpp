#include <iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array-> ";
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cout<<"Enter the element of the array: ";
        cin>>arr[i];
        cout<<endl;
    }

    vector<int> nums(n);

    stack<int> s;
    s.push(-1);
    for(int j = n-1;j>=0;j--){
        int curr = arr[j];
        //finding the next smaller element and then adding it to the nums vector
        while(s.top()>=curr){
            s.pop();
        }
        nums[j] = s.top();
        // again pushing the current value to the stack so that stack remains intact for further loop
        s.push(curr);
    }
    cout<<"{";
    for(int k = 0;k<n;k++){
        cout<< nums[k]<<" ";
    }
    cout<<"}";

}
