#include <iostream>
using namespace std;

int linearSearch(int arr[],int n, int index,int target){

    if(index == n){
        return -1;
    }

    if(arr[index]== target){

        return index;

    }

    return linearSearch(arr,n,index+1,target);
    
}


int main(){
    
    int arr[5] = {3,3,5,32,4};
    int n = 5;
    int target = 32;

    int result = linearSearch(arr,n,0,target);

    if(result == -1){
        cout<< "Element not found";
    }
    else{
        cout<< "Element found at position " << result+1;
    }

}
