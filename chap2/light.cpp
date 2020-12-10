#include<bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif
    uint64_t n;
    long double sr;

    while(cin >> n){
        if(n==0){
            break;
        }
        sr = sqrt(n);
        cout << ((sr - floor(sr) == 0)?"yes":"no") << "\n";
    }

    return 0;
}
