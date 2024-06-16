#include<bits/stdc++.h>
using namespace std;
int s1,s2,a,b,ucln,res1,res2;
int i;
int main()
{
      cin >> a;
      cin >> b;
      for (int i=1; i<=sqrt(a); i++)
      {
        if (a%i==0)
        {
            s1=s1+i;
            if (a%(a/i)==0) s1=s1+(a/i);
        }
      }
      for (int i=1; i<=sqrt(b); i++)
      {
        if (b%i==0)
        {
            s2=s2+i;
            if (b%(b/i)==0) s2=s2+(b/i);
        }
      }
      ucln=__gcd(s1,a);
      res1=s1/ucln;
      res2=a/ucln;
      cout << res1 << endl;
      cout << res2;
}
