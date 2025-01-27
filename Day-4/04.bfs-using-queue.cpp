#include<iostream>
#include<queue>
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

int level(Node* root)
{
    if(root==NULL) return 0; 
    return 1 + max(level(root->left),level(root->right)); 
}

void nthlevel(Node* root , int current , int level)
{
    if(root==NULL) return;
    if(current==level) cout<<root->val;
    nthlevel(root->left,current+1,level);
    nthlevel(root->right,current+1,level);
}

void levelorder(Node* root)
{
    int n = level(root); 

    for(int i = 0 ; i <= n ; i++)
    {
        nthlevel(root,1,i);
    }
}

void levelorderqueue(Node* root)
{
    queue<Node*> q; 

    q.push(root);

    while(q.size()>0)
    {
        Node* temp = q.front(); 
        q.pop();
        cout<<temp->val<<" "; 
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }

    cout<<endl;
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

    levelorderqueue(a);
}