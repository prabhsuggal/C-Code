#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

void print(vector<string> &a, string name = "dp"){
    cout << name << ": ";
    for(auto x : a)cout << x << " ";
    cout << "\n";
}

string Sum(string &a, string &b){
    u_int32_t carry = 0, sum = 0, A,B;

    if(a.size() < b.size())
        return Sum(b,a);
    string res = "";

    int x = b.size()-1, y=a.size()-1;
    for(; x >= 0; x--, y--){
        A = a[y] - '0';
        B = b[x] - '0';
        sum = (A+B+carry)%10;
        carry = (A+B+carry)/10;
        res = (char)(sum + '0') + res;
    }

    while(y >= 0){
        A = a[y] - '0';
        sum = (A+carry)%10;
        carry = (A+carry)/10;
        res = (char)(sum + '0') + res;
        y--;
    }
    if(carry > 0){
        res = (char)(carry + '0') + res;
    }
    return res;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int N;
    cin >> N;

    while(N--){
        string x,z;
        cin >> x;
        cin >> z;

        int n = x.size(), m = z.size();
        vector<string> dp(m+1, "");
        dp[0] = "1";

        for(int i=0; i<n; i++){
            for(int j=m; j>0; j--){
                if(x[i] == z[j-1])
                    dp[j]=Sum(dp[j-1], dp[j]);
                    //dp[j] += dp[j-1];
            }
            //print(dp);
        }

        cout << dp[m] << "\n";

    }

    return 0;
}
