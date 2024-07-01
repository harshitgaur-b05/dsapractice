#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int maxprofit=0;
        int mini=p[0];
        for(int i =0; i<n ;i++){
            int cost= p[i]-mini;
            maxprofit=max(cost,maxprofit);
            mini=min(p[i],mini);

        }
        return maxprofit;
    }
};
//use approach many times