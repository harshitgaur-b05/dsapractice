#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {

        int cnt1 = 0, cnt2 = 0;
        int ele1, ele2;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && ele2 != a[i]) {
                ele1 = a[i];
                cnt1 = 1;
            }
            else  if (cnt2 == 0 && ele1 != a[i]) {
                ele2 = a[i];
                cnt2 = 1;
            } else if (a[i] == ele1) {
                cnt1++;
            } else if (a[i] == ele2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        // check 
        vector<int> ans;
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n ;i++){
            if(a[i]==ele1)cnt1++;
            if(a[i]==ele2)cnt2++;
        }
        if(cnt1>(n/3))ans.push_back(ele1);
        if(cnt2>(n/3)&& ele1!=ele2)ans.push_back(ele2);
        return ans;
        
    }
};