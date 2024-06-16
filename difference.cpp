#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<pair<char, char>, int> mp;
    set<char> se;
    for (int i = 0; i < n; i++)
    {
        char a, b;
        cin >> a >> b;
        int x;
        cin >> x;
        mp.insert(make_pair(make_pair(a, b), x));
        se.insert(a);
        se.insert(b);
    }
//    for (auto it : mp)
//        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    char a, b;
    int flag = 0;
    cin >> a >> b;
    for (auto it : mp)
    {
        if (it.first.first == a)
        {
            if (it.first.second == b)
            {
                cout << "2 dinh ke nhau" << endl;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0) cout << "2 dinh khong ke nhau" << endl;
    //cout << se.size();
    return 0;
}
