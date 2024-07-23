  #include<bits/stdc++.h>
  using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
        while (i < s.size()) {
            string temp = "";

            while (i < s.size() && s[i] == ' ')
                i++;
            if (i >= s.size())
                break;
            while (i < s.size() && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            if (ans.size() == 0)
                ans = temp;
            else
                ans = temp + " " + ans;
        }
        return ans;
    }
};