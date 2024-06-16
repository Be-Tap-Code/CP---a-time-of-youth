#include <iostream>
using namespace std;

const int MAXN = 45;
const int MAXM = 1e6 + 5;

int n, m, a[MAXN];
int dp[MAXM];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Cơ sở quy hoạch động
    dp[0] = 1;

    // Quy hoạch động
    for (int k = 1; k <= n; k++) {
        for (int i = a[k]; i <= m; i++) {
            dp[i] += dp[i - a[k]];
        }
    }

    // Đếm số cách lấy vàng
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        if (i <= m - i) {
            ans += dp[i] * dp[m - i];
        }
    }

    cout << ans << endl;
    return 0;
}
