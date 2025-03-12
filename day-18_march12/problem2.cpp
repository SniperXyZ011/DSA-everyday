// Job Sequencing Problem
// You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find:

// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second; // Sort by profit
    }

    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit)
    {
        // code here
        int n = id.size();

        vector<pair<int, int>> jobs;

        for (int i = 0; i < n; i++)
        {
            jobs.emplace_back(deadline[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end(), compare);

        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, jobs[i].first);
        }

        vector<int> occupied(maxDeadline + 1, -1);

        int count = 0, netProfit = 0;

        for (int i = 0; i < n; i++)
        {
            int jobDeadline = jobs[i].first;
            int jobProfit = jobs[i].second;

            for (int slot = jobDeadline; slot > 0; slot--)
            {
                if (occupied[slot] == -1)
                {
                    occupied[slot] = 1;
                    netProfit += jobProfit;
                    count++;
                    break;
                }
            }
        }
        return {count, netProfit};
    }
};
