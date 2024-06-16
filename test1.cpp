#include <bits/stdc++.h>
using namespace std;

int n;

int quydoi(string s)
{
    if (s[0] == '2')
    {
        if (s[1] == 'N')
            return 1;
        if (s[1] == 'R')
            return 2;
        if (s[1] == 'B')
            return 3;
        if (s[1] == 'C')
            return 4;
    }
    if (s[0] == '3')
    {
        if (s[1] == 'N')
            return 5;
        if (s[1] == 'R')
            return 6;
        if (s[1] == 'B')
            return 7;
        if (s[1] == 'C')
            return 8;
    }
    if (s[0] == '4')
    {
        if (s[1] == 'N')
            return 9;
        if (s[1] == 'R')
            return 10;
        if (s[1] == 'B')
            return 11;
        if (s[1] == 'C')
            return 12;
    }
    if (s[0] == '5')
    {
        if (s[1] == 'N')
            return 13;
        if (s[1] == 'R')
            return 14;
        if (s[1] == 'B')
            return 15;
        if (s[1] == 'C')
            return 16;
    }
    if (s[0] == '6')
    {
        if (s[1] == 'N')
            return 17;
        if (s[1] == 'R')
            return 18;
        if (s[1] == 'B')
            return 19;
        if (s[1] == 'C')
            return 20;
    }
    if (s[0] == '7')
    {
        if (s[1] == 'N')
            return 21;
        if (s[1] == 'R')
            return 22;
        if (s[1] == 'B')
            return 23;
        if (s[1] == 'C')
            return 24;
    }
    if (s[0] == '8')
    {
        if (s[1] == 'N')
            return 25;
        if (s[1] == 'R')
            return 26;
        if (s[1] == 'B')
            return 27;
        if (s[1] == 'C')
            return 28;
    }if (s[0] == '9')
    {
        if (s[1] == 'N')
            return 29;
        if (s[1] == 'R')
            return 30;
        if (s[1] == 'B')
            return 31;
        if (s[1] == 'C')
            return 32;
    }
    if (s[0] == 'T')
    {
        if (s[1] == 'N')
            return 33;
        if (s[1] == 'R')
            return 34;
        if (s[1] == 'B')
            return 35;
        if (s[1] == 'C')
            return 36;
    }
    if (s[0] == 'J')
    {
        if (s[1] == 'N')
            return 37;
        if (s[1] == 'R')
            return 38;
        if (s[1] == 'B')
            return 39;
        if (s[1] == 'C')
            return 40;
    }
    if (s[0] == 'Q')
    {
        if (s[1] == 'N')
            return 41;
        if (s[1] == 'R')
            return 42;
        if (s[1] == 'B')
            return 43;
        if (s[1] == 'C')
            return 44;
    }
    if (s[0] == 'K')
    {
        if (s[1] == 'N')
            return 45;
        if (s[1] == 'R')
            return 46;
        if (s[1] == 'B')
            return 47;
        if (s[1] == 'C')
            return 48;
    }
    if (s[0] == 'A')
    {
        if (s[1] == 'N')
            return 49;
        if (s[1] == 'R')
            return 50;
        if (s[1] == 'B')
            return 51;
        if (s[1] == 'C')
            return 52;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        map<int,int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            a[i] = quydoi(x);
        }
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            b[i] = quydoi(x);
            mp[b[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = a[i] + 1; j <= 52; j++)
                if (mp[j])
                {
                    mp[j]--;
                    cnt++;
                    break;
                }
        }
        cout << cnt << endl;
    }

}
