#include<bits/stdc++.h>

using namespace std;

class NhomMau
{
protected:
    bool rh;
public:
    void nhap()
    {
        char t;
        cout << "Nhap Rhesus";
        cin >> t;
        if (t == '+')
            rh = true;
        else rh = false;
    }
    bool getRh()
    {
        return rh;
    }
    virtual bool KTDiTruyen(char, char) = 0;
    virtual char GetTen() = 0;
    virtual bool TuongThich(char nm, bool) = 0;
};

class NhomA: public NhomMau
{
public:
    bool KTDiTruyen(char me, char con)
    {
        if (me == 'A')
            if (con == 'A' || con == 'O')
                return true;
        if (me == 'B')
            if (con == 'B' || con == 'O')
                return true;
        if (me == 'C')
            if (con == 'C' || con == 'O')
                return true;
        if (me == 'O')
            if (con == 'A' || con == 'O')
                return true;
        return false;
    }
    char GetTen()
    {
        return 'A';
    }
    bool TuongThich(char nm, bool b)
    {
        if (this->getRh() == false)
            if (nm == 'A' || nm == 'C')
                return true;
        if (this->getRh() == true)
            if (b == true)
                if (nm == 'A' || nm == 'C')
                    return true;
        return false;
    }
};

class NhomB: public NhomMau
{
public:
    bool KTDiTruyen(char me, char con)
    {
        if (me == 'A')
            return true;
        if (me == 'B')
            if (con == 'B' || con == 'O')
                return true;
        if (me == 'C')
            if (con == 'C' || con == 'A' || con == 'B')
                return true;
        if (me == 'O')
            if (con == 'B' || con == 'O')
                return true;
        return false;
    }
    char GetTen()
    {
        return 'B';
    }
    bool TuongThich(char nm, bool b)
    {
        if (this->getRh() == false)
            if (nm == 'B' && nm == 'C')
                return true;
        if (this->getRh() == true)
            if (b == true)
                if (nm == 'B' && nm == 'C')
                    return true;
        return false;
    }
};

class NhomAB: public NhomMau
{
    char GetTen()
    {
        return 'C';
    }
    bool KTDiTruyen(char me, char con)
    {
        if (me == 'A')
            if (con != 'O')
                return true;
        if (me == 'B')
            if (con != 'O')
                return true;
        if (me == 'C')
            if (con != 'O')
                return true;
        if (me == 'O')
            if (con == 'A' || con == 'B')
                return true;
        return false;
    }
    bool TuongThich(char nm, bool b)
    {
        if (this->getRh() == false)
            if (nm == 'C')
                return true;
        if (this->getRh() == true)
            if (b == true)
                if (nm == 'C')
                    return true;
        return false;
    }
};

class NhomO: public NhomMau
{
public:
    char GetTen()
    {
        return 'O';
    }
    bool KTDiTruyen(char me, char con)
    {
        if (me == 'A')
            if (con == 'A' || con == 'O')
                return true;
        if (me == 'B')
            if (con == 'B' || con == 'O')
                return true;
        if (me == 'C')
            if (con == 'A' || con == 'B')
                return true;
        if (me == 'O')
            if (con == 'O')
                return true;
        return false;
    }
    bool TuongThich(char nm, bool b)
    {
        if (this->getRh() == false)
            return true;
        if (this->getRh() == true)
            if (b == true)
                return true;
        return false;
    }
};

int main()
{
    int n;
    cout << "Nhap so nguoi: ";
    cin >> n;
    NhomMau* a[100];
    for (int i = 0; i < n; i++)
    {
        int chon;
        cout << "Hay chon 1 cho nguoi nhom mau O";
        cout << "Hay chon 2 cho nguoi nhom mau A";
        cout << "Hay chon 3 cho nguoi nhom mau B";
        cout << "Hay chon 4 cho nguoi nhom mau AB";
        cin >> chon;
        if (chon == 1) a[i] = new NhomO;
        if (chon == 2) a[i] = new NhomA;
        if (chon == 3) a[i] = new NhomB;
        if (chon == 4) a[i] = new NhomAB;
        a[i]->nhap();
    }

    int cha, me, con;
    cout << "Hay nhap so thu tu cua cha, me, con (theo thu tu cha, me, con):";
    bool kq = a[cha]->KTDiTruyen(a[me]->GetTen(), a[con]->GetTen());
    if (kq == 1)
        cout << "hop li" << endl;
    else cout << "khong hop li" << endl;

    int x;
    cout << "Nhap vao thu tu cua nguoi muon chon: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (i != x && a[x]->TuongThich(a[i]->GetTen(), a[i]->getRh()))
            cout << "nguoi thu " << i << "co the thay mau cho nguoi duoc chon" << endl;
    }
    return 0;
}
