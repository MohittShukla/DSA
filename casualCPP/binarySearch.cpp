#include <iostream>
#include<vector>


using namespace std;
int main(){


    int n;
    cout<<"enter your size-> ";
    cin>> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter the values(in ascending order) ";
        cin>> arr[i];
    }

    int target;
    cout<< "Which value you wanna find ";
    cin>> target;

 
    bool isthere = false;
    
    int i = 0;
    int j = n-1;

    int ans = 0;
    while(i<=j){
        int mid = (i+j)/2;
        if(arr[mid] == target){
            ans = mid+1;
            isthere = true;
            break;
            
            
        }
        else if(arr[mid]<target){
            i = mid+1;
        }
        else{
            j= mid-1;
        }
    }

    if(isthere){
        cout<< "your answer is at index-> "<<ans<<endl;
    }
    else{
        cout<<"it isn't there "<<endl;
    }


}
