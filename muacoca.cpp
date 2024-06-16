#include<bits/stdc++.h>

using namespace std;

string s;

int n, k;

int main()
{
    cin >> s;
    n = s.size();
    if (s[0] == s[n-1])
    {
        cout << "Lose";
    }
    else
    {
        cout << "Win";
    }
}
