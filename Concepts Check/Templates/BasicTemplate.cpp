#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

template<class T, class U>
U Max(T a, U b){
    if(a < b){
        return b;
    }
    return a;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    cout << Max(2,3) << "\n";
    cout << Max(-1.0, 2.99) << "\n";
    cout << Max(-1, -3.001) << "\n";

    return 0;
}
