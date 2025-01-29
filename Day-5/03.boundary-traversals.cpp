#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right; 

    // Constructor

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void leftboundary(Node* root)
{
   if(root==NULL) return;
   if(root->left == NULL and root->right == NULL) return;  
   cout<<root->val<<" ";
   leftboundary(root->left);
   if(root->left == NULL) leftboundary(root->right); 
}

void bottomboundary(Node* root)
{
   if(root==NULL) return;
   if(root->left == NULL and root->right == NULL) cout<<root->val<<" ";
   bottomboundary(root->left);
   bottomboundary(root->right); 
}

void rightboundary(Node* root)
{
   if(root==NULL) return;
   if(root->left == NULL and root->right == NULL) return;  
   cout<<root->val<<" ";
   rightboundary(root->right);
   if(root->right == NULL) rightboundary(root->left); 
}

int main()
{
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    a->left = b;
    a->right = c; 
    b->left = d; 
    b->right = e;
    c->left = f;

    leftboundary(a);
    cout<<endl;
    bottomboundary(a);
    cout<<endl; 
    rightboundary(a->right); 
}