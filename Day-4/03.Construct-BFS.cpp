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

Node* construct(vector<int> &arr)
{
    int n = arr.size();
    queue<Node*> q; 

    Node* root = new Node(arr[0]);
    q.push(root);
    
    int i = 1;
    int j = 2;

    while(q.size()>0 && i < n)
    {
        Node* temp = q.front(); 
        q.pop(); 
        Node* l; 
        Node* r;

        if(arr[i]!=INT_MIN) l = new Node(arr[i]); 
        else l = NULL; 

        if(j!= n && arr[j]!=INT_MIN) r = new Node(arr[i]); 
        else r = NULL; 

        temp->left = l;
        temp->right = r; 

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;
    }
    return root; 
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};

    Node* root = construct(arr); 

    levelorderqueue(root);
}