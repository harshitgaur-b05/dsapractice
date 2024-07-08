 #include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int maxlen = 0;
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {

            if (a[i] == 1) {
                cnt++;
                maxlen = max(maxlen, cnt);
            }
            if (a[i] == 0) {
                cnt = 0;
            }
        }
        return maxlen;
    }
};