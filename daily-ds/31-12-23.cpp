/*

Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.


Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.


Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".


Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.


Constraints:

1 <= s.length <= 300
s contains only lowercase English letters.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxLengthBetweenEqualCharacters(string s)
  {
    vector<int> v(26, -1);
    int ans = -1;

    for (int i = 0; i < s.size(); i++)
    {
      int ind = s[i] - 'a';

      if (v[ind] == -1)
      {
        v[ind] = i;
      }
      else
      {
        ans = max(ans, i - v[ind] - 1);
      }
    }

    return ans;
  }
};