#include<bits/stdc++.h>
using namespace std;

map<string,vector<string>> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x,y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for (auto it : mp)
    {
        cout << it.first << " : ";
        for (auto it2 : it.second)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}
