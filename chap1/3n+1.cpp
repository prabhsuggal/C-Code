#include<bits/stdc++.h>
using namespace std;
uint32_t arr[1000000]={1};

//#define ONLINE_JUDGE

int cycle(int n){
    uint32_t tmp;
    /* cout << n << " "; */
    if(n <= 1000000 && arr[n-1])return arr[n-1];
    if(n == 1)return arr[0];
    else if(n%2){
        if(n <= 1000000){
            if(!arr[n-1]){
                tmp = cycle(3*n+1);
                arr[n-1] = 1 + tmp;
            }
            return arr[n-1];
        }
        return 1 + cycle(3*n+1);
    }
    if(n <= 1000000){
        if(!arr[n-1]){
            tmp = cycle(n>>1);
            arr[n-1] = 1 + tmp;
        }
        return arr[n-1];
    }
    return 1 + cycle(n>>1);
}

int main(){
    uint32_t a,b,i,j, res, len;
#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    while(cin >> a >> b){
        i = (a<b)?a:b;
        j = (a>b)?a:b;
        res=0;
        len=0;
        for(uint32_t num = j; num >=i; num--){
            if(arr[num-1]){
                res = (res >= arr[num-1])?res:arr[num-1];
            }
            else{
                /* cout << "Running for num: "<< num << endl; */
                len = cycle(num);
                res = (res >= len)?res:len;
                /* cout <<"res: "<< res << endl; */
                /* for(int x=30; x>-1; x--){ */
                /*     cout << arr[x] << " "; */
                /* } */
                /* cout<<endl; */
            }
        }
        cout << a <<" "<<b<<" "<< res<<endl;
    }
    return 0;
}
