#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int l=0, mid, r=n-1;
    while(l<r){
        mid = l+(r-l)/2;
        cout << l << " " << mid << " " << r << endl;
        if(arr[mid] - arr[l] > mid-l){
            r = mid-1;
        }
        else{
            if(arr[mid+1] - arr[mid] != 1){
                r = mid;
            }
            l = mid;
        }
    }

    cout << arr[r]+1 << endl;

    return 0;
}
