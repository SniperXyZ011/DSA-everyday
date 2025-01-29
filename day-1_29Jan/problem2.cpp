// 151. Reverse Words in a String
// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverseWords(string s) {
        vector<string> ans;
        string temp;
        string result;
        int n = s.size();
        int i = 0;

        while(i < n){
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;

            int start = i;
            while(i < n && s[i] != ' ') i++;

            ans.push_back(s.substr(start, i - start));
        }

        for(int j = ans.size() - 1; j >= 0; j--) {
        result += ans[j];
        if (j > 0) result += " "; // Add space between words
        }
    
    return result;
        
    }