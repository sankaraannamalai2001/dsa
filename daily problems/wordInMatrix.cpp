#include <iostream>

using namespace std;
int r,c;
bool checkMatch(char *mat[c],string s,int i,int j,int r,int c,int l)
{
    if(l==s.length()-1)
    return true;
    if(i<0 || j<0 || i>=r || i>=c)
    return false;
    if(mat[i][j]==s[i]){
        bool res= checkMatch(mat,s,i,j+1,r,c,l+1)||checkMatch(mat,s,i,j-1,r,c,l+1)||checkMatch(mat,s,i+1,j,r,c,l+1)||checkMatch(mat,s,i-1,j,r,c,l+1);
        return res;
    }
    else return false;
}
int main()
{
    cout<<"Enter the number of rows and columns in matrix";
    cin>>r>>c;
    char a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    string s;
    cout<<"Enter the string";
    cin>>s;
    bool res;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==s[0])
            res=checkMatch(a,s,i,j,r,c,0);
        }
    }
    cout<<res;
    return 0;
}