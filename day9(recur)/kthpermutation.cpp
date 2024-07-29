 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k = k - 1;
        while (true) {
            ans =ans+ to_string(nums[k / fact]);
            nums.erase(nums.begin() + (k / fact));
            if (nums.size() == 0)
                break;
            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};
// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         // Initialize the factorial variable to 1
//         int fact = 1;

//         // Vector to store numbers from 1 to n
//         vector<int> nums;

//         // Fill the nums vector with numbers 1 to n-1
//         // and calculate (n-1)! (factorial of (n-1))
//         for (int i = 1; i < n; i++) {
//             fact = fact * i;  // Update factorial value
//             nums.push_back(i); // Add number to vector
//         }

//         // Add the nth number to the vector
//         nums.push_back(n);

//         // Resultant permutation string
//         string ans = "";

//         // Convert k to 0-based index
//         k = k - 1;

//         // Generate the k-th permutation
//         while (true) {
//             // Find the index in nums for the current digit
//             int index = k / fact;

//             // Append the selected number to the result string
//             ans = ans + to_string(nums[index]);

//             // Remove the used number from nums
//             nums.erase(nums.begin() + index);

//             // If nums is empty, we are done
//             if (nums.size() == 0)
//                 break;

//             // Update k to the new position in the reduced set
//             k = k % fact;

//             // Update factorial for the next iteration
//             fact = fact / nums.size();
//         }

//         // Return the resulting permutation
//         return ans;
//     }
// };
