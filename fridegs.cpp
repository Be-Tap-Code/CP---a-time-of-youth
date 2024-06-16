#include<bits/stdc++.h>
using namespace std;

int cs(int n)
{
    int dem = 0;
    while (n != 0)
    {
        n /= 10;
        dem++;
    }
    return dem;
}
bool kt(int n)
{
    int m = n;
    string t = "";
    while (m != 0)
    {
        int k = m % 10;
        m /= 10;
        t += to_string(k);
    }
    string v = to_string(n);
    if (t == v) return 1;
    return 0;
}

int main()
{
    int l, r;
    long long ans = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (kt(i)) ans += i;
    }
    cout << ans;
}
