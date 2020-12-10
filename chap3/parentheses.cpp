#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    string parentheses;
    cin >> parentheses;

    int braces = 0;

    for(int i=0; i < parentheses.size(); i++){
        if(parentheses[i] == '('){
            braces++;
        }
        else if(parentheses[i] == ')'){
            braces--;
        }
        if(braces < 0){
            cout << "Not nested properly at " << i+1 << "\n";
            return 0;
        }
    }

    if(braces != 0){
        cout << "Not nested properly at " << parentheses.size() << "\n";
    }
    else{
        cout << "Nesting is good\n";
    }

    return 0;
}
