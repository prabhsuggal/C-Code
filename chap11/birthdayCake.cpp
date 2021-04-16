#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

typedef struct point_{
    int x, y;
}point;

#define ABS(x)  ((x>0)?x:-x)

int max(point &a){
    if(ABS(a.x) > ABS(a.y))return a.x;
    return a.y;
}

bool goodPartition(vector<point> &cherries, int A, int B){

    if(ABS(A) > 500 || ABS(B) > 500)return false;

    int N = cherries.size()/2, cnt=0;
    for(int i=0; i < cherries.size(); i++){
        if(A*cherries[i].x + B*cherries[i].y == 0)return false;
        if(A*cherries[i].x + B*cherries[i].y > 0)cnt++;
    }
    // cout << cnt << "||";
    return (cnt == N);
}

bool verify(vector<point> &cherries, point cherry){
    int mult_factor = 500/max(cherry);
    int At = -1*mult_factor*cherry.y;
    int Bt = mult_factor*cherry.x;

    if(goodPartition(cherries, At+1, Bt)){
        cout << At+1 << " " << Bt << "\n";
        return true;
    }
    if(goodPartition(cherries, At-1, Bt)){
        cout << At-1 << " " << Bt << "\n";
        return true;
    }
    if(goodPartition(cherries, At, Bt+1)){
        cout << At << " " << Bt+1 << "\n";
        return true;
    }
    if(goodPartition(cherries, At, Bt-1)){
        cout << At << " " << Bt-1 << "\n";
        return true;
    }
    return false;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int N;

    while(cin >> N){
        if(N == 0)break;

        // cout << N << "\n";
        vector<point> cherries(2*N);

        for(int i=0; i < 2*N; i++){
            cin >> cherries[i].x >> cherries[i].y;
        }

        for(int i=0; i < 2*N; i++){
            if(verify(cherries, cherries[i]))break;
        }

        // cout << "\n";

    }

    return 0;
}
