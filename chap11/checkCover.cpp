#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> ans;

bool isCoverSafe(int row, int col){

    int sz = ans.size();
    for(int i=0; i< sz; i++){
        if(ans[i] == col)return false;
    }

    for(int i=0; i<sz; i++){
        if((row - i == col - ans[i]) || (row - i == ans[i] - col))return false;
    }

    int x1,x2,x3 = col,y1,y2,y3 = row;
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            x1 = ans[i];
            y1 = i;
            x2 = ans[j];
            y2 = j;
            if((y2-y1)*(x3 - x2) == (y3 - y2)*(x2-x1))return false;
        }
    }

    return true;
}

bool isValid(int N, int row){
    if(row >= N)return true;

    for(int col = 0; col < N; col++){
        if(isCoverSafe(row, col)){
            ans.push_back(col);
            if(isValid(N, row+1))return true;
            ans.pop_back();
        }
    }
    return false;
}

void print(int N){
    for(int i=N-1; i>=0; i--){
        for(int j=0; j<N; j++){
            if(j == ans[i])cout << "S";
            else cout << "*";
            cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    int N =  31;

    for(int col=0; col<N; col++){
        ans.push_back(col);
        if(isValid(N, 1))break;
        ans.pop_back();
    }

    cout << N << "\n";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i]+1 ;
        if(i == ans.size()-1){
            cout << "\n";
        }
        else cout << " ";
    }
    //print(N);

    return 0;
}