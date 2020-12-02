#include<iostream>

using namespace std;

int
pdiv(int a, int b){
    int res=0;
    int sign = ((a<0) ^ (b < 0)) ? -1 : 1;

    a=abs(a);
    b=abs(b);

    if(b==0){
        return sign*INT_MAX;
    }
    for(int it=31; it >=0; it--){
        if(a >= ((long)b<<it)){
            res|=(1<<it);
            a -= (b<<it);
        }
    }
    return sign*res;
}

int
pmult(int a, int b){
    int res=0, inc=0;
    int sign = ((a<0) ^ (b < 0)) ? -1 : 1;
    
    a=abs(a);
    b=abs(b);
    while(b){
        res += (a << (inc++ * (b&1)));
        b = b >> 1;
    }

    return res*sign;
}

int main(){
    int a=28,b=-3;
    cout << " a: " << a <<" b : " << b << endl;
    cout << "real val mult: " << a*b << " div: " << a/b << endl;
    cout << "a*b : " << pmult(a,b) << " a/b : " << pdiv(a,b) << endl;
    return 0;
}
