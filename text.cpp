#include<bits/stdc++.h>
using namespace std;

int a[100][100],k,n,x[100], d1[100], d2[100], cot[100], cnt = 0;

void inkq()
{
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
        a[i][x[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j];
            cout << endl;
    }
    cout << endl;
}

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 1 && d1[i - j + n] == 1 && d2[i + j - 1] == 1)
        {
            x[i] = j;
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            if (i == n) ++cnt;
               // inkq();
            else Try(i + 1);
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= 99; i++)
    {
        cot[i] = d1[i] = d2[i] = 1;
    }
    Try(1);
    cout << cnt;
    return 0;
}
