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


void printLevel(Node*root,int lvl)
{
    if(root==NULL)
    return;
    if(lvl==1)
    cout<<root->data<<" ";
    else if(lvl>1)
    {
        printLevel(root->left,lvl-1);
        printLevel(root->right,lvl-1);
    }
}
int heightOfTree(Node* root)
{
    if(root==NULL)
    return 0;
    int h1=heightOfTree(root->left);
    int h2=heightOfTree(root->right);
    if(h1>h2)
    return h1+1;
    else
    return h2+1;
}
void bfs(Node*root)
{
    if(root==NULL)
    return;
    int h=heightOfTree(root);
    // cout<<"\nHeight of the tree"<<h;
    for(int i=1;i<h+1;i++)
    printLevel(root,i);
}
int main()
{
    int arr[100],data;   
    Node*root=NULL;
    cout<<"\nBinary Search Tree DFS";
    cout<<"\nEnter the elements of tree ";
    do{
        cin>>data;
        if(data==-1)
        break;
        root=insert(root,data);
    }while(data>=0);
    bfs(root);
    
    return 0;
}