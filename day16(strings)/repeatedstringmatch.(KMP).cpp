//686. Repeated String Match
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void lpsfind(vector<int>& lps, string s) {
        int pre = 0, suf = 1;
        lps[pre] = 0;
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                suf++;
                pre++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;

                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }
    bool KMP_MATCH(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);
        int f = 0;
        int sec = 0;
        while (f < haystack.size() && sec < needle.size()) {
            if (haystack[f] == needle[sec]) {
                f++;
                sec++;

            } else {
                if (sec == 0)
                    f++;
                else
                    sec = lps[sec - 1];
            }
        }
        if (sec == needle.size())
            return true;
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1;
        int rep = 1;
        string temp = a;
        while (temp.size() < b.size()) {
            temp += a;
            rep++;
        }
        // check if b exist in temp by kmp mathcher
        if (KMP_MATCH(temp, b))
            return rep;
        // if not fonund then add +a one more time
        if (KMP_MATCH(temp + a, b))
            return rep + 1;

        return -1;
    }
};