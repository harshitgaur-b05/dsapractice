#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> nums;
        for(int i =0;i<rows;i++){
            vector<int> cols(i+1,1);
            if(i==0||i==1)nums.push_back(cols);
            else{
                for(int j=1;j<cols.size()-1;j++){
                    cols[j]=nums[i-1][j]+nums[i-1][j-1];
                }

                nums.push_back(cols);
            }
        }
        return nums;
    }
};