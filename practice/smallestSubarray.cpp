#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<" Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);

    for(int i = 0;i<n;i++){
        cout<< "Enter the elements-> ";
        cin>>arr[i];
    }

    int sum;
    cout<< "write the sum you wanna find the subarray for -> ";
    cin>> sum;


    int i = 0;
    int j = 0;
    int minL = INT_MAX;
    int value = 0;
    while(j<n){
        value += arr[j];
        while(value>sum){
            value -= arr[i];
            i++;
        }
        if(value == sum){
            minL = min(minL,j-i+1);
        }
        j++;

    }
    if (minL != INT_MAX) {
        cout << "smallest subarray size is: " << minL << endl;
    } else {
        cout << "No subarray found with the given sum." << endl;
    }

    

    return 0;
}
