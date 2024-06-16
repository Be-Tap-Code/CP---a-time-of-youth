#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,s;
    priority_queue<int>p;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout << endl;
        int u,v;
        cin>>u>>v;
        s+=u;
        if(i%2==0)
        {
            s-=p.top();
            p.pop();
        }
        p.push(u-v);
    }
    cout<<s;
}
