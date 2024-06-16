#include<bits/stdc++.h>

using namespace std;

long long cnt, n, k;

int main()
{
    cin >> n >> k;
    if (k % 2 == 0)
        cout << ((n + k / 2) / k) * ((n + k / 2) / k) * ((n + k / 2) / k) + (n / k) * (n / k) * (n / k);
    else cout << (n / k) * (n / k) * (n / k);
}
