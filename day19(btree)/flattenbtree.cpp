
  #include<bits/stdc++.h>
  using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left != NULL) {
                // find pred and save right
                TreeNode* r = curr->right;
                // link tree->right to left
                curr->right = curr->left;
                // find pred
                TreeNode* pred = curr->left;
                while (pred->right != NULL)
                    pred = pred->right;
                // link pred to right
                pred->right = r;
                //move to left
                curr=curr->left;

            } else
                curr = curr->right;
        }
        TreeNode* temp = root;
        while (temp->right != NULL) {
            temp->left = NULL;
            temp = temp->right;
        }
    }
};