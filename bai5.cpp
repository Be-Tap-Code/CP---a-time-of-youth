#include<bits/stdc++.h>
using namespace std;

class Nguoi
{
protected:
    int sucnhay[7];
    int chieucao;
    int sucmanh[5];
public:
    void nhap()
    {
        for (int i = 0; i < 7; i++)
            cin >> sucnhay[i];
        cin >> chieucao;
        for (int i = 0; i < 5; i++)
            cin >> sucmanh[i];
    }
    void Antao(int x)
    {
        for (int i = 0; i < 7; i++)
            sucnhay[i] += x;
    }
    int GetSucNhay(int i)
    {
        return sucnhay[i];
    }
    int GetSucManh(int i)
    {
        return sucmanh[i];
    }
    int GetChieuCao()
    {
        return chieucao;
    }
};

class VatCan
{
public:
    virtual void Nhap() = 0;
    virtual int GetLoai() = 0;
    virtual int VuotQua(Nguoi A) = 0;
};

class KhuRung: public VatCan
{
protected:
    int caychong[7];
    int tao;
public:
    int GetLoai()
    {
        return 1;
    }
    void Nhap()
    {
        cin >> tao;
        for (int i = 0; i < 7; i++)
            cin >> caychong[i];
    }
    int VuotQua(Nguoi A)
    {
        for (int i = 0; i < 7; i++)
            if (A.GetSucNhay(i) <= caychong[i])
                return 0;
        return 1;
    }
    int GetTao()
    {
        return tao;
    }
};

class DuongHam: public VatCan
{
protected:
    int n;
    int hamnui[];
public:
    void Nhap()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> hamnui[i];
    }
    int GetLoai()
    {
        return 2;
    }
    int VuotQua(Nguoi A)
    {
        for (int i = 0; i < n; i++)
            if (A.GetChieuCao() > hamnui[i])
                return 0;
        return 1;
    }
};

class QuaiVat: public VatCan
{
protected:
    int smqv[5];
public:
    void Nhap()
    {
        for (int i = 0; i < 5; i++)
            cin >> smqv[i];
    }
    int GetLoai()
    {
        return 3;
    }
    int VuotQua(Nguoi A)
    {
        int cnt = 0;
        for (int i = 0; i < 5; i++)
            if (A.GetSucManh(i) > smqv[i]) cnt++;
            else cnt--;
        if (cnt) return 1;
        return 0;
    }
};

class QuanLy
{
protected:
    int n;
    VatCan **ds;
    Nguoi A;
public:
    void Nhap()
    {
        cin >> n;
        ds = new VatCan*[n];
        for (int i = 0; i < n; i++)
        {
            int loai;
            cin >> loai;
            if (loai == 1)
                ds[i] = new KhuRung;
            if (loai == 2)
                ds[i] = new DuongHam;
            if (loai == 3)
                ds[i] = new QuaiVat;
            ds[i]->Nhap();
        }
        A.nhap();
        for (int i = 0; i < n; i++)
        {
            if (ds[i]->GetLoai() == 1)
                A.Antao(dynamic_cast<KhuRung*>(ds[i])->GetTao());
        }
    }
    void Xuat()
    {
        for (int i = 0; i < n; i++)
            if (ds[i]->VuotQua(A) == 0)
            {
                cout << "Khong tim duoc kho bau" << endl;
                return;
            }
        cout << "Tim duoc kho bau" << endl;
    }
};

int main()
{
    QuanLy Qly;
    Qly.Nhap();
    Qly.Xuat();
    return 0;
}
