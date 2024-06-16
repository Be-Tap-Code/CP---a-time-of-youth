#include <bits/stdc++.h>

using namespace std;

int n;
int sum = 0;
int x[100];

void out(int i) {
    for (int j = 1; j < i; j++)
        cout << x[j] << "+";
    cout << x[i] << endl;
}

void bt(int i, int k) {
    for (int j = k; j <= n; j++) {
        if (sum + j > n) return;
        x[i] = j;
        sum += j;
        if (sum < n) bt(i + 1, j);
            else out(i);
        sum -= j;
    }
}

int main() {
    ios::sync_with_stdio(0);
  //  freopen("PTSO.INP","r",stdin);
   // freopen("PTSO.OUT","w",stdout);
    cin >> n;
    bt(1, 1);
}
