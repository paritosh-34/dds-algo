/*

URL: https://leetcode.com/problems/sequential-digits/description/

1291. Sequential Digits

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 
Example 1:
Input: low = 100, high = 300
Output: [123,234]
Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

 
Constraints:

	10 <= low <= high <= 10^9

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string c = "123456789";
        vector<int>a;

        for(int i =0;i<c.size();i++){
            for(int j =i+1;j<=c.size();j++){
                int curr = stoi(c.substr(i,j-i));
                if(curr<=high && curr>=low)a.push_back(curr);
            }
        }
        sort(a.begin(),a.end());
        return a;
    }
};

