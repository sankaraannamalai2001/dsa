#include <iostream>
#include<queue>
using namespace std;

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}Node;


Node*create(int data)
{
    Node*leaf=(Node*)malloc(sizeof(Node*));
    leaf->data=data;
    leaf->left=leaf->right=NULL;
    return leaf;
}

Node*insert(Node*root,int data)
{
    if(root==NULL)
    return create(data);
    if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);
    return root;
}

void bfs(Node*root)
{
    queue<Node*>q;
    if(root==NULL)
    return;
    q.push(root);
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        if(q.front()->left!=NULL)
        q.push(q.front()->left);
        if(q.front()->right!=NULL)
        q.push(q.front()->right);
        q.pop();
    }
    
}
int main()
{
    int arr[100],data;   
    Node*root=NULL;
    cout<<"Binary Search Tree DFS";
    cout<<"Enter the elements of tree";
    do{
        cin>>data;
        if(data==-1)
        break;
        root=insert(root,data);
    }while(data>=0);
    bfs(root);
    
    return 0;
}