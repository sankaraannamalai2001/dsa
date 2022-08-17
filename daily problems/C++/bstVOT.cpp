#include <iostream>
#include<queue>
#include<map>
using namespace std;

typedef struct node{
    int data;
    int hd;
    struct node*left;
    struct node*right;
}Node;


Node*create(int data,int hd)
{
    Node*leaf=(Node*)malloc(sizeof(Node*));
    leaf->data=data;
    leaf->hd=hd;
    leaf->left=leaf->right=NULL;
    return leaf;
}

Node*insert(Node*root,int data,int hd)
{
    if(root==NULL)
    return create(data,hd);
    if(data<root->data)
    root->left=insert(root->left,data,hd-1);
    else
    root->right=insert(root->right,data,hd+1);
    return root;
}

void vot(Node*root)
{
    map<int,vector<int>> m;
    queue<Node*> q;
    if(root==NULL)
    return;
    q.push(root);
    while(!q.empty())
    {
        // cout<<q.front()->data<<" ";
        if(q.front()->left!=NULL)
        q.push(q.front()->left);
        if(q.front()->right!=NULL)
        q.push(q.front()->right);
        m[q.front()->hd].push_back(q.front()->data);
        q.pop();
    }
    for(auto i:m)
    {
        for(auto j=i.second.begin();j!=i.second.end();j++)
        {
            cout<<*j<<" ";
        }
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
        root=insert(root,data,0);
    }while(data>=0);
    vot(root);
    
    return 0;
}