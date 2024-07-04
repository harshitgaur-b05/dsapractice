#include <bits/stdc++.h>
using namespace std;
//MORRE VOTING ALGORITHM
class Solution {
public:
    int majorityElement(vector<int>& a) {
        int ele;
        int cnt = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                ele = a[i];
                cnt = 1;
            } else if (a[i] == ele) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ele;
    }
};
//approch 2 unordered  map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n= nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second>(nums.size()/2)){
                return it.first;
            }
        }
        return 0;
    }
};
