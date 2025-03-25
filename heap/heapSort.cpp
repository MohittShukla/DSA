// algo for heap sort 1. swap the first index with the last, then after swapping put the node to it's right position using heapify and do size-- after doing it

#include <iostream>
using namespace std;
void heapify(int arr[],int size,int i ){
   
    int largest = i;
        int leftIndex = 2*i;
        int rightIndex = 2*i+1;
        if(leftIndex<=size && arr[leftIndex]>arr[largest]){
            largest = leftIndex;
        }
        if(rightIndex<=size && arr[rightIndex]>arr[largest]){
            largest = rightIndex;
        }
        if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest); 
    }

}

void heapSort(int arr[],int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}
int main(){
    int arr[6] = {-1,54,53,55,52,50};
    int size = 5;
    int i = size/2;

    for(int i = size/2;i>0;i--){
        heapify(arr,size,i);
    }
    for(int i = 1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,size);
    for(int i = 1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
