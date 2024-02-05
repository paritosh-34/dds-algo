/*

URL: https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

387. First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 
Example 1:
Input: s = "leetcode"
Output: 0
Example 2:
Input: s = "loveleetcode"
Output: 2
Example 3:
Input: s = "aabb"
Output: -1

 
Constraints:

	1 <= s.length <= 105
	s consists of only lowercase English letters.

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;

        for (char ch : s) mpp[ch]++;

        for (int i=0;i<s.length();i++) {
            char ch = s[i];
            if (mpp[ch] == 1) return i;
        }

        return -1;
    }
};
