#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int  n = mat.size();
        int m = mat[0].size();
        for(int i =0;i<n ;i++){
            for(int j= i+1 ; j<m ; j++){// i+1 to avoid reswapping
                int temp =mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
        for(int i = 0; i< n ;i++){
            reverse(mat[i].begin(),mat[i].end());
        }

        
    }
};