  #include <bits/stdc++.h>
using namespace std;
class Solution {
  public:

    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<long long,int> mpp;
        int longest=0;
        int sum =0;
        for(int i =0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                longest=max(longest,i+1);
            }
             //rem=sum -k
            if(mpp.find(sum)!=mpp.end()){//find (rem)
                int len =i-mpp[sum];//rem
                longest=max(len,longest);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return longest;
    }
};