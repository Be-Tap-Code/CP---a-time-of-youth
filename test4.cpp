#include<iostream>
using namespace std;
int main()
{
    int ss;
    cin >> ss;
    int ngay, gio, phut, giay;
    giay = ss % 60;
    phut = ss / 60;
    gio = ss / 60 / 60;
    ngay = ss / 60 / 60 / 24;
    cout << "ngay = " << ngay << endl;
    cout << "gio = " << gio << endl;
    cout << "phut = " << phut << endl;
    cout << "giay = " << giay << endl;
    return 0;
}
