#include <iostream>
#include<algorithm>
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

int commonAncestor(Node *root,int p,int q)
{
    if(root->data>max(p,q))
    return commonAncestor(root->left,p,q);
    else if(root->data<min(p,q))
    return commonAncestor(root->right,p,q);
    else
    return root->data;
    return root->data;
}
int main()
{
    int arr[100],data,p,q;   
    Node*root=NULL;
    cout<<"\nBinary Search Tree DFS";
    cout<<"\nEnter the elements of tree ";
    do{
        cin>>data;
        if(data==-1)
        break;
        root=insert(root,data);
    }while(data>=0);
    cout<<"Enter the 2 values to find ancestor";
    cin>>p>>q;
    cout<<"Common ancestor: "<<commonAncestor(root,p,q);
    return 0;
}