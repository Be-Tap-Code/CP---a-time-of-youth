#include <bits/stdc++.h>
using namespace std;

void xuli(long long b[], int N)
{
    b[0] = 1;
    for (int i = 1; i < N; i++)
        b[i] = b[i - 1] * i;
}

long long dem(long long b[], int N, int R)
{
    if (R > N)
        return 0;
    long long res = b[N] / b[R];
    res /= b[N - R];
    return res;
}

long long demcach(vector<int>& a, long long b[])
{
    int N = a.size();

    if (N <= 2)
        return 1;
    vector<int> caytrai;
    vector<int> cayphai;
    int root = a[0];
    for (int i = 1; i < N; i++)
        if (a[i] < root)
            caytrai.push_back(a[i]);
        else
            cayphai.push_back(a[i]);
    int N1 = caytrai.size();
    int N2 = cayphai.size();
    long long demtrai = demcach(caytrai,b);
    long long demphai = demcach(cayphai,b);
    return dem(b, N - 1, N1) * demtrai * demphai;
}

int main()
{
    vector<int> a;
    int N ;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    long long b[N];
    xuli(b, N);
    long long k = demcach(a, b);
    cout << k;

    return 0;
}
