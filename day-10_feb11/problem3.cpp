// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        int n = s.size();
        int i = 0;

        for (; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                stk.push(ch);
            }
            else
            {
                if (stk.empty())
                {
                    return false;
                }
                if ((ch == ')' && stk.top() == '(') ||
                    (ch == ']' && stk.top() == '[') ||
                    (ch == '}' && stk.top() == '{'))
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        if (!stk.empty())
        {
            return false;
        }

        return true;
    }
};