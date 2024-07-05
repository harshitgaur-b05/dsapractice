#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        vector<int> mpp(256,-1);
        int len=0;
        int left=0;
        int right=0;
        while(right<s.size()){
            if(mpp[s[right]]!=-1) left=max(left,mpp[s[right]]+1);
            mpp[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }

        return len;
    }
};
