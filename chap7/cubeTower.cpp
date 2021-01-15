

///DOESN'T WORK :( 

#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

string cubeFace(int a){
    switch(a){
        case 0: return "front";
        case 1: return "back";
        case 2: return "left";
        case 3: return "right";
        case 4: return "top";
        case 5: return "bottom";
    }
    return "shit";

}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
#endif

    while(true){
        int N;
        cin >> N;
        if(N == 0){
            break;
        }

        vector<vector<vector<int> > > cubes(N, vector<vector<int> >(3, vector<int>(2, 0)));
        for(int i=0; i<N; i++){
            cout << i+1 << ": ";
            for(int j=0; j<3; j++){
                cin >> cubes[i][j][0] >> cubes[i][j][1];
                cout << cubes[i][j][0] << " " << cubes[i][j][1] << " ";
            }
            cout << "\n";
        }

        vector<int> dp(N,1);
        vector<pair<int, int> > parent(N, make_pair(-1, -1));
        unordered_map<int, int> tower;
        int max_len=0, max_len_idx=-1;
        for(int i=N-1; i>=0; i--){
            for(int j=0; j<3; j++){
                for(int k=0; k<2; k++){
                    if(tower.find(cubes[i][j][k]) != tower.end() && tower[cubes[i][j][k]]!=i){
                        if(dp[i] < dp[tower[cubes[i][j][k]]] + 1){
                            dp[i] = dp[tower[cubes[i][j][k]]] + 1;
                            parent[i] = make_pair(tower[cubes[i][j][k]], 2*j+k);
                        }
                    }
                    int other_side_color = cubes[i][j][(k+1)%2];
                    if(tower.find(other_side_color) == tower.end()){
                        tower[other_side_color] = i;
                    }
                    else{
                        tower[other_side_color] = (dp[i] > dp[tower[other_side_color]])?i:tower[other_side_color];
                    }
                }
            }
            if(max_len < dp[i]){
                max_len = dp[i];
                max_len_idx = i;
            }
        }

        cout << max_len_idx+1 ;
        while(parent[max_len_idx].first != -1){
            cout << "->" << parent[max_len_idx].first+1 << "(" << parent[max_len_idx].second << ")";
            max_len_idx = parent[max_len_idx].first;
        }
        cout << " = bottom\n";
        
        cout << max_len << "\n";


    }

    return 0;
}
