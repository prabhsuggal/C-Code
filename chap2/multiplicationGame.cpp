#include<bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    uint64_t n,p;

    while(cin >> n){
        p=1;
        for(int i=0;;i++){
            p*=(uint64_t)((i%2)?2:9);
            if( p >= n){
                cout << ((i%2==0)?"Stan":"Ollie") << " wins.\n";
                break;
            }
        }
    }

    return 0;
}
