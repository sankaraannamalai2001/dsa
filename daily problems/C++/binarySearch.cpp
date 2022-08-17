#include<iostream>
using namespace std;
int binarySearch(int a[],int t,int s, int e)
{
    if(s<=e)
    {
    int mid=(s+e)/2;
    if(a[mid]==t)
    return mid;
    else if(a[mid]>t)
    return binarySearch(a,t,s,mid-1);
    else if(a[mid]<t)
    return binarySearch(a,t,mid+1,e);
    }
    return -1;
}
int main()
{
    int n,t,res=-1;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>t;
    res=binarySearch(a,t,0,n-1);
    if(res!=-1)
    cout<<"Element found at "<<res<<"\n";
    else
    cout<<"Not found\n";
    return 0;
}