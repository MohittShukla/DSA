// In a heap the leaf nodes are present from (n/2+1) to n index where n is the size of the array,this is for 1-based indexing
// In 0 based indexing (n/2-1) to 0 is non leaf node; in 1 based indexing it is n/2 to 1;
// In 0 based indexing left child -> 2*i+1, right child-> 2*i+2
// in 1 based indexing left Child-> 2*i, right child -> 2*i+1
// so in heapify algorithm we have to only process from 1 to n/2
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
int main(){
    int arr[6] = {-1,55,32,34,92,21};
    int size = 5;
    int i = size/2;
    // Building the heap
    for(int i = size/2;i>0;i--){
        heapify(arr,size,i);
    }
    for(int i = 1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
