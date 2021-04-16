#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3
#define MAX_DIR 4

#define BLUE  0
#define WHITE 1
#define GREEN 2
#define BLACK 3
#define RED   4
#define MAX_COLOR 5

typedef struct state_{
    int row;
    int col;
    int direction;
    int color;
}state;

typedef pair<state, int> spair;

void print(state &a){
    cout  << a.row << " " << a.col << " " << a.direction << " " << a.color << "\n";
}

bool isTarget(state &a, state &b){
    return (a.row == b.row) && (a.col == b.col) && (a.color == b.color);
}

bool moveForward(state &s, state &t, int m, int n){
    t = s;
    switch(s.direction){
        case NORTH:{
            if(t.row < 1)return false;
            t.row--;
            t.color = (t.color+1)%MAX_COLOR;
            break;
        }
        case EAST:{
            if(t.col >= n-1)return false;
            t.col++;
            t.color = (t.color+1)%MAX_COLOR;
            break;
        }
        case SOUTH:{
            if(t.row >= m-1)return false;
            t.row++;
            t.color = (t.color+1)%MAX_COLOR;
            break;
        }
        case WEST:{
            if(t.col < 1)return false;
            t.col--;
            t.color = (t.color+1)%MAX_COLOR;
            break;
        }
        default:{
            cout << m << " " << n << "\n";
            print(s);
            print(t);
            assert(0);
        }
    }
    return true;
}

bool isEqual(state& s, state& t){
    return (s.row == t.row) && (s.col == t.col) && (s.direction == t.direction) && (s.color == t.color);
}

void turn(state &s, state &t, bool turnLeft){
    t = s;
    if(turnLeft) t.direction = (t.direction - 1 + MAX_DIR)%MAX_DIR;
    else t.direction = (t.direction + 1)%MAX_DIR;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int cases = 1;
    while(true){
        int m, n;

        cin >> m >> n;
        if(m==0 && n==0)break;

        if(cases > 1)cout << "\n";
        cout << "Case #" << cases++ << "\n";

        vector<vector<bool> > blocked(m, vector<bool>(n, false));

        state source, target;
        char c;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> c;
                switch(c){
                    case 'S':{
                        source.row = i;
                        source.col = j;
                        source.direction = NORTH;
                        source.color = GREEN;
                        break;
                    }
                    case 'T':{
                        target.row = i;
                        target.col = j;
                        target.color = GREEN;
                        break;
                    }
                    case '#':{
                        blocked[i][j] = true;
                        break;
                    }
                    default:continue;
                }
            }
        }

        // print(source);
        // print(target);
        queue<spair> bfs;
        state cur_state;
        int cur_time;
        bool visited[m][n][MAX_DIR][MAX_COLOR];
        memset(visited, 0, m*n*MAX_DIR*MAX_COLOR);
        state parent[m][n][MAX_DIR][MAX_COLOR];
        memset(parent, -1, sizeof(state)*m*n*MAX_DIR*MAX_COLOR);

        bfs.push(make_pair(source, 0));
        visited[source.row][source.col][source.direction][source.color] = true;

        while(!bfs.empty()){
            cur_state = bfs.front().first;
            cur_time = bfs.front().second;
            bfs.pop();

            // cout << "cur_state\n";
            // print(cur_state);

            if(isTarget(cur_state, target)){
                cout << "minimum time = " << cur_time << " sec\n";
                goto passed;
            }

            state next_state;
            if(moveForward(cur_state, next_state, m, n) &&
                !blocked[next_state.row][next_state.col] &&
                !visited[next_state.row][next_state.col][next_state.direction][next_state.color]){
                visited[next_state.row][next_state.col][next_state.direction][next_state.color] = true;
                bfs.push(make_pair(next_state, cur_time+1));
                parent[next_state.row][next_state.col][next_state.direction][next_state.color] = cur_state;
                // cout << "next_state: \n";
                // print(next_state);
            }

            turn(cur_state, next_state, 0);
            if(!visited[next_state.row][next_state.col][next_state.direction][next_state.color]){
                visited[next_state.row][next_state.col][next_state.direction][next_state.color] = true;
                bfs.push(make_pair(next_state, cur_time+1));
                parent[next_state.row][next_state.col][next_state.direction][next_state.color] = cur_state;
                // cout << "next_state: \n";
                // print(next_state);
            }

            turn(cur_state, next_state, 1);
            if(!visited[next_state.row][next_state.col][next_state.direction][next_state.color]){
                visited[next_state.row][next_state.col][next_state.direction][next_state.color] = true;
                bfs.push(make_pair(next_state, cur_time+1));
                parent[next_state.row][next_state.col][next_state.direction][next_state.color] = cur_state;
                // cout << "next_state: \n";
                // print(next_state);
            }
        }

        cout << "destination not reachable\n";
        continue;

passed:
        // vector<vector<int> > path(m, vector<int>(n, 0));
        // state p = cur_state;
        // path[p.row][p.col] = 1;
        // print(p);
        // while(!isEqual(p, source)){
        //     p = parent[p.row][p.col][p.direction][p.color];
        //     path[p.row][p.col] = 1;
        //     print(p);
        // }
        // cout << " path: \n";
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout << path[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        continue;

    }




    return 0;
}
