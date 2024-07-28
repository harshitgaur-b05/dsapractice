 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    void findcom(int ind, int target, vector<int>& ds, vector<int>& arr,
                 vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findcom(i + 1, target - arr[i], ds, arr,
                    ans); // ind+1 cause we mush not (PICK) same index
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findcom(0, target, ds, arr, ans);
        return ans;
    }
};