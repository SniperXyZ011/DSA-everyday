// 242. Valid Anagram
// Given two strings s and t, return true if t is an 
// anagram
//  of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t){
            return true;
        }

        return false;
    }
