#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

#define DEST "123456789abcdef0"
typedef pair<string, string> cpair;

bool tryUp(int idx){ return (idx >=4);}
bool tryDown(int idx){ return (idx<12);}
bool tryLeft(int idx){ return !(idx%4 == 0);}
bool tryRight(int idx){ return !((idx+1)%4 == 0);}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    for(int i=0; i<16; i++){
        cout << "For i: " << i << "tryUp: " << tryUp(i) << " tryDown: " 
            << tryDown(i) << " tryLeft: " << tryLeft(i) << " tryRight: " << tryRight(i) << "\n";
    }
    return 0;

    int N;
    cin >> N;
    while(N--){
        string src;

        int val;
        for(int i=0; i<16; i++){
            cin >> val;
            if(val < 10)src += (char)('0' + val);
            else src += (char)('a' + val - 10);
        }

        queue<cpair> bfs;
        unordered_set<string> visited;
        visited.insert(src);
        string str, steps;
        bfs.push(make_pair(steps, src));
        

        while(!bfs.empty()){
            steps = bfs.front().first;
            str = bfs.front().second;
            bfs.pop();

            if(str == DEST){
                cout << steps << "\n";
                break;
            }
            if(steps.size() > 45){
                cout << "This puzzle is not solvable.\n";
                break;
            }
            int pos = str.find('0');
            if(tryUp(pos)){
                swap(str[pos], str[pos-4]);
                if(visited.find(str) == visited.end())bfs.push(make_pair(steps+'U', str));
                swap(str[pos], str[pos-4]);
            }

            if(tryDown(pos)){
                swap(str[pos], str[pos+4]);
                if(visited.find(str) == visited.end())bfs.push(make_pair(steps+'D', str));
                swap(str[pos], str[pos+4]);
            }

            if(tryLeft(pos)){
                swap(str[pos], str[pos-1]);
                if(visited.find(str) == visited.end())bfs.push(make_pair(steps+'L', str));
                swap(str[pos], str[pos-1]); 
            }

            if(tryRight(pos)){
                swap(str[pos], str[pos-1]);
                if(visited.find(str) == visited.end())bfs.push(make_pair(steps+'L', str));
                swap(str[pos], str[pos-1]); 
            }
            
        }
    }

    return 0;
}
