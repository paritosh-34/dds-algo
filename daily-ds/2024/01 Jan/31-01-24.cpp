/*

URL: https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 
Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

 
Constraints:

	1 <= temperatures.length <= 105
	30 <= temperatures[i] <= 100

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures( vector<int>& temperatures) {
        deque<int> deque;
        
        vector<int> res(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            if (deque.empty()) {
                deque.push_front(i);
                res[i] = 0;
            } else {
                while (!deque.empty() && temperatures[i] >= temperatures[deque.front()]) {
                    deque.pop_front();
                }

                if (deque.empty()) {
                    res[i] = 0;
                } else {
                    res[i] = deque.front() - i;
                }

                deque.push_front(i);
            }
        }

        return res;
    }
}; 



