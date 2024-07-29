 #include<bits/stdc++.h>
 using namespace std;
 class Solution {
public:
    void storeperrmu(int idx, vector<int> nums, vector<vector<int>> &ans) {
        if (idx >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            storeperrmu(idx + 1, nums, ans);

            //back track
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        storeperrmu(0, nums, ans);
        return ans;
    }
};