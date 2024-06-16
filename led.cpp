#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n, 0);
    set<int> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i:s)
    {
        cout << i << ' ';
        k--;
        if (k == 0) break;
    }
    if (k > 0)
    {
        for (int i = 0; i < n; i++)
        if (b[i])
        {
            cout << a[i] << ' ';
            if (--k == 0) break;
        }
    }
}
