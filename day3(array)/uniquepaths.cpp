#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>> dp;
 int count(int i,int j){
    if(i<=0||j<=0){
        return 1;
    }
    if(dp[i][j]!=-1)return dp[i][j];

    return dp[i][j]=count(i-1,j)+count(i,j-1);

 }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int> (n,-1));
        return count(m-1,n-1);
    }
};