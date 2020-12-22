#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

bool validFrag(vector< vector<string> > &fragment, vector<int> &sizes, string file){
    for(int i=0; i<sizes.size(); i++){
        string prefix = file.substr(0, sizes[i]), suffix = file.substr(file.size()-sizes[i],sizes[i]);

        for(int j=0; j<fragment[sizes[i]].size(); j++){
            if(fragment[sizes[i]][j] != prefix &&  fragment[sizes[i]][j] != suffix){
                return false;
            }
        }
    }
    return true;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n;
    string t;
    cin >> n;
    cin.ignore(1,'\n');
    getline(cin,t);

    while(n--){
        vector< vector<string> > fragment(257);
        vector<int> sizes;
        int file_len, tot_len=0, files=0;
        string f_i;
        while(getline(cin, f_i)){
            if(f_i.empty())
                break;
            fragment[f_i.size()].push_back(f_i);
            tot_len+=f_i.size();
            files++;
        }
        file_len = (tot_len*2)/files;

        for(size_t i=0; i<fragment.size(); i++){
            if(fragment[i].size()){
                sizes.push_back(i);
            }
        }
        string file;
        for(int i=0; i < fragment[sizes[0]].size(); i++){
            int j=0;
            if(sizes[0] == file_len-sizes[0]){
                j = i+1;
            }
            for(; j < fragment[sizes[0]].size(); j++){
                
                file = fragment[sizes[0]][i] + fragment[file_len - sizes[0]][j];
                if(validFrag(fragment, sizes, file)){
                    goto done;
                }
                file = fragment[file_len - sizes[0]][j] + fragment[sizes[0]][i];
                if(validFrag(fragment, sizes, file)){
                    goto done;
                } 
            }
        }
done:
        cout << file << "\n";
        if(n){
            cout << "\n";
        }
    }

    return 0;
}
