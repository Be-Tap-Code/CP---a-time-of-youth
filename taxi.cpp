#include <iostream>

using namespace std;

int main()
{
    int a[5], chan = 0, le = 0;
    for (int i = 0; i < 5; i++)
        cin >> a[i];
   for (int i = 0; i < 5; i++)
   {
       if (a[i] % 2 == 0)
       {
           chan = max(a[i],chan);
       }
   }
   for (int i = 0; i < 5; i++)
   {
       if (a[i] % 2 != 0)
       {
           le = max(a[i],le);
       }
   }
   cout << "so chan lon nhat: " << chan << endl;
   cout << "so le lon nhat: " << le;
}
