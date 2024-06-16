#include<bits/stdc++.h>
using namespace std;

static int TongTien = 0;

class KhachHang
{
protected:
    string Ten;
    double SoLuong;
    double DonGia;
public:
    virtual void Nhap()
    {
        cin >> Ten;
        cin >> SoLuong;
        cin >> DonGia;
    }
    string GetTen()
    {
        return Ten;
    }
    double TienHang()
    {
        return SoLuong * DonGia;
    }
    double ThueVat()
    {
        return TienHang() * 10 / 100;
    }
    virtual double TienKhachTra() = 0;
    void Xuat()
    {
        cout << Ten << endl;
        cout << TienKhachTra() << endl;
    }
};

class KHLoaiA: public KhachHang
{
public:
    void Nhap()
    {
        KhachHang::Nhap();
    }
    double TienKhachTra()
    {
        return TienHang() + ThueVat();
    }
};

class KHLoaiB: public KhachHang
{
protected:
    int SoNamThanThiet;
public:
    void Nhap()
    {
        KhachHang::Nhap();
        cin >> SoNamThanThiet;
    }
    double PhanTramKhuyenMai()
    {
        return max((double)SoNamThanThiet * 5 / 100, 0.5);
    }
    double TienKhachTra()
    {
        return TienHang() * (1 - PhanTramKhuyenMai()) + ThueVat();
    }
};

class KHLoaiC: public KhachHang
{
public:
    void Nhap()
    {
        KhachHang::Nhap();
    }
    double TienKhachTra()
    {
        return TienHang() * 50 / 100 + ThueVat();
    }
};

class QuanLy
{
protected:
    int x,y,z;
    KhachHang* ds[];
public:
    QuanLy(){}
    void Nhap()
    {
        cin >> x >> y >> z;
        for (int i = 0; i < x + y + z; i++)
        {
            if (i < x)
                ds[i] = new KHLoaiA;
            else
            if (i < x + y)
                ds[i] = new KHLoaiB;
            else
            if (i < x + y + z)
                ds[i] = new KHLoaiC;
            ds[i]->Nhap();
            TongTien += ds[i]->TienKhachTra();
        }
    }
    void Xuat()
    {
        cout << x << " " << y << " " << z << endl;
        for (int i = 0; i < x + y + z; i++)
            ds[i]->Xuat();
        cout << TongTien;
    }
};

int main()
{
    QuanLy qly;
    qly.Nhap();
    qly.Xuat();
    return 0;
}
