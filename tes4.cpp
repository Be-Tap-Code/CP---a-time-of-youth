#include<bits/stdc++.h>
using namespace std;

int l;
int depth[200001], up[200001][17],visited[200001];

void bfs( vector<vector<int>> adj)
{
    queue<int> Q;
    Q.push(1);
    depth[1]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(!visited[u])
        {
            visited[u]=1;
            for(int v:adj[u])
            {
                if(v==up[u][0])
                    continue;
                up[v][0]=u;
                depth[v]=depth[u]+1;
                for(int i=1; i<=16; i++)
                    up[v][i]=up[up[v][i-1]][i-1];
                Q.push(v);
            }
        }
    }
}
int lca(int u, int v)   ///Tim LCA Sparse upable
{
    if(depth[u] < depth[v])
        swap(u, v);
    for(int i = 16; i >= 0; i--) ///nhay den cung do sau
        if(depth[up[u][i]] >= depth[v])
            u = up[u][i];
    if(u == v)
        return u;
    for(int i = 16; i >= 0; i--)///nhay den LCA
        if(up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v;
    vector<vector<int>> cay(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        cay[a].push_back(b);
        cay[b].push_back(a);
    }
    int goc = 0;
    int mx = 0;
    goc = 1;
    bfs(cay);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int w = lca(a,b);
        cout << depth[a] + depth[b] - 2 * depth[w] << endl;
    }
}
