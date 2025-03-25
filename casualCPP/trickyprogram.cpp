#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<< " enter the size of rows and columns ";
    cin>> n;
    vector<vector<char> > tricky(n,vector<char>(n));

    string str;
    cout<< "Enter the string ";
    cin>> str;

    int size = n;

    int i = n-1;
    int j = 0;
    
    while(i>=0 && j<n){
        char v = str[i];
        
        tricky[i][j] = v;
         i--;
         j++;
    }
    int k =0;
    while(k<n){
        char s = str[k];
        tricky[k][k] = s;
        
        k++;
    }

    for(int i = 0;i<tricky.size();i++){
        for(int j =0;j<tricky[i].size();j++){
            cout<< tricky[i][j]<<" ";
        }
        cout<<endl;
    }


}
