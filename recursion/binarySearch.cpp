#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int target ){

    if(s > e){
        return -1;
    }

    

    int mid = s+ (e-s)/2;

    
    if(arr[mid]== target){
        return mid;
    }

    if(arr[mid]<target){
        return binarySearch(arr,mid+1,e,target);

    }
  
    return binarySearch(arr,s,mid-1,target);
    



}

int main(){
    int arr[5] = {4,6,30,54,60};
    int n = 5;

    int target = 60;

    int result = binarySearch(arr,0,n-1,target);

    if(result == -1){
        cout<< "can't see what you are trying to find  "<<endl;
    }

    else{
    cout<< "we found the element at the position-> "<< result+1<<endl;;

    }
}
