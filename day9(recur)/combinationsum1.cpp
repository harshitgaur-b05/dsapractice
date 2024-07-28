 #include<bits/stdc++.h>
 using namespace std;
 class Solution {
public:
    void findcomb(int ind, int target, vector<int>& arr, vector<int>& ds,
                  vector<vector<int>>& ans) {
        if (ind == arr.size()) {
            if (target == 0)
                ans.push_back(ds);
            return;
        }

        if (target >= arr[ind]) {
            ds.push_back(arr[ind]);
            findcomb(ind, target - arr[ind], arr, ds, ans);
            ds.pop_back();
        }
        findcomb(ind + 1, target, arr, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        findcomb(0, target, arr, ds, ans);
        return ans;
    }
};