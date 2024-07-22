   #include<bits/stdc++.h>
  using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    

    Node() : key(0), left(NULL), right(NULL) {}

    Node(int _val) : key(_val), left(NULL), right(NULL) {}

    Node(int _val, Node* _left, Node* _right )
        : key(_val), left(_left), right(_right) {}
};
  void preFun(Node* root,int key,Node* &pre){
        if(root==NULL)
            return;
        if(root->key < key){
            pre=root;
            preFun(root->right,key,pre);
            return;
            
        }
        else
            preFun(root->left,key,pre);
        return;
        
    }
 
    void sucFun(Node* root,int key,Node* &suc){
        if(root==NULL)
            return;
        if(root->key > key){
            suc=root;
            sucFun(root->left,key,suc);
            return;
        }
        else{
            sucFun(root->right,key,suc);
        }
        return;
    }
 
     
    
    void findPreSuc(Node* root, Node* &pre, Node* &suc, int key)
    {
        // Your code goes here
        pre=NULL;
        suc=NULL;
    
        preFun(root,key,pre);
        sucFun(root,key,suc);    
    
        return;
    }

