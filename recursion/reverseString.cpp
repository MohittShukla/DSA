#include <iostream>
using namespace std;

void reverseString(string &str,int i, int j){

  

    if(i>j){
        return;
    }
   
    swap(str[i],str[j]);

    i++;
    j--;

     

    reverseString(str,i,j);

   
     

}

int main(){
    string str = "doing";
    int i = 0;
    int j = str.length();

    reverseString(str,0,j-1);
    cout<< str;
    

    
}
