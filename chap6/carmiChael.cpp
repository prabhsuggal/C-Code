#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE
#define MAX_N 65000
unordered_set<int> primes;

void find_primes(void){

    vector<bool> num(MAX_N + 1, true);
    num[0] = false;
    num[1] = false;
    for(int i = 2; i*i <= MAX_N; i++){
        if(!num[i]){
            continue;
        }
        for(int j=2; i*j <= MAX_N; j++){
            num[i*j] = false;
        }
    }
    for(int i=0; i<= MAX_N; i++){
        if(num[i]){
            primes.insert(i);
        }
    }
}

long long int raiseToPowerModN(long long base, int exp) {
    long long result = 1;
    int mod = exp;
    while(exp > 0) {
        if(exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool satisfiesFermat(int n){
    long long a;
    std::random_device rd;
    std::mt19937 mt(rd());
    uniform_int_distribution<> distr(2,n-1);
    for(int i = 0; i < 1000; i++){
        a = distr(mt);
        if(raiseToPowerModN(a, n) != a){
            return false;
        }
    }

    return true;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif
    find_primes();
    
    int n;
    vector<int> is_carmiChael(MAX_N, 0);
    while(true){
        cin >> n;
        if(!n){
            break;
        }
        if(is_carmiChael[n] > 0){
            cout << "The number " << n << " is a Carmichael number.\n";
            continue;
        }
        if(is_carmiChael[n] < 0){
            cout << n << " is normal.\n";
            continue;
        }
        if(satisfiesFermat(n)){
            if(primes.find(n) == primes.end()){
                cout << "The number " << n << " is a Carmichael number.\n";
                is_carmiChael[n] = 1;
                continue;
            }
        }
        cout << n << " is normal.\n";
        is_carmiChael[n] = -1;


    }

    return 0;
}
