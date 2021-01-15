#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int N;
    cin >> N;
    while(N--){
        string start="", desired="";
        int a;

        /* 
        start combination
        */

        for(int i=0; i<4; i++){
            cin >> a;
            start += (char)(a + '0');
        }

        /* 
        final combination
        */

        for(int i=0; i<4; i++){
            cin >> a;
            desired += (char)(a+'0');
        }


        int n;
        cin >> n;
        unordered_set<string> forbidden;
        
        for(int i=0; i<n; i++){
            string tmp="";
            for(int j=0; j<4; j++){
                cin >> a;
                tmp += (char)(a+'0');
            }
            forbidden.insert(tmp);
        }

        if(start == desired){
            cout << "0\n";
            continue;
        }

        queue<pair<string, int> > bfs;
        unordered_set<string> visited;

        bfs.push(make_pair(start, 0));
        visited.insert(start);
        while(!bfs.empty()){
            string node = bfs.front().first;
            string orig = node;
            int combinations = bfs.front().second;
            bfs.pop();
            for(int i=0; i<4; i++){
                uint8_t val = node[i] - '0';
                node[i] = (char)((val+1)%10 + '0');
                if(node == desired){
                    cout << combinations+1 << "\n";
                    goto end;
                }

                if(forbidden.find(node) == forbidden.end() && visited.find(node) == visited.end()){
                    visited.insert(node);
                    bfs.push(make_pair(node, combinations+1));
                }
                node[i] = (char)((val + 10 -1)%10 + '0');
                if(node == desired){
                    cout << combinations+1 << "\n";
                    goto end;
                }

                if(forbidden.find(node) == forbidden.end() && visited.find(node) == visited.end()){
                    visited.insert(node);
                    bfs.push(make_pair(node, combinations+1));
                }
                node[i] = (char)(val+'0');
            }
        }

        cout << "-1\n";
    end:
    //reading the blank line
    //    cin.ignore('\n', 1);
        continue;
    }

    return 0;
}
