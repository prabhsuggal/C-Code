#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE
#define NEG_INF -100000
#define ABS(x) ((x>0)?x:-(x))

int sum = 0;
int balancedWeights(vector<int> &arr, uint32_t idx, int weight, int k){
    if(k == 0){
        return weight;
    }
    if(idx == arr.size()){
        return NEG_INF;
    }

    int w1 = balancedWeights(arr, idx+1, weight + arr[idx], k-1);
    int w2 = balancedWeights(arr, idx+1, weight, k);

    return ((ABS(2*w1-sum) < ABS(2*w2-sum))?w1:w2);
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int N;
    cin >> N;
    while(N--){
        int n;
        cin >> n;
        vector<int> people(n);
        for(int i=0; i<n; i++){
            cin >> people[i];
            sum += people[i];
        }

        int w1 = balancedWeights(people, 0, 0, n/2);
        int w2 = sum - w1;

        if(w1<w2){
            cout << w1 << " " << w2 << "\n";
        }
        else{
            cout << w2 << " " << w1 << "\n";
        }

    }

    return 0;
}
