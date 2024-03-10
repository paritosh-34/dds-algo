/*

URL: https://leetcode.com/problems/intersection-of-two-arrays/description/

349. Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

 
Constraints:

	1 <= nums1.length, nums2.length <= 1000
	0 <= nums1[i], nums2[i] <= 1000

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        vector<int>result;
        unordered_map<int,int>mp;
        for(auto &num : nums1){
            mp[num]++;
        }
        for(auto & num : nums2){
            if(mp.find(num) != mp.end()){
                result.push_back(num);
                mp.erase(num);
            }
        }
        return result;
    }
};
