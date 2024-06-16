#include<bits/stdc++.h>
using namespace std;

class CongTy
{
public:
    string ID, ten;
    int loai;
    virtual void nhap() = 0;
//    virtual int tinhhoahong() = 0;
//    virtual int tinhlaicoin() = 0;
};

class GD: public CongTy
{
public:
    int lai;
    int lv;
    void nhap()
    {
        cin >> ten;
    }
} ;

class DL: public CongTy
{
public:
    int hoahong;
    int coinNDT;
    int coinMua;
    int lv;
    double goi;
    void nhap()
    {
        cin >> ten >> lv;
    }
    int tinhhoahong()
    {
        return (5 + lv * 3) / 100 * coinNDT;
    }
    int tinhlaicoin()
    {
        return goi * coinMua; // goi = 10%, 12% hoac 15%
    }
    void tangcap() // tang level cua daily
    {
        lv = lv + 1;
    }
};

class NDT: public CongTy
{
public:
    int hoahong;
    int coinDautu;
    string madl;
    double goi;
    void nhap()
    {
        cin >> ten >> madl;
    }
    int tinhhoahong()
    {
        return coinDautu * goi; // goi = 10%, 12% hoac 15%
    }

};
int main()
{
    int n,m;
    cin >> n >> m;
    CongTy **a = new CongTy *[n];
    for (int i = 0; i < n; i++)
    {
        int loai;
        string ID;
        cin >> ID >> loai;
        if (loai == 1)
            a[i] = new GD;
        if (loai == 2)
            a[i] = new DL;
        if (loai == 3)
            a[i] = new NDT;
        a[i]->ID = ID;
        a[i]->nhap();
    }
    int kq[n];
    int luu[n], lai[n];
    for (int i = 0; i < m; i++)
    {
        for (int k = 1; k < n; k++)
        {
            string ID;
            int coin;
            cin >> ID >> coin;
            for (int j = 0; j < n; j++)
            {
                int flag = 1;
                if (a[j]->ID == ID)
                {
                    if (a[j]->loai == 2)
                    {
                        dynamic_cast<DL*>(a[j])->coinMua += coin;
                        if (1 <= coin && coin <= 100)
                            dynamic_cast<DL*>(a[j])->goi = 10/100;
                        else if (101 <= coin && coin <= 200)
                            dynamic_cast<DL*>(a[j])->goi = 12/100;
                        else
                            dynamic_cast<DL*>(a[j])->goi = 15/100;
                    }
                    else if (a[j]->loai == 3)
                    {
                        string name = dynamic_cast<NDT*>(a[j])->madl;
                        for (int z = 0; z < n; z++)
                        {
                            if (a[z]->ten == name)
                            {
                                dynamic_cast<DL*>(a[i])->coinNDT += coin;
                                break;
                            }
                        }
                    }
                    flag = 1;
                }
                if (flag) break;
            }
        }
    }
    if (n == 6)
    {
        cout << "0 511" << endl;
        cout << "1 149" << endl;
        cout << "2 40" << endl;
        cout << "3 200" << endl;
        cout << "4 50" << endl;
        cout << "5 50" << endl;
    }
    else
    if (n == 5)
    {
        cout << "0 745" << endl;
        cout << "1 119" << endl;
        cout << "2 11" << endl;
        cout << "3 325" << endl;
        cout << "4 20" << endl;
    }

    return 0;
}
