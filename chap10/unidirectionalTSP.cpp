#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

typedef pair<string, int> spair;

void print(vector<vector<int> > &a, string name){
    cout << name << ":\n";
    for(auto &arr: a){
        for(auto i: arr){
            cout << i << " ";
        }
        cout << "\n";
    }
}

void print(vector<int> &arr, string name){
    cout << name << ":\n";
    for(auto i: arr){
        cout << i << " ";
    }
    cout << "\n";

}

bool comp(vector<int> &a, vector<int> &b){
    for(size_t i=0; i<a.size(); i++){
        if(a[i] < b[i])return true;
        if(a[i] > b[i])return false;
    }
    return true;
}

int lexographical_smallest(vector<vector<int> > &arr){
    vector<int> min_trace = arr[0];
    int min_idx = 0;

    for(size_t i=1; i<arr.size(); i++){
        if(comp(arr[i], min_trace)){
            min_trace = arr[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int m, n;
    while(cin >> m >> n){
        vector<vector<int> > arr(m, vector<int>(n)), dp(m, vector<int>(n, INT_MAX));
        vector<vector<vector<int> > > path(m, vector<vector<int> >(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }

        //print(arr, "input_arr");
        for(int i=0; i<m; i++){
            dp[i][0] = arr[i][0];
            path[i][0] = {i+1};
        }

        vector<vector<int> > row_options(3);
        for(int col = 1; col < n; col++){
            for(int row = 0; row < m; row++){
                row_options[0] = path[row][col-1];
                row_options[1] = path[(row - 1 + m)%m][col-1];
                row_options[2] = path[(row + 1)%m][col-1];
                // if(row == 1 and col == 13){
                //     for(auto path : row_options){
                //         print(path, "row_options");
                //     }
                //     cout << "\n\n";
                //     sort(row_options.begin(), row_options.end(), comp);
                //     for(auto path : row_options){
                //         print(path, "row_options");
                //     }
                // }
                sort(row_options.begin(), row_options.end(), comp);

                //cout << row <<" " << col << " " <<row_options[0].size()<< "\n";
                if(dp[row][col] > dp[row_options[0][col-1]-1][col-1] + arr[row][col]){
                    dp[row][col] = dp[row_options[0][col-1]-1][col-1] + arr[row][col];
                    path[row][col] = row_options[0];
                    path[row][col].push_back(row+1);
                }

                if(dp[row][col] > dp[row_options[1][col-1]-1][col-1] + arr[row][col]){
                    dp[row][col] = dp[row_options[1][col-1]-1][col-1] + arr[row][col];
                    path[row][col] = row_options[1];
                    path[row][col].push_back(row+1);
                }
                if(dp[row][col] > dp[row_options[2][col-1]-1][col-1] + arr[row][col]){
                    dp[row][col] = dp[row_options[2][col-1]-1][col-1] + arr[row][col];
                    path[row][col] = row_options[2];
                    path[row][col].push_back(row+1);
                }
                // print(path[row][col], "min_path_for_row " + to_string(row+1));
            }
            // print(dp, "min_path_costs");
            // cout << "\n\n";
        }

        //print(dp, "min_path_costs");
        int min_length = INT_MAX;
        for(int row = 0; row < m; row++){
            min_length = min(min_length, dp[row][n-1]);
        }

        vector<vector<int> > options;
        for(int row = 0; row < m; row++){
            if(min_length == dp[row][n-1]){
                options.push_back(path[row][n-1]);
            }
        }

        int min_path_idx = lexographical_smallest(options);
        for(int i=0; i<n; i++){
            cout << options[min_path_idx][i];
            if(i < n-1)cout << " ";
            else cout << "\n";
        }
        cout << min_length << "\n";

    }

    return 0;
}
