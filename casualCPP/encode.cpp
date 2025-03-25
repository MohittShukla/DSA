#include <iostream>
#include <string>
#include <vector>
using namespace std;
string encode(vector<string>& s) {
        // code here
        string result = "";
        for(auto word: s){
            result += word + '#';
        }
        return result;
    }
    vector<string> decode(string& s) {
        // code here
        vector<string> res;
        string ap = "";
        for(int i = 0;i<s.size();i++){
            if(s[i] == '#'){
                res.push_back(ap);
                ap = "";
            }
            else{
                ap += s[i];
            }
        }
        if(!ap.empty()){
            res.push_back(ap);
        }
        return res;
    }
int main(){
   vector<string> words;  
   int n;
   cout<< "enter the amount of words you need to encode ";
   cin>> n;
   cout<< "enter the words "<<endl;
   for(int i = 0;i<n;i++){
    string w;
    cin>> w;
    words.push_back(w);
   }
 string encoded = encode(words);
    cout<< encoded;
    vector<string> decoded = decode(encoded);
    cout<<endl;
   for(int i= 0;i<decoded.size();i++){
    cout<< decoded[i]<<" ";
   }
}
