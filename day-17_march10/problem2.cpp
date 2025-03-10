// Fractional Knapsack
// Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
// Return the maximum value as a double, rounded to 6 decimal places

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(pair<double, int> p1, pair<double, int> p2)
    {
        return p1.first > p2.first; // descending order
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // Your code here
        double max = 0;
        int n = val.size();
        vector<pair<double, int>> ratio;

        for (int i = 0; i < n; i++)
        {
            double r = val[i] / (double)wt[i];
            ratio.emplace_back(r, i);
        }

        sort(ratio.begin(), ratio.end(), compare);

        for (int i = 0; i < n; i++)
        {
            if (capacity >= wt[ratio[i].second])
            {
                max += val[ratio[i].second];
                capacity -= wt[ratio[i].second];
            }
            else
            {
                max += ratio[i].first * capacity;
                capacity = 0;
            }
        }

        return max;
    }
};