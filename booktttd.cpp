#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    string s, ans;
    char mn = 'z', mx = 'a';
    cin >> n >> s >> k;
    bool b[26] = {0};
    for (char c:s)
    {
        if (c > mx) mx = c;
        if (c < mn) mn = c;
        b[c - 97] = true;
    }
    if (n < k)
    {
        ans = s;
        for (int i = 0; i <= n - k; i++)
            ans += mn;
        cout << ans ;
        return 0;
    }
    int p = k - 1, q;
    while (p >= 0 && s[p] == mx) --p;
    for (int i = s[p] - 96; i < 26; i++)
        if (b[i])
        {
            q = i;
            break;
        }
    ans = s.substr(0, p) + char(q + 97);
    for (int i = p + 1; i < k; i++) ans +=mn;
    cout << ans;
}
