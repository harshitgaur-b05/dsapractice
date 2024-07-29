 #include<bits/stdc++.h>
 using namespace std;
 class Solution {
public:
    bool ispalindrome(string s, int st, int ed) {
        while (st <= ed) {
            if (s[st] != s[ed])
                return false;
            st++;
            ed--;
        }
        return true;
    }
    void func(int ind, string s, vector<vector<string>>& res,
              vector<string>& v) {
        if (ind == s.size()) {
            res.push_back(v);
        }
        for (int i = ind; i < s.size(); i++) {
            if (ispalindrome(s, ind, i)) {
                v.push_back(s.substr(ind, i - ind + 1));
                func(i + 1, s, res, v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        func(0, s, res, v);
        return res;
    }
};