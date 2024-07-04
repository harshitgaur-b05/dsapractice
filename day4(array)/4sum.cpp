#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // in this approach we set 2 pointes (i,j) constant and (k,l ) variable aur
    // moveable
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        int n = a.size();
        sort(a.begin(), a.end()); // to not use sets and identify duplicates as
                                  // we want unique answers
        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i - 1])
                continue; // to skip duplicates
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && a[j] == a[j - 1])
                    continue; // to skip duplicates
                int k = j + 1;
                int l = n - 1;
                while (l > k) {
                    long long 
                     sum =a[i];
                    sum += a[j];
                    sum += a[k];
                    sum += a[l];
                    // after calculating sum check
                    if (sum == target) {
                        vector<int> temp = {a[i], a[j], a[k], a[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && a[k] == a[k - 1])
                            k++;//here my mistake was using if intead of while
                        while(k < l && a[l] == a[l + 1])
                            l--;
                    } else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }
};