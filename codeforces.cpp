    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n, flag = 0;
            cin >> n;
            vector<int> a(n);
            vector<int> b(n - 1);
            for (int i = 0; i < n - 1; i++)
            {
                cin >> b[i];
                a[i] = b[i];
            }
            for (int i = 0; i < n - 2; i++)
                if (b[i] < b[i + 1])
                {
                    a.insert(a.begin() + i + 1, 0);
                    flag = 1;
                    break;
                }
            if (flag == 0) a[n - 1] = 0;
            for (int i = 0; i < n - 1; i++)
                if (max(a[i], a[i + 1]) != b[i])
                    a[i] = 0;
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
