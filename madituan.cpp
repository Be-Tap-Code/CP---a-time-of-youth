#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int n;
int flag = 0;
vector<vector<int>> banco;
vector<pair<int,int>> s;
int dem = 0;

void xuat(vector<vector<int>> k) // hàm này để xuất bàn cờ, đây mà một tra trận n x n có giá trị ở mỗi ô là thứ tự mã xuất hiện tại ô đó
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(2) << k[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    while (dem != n * n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k[i][j] == dem)
                {
                    s.push_back(make_pair(i,j));
                    dem++;
                    flag = 1;
                    continue;
                }
            }
            if (flag == 1) continue;
        }
    }
}

void xuat1(vector<pair<int,int>> s) // hàm xuất tọa độ của từng điểm di chuyển
{
    for (auto p : s)
    {
        cout << p.first << ',' << p.second << ',' << endl;
    }
}
void trie(int i,int x, int y) // đây là hàm backtracking để tìm ra tất cả các trường hợp mã có thể đi
{
    if (i == n * n) // đây là trường hợp mã đi hết bàn cờ
    {
        xuat(banco);
        //xuat1(s);
        flag++;
        //exit(0);
    }
    for (int j = 0; j < 8; j++)
    {
        int x_next = x + dx[j]; // cập nhật tọa độ x
        int y_next = y + dy[j]; // cập nhật tọa độ y
        if (x_next >= 0 && x_next < n && y_next >= 0 && y_next < n && banco[x_next][y_next] == -1) // kiểm tra tọa độ vừa cập nhật có hợp lệ hay không
        {
            banco[x_next][y_next] = i;
            trie(i+1,x_next,y_next); // backtracking
            banco[x_next][y_next] = -1; // trả lại giá trị -1 để nó có thể đi tìm tiếp trường hợp khác
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int x,y;
    cin >> n;
    if (n < 0 || n > 10)
    {
        cout << "kich thuoc ban co khong hop le!";
        return 0;
    }
    banco = vector<vector<int>>(n, vector<int>(n,-1));
    cin >> x >> y;
    if (x < 0 || y < 0 || x >= n || y >= n)
    {
        cout << "vi tri cua ma khong hop le!";
        return 0;
    }
    banco[x][y] = 0;
    trie(1,x, y);
    if (!flag) cout << "Khong ton tai duong di thoa man!";
}
