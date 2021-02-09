#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

#define DEST "034305650121078709a90"
#define MAX_STEPS 8

typedef pair<string, string> spair;

string leftRotateClkwise(string &a){
    string res;
    res = a.substr(10, 2);
    res += a.substr(0, 10);
    res += a.substr(12, 9);
    return res;
}

string rightRotateClkwise(string &a){
    string res;
    res = a.substr(0, 9);
    res += a.substr(11);
    res += a.substr(9, 2);
    return res;
}

string leftRotateCounterClkWise(string &a){
    string res;
    res = a.substr(2, 10);
    res += a.substr(0,2);
    res += a.substr(12);
    return res;
}

string rightRotateCounterClkwise(string &a){
    string res;
    res = a.substr(0, 9);
    res += a.substr(19);
    res += a.substr(9, 10);
    return res;
}

void generate_first(unordered_map<string, string> &bt){
    queue<spair> bfs;
    unordered_set<string> visited;
    bfs.push(make_pair(DEST, ""));
    visited.insert(DEST);

    string str, steps;

    while(!bfs.empty()){
        str = bfs.front().first;
        steps = bfs.front().second;
        if(steps.size() > MAX_STEPS){
            break;
        }
        bt[str] = steps;
        bfs.pop();

        
        string node;
        node = leftRotateClkwise(str);
        if(visited.find(node) == visited.end()){
            visited.insert(node);
            bfs.push(make_pair(node, '3'+steps));
        }
        node = rightRotateClkwise(str);
        if(visited.find(node) == visited.end()){
            visited.insert(node);
            bfs.push(make_pair(node, '4'+steps));
        }
        node = leftRotateCounterClkWise(str);
        if(visited.find(node) == visited.end()){
            visited.insert(node);
            bfs.push(make_pair(node, '1'+steps));
        }
        node = rightRotateCounterClkwise(str);
        if(visited.find(node) == visited.end()){
            visited.insert(node);
            bfs.push(make_pair(node, '2'+steps));
        }
    }
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n;
    cin >> n;
    while(n--){
        string src;
        int val;
        for(int i=0; i<24; i++){
            cin >> val;
            if(val < 10)src += (char)(val + '0');
            else src += (char)('a' + val - 10);
        }

        src = src.substr(0, 21);
        // cout << "src: " << src <<
        //         " leftRotateClkwise(src): " << leftRotateClkwise(src) <<
        //         " rightRotateClkwise(src): " << rightRotateClkwise(src) <<
        //         " leftRotateCounterClkWise(src): " << leftRotateCounterClkWise(src) <<
        //         " rightRotateCounterClkwise(src): " << rightRotateCounterClkwise(src)  << "\n";

        queue<spair> bfs;
        unordered_set<string> visited;
        bfs.push(make_pair(src, ""));
        visited.insert(src);

        string str, steps;
        unordered_map<string, string> backtrack;
        generate_first(backtrack);

        while(!bfs.empty()){
            str = bfs.front().first;
            steps = bfs.front().second;

            bfs.pop();

            if(backtrack.find(str) != backtrack.end()){
                steps += backtrack[str];
                if(steps.size() == 0){
                    cout << "PUZZLE ALREADY SOLVED\n";
                }
                else{
                    cout << steps << "\n";
                }
                break;
            }

            if(steps.size() > MAX_STEPS){
                cout << "NO SOLUTION WAS FOUND IN " << MAX_STEPS*2 << " STEPS\n";
                break;
            }
            string node;
            node = leftRotateClkwise(str);
            if(visited.find(node) == visited.end()){
                visited.insert(node);
                bfs.push(make_pair(node, steps+'1'));
            }
            node = rightRotateClkwise(str);
            if(visited.find(node) == visited.end()){
                visited.insert(node);
                bfs.push(make_pair(node, steps+'2'));
            }
            node = leftRotateCounterClkWise(str);
            if(visited.find(node) == visited.end()){
                visited.insert(node);
                bfs.push(make_pair(node, steps+'3'));
            }
            node = rightRotateCounterClkwise(str);
            if(visited.find(node) == visited.end()){
                visited.insert(node);
                bfs.push(make_pair(node, steps+'4'));
            }
        }

    }

    return 0;
}
