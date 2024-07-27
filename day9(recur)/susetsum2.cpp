#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void f(vector<int> a,vector<vector<int>> &res, vector<int> &v,int j){
res.push_back(v);
for(int i=j;i<a.size();i++)
{    
    if(i!=j &&a[i]==a[i-1])continue;
    v.push_back(a[i]);
    f(a,res,v,i+1);
    v.pop_back();
}
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(),nums.end());
        f(nums,res,v,0);
        return res;
        
    }
};