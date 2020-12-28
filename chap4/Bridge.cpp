#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int cases;
    cin >> cases;

    while(cases--){
        int n;
        cin >>n;
        if(!n){
            continue;
        }
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int A,B,C,D,sum = 0;
        string output="", a, b,c,d;
        while(true){
            A = arr[0];
            a = to_string(A);
            if(arr.size() == 1){
                sum += A;
                output += (a+'\n');
                output = to_string(sum)+'\n'+output;
                cout << output;
                break;
            }
            B = arr[1];
            b = to_string(B);
            if(arr.size() == 2){
                sum += B;
                output +=(a+' '+b+'\n');
                output = to_string(sum)+'\n'+output;
                cout << output;
                break;
            }
            if(arr.size() == 3){
                c = to_string(arr[2]);
                sum +=(B+A+arr[2]);
                output += (a+' '+b+'\n'+a+'\n'+a+' '+c+'\n');
                output = to_string(sum)+'\n'+output;
                cout << output;
                break;
            }
            D = arr[arr.size()-1];
            d = to_string(D);
            C = arr[arr.size()-2];
            c = to_string(C);
            arr.pop_back(); arr.pop_back();

            if(2*B <= A+C){
                output += (a+' '+b+'\n'+a+'\n'+c+' '+d+'\n'+b+'\n');
                sum +=(2*B+A+D);
            }
            else{
                output += (a+' '+c+'\n'+a+'\n'+a+' '+d+'\n'+a+'\n');
                sum+=(2*A+D+C);
            }
        }
        if(cases)
        cout << '\n';
    }

    return 0;
}
