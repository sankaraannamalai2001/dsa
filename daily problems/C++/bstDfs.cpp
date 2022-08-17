#include <iostream>
using namespace std;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* create(int data)
{
    Node* leaf=(Node*)malloc(sizeof(Node*));
    leaf->data=data;
    leaf->left=leaf->right=NULL;
    return leaf;
}

Node* insert(Node* root,int data)
{
    if(root==NULL)
    return create(data);
    if(data>root->data)
    {
        root->right= insert(root->right,data);
    }
    else
    {
        root->left= insert(root->left,data);
    }
    return root;
}

void printInorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
    
}

void printPreorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printInorder(root->left);
    printInorder(root->right);
}
void printPostorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    printInorder(root->left);
    printInorder(root->right);
    cout<<root->data<<" ";
    
}
int main()
{
    int data;
    Node*root=NULL;
    cout<<"Enter the elements of Tree  ";
    do{
        cin>>data;
        if(data==-1)
        break;
        root=insert(root,data);
    }while(data>=0);
    cout<<"\nInorder  ";
    printInorder(root);
    cout<<"\nPreorder  ";
    printPreorder(root);
    cout<<"\nPostorder  ";
    printPostorder(root);

    return 0;
}



