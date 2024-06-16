#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,r,l,x,y,dem=0;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long Max=-1000000;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            l=j+1,r=n-1;
            while (l<=r)
            {
                x=(l+r)/2;
                if(2*a[j]-a[i]==a[x])
                {
                    dem=dem+1;
                    Max=max(Max,a[i]+a[j]+a[x]);
                    break;
                } else if(2*a[j]-a[i]>a[x])
                {
                    l=x+1;
                } else r=x-1;
            }
        }
    }
    cout<<dem<<endl<<Max;
    return 0;
}
