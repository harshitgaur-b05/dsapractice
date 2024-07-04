#include <bits/stdc++.h> 
using namespace std;
 long long int merge(vector<long long> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr
    int count=0;
    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            count=left-mid+1;
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
    return count;
}

long long  mergeSort(vector<long long> &arr, int low, int high) {
    long long count=0;
    if (low >= high) return 0;
    int mid = (low + high) / 2 ;
    count+=mergeSort(arr, low, mid);  // left half
    count+= mergeSort(arr, mid + 1, high); // right half
    count=merge(arr, low, mid, high);
    return count;  // merging sorted halves
}

long long getInversions(vector<long long> arr, int n){
    // Write your code here.

   return mergeSort( arr,0,arr.size()-1);
}
