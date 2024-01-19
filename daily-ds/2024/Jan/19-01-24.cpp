/*

URL: https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 
Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

 
Constraints:

  n == matrix.length == matrix[i].length
  1 <= n <= 100
  -100 <= matrix[i][j] <= 100

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int calc(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
  {
    int n = matrix.size();
    if (row == n - 1)
      return matrix[row][col];

    if (dp[row][col] != INT_MAX)
      return dp[row][col];

    int left = INT_MAX, right = INT_MAX;

    if (col > 0)
      left = calc(matrix, row + 1, col - 1, dp);
    if (col < n - 1)
      right = calc(matrix, row + 1, col + 1, dp);

    int below = calc(matrix, row + 1, col, dp);

    dp[row][col] = matrix[row][col] + min(left, min(right, below));
    return dp[row][col];
  }
  int minFallingPathSum(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    if (n == 1)
      return matrix[0][0];

    int mini = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
    {
      mini = min(mini, calc(matrix, 0, i, dp));
    }

    return mini;
  }
};
