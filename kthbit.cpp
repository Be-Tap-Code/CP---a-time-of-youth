#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 100001;
int n, m, s, diemdau, diemden;
vector<pair<int,int>> adj[maxn];

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    cin >> diemdau >> diemden;
}

int pre[maxn];

void dijkstra(int s)
{
    vector<ll> d(n+1,INT_MAX);
    d[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0,s});
    while (!Q.empty())
    {
        pair<int,int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u]) continue;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v],v});
                pre[v] = u;
            }
        }
    }
    cout << d[diemden] << endl;
    vector<int> path;
    while (1)
    {
        path.push_back(diemden);
        if (diemden == diemdau) break;
        diemden = pre[diemden];
    }
    reverse(begin(path), end(path));
    for (int x : path)
        cout << x << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    dijkstra(diemdau);
}
6 9
1 2 5
1 3 1
2 3 2
2 5 2
3 5 5
5 6 7
5 4 3
2 4 10
4 6 3
