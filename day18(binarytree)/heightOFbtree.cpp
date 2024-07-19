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
    void preorder(TreeNode* root,int level,int &maxi){
        if(root==NULL)return ;
        maxi=max(maxi,level);
        preorder(root->left,level+1,maxi);
        preorder(root->right,level+1,maxi);
    }

    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;

        int max=1;
        preorder(root,1,max);
        return max;
    }
};