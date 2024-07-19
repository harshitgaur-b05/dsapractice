#include <vector>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL)return ans;
        map<int ,int > mpp;
        queue<pair<Node * ,int>> qu;
        qu.push({root,0});
        while(!qu.empty()){
            auto temp=qu.front();
            qu.pop();
            Node * n=temp.first;
            int x=temp.second;
            mpp[x]=n->data;
            if(n->left !=NULL)qu.push({n->left,x-1});
            if(n->right !=NULL)qu.push({n->right,x+1});
        }
        for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
    }

};