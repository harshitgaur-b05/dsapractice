#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int k = m + n - 1;
        int l = m - 1, r = n - 1;
        while (l >= 0 && r >= 0 && k >= 0) {
            if (a[l] > b[r]) {
                a[k] = a[l];
                k--;
                l--;
            } else {
                a[k] = b[r];
                k--;
                r--;
            }
        }
        while(r>=0)a[k--]=b[r--];
    }
};
// approach 1 isme hum log max of left sub array and min of right sub array

// ko compare karke sahi position pe laate hai
// int left = m - 1;
// int right = 0;
// while (left >= 0 && right < n) {
//     if (a[left] >= b[right]) {
//         swap(a[left], b[right]);
//          left++,right--
//     }
//      else{
//    break
//    }
// }
// sort(a,a+n);
// sort(b,b+m);