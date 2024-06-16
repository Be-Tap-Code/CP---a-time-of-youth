#include<bits/stdc++.h>
using namespace std;

class vatpham
{
public:
    string name, producer;
    int loai;
    float price;
    virtual void nhap() = 0;
    virtual float getprice()
    {
        return 0;
    }
};

class quan: public vatpham
{
public:
    float length;
};

class jean: public quan
{
public:
    void nhap()
    {
        vatpham::nhap();
        loai = 1;
        cin >> length;
    }
    float getprice()
    {
        return price * 0.8;
    }
};

class kaki: public quan
{
public:
    void nhap()
    {
        vatpham::nhap();
        loai = 2;
        cin >> length;
    }
    float getprice()
    {
        return price*1.5;
    }
};

class ao: public vatpham
{
public:
    int loai;
    string color;
};

class aongantay: public ao
{
public:
    bool co;
    void nhap()
    {
        vatpham::nhap();
        loai = 3;
        cin >> co;
    }
};

class aodaitay: public ao
{
public:
    float length;
    void nhap()
    {
        vatpham::nhap();
        loai = 4;
        cin >> length;
    }
};

class mu: public vatpham
{
public:
    int level;
    virtual void nhap()
    {
        vatpham::nhap();
        cin >> level;
    }
};

class ironhat: public mu
{
public:
    void nhap()
    {
        mu::nhap();
        loai = 5;
        price = 0;
    }
};

class silverhat: public mu
{
public:
    void nhap()
    {
        mu::nhap();
        loai = 6;
    }
};

class goldhat: public mu
{
public:
    void nhap()
    {
        mu::nhap();
        loai = 7;
    }
};


int main()
{
    return 0;
}
