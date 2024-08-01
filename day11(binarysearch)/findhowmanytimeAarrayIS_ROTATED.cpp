#include <bits/stdc++.h>
using namespace std;

int countRotations(int a[], int n) {
    int st = 0;
    int end = n - 1;

    // If the array is not rotated, the smallest element is at index 0
    if (a[st] <= a[end]) return 0;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        // Check if the mid element is the minimum element
        if (a[mid] <= a[prev] && a[mid] <= a[next]) {
            return mid;
        }
   else if(a[st]<=a[mid] && a[mid]<=a[end]){
                end=mid-1;
            }
        // If the left part is sorted, move to the right part
        if (a[mid] >= a[st]) {
            st = mid + 1;
        } else { // If the right part is sorted, move to the left part
            end = mid - 1;
        }
    }

    // Should not reach here if the input array is a valid rotated sorted array

}

int main() {
    int arr[] = {15, 18, 19, 20, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rotations = countRotations(arr, n);

    if (rotations == -1) {
        cout << "Error: Invalid input or logic issue." << endl;
    } else {
        cout << "The array is rotated " << rotations << " times." << endl;
    }

    return 0;
}

