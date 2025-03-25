#include<iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;   
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{   
                return;

            }
        }
    }
    void print(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
   void deleteFromHeap() {
    if (size == 0) {
        return;
    }

    // Replace root with the last element
    arr[1] = arr[size];
    size--;

    // Heapify down
    int i = 1;
    while (i <= size) {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;
        int largest = i;
       
        
        // Compare with left child
        if (leftIndex <= size && arr[leftIndex] > arr[largest]) {
           
            largest = leftIndex;
        }
        // Compare with right child
        if (rightIndex <= size && arr[rightIndex] > arr[largest]) {
             
            largest = rightIndex;
        }

        // If the largest is not the current node, swap and continue
        if (largest != i) {
            
            swap(arr[i], arr[largest]);
            i = largest;
        } else {
            return;
        }
    }
}

};

int main(){
    heap h;
    h.insert(55);
    h.insert(54);
    h.insert(27);
    h.insert(99);
    h.insert(77);
    h.insert(52);
    h.print();
    h.deleteFromHeap();

    cout<<endl;
    h.print();
}
