#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> s1, s2;
vector<ll> a;
int j = 0;

void try1(int i, ll sum)
{
    int n = j;
    if (i == n / 2)
    {
        s1.push_back(sum);
        return;
    }
    try1(i + 1, sum + a[i]);
    try1(i + 1, sum);
}

void try2(int i, ll sum)
{
    int n = j;
    if (i == n)
    {
        s2.push_back(sum);
        return;
    }
    try2(i + 1, sum + a[i]);
    try2(i + 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (j < 30 && (1 << j) <= 1000000000)
    {
        ll m = (1 << j);
        a.push_back(m);
        j++;
    }
    while (t--)
    {
        int n, k;
        int flag = 0;
        cin >> n >> k;
        for (int i = 0; i <= k; i++)
            if (a[i] > n)
            {
                flag = 1;
                j = i - 1;
                break;
            }
        if (flag == 0) j = k - 1;
        try1(0,0);
        try2(j/2,0);
        sort(s2.begin(),s2.end());
        ll ans = 0;
        for (ll sum : s1)
            ans += upper_bound(s2.begin(), s2.end(), n - sum) - s2.begin();
        cout << ans << endl;
//        a.clear();
        s2.clear();
        s1.clear();
        j = 0;
    }
}
