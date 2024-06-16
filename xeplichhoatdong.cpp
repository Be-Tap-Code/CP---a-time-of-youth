#include <bits/stdc++.h>

using namespace std;

// Một công việc có thời gian bắt đầu, kết thúc.
struct HD
{
    int BD, KT;
};

// Hàm được sử dụng để sắp xếp
// các hoạt động theo thời gian kết thúc
bool sosanh(HD h1, HD h2)
{
    return (h1.KT < h2.KT);
}

// In ra số lượng tối đa các hoạt động có thể
// được thực hiện bởi một người, một lần một lượt.
void solve(HD a[], int n)
{
    // Sắp xếp các hoạt động theo thời gian kết thúc
    sort(a, a + n, sosanh);


    // Luôn chọn hoạt động đầu tiên
    int i = 0;
    cout << "(" << a[i].BD << ", " << a[i].KT << ")";

    // Xem xét các hoạt động còn lại
    for (int j = 1; j < n; j++)
    {
        // Nếu thời gian bắt đầu của hoạt động này
        // lớn hơn hoặc bằng thời gian kết thúc của hoạt động được chọn trước đó,
        // thì chọn nó
        if (a[j].BD >= a[i].KT)
        {
            //in ra cac hoat dong duoc chon
            cout << ", (" << a[j].BD << ", " << a[j].KT << ")";
            i = j;
        }
    }
}

int main()
{
    int n;
    // Nhập số lượng hoạt động
    cin >> n;

    HD a[n];

    // Nhập thời gian bắt đầu
    for (int i = 0; i < n; i++)
        cin >> a[i].BD;

    // Nhập thời gian kết thúc
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].KT;

        // Kiểm tra trường hợp ngoại lệ
        if (a[i].KT <= a[i].BD)
        {
            cout << "Loi: Thoi gian ket thuc khong lon hon thoi gian bat dau cho hoat dong " << i + 1 << endl;
            return 0; // Kết thúc chương trình
        }
    }

    // Gọi hàm
    solve(a, n);

    return 0;
}
