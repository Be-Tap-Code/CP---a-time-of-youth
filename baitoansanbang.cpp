#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e, n;
    cin >> v >> e;
    vector<string> dinh(v);
    map<string,int> chiso;
    vector<string> dsk[v];
    vector<int> color2(v,-1);
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

    for (int i = 0; i < v; i++)
    {
        for (int mau = 0; mau <= 10000; mau++)
        {
            int flag = 1;
            color2[i] = mau;
            for (string j : dsk[i])
                if (color2[i] == color2[chiso[j]])
                {
                    flag = 0;
                    break;
                }
            if (flag == 1)
                break;
        }
    }
    for (int i : color2)
        cout << i << ' ';
}
