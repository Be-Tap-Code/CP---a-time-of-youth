#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long res(int x, int y, int z)
{
    if (y == 0)
        return 1;
    long long ans = res(x, y / 2, z);
    if (y % 2 == 1)
        return (((ans * ans) % z) * x) % z;
    else
        return (ans * ans) % z;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int k = res(b, c, mod -1);
        cout << res(a, k, mod) << endl;
    }
}
