#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    string a,b;
    vector<char> word_a(26), word_b(26);

    while(getline(cin, a) && getline(cin, b)){
        //cout << "a: "<< a<<" b: "<<b<<"\n";
        fill(word_a.begin(), word_a.end(), 0);
        fill(word_b.begin(), word_b.end(), 0);
        for(int i=0; i<a.size();i++)word_a[a[i]-'a']++;
        for(int i=0; i<b.size();i++)word_b[b[i]-'a']++;
        string x;
        for(int i=0; i<26; i++){
            for(int j=0; j<min(word_a[i], word_b[i]);j++){
                x+=(char)('a'+i);
            }
        }
        cout << x <<"\n";
    }

    return 0;
}
