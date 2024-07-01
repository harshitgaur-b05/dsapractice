// ues 4......
// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

//  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


// solution.........

// //if my sum is getting negative we consider sum as 0 cause negative will decrease the total (and we need maximum)
// // to find print array we can find {(st)update where sum =0} index and end update with maxneg index 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // kandane algorithm
    int maxSubArray(vector<int>& a) {
        int maxi = INT_MIN;
        int sum = 0;
        int n = a.size();
        int maxneg = INT_MIN;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                k++;
                maxneg = max(maxneg, a[i]);
            }
        }
        if (k == n)
            return maxneg;
        else {
            for (int i = 0; i < n; i++) {
                sum = sum + a[i];

                if (sum < 0) {
                    sum = 0;
                }
                if (sum > maxi) {
                    maxi = sum;
                }
            }
        }
        return maxi;
    }
};

//not best method next one but similar to buy and sell stocks
// int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         if(n==0)return 0;
//         int sum=INT_MIN,k=0;
        
//         for(int i=0;i<n;i++){
//             if(nums[i]<0)
//             {sum=max(sum,nums[i]);
//             k++;}
//         }
//         if(k==nums.size())
//         return sum;
//         else{ 
//         int currs=0;
//         int maxsum=0;
//         for(int i=0;i<n;i++){
//             currs=max(nums[i]+currs,nums[i]);
//             maxsum=max(currs,maxsum);
//         } 
//         return maxsum;}
//     }
    
// };