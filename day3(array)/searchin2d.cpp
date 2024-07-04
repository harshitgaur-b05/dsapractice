#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) {
        int n = arr.size();
        int m = arr[0].size();
        int i = 0;
        int j = m - 1;
        while (j >= 0 && i >= 0 && j < m && i < n) {
            if (arr[i][j] < t) {
                i++;
            } else if (arr[i][j] > t) {
                j--;
            } else
                return true;
        }

        return false;
    }
};