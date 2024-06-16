#include<bits/stdc++.h>
using namespace std;

static int tongTienCuoc = 0;

class loaiXe
{
protected:
    double trongTai;
    string xuatXu, maPT;
    int tgSanXuat;
public:
    void nhap()
    {
        cin >> trongTai;
        cin >> xuatXu >> maPT;
        cin >> tgSanXuat;
    }
    virtual double nhienLieu(double soKm) = 0;
    virtual int tienCuoc(double soKm) = 0;
};

class xeContainer: public loaiXe
{
public:
    double nhienLieu(double soKm)
    {
        double k = soKm / 100;
        return 40 * k;
    }
    int tienCuoc(double soKm)
    {
        return soKm * (trongTai * 1000) * 150;
    }
};

class xeBen: public loaiXe
{
public:
    double nhienLieu(double soKm)
    {
        double k = soKm / 100;
        return 40 * k;
    }
    int tienCuoc(double soKm)
    {
        return soKm * trongTai * 5000;
    }
};

class xeDongLanh: public loaiXe
{
public:
    double nhienLieu(double soKm)
    {
        double k = soKm / 100;
        return 25 * k;
    }
    int tienCuoc(double soKm)
    {
        return soKm * (trongTai * 1000) * 200;
    }
};

class tuyenDuong
{
protected:
    int maTD, soKm;
    string tenTD;
public:
    void nhap()
    {
        cin >> maTD >> soKm;
        cin >> tenTD;
    }
    int GetmaTD()
    {
        return maTD;
    }
    int GetsoKm()
    {
        return soKm;
    }
};

class quanLyXe
{
protected:
    string maChuyenHang;
    string maPhuongTien;
    int maTuyenDuong;
    int tgianXeChay;
public:
    void xuli()
    {
        int n, m;
        cout << "nhap so tuyen duong: ";
        cin >> m;
        tuyenDuong* b[m];
        for (int i = 0; i < n; i++)
            b[i]->nhap();
        cout << "nhap so luong xe: ";
        cin >> n;
        loaiXe* a[n];
        for (int i = 0; i < n; i++)
        {
            int chon;
            cout << "hay chon 1 cho xe container" << endl;
            cout << "hay chon 2 cho xe ben" << endl;
            cout << "hay chon 3 cho xe dong lanh" << endl;
            cin >> chon;
            if (chon == 1) a[i] = new xeContainer;
            if (chon == 2) a[i] = new xeBen;
            if (chon == 3) a[i] = new xeDongLanh;
            a[i]->nhap();
        }
        for (int i = 0 ; i < n; i++)
        {
            cout << "nhap ma chuyen hang :";
            cin >> maChuyenHang;
            cout << "nhap ma phuong tien:";
            cin >> maPhuongTien;
            cout << "nhap ma tuyen duong: ";
            cin >> maTuyenDuong;
            cout << "nhap thoi gian xe chay: ";
            cin >> tgianXeChay;
            for (int j = 0; j < m; j++)
                if (maTuyenDuong == b[j]->GetmaTD())
                {
                    cout << "Cuoc van tai cho xe " << i << " chay la: ";
                    int k = a[i]->tienCuoc(b[j]->GetsoKm());
                    cout << k << "d" << endl;
                    break;
                }
        }
    }
};

int main()
{
    quanLyXe Qly;
    Qly.xuli();
    return 0;
}
