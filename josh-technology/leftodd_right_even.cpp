#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int val;
    node *left;
    node *right;
    node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;

    }
};
void  convertnodes(node * root){
    if(root==NULL)return ;
    if (root->left != NULL && root->left->val % 2 != 0) {
        root->left->val -= 1;
    }
    if (root->right != NULL && root->right->val % 2 == 0) {
        root->right->val += 1;
    }

    convertnodes(root->left);
    convertnodes(root->right);
    

}
void display(node * root){
    if(root==NULL)return ;
    
    display(root->left);
    cout<<root->val<<" ";
    display(root->right);
}
int main(){
    node * a= new node(1);
    node * b= new node(2);
    node * c= new node(3);
    node * d= new node(4);
    node * e= new node(5);
    node * f= new node(6);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;

    display(a);
    convertnodes(a);
    display(a);

    return 0;
}