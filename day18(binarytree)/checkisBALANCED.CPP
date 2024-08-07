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
    int  depth(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int lh,rh;
        lh=depth(root->left);
        rh=depth(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left)&& isBalanced(root->right))return true;

        return false;

    }
};