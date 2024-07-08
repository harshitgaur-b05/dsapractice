 #include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int left = 0, right = n - 1;
        int maxleft = 0, maxright = 0;
        int res = 0;
        while (left < right) {
            if (a[left] <= a[right]) {
                if (a[left] >= maxleft)
                    maxleft = a[left];
                else {
                    res += (maxleft - a[left]);
                }
                left++;
            } else {
                if (a[right] >= maxright)
                    maxright = a[right];

                else {
                    res += (maxright - a[right]);
                }
                right--;
            }
        }
        return res;
    }
};