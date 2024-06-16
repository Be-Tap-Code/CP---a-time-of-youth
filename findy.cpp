#include<bits/stdc++.h>
using namespace std;


long long x[8]= {0, 1, -1,0,1, 1,-1,-1 };
long long y[8]= {1, 0, 0, -1, 1, -1, -1,1};
long long a[1500][1500];

long long bfs(long long m,long long n, long long x0, long long y0, long long x1, long long y1)
{
    x0=m-x0-1;
    x1=m-x1-1;
    long long cnt=0;
    queue<pair<pair<long long,long long>,long long>>  q;
    q.push({{x0,y0},0});
    while(q.size()>0)
    {
        auto tmp=q.front();
        q.pop();
        if(tmp.first.first==x1&&tmp.first.second==y1)
        {
            return tmp.second;
        }
        for(long long i=0; i<8; i++)
        {
            long long x_new=tmp.first.first+x[i];
            long long y_new=tmp.first.second+y[i];
            if(x_new>=0&&x_new<m &&y_new>=0&&y_new<n&&a[x_new][y_new]==0)
            {
                q.push({{x_new,y_new},tmp.second+1});
                a[x_new][y_new]=1;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long m,n, x0,y0,x1,y1;
    cin>>m>>n>>x0>>y0>>x1>>y1;
    for(int i= 0; i < m; i++)
    {
        for(int j=0; j <n; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<bfs(m,n,x0,y0,x1,y1);
}
