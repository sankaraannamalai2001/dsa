#include <iostream>
#include<vector>
using namespace std;

vector<int> result;
void longestSequence(vector<int>ans,vector<vector<int>>&a,int r,int c,int i,int j,int prev,vector<vector<int>>&visited)
{
    if(i<0 || j<0 || i>=r || j>=c || visited[i][j]==1||a[i][j]<=prev)
    {
        if(result.size()<ans.size())
        {
            result.clear();
            result.assign(ans.begin(),ans.end());
        }
        return;
    }
    visited[i][j]=1;
    ans.push_back(a[i][j]);

    longestSequence(ans,a,r,c,i+1,j,a[i][j],visited);
    
    longestSequence(ans,a,r,c,i,j+1,a[i][j],visited);
    
    longestSequence(ans,a,r,c,i-1,j,a[i][j],visited);
    
    longestSequence(ans,a,r,c,i,j-1,a[i][j],visited);
    ans.pop_back();
    visited[i][j]=0;
}
int main()
{
    int r,c;
    cout<<"Enter the size of matrix";
    cin>>r>>c;
    vector<int>ans;


    vector<int>row(c,0);

    vector<vector<int>>visited(r,row);
    vector<vector<int>>a(r,row);
    int temp;
   
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
            // visited[i][j]=0;
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            longestSequence(ans,a,r,c,i,j,-1,visited);
            // if(temp.size()>max.size())max.assign(temp.begin(),temp.end());
        }
    }
    //cout<<"Size: "<<result.size();
    for(auto i:result)
    cout<<i<<" ";

    return 0;
}