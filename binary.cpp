#include<bits/stdc++.h>
using namespace std;

int chatnp(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return chatnp(a, l, mid - 1, x);
        return chatnp(a, mid + 1, r, x);
    }
    return -1;
}
int main()
{
    int n, a[100000], m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int j = 1; j <= m; j++)
    {
        int x;
        cin >> x;
        cout << chatnp(a, 0, n - 1, x) << endl;
    }
}
