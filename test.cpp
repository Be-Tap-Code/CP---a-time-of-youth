#include<bits/stdc++.h>
using namespace std;

vector<int> a(5000);
int n;

void lis(const vector<int> &f, const vector<int> &a)
{
    vector<int> LIS;
    int res = *max_element(f.begin(), f.end()) + 1;

    for (int p = n - 1; p >= 0; p--)
    {
        if (res == f[p] + 1)
        {
            res--;
            LIS.push_back(a[p]);
        }
    }
    reverse(LIS.begin(), LIS.end());
    cout << "Danh sach cac so: ";
    for (auto i : LIS)
        cout << i << ' ';
}

int main()
{
    cin >> n;

    int res = 0;
    vector<int> a(n), f(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = 9999999999;
        f[i] = lower_bound(b.begin(), b.begin() + res + 1, a[i]) - b.begin();
        res = max(res, f[i] + 1);
        b[f[i]] = a[i];
    }

    cout << "So so dac biet = " << res << endl;
    lis(f, a);
    return 0;
}

