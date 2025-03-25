#include <iostream>
using  namespace std;

void subsequence(string str, string output, vector<string>& result,int index){

    if(index>= str.length()){

        result.push_back(output);
        return;
    }

    // excluding the string 
    subsequence(str,output,result,index+1);

    //including the string
    
    char element = str[index];
    output.push_back(element);

    subsequence(str,output,result,index+1);




}


int main(){
    string str = "abc";
    string output;
    vector<string> result;
    int index = 0;

    subsequence(str,output,result,index);

    for(int i = 0;i<result.size();i++){
        cout<< result[i]<<" ";
    }

}
