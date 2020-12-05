#include<bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE

void print(vector<vector<int> > &ballot){
    for(int i=0; i<ballot.size(); i++){
        for(int j=0; j<ballot[i].size(); j++){
            cout << ballot[i][j] << " ";
        }
        cout <<"\n";
    }
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int cases;
    cin >> cases;
    string temp;
    getline(cin, temp);
    getline(cin, temp);

    while(cases--){

        int n;
        cin >>n;
        getline(cin, temp);

        vector<string> candidates(n);
        for(int i=0; i<n; i++){
            getline(cin, candidates[i]);
            cout << candidates[i] << "\n";
        }

        vector<vector<int> > ballot;
        vector<int> b(n);
        istringstream ss;

        for(int i=0; ; i++){
            getline(cin, temp);
            if(temp.empty()){
                break;
            }
            ss.str(temp);
            for(int j=0; j<n; j++){
                ss >> b[j];
            }
            ballot.push_back(b);
            ss.str("");
            ss.clear();
        }

        print(ballot);


    }

    return 0;
}
