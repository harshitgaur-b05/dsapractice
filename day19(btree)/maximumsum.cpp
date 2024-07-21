#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to construct a binary tree from a list
TreeNode* constructTree(const vector<int*>& vals) {
    if (vals.empty() || vals[0] == nullptr) return nullptr;

    TreeNode* root = new TreeNode(*vals[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (vals[i] != nullptr) {
            current->left = new TreeNode(*vals[i]);
            q.push(current->left);
        }
        i++;

        if (i < vals.size() && vals[i] != nullptr) {
            current->right = new TreeNode(*vals[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Function to find the maximum width of the binary tree
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;  // Edge case: if the root is null, return 0.

        int ans = 0;  // Initialize the maximum width.
        queue<pair<TreeNode*, unsigned long long>> q;  // Queue to store nodes and their indices.
        q.push({root, 0});  // Start with the root node at index 0.

        while (!q.empty()) {
            int size = q.size();
            unsigned long long mini = q.front().second;  // Get the minimum index at the current level.
            unsigned long long first, last;  // Variables to store the first and last indices at the current level.

            for (int i = 0; i < size; i++) {
                unsigned long long curr_index = q.front().second - mini;  // Normalize the index.
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curr_index;  // Capture the first index at the current level.
                if (i == size - 1) last = curr_index;  // Capture the last index at the current level.

                if (node->left) q.push({node->left, 2 * curr_index + 1});  // Index for the left child.
                if (node->right) q.push({node->right, 2 * curr_index + 2});  // Index for the right child.
            }

            ans = max(ans, static_cast<int>(last - first + 1));  // Update the maximum width.
        }

        return ans;
    }
};

