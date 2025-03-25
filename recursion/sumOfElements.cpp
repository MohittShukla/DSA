#include <iostream>
using namespace std;

int sumOfElements(int arr[],int n,int index){

    if(index == n){
        return 0;
    }

    return arr[index] + sumOfElements(arr,n,index+1);


}

int main(){


    int arr[5] = {2,5,2,2,3};
    int n = 5;

    cout << sumOfElements(arr,5,0)<<" ";

}
