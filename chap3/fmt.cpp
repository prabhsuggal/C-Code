#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

#define MAX_LEN 72

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    string in, out, word;
    int word_count=0;
    while(getline(cin, in)){
        if(in.empty()){
            out+='\n';
            continue;
        }
        stringstream ss(in);
        while(ss >> word){
            if(word_count + word.size()+1 > MAX_LEN){
                out+='\n';
                out+=word;
                word_count=word.size();
            }
            else{
                out+=' ';
                out+=word;
                word_count+=(word.size()+1);
            }
        }
    }
    cout << out << "\n";

    return 0;
}
