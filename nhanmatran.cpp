#include<bits/stdc++.h>
using namespace std;

void Nhanmatran(int dims[], int n, vector<vector<int>> &m, vector<vector<int>> &s)
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int cost = m[i][k] + m[k+1][j] + dims[i-1] * dims[k] * dims[j];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
}

void inketqua(const vector<vector<int>>& s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        inketqua(s, i, s[i][j]);
        inketqua(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int dims[n + 1];
    for (int i = 0; i <= n; i++)
        cin >> dims[i];
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
    Nhanmatran(dims, n, m, s);
    cout << "Tich cua phep nhan ma tran tu A1 -> A" << n << " la ma tran A co so chieu: " << dims[0] << 'x' << dims[n] << endl;
    cout << "Chi phi toi thieu de nhan chuoi ma tran la: " << m[1][n] << endl;
    cout << "Thu tu cua phep nhan chuoi ma tran tren la: ";
    inketqua(s, 1, n);
    cout << endl;
    return 0;
}
