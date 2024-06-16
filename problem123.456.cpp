#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> se;
    multiset<int> mse;
    multiset<int> mset;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto kt = se.find(x);
        if (kt == se.end())
            se.insert(x);
        else mse.insert(x);
    }
    int m = 0;
    for (auto it = se.begin(); it != se.end(); it++)
    {
        if (m > k) break;
        mset.insert(*it);
        m++;
    }
    if (m < k)
    {
        for (auto &it : mse)
        {
            if (m == k) break;
            mset.insert(it);
            m++;
        }
    }
    for (auto &it : mset)
        cout << it << " ";
}
