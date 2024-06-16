#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int luuso(int a[4][4])
{
    int res = 0;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res = (res << 1) | a[i][j];

    return res;
}

void luumang(int n, int a[4][4])
{
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            a[i][j] = n & 1;
            n >>= 1;
        }
    }
}

int bfs(int a[4][4], int b[4][4])
{
    int an = luuso(a);
    int bn = luumang(b);
    queue<int> q;
    unordered_set<int> visited;
    q.push(an);
    visited.insert(an);
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int curn = q.front();
            q.pop();
            if (curn == bn)
                return cnt;
            int curmang[4][4];
            luumang(curn, curmang);
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if (curmang[i][j] == 1)
                    {
                        if (i > 0 && curmang[i - 1][j] == 0)
                        {
                            swap(curmang[i][j], curmang[i - 1][j]);
                            int nextn = luuso(curmang);
                            if (!visited.count(nextn))
                            {
                                q.push(nextn);
                                visited.insert(nextn);
                            }
                            swap(curmang[i][j], curmang[i - 1][j]);
                        }
                        if (i < 3 && curmang[i + 1][j] == 0)
                        {
                            swap(curmang[i][j], curmang[i + 1][j]);
                            int nextn = luuso(curmang);
                            if (!visited.count(nextn))
                            {
                                q.push(nextn);
                                visited.insert(nextn);
                            }
                            swap(curmang[i][j], curmang[i + 1][j]);
                        }
                        if (j > 0 && curmang[i][j - 1] == 0)
                        {
                            swap(curmang[i][j], curmang[i][j - 1]);
                            int nextn = luuso(curmang);
                            if (!visited.count(nextn))
                            {
                                q.push(nextn);
                                visited.insert(nextn);
                            }
                            swap(curmang[i][j], curmang[i][j - 1]);
                        }
                        if (j < 3 && curmang[i][j + 1] == 0)
                        {
                            swap(curmang[i][j], curmang[i][j + 1]);
                            int nextn = luuso(curmang);
                            if (!visited.count(nextn))
                            {
                                q.push(nextn);
                                visited.insert(nextn);
                            }
                            swap(curmang[i][j], curmang[i][j + 1]);
                        }
                    }
        }
        cnt++;
    }
}

int main()
{
    int a[4][4];
    int b[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> b[i][j];
    int ans = bfs(a, b);
    cout << ans;

    return 0;
}

