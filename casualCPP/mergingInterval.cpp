#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> ump;
    int n;
    cin>> n;
    vector<vector<int> > meetings(n, vector<int>(2));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<2;j++){
            cin>> meetings[i][j];
        }
    }
    vector<int> count;
    vector<pair<int,int> > intervals;
    int bookedDays = 0;
    for(auto meeting: meetings){
    intervals.push_back(make_pair(meeting[0], meeting[1]));
    }
    sort(intervals.begin(),intervals.end());
    int start = intervals[0].first;
    int end = intervals[0].second;
    for(int i = 1;i<intervals.size();i++){
        cout<<intervals[i].first<<" <- starting value of intervals "<<endl;
        if(intervals[i].first > end){
            bookedDays += end - start + 1;
            cout<< bookedDays<< "<- booked " <<endl;
            start = intervals[i].first;
            cout<<start<<"-< start "<<endl;
            end = intervals[i].second;
            cout<< end<<"<- changing end to"<<endl;
        }
        else{
            end = max(end,intervals[i].second);
            cout<< "maximissed end-> "<<end<<endl;
        }
    }
    bookedDays += end - start + 1;
    cout<< bookedDays<<endl;
}
