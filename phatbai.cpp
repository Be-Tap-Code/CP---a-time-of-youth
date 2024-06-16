#include<bits/stdc++.h>
using namespace std;
int k, n, q, p, kt;
int main()
{
    25

    5

    6

    2
    cin >> n >> k >> p >> q;
    kt = (p - 1) * 2 + q;
    if (kt - k <= 0)
    {
        kt = kt + k;
        if (kt > n)
        {
            cout << "-1";
            return 0;
        } else
        {   cout << (kt + 1) / 2 << " " ;
            if  (kt % 2 == 0)
            {
                cout << 2;
            }
            else cout << 1;
        }
    } else
    {
        cout << (kt - k + 1) / 2 << " " ;
        if  (kt - k) % 2 == 0)
        {
            cout << 2;
        }
        else cout << 1;
    }
}
