#include <iostream>

using namespace std;

void reverseArray(int arr[],int start, int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

}
int main(){
    int arr[8] = {1,3,4,6,6,7,3,2};
    int n = 8;


    int k = 2;
    k = k%n;

    reverseArray(arr,0,n-1);
    reverseArray(arr,0,k-1);
    reverseArray(arr,k,n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    

}
