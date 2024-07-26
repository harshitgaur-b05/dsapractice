  #include<bits/stdc++.h>
  using namespace std;
class Solution {
public:
    // Function to expand around the center and return the length of the palindrome
    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // length of the palindrome
    }
    
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(s, i, i); // Odd length palindrome
            int len2 = expandAroundCenter(s, i, i + 1); // Even length palindrome
            int len = max(len1, len2);
            
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};