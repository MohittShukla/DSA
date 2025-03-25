#include <iostream>
using namespace std;

int maxSum(int arr[],int n,int k){
    int sum ;
    int mx = INT_MIN;

    int i,j = 0;
    while(j<n){
        sum += arr[j];
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            mx = max(mx,sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return mx;

    


    
}


int main(){
    int arr[9] = {1,21,42,40,3,3,2,4,2};
    int n = 9;
    int k = 3;
    cout<< maxSum(arr,9,5);
}
