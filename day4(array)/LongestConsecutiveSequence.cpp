#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int maxlength=0; 
        int n = a.size();
        if (n == 0)
            return 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(a[i]);
        }
        for(auto it :st){
            if(st.find(it-1)==st.end()){
                int x=it;
                int length =1;
                while(st.find(x+1)!=st.end()){
                    x++;
                    length++;
                }
                maxlength=max(length ,maxlength);
            }
        }
        return maxlength;
        
    }
};