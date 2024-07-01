#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setrow(vector<vector<int>>& matrix,int r){
        for(int i=0; i<matrix[0].size();i++){
            matrix[r][i]=0;

        }
    }
        void setcol(vector<vector<int>>& matrix,int c){
        for(int i=0;i<matrix.size();i++){
            matrix[i][c]=0;

        }
    }
     void find0(vector<vector<int>>& matrix){
        vector<int> row;
        int k=0;
        vector<int> cols;
        for(int i=0;i<matrix.size();i++){
            for(int j=0 ;j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    cols.push_back(j);
                    k++;
                }
            }
        }
        for(int i=0;i<k;i++){
            setrow(matrix,row[i]);
            setcol(matrix,cols[i]);
        }
     }
    void setZeroes(vector<vector<int>>& matrix) {
        find0(matrix);
    }
};