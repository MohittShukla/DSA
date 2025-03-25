#include <iostream>
using namespace std;

int main(){
    int arr[6] = {1,-1,4,5,5,-5};

    int n = 6;

    int maximum = INT_MIN;
    int end = 0;

    for(int i = 0;i<n;i++){
        end = end + arr[i];
            

        if(maximum<end){
            
            maximum = end;

        }
    if(end<0){
        end = 0;
    }
    }
    cout<< maximum;
}
