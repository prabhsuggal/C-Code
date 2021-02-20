#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

typedef pair<int, int> ipair;

void print(vector<vector<int> > &a, string name){
    cout << name << ":\n";
    for(auto &arr : a){
        for(int i : arr){
            cout << i << " ";
        }
        cout << "\n";
    }
}

void print(vector<int> &arr, string name){
    cout << name << ":\n";
    for(int i : arr){
        cout << i << " ";
    }
    cout << "\n";
}

void print(vector<vector<ipair> > &a, string name){
    cout << name << ":\n";
    for(auto &arr : a){
        for(auto i : arr){
            cout << "[" << i.first << " " << i.second << "] ";
        }
        cout << "\n";
    }
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int N;
    cin >> N;

    while(N--){
        int ferryLen;
        cin >> ferryLen;
#define INF (ferryLen*100 + 1)
        vector<int> cars;
        int carLen, sumCarsLen = 0, max_cars_possible = 0, n;
        while(true){
            cin >> carLen;
            if(carLen == 0)break;
            cars.push_back(carLen);
            sumCarsLen += carLen;
            if(ferryLen*200 >= sumCarsLen)max_cars_possible++;
        }

        n = cars.size();
        n = min(n, max_cars_possible);

        vector<vector<ipair> > dp(n+1, vector<ipair>(n+1, make_pair(INF, INF)));
        vector<vector<int> > Arrangement(n+1, vector<int>(n+1, -1));

        dp[0][0] = make_pair(0, 0);
        max_cars_possible = 0;
        int x=0,y=0;
        for(int i=1; i<=n; i++){
            dp[0][i] = make_pair(0, min(dp[0][i-1].second + cars[i-1], INF));
            if(dp[0][i].second < INF){
                y = i;
                max_cars_possible = i;
            }
            Arrangement[0][i] = 1;
            dp[i][0] = make_pair(dp[0][i].second, 0);
            Arrangement[i][0] = 0;
        }


        for(int j=1; j<=n; j++){
            for(int i=1; i+j<=n; i++){
                if(dp[i-1][j].second < INF && dp[i-1][j].first + cars[i+j-1] < INF){
                    dp[i][j] = make_pair(dp[i-1][j].first + cars[i+j-1], dp[i-1][j].second);
                    Arrangement[i][j] = 0;
                }
                else if(dp[i][j-1].first < INF && dp[i][j-1].second + cars[i+j-1] < INF){
                    dp[i][j] = make_pair(dp[i][j-1].first, dp[i][j-1].second + cars[i+j-1]);
                    Arrangement[i][j] = 1;
                }
                if((dp[i][j].first < INF && dp[i][j].second < INF) && max_cars_possible < i+j){
                    x = i;
                    y = j;
                    max_cars_possible = i+j;
                }
                // cout << "i: " << i << " j: " << j << " max_cars: " << max_cars_possible << "\n";
                // print(dp, "arrangement");
                // print(Arrangement, "Starboard");
                // cout << "\n\n\n";
            }
        }

        // print(cars, "Car_len_arr");
        cout << max_cars_possible <<"\n";
        vector<int> carPlacement(max_cars_possible);

        int cars_in_port = 0, cars_in_starboard = 0;
        while(x!=0 || y!= 0){
            carPlacement[x+y-1] = Arrangement[x][y];
            if(Arrangement[x][y] == 1){
                cars_in_starboard += cars[x+y-1];
                y--;
            }
            if(Arrangement[x][y] == 0){
                cars_in_port += cars[x+y-1];
                x--;
            }
        }
        // cout << "cars_len_in_port: " << cars_in_port << " cars_len_in_starboard: "
        //         << cars_in_starboard << " ferry len: " << ferryLen*100 << "\n";


        for(int arrangement : carPlacement){
                if(arrangement == carPlacement[0])cout << "port\n";
                else cout << "starboard\n";
        }
        if(N)cout << "\n";
    }

    return 0;
}
