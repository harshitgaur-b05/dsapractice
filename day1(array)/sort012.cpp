#include<bits/stdc++.h>
using namespace std;

// ques.....
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]




// solution.....
// //use mid only


    void sortColors(vector<int>& n) {
                int beg=0;
                int mid=0;
                int end=n.size()-1;
                while(end>=mid){
                    if(n[mid]==2)
                    {swap(n[mid],n[end]);
                    end--;

                    }
                    else if(n[mid]==0){
                        swap(n[mid],n[beg]);
                    beg++;
                    mid++;
                    }
                    else if(n[mid]==1)
                    mid++;
                    
                }

    }
