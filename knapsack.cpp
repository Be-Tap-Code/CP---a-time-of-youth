#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Khai báo một struct item để lưu thông tin về đồ vật
struct item {
    int idx;     // Index của đồ vật
    double w, p; // Trọng lượng và giá trị của đồ vật

    // Constructor mặc định
    item() {
        idx = -1;
        w = 0;
        p = 0;
    }
};

// Hàm so sánh để sắp xếp các đồ vật theo tỷ lệ giá trị/trọng lượng giảm dần
bool cmp(item a, item b) {
    double item1 = a.p / a.w;
    double item2 = b.p / b.w;
    return item1 > item2;
}

int main() {
    int n; // Số lượng đồ vật
    double m; // Trọng lượng tối đa của balo
    cin >> n >> m;

    // Khai báo một vector chứa các đối tượng item (đồ vật)
    vector<item> itms(n);

    // Vector để lưu kết quả, giả sử giá trị của mỗi đồ vật có thể là một phần của nó
    vector<double> res(n, 0);

    // Nhập thông tin về từng đồ vật
    for (int i = 0; i < n; i++) {
        itms[i].idx = i; // Lưu index của đồ vật
        cin >> itms[i].w >> itms[i].p; // Nhập trọng lượng và giá trị của đồ vật
    }

    // Sắp xếp các đồ vật theo tỷ lệ giá trị/trọng lượng giảm dần
    sort(itms.begin(), itms.end(), cmp);

    double weight = 0; // Tổng trọng lượng của các đồ vật đã chọn
    double price = 0;  // Tổng giá trị của các đồ vật đã chọn
    int id_frac = -1;  // Index của đồ vật bị chia nhỏ (frac)

    // Duyệt qua từng đồ vật để xác định cách chia trọng lượng và tính tổng giá trị
    for (auto& x : itms) {
        if (weight < m) {
            double frac = 1;
            if (weight + x.w >= m) {
                id_frac = x.idx;
                frac = 1 - ((weight + x.w - m) / x.w);
            }
            res[x.idx] = frac;        // Lưu kết quả chia trọng lượng
            weight += x.w * frac;     // Cập nhật tổng trọng lượng
            price += x.p * frac;      // Cập nhật tổng giá trị
        }
        else break;
    }

    // In ra kết quả chia trọng lượng cho từng đồ vật
    for (double x : res) cout << x << " ";
    cout << endl;

    // In ra tổng trọng lượng và tổng giá trị của các đồ vật đã chọn
    cout << "weight = " << weight << endl << "price = " << price;

    return 0;
}
