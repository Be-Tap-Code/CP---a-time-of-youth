#include<bits/stdc++.h>
using namespace std;
int k;
int v, e;
vector<int> color(100);
map<string,int> chiso;

void in()
{
    for (int i = 0; i < v; i++)
        cout << color[i] << ' ';
    exit(0);
}

int check_color(int i, int x, vector<string> dsk[])
{
    for (string j : dsk[i])
        if (x == color[chiso[j]])
            return 0;
    return 1;
}

void trie(int i, vector<string> dsk[])
{
    for (int j = 0; j < k; j++)
    {
        if(check_color(i, j,dsk) == 1)
        {
            color[i] = j;
            if (i == v - 1)
                in();
            else trie(i + 1, dsk);
            color[i] = -1;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e;
    vector<string> dinh(v);
    vector<string> dsk[v];
    for (int i = 0; i < 100; i++)
        color[i] = -1;
    for (int i = 0; i < v; i++)
    {
        cin >> dinh[i];
        chiso[dinh[i]] = i;
    }
    for (int i = 0; i < e; i++)
    {
        string a,b;
        cin >> a >> b;
        dsk[chiso[a]].push_back(b);
        dsk[chiso[b]].push_back(a);
    }
    for (int i = 1; i <= v; i++)
    {
        k = i;
        trie(0, dsk);
    }
}
