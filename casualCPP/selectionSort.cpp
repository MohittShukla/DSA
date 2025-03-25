#include <iostream>
using namespace std;


void selectionSort(int arr[],int n){
    for(int i = 0;i<n;i++){
        for(int j =i+1;j<n;j++){
        if(arr[j]<arr[i]){
            swap(arr[j],arr[i]);
        }
        }
    }
}
int main(){
    int arr[6] = {33,4,32,223,1,23};
    selectionSort(arr,6);
    for(int i =0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}
