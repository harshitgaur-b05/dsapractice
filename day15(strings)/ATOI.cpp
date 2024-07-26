  #include<bits/stdc++.h>
  using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        bool sign=true;
        int i=0;
        long ans=0;
        while(i<s.size()&& s[i]==' ')i++;
        if(s[i]=='-')
        {
            sign=false;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<s.size()){
            if(s[i]>='0'&& s[i]<='9'){
                ans=ans*10 + (s[i]-'0');
                if(ans>INT_MAX && sign==false)return INT_MIN;
                if(ans>INT_MAX && sign==true)return INT_MAX;
                i++;
            }
            else{
               return sign ? ans : -ans;
            }
        }
        return sign ? ans : -ans;
    }
};