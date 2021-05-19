#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

int gcdExtended(int a, int b, int &x, int &y){

    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1, gcd;

    gcd = gcdExtended(b%a, a, x1, y1);

    x = y1 - (b/a)*x1;
    y = x1;

    if(a == b && x > y)swap(x,y);

    return gcd;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int a,b;
    while(cin >> a >> b){
        int x,y,d;
        d = gcdExtended(a, b, x, y);
        cout << x << " " << y << " " << d << "\n";
    }

    return 0;
}
