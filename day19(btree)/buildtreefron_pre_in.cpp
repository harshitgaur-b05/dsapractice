
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
    TreeNode* build(vector<int>& preorder,int prest,int preend, vector<int>& inorder,int inst,int inend,map<int,int> &mpp){
        if(prest>preend || inst> inend)return NULL;
        TreeNode* root=new TreeNode(preorder[prest]);
        int inroot=mpp[root->val];
        int leftlen=inroot-inst;//length of left subtreee
        root->left=build(preorder,prest+1,prest+leftlen,inorder,inst,inroot-1,mpp);
        root->right=build(preorder,prest+leftlen+1,preend,inorder,inroot+1,inend,mpp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // add inorder to hash map to increase aceesability
        map<int,int> inmap;
        int p=preorder.size();
        int q=inorder.size();
        for(int i=0;i<q;i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,0,p-1,inorder,0,q-1,inmap);
        return root;
        
    }
};