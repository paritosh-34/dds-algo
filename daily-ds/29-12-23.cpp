#include <bits/stdc++.h>

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