// q3...
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]




// soluton... 


// 3 solution 
// 1 brute force 

// form all permutation and return next permutaion by liner search o(n!*n) too big

// c++ stl...
// next_permutation(nums.begin(),nums.end()); 

// 3rd...3 step
// [2 1 5 4 3 0 0]
// thought :::::: find 1 index of change ex in dictionary ab c ,ab d, ab e prefix same so we will find point where stating 
// from (n-2 -> 0 where a[i]<a[i+1] in =i)
// [2 1(in) 5 4 3 0 0] 
// <---
// then we got the index after which trace from(n-1 to in +1)we have to change we find the next big element and  swap(a[i],a[nextbigthen a[i]) 
// [2 3  5 4 1 0 0]
// then sort remaining or reverse them 
// [2 3 0 0 1 4 5](output)

// code....

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int in = -1;
        int n = a.size();
        for (int i = n - 2; i >= 0; i--) {
            // point of change
            if (a[i] < a[i + 1]) {
                in = i;
                break;
            }
        }
        if (in == -1)
            reverse(a.begin(), a.end());
        // next greater element from n-1 to i+1
    else
    {    for (int i = n - 1; i >= in + 1; i--) {
            if (a[i] > a[in]) {

                swap(a[i], a[in]);

                break;
            }
        }
        // sort or reverse from in+1 to n-1
        reverse(a.begin() + in + 1, a.end());
    }}
};