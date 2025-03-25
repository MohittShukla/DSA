#include<iostream>

#include<vector>
using namespace std;

int main(){
    vector<vector<int> > ratings;
    ratings.push_back({512,3});
    ratings.push_back({123,4});
    ratings.push_back({987,4});
    int rows  = ratings.size();
    int cols = ratings[0].size();
    int maxi = INT_MIN;
    int id = -1;
    for(int i = 0;i<rows;i++){
        if(ratings[i][1]>maxi){
            maxi = ratings[i][1];
            id = ratings[i][0];
        }
    }
    cout<< id;
}
