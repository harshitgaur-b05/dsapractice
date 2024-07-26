#include<bits/stdc++.h>
using namespace std;
int solve(string A) {
    string s=A;
    vector<int> lps(2 * A.size()+1,0);
    string rev=A;
    reverse(rev.begin(),rev.end());
    s+="$";
    s+=rev;
    
    //calc lps
    int f=0;
    int sec=1;
    
    
    while(sec<s.size()){
        //match
        if(s[sec]==s[f]){
            lps[sec]=f+1;
            f++;
            sec++;
        }
        else{
        //not match
            if(f==0){
                sec++;
            }
        else{
            f=lps[f-1];
        
        }
        }
        
    }
    
    return A.size()-lps[s.size()-1];
    
}