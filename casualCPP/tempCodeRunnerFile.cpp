#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> ump;
    vector<vector<int> > meetings;
 meetings.push_back(vector<int>{1, 3});
    meetings.push_back(vector<int>{3, 6});
    meetings.push_back(vector<int>{8, 13});
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
        if(intervals[i].first > end){
            bookedDays += end - start + 1;
            start = intervals[i].first;
            end = intervals[i].second;
        }
        else{
            end = max(end,intervals[i].second);
        }
    }
    bookedDays += end - start + 1;
    cout<< bookedDays<<endl;
}
