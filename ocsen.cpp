#include<iostream>
using namespace std;
int a[4] = {-1,1,0,0},b[4] = {0,0,-1,1},n,m,x,y,danhdau[2050][2050],dem = 0;

void nhap (){
for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
        cin >> danhdau[i][j];
        }
    }
}

void backtracking(int y,int x){
        for(int i = 0;i<4;i++){
        int u = y + a[i];
        int v = x + b[i];
        if(u>=0 && u<n && v>=0 && v<m && danhdau[u][v]==0){
        dem++;
        danhdau[u][v] = 1;
        backtracking(u,v);
        }
    }
}
int main (){
    freopen("ocsen.inp", "r", stdin);
    freopen("ocsen.out", "w", stdout);
    cin >> n >> m >> y >> x;
    nhap();
    if (danhdau[y-1][x-1] == 1) {
        cout << "-1";
        return 0;
    }
    if(danhdau[y-1][x-1] == 0){
    danhdau[y-1][x-1] = 1;
    dem++;
    }
backtracking(y-1,x-1);
cout << dem;
}
