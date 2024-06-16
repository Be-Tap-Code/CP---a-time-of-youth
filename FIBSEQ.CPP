#include <bits/stdc++.h>
using namespace std;


#define TASK "FIBSEQ"
#define X first
#define Y second

const int N = 1e5 + 5;
const int MAXN = 1e6;
vector <int> fib;
bool F[MAXN + 5];
int n, P, Q;
void Pre_Compute(){
    fib.push_back(0);
    fib.push_back(1);
    F[0] = F[1] = true;
    while (true){
        int num = fib[(int) (fib.size() - 1)] + fib[(int) (fib.size() - 2)];
        if (num > MAXN) break;
        fib.push_back(num);
        F[num] = true;
    }
}

bool Fib_Cont(int x, int y){
    if (x > y) return false;
    if (!F[x] && !F[y]) return false;
    int idx = lower_bound(fib.begin(), fib.end(), x) - fib.begin();
    return (idx + 1 <= (int) fib.size() - 1 && fib[idx + 1] == y);
}
bool isFib(vector <int> &curr){
    int sz = (int) (curr.size());
    if (sz == 1){
        return F[curr.back()];
    }
    if (!Fib_Cont(curr[0], curr[1])) return false;
    for (int i = 2; i < sz; ++i){
        if (curr[i] != curr[i - 1] + curr[i - 2]) return false;
    }
    return true;
}
int good(vector <int> &a, int len){
    int n = (int) (a.size()), cnt = 0;
    vector <int> curr;
    for (int i = 0; i < len; ++i){
        curr.push_back(a[i]);
    }
    cnt += isFib(curr);
    for (int i = 1; i < n - len + 1; ++i){
        curr.erase(curr.begin());
        curr.push_back(a[i + len - 1]);
        cnt += isFib(curr);
    }
    return cnt;
}

void Solve(){
    Pre_Compute();
    cin >> n >> P >> Q;
    vector <int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int len = 1; len <= Q - P + 1; ++len){
        ans += good(a, len);
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    int ntest = 1;
//    cin >> ntest;
    while (ntest--){
        Solve();
    }
    return 0;
}
