#include<iostream>
using namespace std;
class Node{
    public:
    
    int val;
    Node* left;
    Node* right; 


    // Constructor 

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node* root)
    {
      if(root==NULL) return;
      cout<<root->val<<" "; // root
      preorder(root->left); // left
      preorder(root->right); //right
    }

void inorder(Node* root)
    {
      if(root==NULL) return;
      inorder(root->left); // left
      cout<<root->val<<" "; // root
      inorder(root->right); //right
    }

void postorder(Node* root)
    {
      if(root==NULL) return;
      postorder(root->left); // left
      postorder(root->right); //right
      cout<<root->val<<" "; // root
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

    preorder(a);
    cout<<endl;
    inorder(a);
    cout<<endl;
    postorder(a);
    return 0; 
}