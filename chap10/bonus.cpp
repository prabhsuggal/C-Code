#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

void print(vector<vector<int> > &a, string name){
    cout << name <<":\n";
    for(auto arr : a){
        for(int i : arr){
            cout << std::setfill(' ') << std::setw(15) << i;
        }
        cout << "\n";
    }
}

void print(vector<int> &a){
    for(int i : a){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    string expr;
    cin >> expr;

    if(expr.empty()){
        cout << "Empty String\n";
        return 0;
    }

    vector<char> symbol;
    vector<int> arr(1);

    for(char c : expr){
        if(c >= '0' && c <='9'){
            arr[arr.size()-1]*=10;
            arr[arr.size()-1] += (c - '0');
        }
        else{
            symbol.push_back(c);
            arr.push_back(0);
        }
    }

    print(arr);

    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(n, INT_MIN)), mid(n, vector<int>(n, -1));

    for(int i=0; i<n; i++){
        dp[i][i] = arr[i];
    }

    print(dp, "Initial parentheses arr");
    for(int size = 1; size<n; size++){
        for(int i=0; i+size < n; i++){
            int solution;
            for(int j=i; j+1 <= i+size; j++){
                switch(symbol[j]){
                    case '+':solution = dp[i][j] + dp[j+1][i+size]; break;
                    case '-':solution = dp[i][j] - dp[j+1][i+size]; break;
                    case '*':
                    case 'x':solution = dp[i][j] * dp[j+1][i+size]; break;
                }
                if(solution >= dp[i][i+size]){
                    mid[i][i+size] = j;
                    dp[i][i+size] = solution;
                }
            }
        }
        print(mid, "Array to use for parentheses");
        print(dp, "Parentheses arr");
    }

    print(mid, "Array to use for parentheses");
    cout << "Maximum Bonux: " << dp[0][n-1] << "\n";


    return 0;
}
