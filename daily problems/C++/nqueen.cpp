#include <iostream>
#include<vector>
using namespace std;


bool isSafe(vector<string>&board,int row,int col,int n)
{
    int trow=row,tcol=col;
    while(row>=0 && col>=0)
    {
        if(board[row][col]=='Q')
        return false;
        row--;
        col--;
    }
    row=trow;
    col=tcol;
    while(col>=0)
    {
        if(board[row][col]=='Q')
        return false;
        col--;
    }
    col=tcol;
    while(row<n && col>=0)
    {
        if(board[row][col]=='Q')
        return false;
        col--;
        row++;
    }
    return true;
}

void solveQueen(vector<vector<string>>&ans,vector<string>&board,int n,int col)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,col,n))
        {
            board[i][col]='Q';
            solveQueen(ans,board,n,col+1);
            board[i][col]='.';
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    board[i]=s;
    solveQueen(ans,board,n,0);
    for(auto i:ans)
    {
        for(auto j:i)
        cout<<j<<endl;
        cout<<endl<<endl;
    }
    return 0;
}