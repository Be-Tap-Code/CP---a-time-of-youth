#include<bits/stdc++.h>

using namespace std;

long double dem, cnt,n, m, h, w, k1, k2, cnt1, cnt2;

int main()
{
    cin >> n >> m >> h >> w;
    k1 = n ;
    k2 = m ;
    while (k1 > h)
    {
        k1 = k1 / 2;
        cnt1++;
    }
    while (k2 > w)
    {
        k2 = k2 /2;
        cnt1++;
    }
    k1 = n ;
    k2 = m ;
    while (k1 > w)
    {
        k1 = k1 / 2;
        cnt2++;
    }
    while (k2 > h)
    {
        k2 = k2 /2;
        cnt2++;
    }
    cout << min(cnt1, cnt2);
}
