  #include<bits/stdc++.h>
  using namespace std;

  struct Node {
      int val;
      Node *left;
      Node *right;
      Node() : val(0), left(nullptr), right(nullptr) {}
      Node(int x) : val(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : val(x), left(left),
  right(right) {}
  };
class Solution
{   
    private:
    void inorder(Node *root, int & k,int & ans){
        if(root==NULL)return ;
        inorder(root->right,k,ans);
        k--;
        if(k==0)ans=root->val;
        inorder(root->left,k,ans);
    }
    public:
    int kthLargest(Node *root, int k)
    {
        int ans=-1;
        inorder(root,k,ans);
        return ans;
    }
};