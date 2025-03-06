//Greedy approach
// This is a question on activity selection very famous
// ther is start and end of activities 
// start = [1,, 3, 0, 5, 8, 5]
// end = [2, 4, 6, 7, 9, 9]
//we need to select the max number of activities which are non overlapping 
//given that end is sorted so we can say that non overlapping condition = last activity end <= next activity start

#include <iostream>
#include <vector>
using namespace std;

int maxActivity(vector<int> start, vector<int> end){
    //sort end activity // already sorted
    //select A0 first
    int count = 1;
    int currEndTime = end[0];

    for(int i = 1; i < end.size(); i++){
        if(currEndTime <= start[i]){ // for non overlapping
            count++;
            currEndTime = end[i];
        }
    }

    return count; //4
}


int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << maxActivity(start, end) << endl;
    return 0;
}