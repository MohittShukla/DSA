#include <iostream>

using namespace std;

int main(){
    int rows,cols;
    cout<< "enter the number of rows you need ";
    cin>> rows;
    cout<< "enter columns ";
    cin>> cols;

    vector<vector<int> > arr(rows,vector<int>(cols));

    for(int i = 0;i<rows;++i){
        for(int j = 0;j<cols;++j){
            cin>>arr[i][j];
        }
    }
    for(int i = 0;i<rows;++i){
        for(int j = 0;j<cols;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

  

        

}
