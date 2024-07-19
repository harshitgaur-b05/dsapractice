
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mpp; 
        queue < pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            mpp[x][y].insert(node->val);
            if (node->left != NULL)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right != NULL)
                q.push({node->right, {x + 1, y + 1}});
        }
        for (auto it : mpp) {
            vector<int> cols;
            for (auto p : it.second) {
                cols.insert(cols.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(cols);
        }
        return ans;
    }
};