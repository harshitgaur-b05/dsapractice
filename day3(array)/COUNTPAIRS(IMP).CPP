#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int countpairs(vector<int> &a,int lo ,int  mid , int hi){

    int right=mid+1;
    int count=0;
    for(int i=lo;i<=mid;i++){
        while(right<=hi && 2LL*a[right]<a[i]){// 2LL TO AVOID OVERFLOW
            right++;
        }
        count+=(right-(mid+1));
    }
    return count;
}





void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

  

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt=0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt+=mergeSort(arr, low, mid);  // left half
    cnt+=mergeSort(arr, mid + 1, high); // right half
    cnt+=countpairs(arr,low,mid,high);
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
    int reversePairs(vector<int>& arr) {
       int count= mergeSort(arr,0,arr.size()-1);
        return count;

    }
}
;