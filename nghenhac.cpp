#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, t;
    cin >> n >> k;
    vector<int64_t> a(n);
    int64_t m1 = 0, m2 = 0;
    for (int64_t &i:a) cin >> i;
    for (int64_t i:a) if (i > m1) m1 = i;
    for (int64_t &i:a) if (i == m1) {i = 0; break;}
    for (int64_t i:a) if (i > m2) m2 = i;
    int64_t q = m1 - m2 + 1;
    t = (m1 + m2) * q / 2;
    int64_t p = k / q, r = k % q;
    int64_t ans = (2 * m1 - r + 1) * r / 2 + p * t;
    cout << ans;
}
