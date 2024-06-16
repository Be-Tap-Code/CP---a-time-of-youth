#include<bits/stdc++.h>

using namespace std;

bool bs(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return true;
        else
        if (a[m] < x)
            l = m + 1;
        else
        if (a[m] > x)
            r = m - 1;
    }
    return false;
}

bool binary_search(int a[], int l, int r, int x)
{
    if (l > r)
        return false;
    int m = (l + r) / 2;
    if (a[m] == x)
        return true;
    else
    if (a[m] < x)
        return binary_search(a, m + 1, r, x);
    else
        return binary_search(a, m - 1, l, x);
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (bs(a, n, x))
        cout << "Found\n";
    else
        cout << "Not found\n";
    return 0;
}
