/*
1335. Minimum Difficulty of a Job Schedule
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/?envType=daily-question


You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.



Example 1:

Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7


Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.


Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.


Constraints:

1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10


*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int solve(vector<int> &jobDifficulty, int d, int index)
  {
    if (d == 1)
    {
      return *max_element(jobDifficulty.begin() + index, jobDifficulty.end());
    }

    int ans = INT_MAX;
    int maxi = INT_MIN;
    for (int i = index; i <= (jobDifficulty.size() - d); i++)
    {
      maxi = max(maxi, jobDifficulty[i]);
      ans = min(ans, maxi + solve(jobDifficulty, d - 1, i + 1));
    }
    return ans;
  }

  int solveMem(vector<int> &jobDifficulty, int d, int index, vector<vector<int>> &dp)
  {
    if (d == 1)
    {
      return *max_element(jobDifficulty.begin() + index, jobDifficulty.end());
    }
    if (dp[d][index] != -1)
      return dp[d][index];

    int ans = INT_MAX;
    int maxi = INT_MIN;
    for (int i = index; i <= (jobDifficulty.size() - d); i++)
    {
      maxi = max(maxi, jobDifficulty[i]);
      ans = min(ans, maxi + solveMem(jobDifficulty, d - 1, i + 1, dp));
    }
    return dp[d][index] = ans;
  }

  int minDifficulty(vector<int> &jobDifficulty, int d)
  {
    if (d > jobDifficulty.size())
      return -1;

    // 1. Recursion
    // return solve(jobDifficulty,d,0);

    // 2. Memoization
    vector<vector<int>> dp(d + 1, vector<int>(jobDifficulty.size() + 1, -1));
    return solveMem(jobDifficulty, d, 0, dp);
  }
};