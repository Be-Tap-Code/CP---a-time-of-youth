#include<bits/stdc++.h>

using namespace std;

int64_t n, a, b, c, d, ans;

int main()
{
    ios_base::sync_with_stdio(o); cin.tie(0);
    cin >> n >> a >> b >> c;
    d = b - c;
    if (a <= d) ans = n / a;
    else
    {
        ans = (n - b) / d + 1;
        n -= ans * d;
        ans += n / a;
    }
    cout << ans;
}
