#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n = in.size();
        int m = in[0].size();
        vector<vector<int>> ans;
        sort(in.begin(), in.end());
        for (int i = 0; i < in.size(); i++) {
            // here ve haive to think 2 cases add new interval and 2 merge
            // existing interval in ans

            // add new interval
            if (ans.empty() || in[i][0] > ans.back()[1]) {
                // add new interval
                ans.push_back(in[i]);
            } else {
                // now we merge intevals //when (in[i][0] < ans.back()[1])
                ans.back()[1] = max(ans.back()[1],in[i][1]);
            }
        }
        return ans;
    }
};