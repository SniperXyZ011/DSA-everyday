// N meetings in one room
// You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

// Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find the maximum number of meetings that can
      // be performed in a meeting room.
      static bool compare(pair<int, int>p1, pair<int, int>p2){
          return p1.second < p2.second;
      }
      
      int maxMeetings(vector<int>& start, vector<int>& end) {
          
          int n = start.size();
          
          vector<pair<int,int>> vec;
          for(int i = 0; i < n; i++){
              vec.emplace_back(start[i], end[i]);
          }
          
          sort(vec.begin(), vec.end(), compare);
          
          int ans = 1;
          int lastEnd = vec[0].second;
          for(int i = 1; i < n; i++){
              if(vec[i].first > lastEnd){
                  ans++;
                  lastEnd = vec[i].second;
              }
          }
          
          return ans;
          // Your code here
      }
  };