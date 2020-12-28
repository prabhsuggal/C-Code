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
        cin >> n;
        cin.ignore(1,'\n');
        vector<string> initial(n), final(n);
        for(int i=0; i<n; i++){
            getline(cin, initial[i]);
        }
        for(int i=0; i<n; i++){
            getline(cin, final[i]);
        }

        int ini,fin;
        for(ini = n-1, fin = n-1; ini>=0; ){
            if(initial[ini] == final[fin]){
                ini--;fin--;
            }
            else{
                ini--;
            }
        }
        while(fin >= 0){
            cout << final[fin--]<<"\n";
        }
        cout << '\n';
    }

    return 0;
}
