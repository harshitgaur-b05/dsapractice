  #include<bits/stdc++.h>
  using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string res = "";

        sort(strs.begin(), strs.end());
        string first;
        if (!strs[0].empty())
            first = strs[0];
        else
            return res;
        string last = strs[strs.size() - 1];
        for (int i = 0; i < first.size(); i++) {
            if (last[i] != first[i])
                break;
            res += first[i];
        }
        return res;
    }
};