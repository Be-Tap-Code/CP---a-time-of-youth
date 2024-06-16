#include <bits/stdc++.h>
using namespace std;

int ans[100] = {-1};

void Solve(int i, int n, int &num_0, int &num_1)
{
    for (int j = 0; j <= 1; j++)
    {
        if (j == 0 && num_0 < n)
        {
            ans[i] = j;
            num_0++;
            if (i == 2*n-1)
            {
                for (int k = 0; k < 2*n; k++)
                {
                    if (ans[k] == 0) cout << "(";
                    else cout << ")";
                }
                cout << endl;
            }
            else Solve(i+1, n, num_0, num_1);
            num_0--;
        }
        else if (j == 1 && num_1 < num_0 && num_1 < n)
        {
            ans[i] = j;
            num_1++;
            if (i == 2*n-1)
            {
                for (int k = 0; k < 2*n; k++)
                {
                    if (ans[k] == 0) cout << "(";
                    else cout << ")";
                }
                cout << endl;
            }
            else Solve(i+1, n, num_0, num_1);
            num_1--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    ans[0] = 0;
    int num_1 = 0;
    int num_0 = 1;
    Solve(1,n, num_0, num_1);
}
