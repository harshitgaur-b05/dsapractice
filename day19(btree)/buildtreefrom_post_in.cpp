
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
    TreeNode* build(vector<int>& inorder, int inst, int inend,
                    vector<int>& postorder, int pst, int pend,
                    map<int, int> &mpp) {
        if (pst > pend || inst > inend)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pend]);
        int inroot = mpp[root->val];
        int numsleft = inroot - inst;
        root->left = build(inorder, inst, inroot - 1, postorder, pst,
                           pst + numsleft-1, mpp);
        root->right = build(inorder, inroot + 1, inend, postorder,
                           pst + numsleft , pend - 1, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inmap;
        int p = postorder.size();
        int q = inorder.size();
        for (int i = 0; i < q; i++) {
            inmap[inorder[i]] = i;
        }
        TreeNode* root = build(inorder, 0, q - 1, postorder, 0, p - 1, inmap);
        return root;
    }
};