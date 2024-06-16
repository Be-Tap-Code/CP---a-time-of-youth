#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<char> a(n + 1);
    vector<int> b(m + 1);
    vector<int> ans;
    vector<int> res;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
        while (b[i] < k)
        {
            ans.push_back(i);
            b[i]++;
        }
    for (auto i: ans)
        b[i]--;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 'E')
        {
            for (auto j : ans)
            {

                int flag = 1;
                int tam1 = b[j] + 1;
                for (int z = 1; z <= m; z++)
                {
                    if (b[z] < tam1 - 1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    b[j]++;
                    res.push_back(j);
                    auto it = find(ans.begin(), ans.end(),j);
                    ans.erase(it);
                    break;
                }
            }
        }
        if (a[i] == 'W')
        {
            for (auto j : ans)
            {
                int flag = 1;
                int tam1 = b[j] + 1;
                for (int z = 1; z <= m; z++)
                {
                    if (b[z] > tam1 && b[z] < k)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    b[j]++;
                    res.push_back(j);
                    auto it = find(ans.begin(), ans.end(),j);
                    ans.erase(it);
                    break;
                }
            }
        }
    }
    reverse(res.begin(), res.end());
    for (auto i : res)
        cout << i << ' ';
}
