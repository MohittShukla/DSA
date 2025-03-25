#include <iostream>
using namespace std;

int isSorted(int arr[],int n,int index){


    if(index == n-1){
        return true;
    }

    if(arr[index]>arr[index+1]){
        return false;
    }

    return isSorted(arr,n,index+1);


}

int main(){


    int arr[6] = {1,22,3,4,5,6};
    int n = 6;
    
    
    if(isSorted(arr,6,0)){
        cout<< "Array is sorted";

    }
    else{
        cout<< "array is not sorted";
    }

}
