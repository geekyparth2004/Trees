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

void nthlevel(Node* root, int current , int level)
{
    if(root==NULL) return;
    if(current==level) cout<<root->val;
    nthlevel(root->right,current+1,level);
    nthlevel(root->left,current+1,level);
    
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

    nthlevel(a,1,2);
}