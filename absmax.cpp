#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
void XuatS(int n, vector<string> k)
{
    for (int i = 1; i<= 2*n; i++)
    cout<<k[i];
    cout<<endl;
}
void capngoacdon(int i, int &l, int &r,int n, vector<string> &k)
{
    for(int j = 1; j <= 2; j++)
    {
        if(j==1 && l >=r && l <n)
        {
            k[i]='(';
            l++;
            if(l==r) {XuatS(n,k);}
            else{capngoacdon(i+1,l,r,n,k);}
            l--;
        }
        else if(j==2 && l>=r && r<n){
            k[i]=')';
            r++;
            if(l==r) {XuatS(n,k);}
            else{capngoacdon(i+1,l,r,n,k);}
            r--;
        }

    }
}
int main()
{
    cin>>n;
    vector<string> k (2*n+1,"");
    int l,r;
    l=0;r=0;
    capngoacdon(1,l,r,n,k);
}
