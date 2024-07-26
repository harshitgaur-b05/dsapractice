#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    string countAndSay(int n) {


        if(n==1)
        return "1";
           string x=countAndSay(n-1);
            int count=1;
            char ch=x[0];
            string ans="";
            for(int i=1;i<x.size();i++){
                char dh=x[i];

                if(ch==dh){
                    count++;
                }
                else{
                    ans+=to_string(count)+ch;
                    ch=dh;
                    count=1;
                }
            }
             ans+=to_string(count)+ch;
        return ans;
 }
};