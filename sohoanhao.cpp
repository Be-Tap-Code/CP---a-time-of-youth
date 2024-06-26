#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;
int dp[105][11][11][11][11][11], l[105], r[105], sum[105];
int n, k, m, D;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m >> D;
    for(int i = 1; i <= m; i++)
    {
        cin >> l[i];
        r[i] = l[i] + 9;
        sum[i] = 10;
    }
    dp[0][0][0][0][0][0] = 1;
    for(int i = 1; i <= n; i++)
    for(int sum1 = 0; sum1 <= sum[1]; sum1++)
    for(int sum2 = 0; sum2 <= sum[2]; sum2++)
    for(int sum3 = 0; sum3 <= sum[3]; sum3++)
    for(int sum4 = 0; sum4 <= sum[4]; sum4++)
    for(int sum5 = 0; sum5 <= sum[5]; sum5++)
    for(int digit = 0; digit <= k-1; digit++)
    {
        int tmp1 = sum1 + digit*(l[1] <= i && i <= r[1]);
        int tmp2 = sum2 + digit*(l[2] <= i && i <= r[2]);
        int tmp3 = sum3 + digit*(l[3] <= i && i <= r[3]);
        int tmp4 = sum4 + digit*(l[4] <= i && i <= r[4]);
        int tmp5 = sum5 + digit*(l[5] <= i && i <= r[5]);
        if(max({tmp1, tmp2, tmp3, tmp4, tmp5}) > 10) break;
        dp[i][tmp1][tmp2][tmp3][tmp4][tmp5] += dp[i-1][sum1][sum2][sum3][sum4][sum5];
        dp[i][tmp1][tmp2][tmp3][tmp4][tmp5] %= D;
    }
    cout << dp[n][sum[1]][sum[2]][sum[3]][sum[4]][sum[5]];
}
