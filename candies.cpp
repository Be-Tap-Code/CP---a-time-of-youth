#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> dtlt(k);
        vector<vector<int>> vitri(n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            int g = min(i % k, k - i % k);
            vitri[g].push_back(i);
            dtlt[g].push_back(x);
        }
        int b[n+1];
        for (int i = 0; i < k; i++)
            sort(dtlt[i].begin(),dtlt[i].end());
        for (int i = 1; i < k; i++)
        {
            for (int j = 0; j < vitri[i].size(); j++)
                b[vitri[i][j]] = dtlt[i][j];
        }
        for (int j = 0; j < vitri[0].size(); j++)
            b[vitri[0][j]] = dtlt[0][j];
        int flag = 0;
        for (int i = 1; i <= n - 1; i++)
            if (b[i] > b[i+1])
            {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        if (flag == 0) cout << "YES" << endl;
    }
}
