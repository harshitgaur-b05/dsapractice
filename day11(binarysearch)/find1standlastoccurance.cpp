#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findst(vector<int>& a, int t, int st, int end) {
    
        int res = -1;
        int mid = st + (end - st) / 2;
        while (st <= end) {
            mid = st + (end - st) / 2;
            if (a[mid] == t) {
                res = mid;
                end = mid - 1;
            } else if (a[mid] > t) {
                end = mid - 1;

            } else {
                st = mid + 1;
            }
             
        }
        return res;
    }
    int findend(vector<int>& a, int t, int st, int end) {
       
        int res = -1;
        int mid = st + (end - st) / 2;
        while (st <= end) {
            mid = st + (end - st) / 2;
            if (a[mid] == t) {
                res = mid;
                st=mid+1;
            } else if (a[mid] > t) {
                end = mid - 1;

            } else {
                st = mid + 1;
            }
        }
        return res;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        int left = findst(nums, target, st, end);
        int right = findend(nums, target, st, end);
        return {left, right};
    }
};