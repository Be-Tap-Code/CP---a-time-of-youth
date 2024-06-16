#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int giaiPT(float a, float b, float c,float &x1, float &x2){
    float delta = b*b - 4*a*c;
    if(delta<0){
        x1=x2=0.0;
        return 0;
    }
    else if(delta==0){
        x1 = x2 = -b/(2*a);
        return 1;
    }
    else{
        delta = sqrt(delta);
        x1 = (-b + delta) / (2*a);
        x2 = (-b - delta) / (2*a);
        return 2;
    }
}
int main(){
    float a,b,c;
    float x1,x2;
    cin >> a >> b >> c;
    int num = giaiPT(a,b,c,x1,x2);
        if(num == 0) {
        cout << "Vo nghiem";
    }
    else if(num == 1){
        cout << setprecision(2) << fixed << x1;
    }
    else{
        cout << setprecision(2) << fixed << x1 << " " << setprecision(2) << fixed << x2;
    }
}
