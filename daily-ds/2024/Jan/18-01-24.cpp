/*

URL: https://leetcode.com/problems/climbing-stairs/?envType=daily-question&envId=2024-01-18

70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 
Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 
Constraints:

  1 <= n <= 45

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int climb(int n, int level, vector<int> &dp)
  {
    if (level == n)
      return 1;
    if (level > n)
      return 0;
    if (dp[level] != -1)
      return dp[level];

    int one = climb(n, level + 1, dp);
    int two = climb(n, level + 2, dp);
    int ans = one + two;
    dp[level] = ans;

    return ans;
  }
  int climbStairs(int n)
  {
    vector<int> dp(n, -1);
    return climb(n, 0, dp);
  }
};
