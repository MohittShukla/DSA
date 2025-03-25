#include<iostream>
#include<stack>
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

    vector<int> res(n);
    stack<int> st;

}
