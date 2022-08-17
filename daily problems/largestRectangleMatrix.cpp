#include <iostream>
#include<stack>
using namespace std;


int largestRect(int a[],int n)
{
    int left[n],right[n];
    for(int i=0;i<n;i++)
    {
        left[i]=1;
        right[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        int r=i+1;
        while(r<n)
        {
            if(a[r]>=a[i])
            left[i]++;
            else
            break;
            r++;
        }
        int l=i-1;
        while(l>=0)
        {
            if(a[l]>=a[i])
            right[i]++;
            else
            break;
            l--;
        }
    }
   
    int max_val=0;
    for(int i=0;i<n;i++)
    {
        max_val=max(max_val,((left[i]+right[i]-1)*a[i]));
    }
    return max_val;
}
int main()
{
    int a[100][100],m,n;
    cout<<"Enter the number of rows and columns";
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int max_val=0;
    for(int i=0;i<m;i++)
    {
        if(i==0)
        {
          max_val= largestRect(a[0],n);
        }
        else
        {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                a[i][j]=1+a[i-1][j];
            }
        }
        max_val=max(max_val,largestRect(a[i],n));
        }
    }
    cout<<"Largest Rectangle area: ";
    cout<<max_val;
    return 0;
}
