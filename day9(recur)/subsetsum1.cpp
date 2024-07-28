 #include<bits/stdc++.h>
 using namespace std;
 void allsubsets(int i ,int sum,vector<int>& arr ,vector<int> &subsum,int n){
        if(i==n){
            subsum.push_back(sum);
            return;
        }
        allsubsets(i+1,sum+arr[i],arr,subsum,n);
        allsubsets(i+1,sum,arr,subsum,n);
        
    }

    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> subsum;
        allsubsets(0,0,arr,subsum,n);
        sort(subsum.begin(),subsum.end());
        return subsum;
        
    }