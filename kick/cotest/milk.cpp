/*
 * =====================================================================================
 *
 *       Filename:  milk.cpp
 *
 *    Description:  file mate
 *
 *        Version:  1.0
 *        Created:  Sunday 26 August 2018 11:41:08  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

int main(int argc,char** argv){
    ifstream in;
    ofstream out;
    in.open(argv[1],ios::in);
    out.open("output.txt",ios::out);
    int T;
    in>>T;
    for(int t=0;t<T;t++){
        int N,M,P;
        in>>N>>M>>P;
        vector<vector<int> > pref(P,vector<int>(2));
        string temp;
        for(int i=0;i<N;i++){
            in>>temp;
            for(int j=0;j<P;j++){
                if(temp[j]=='0')pref[j][0]++;
                else pref[j][1]++;
            }
        }

        vector<pair<int,int> > min_diff(P);
        for(int i=0;i<P;i++){
            min_diff[i].first=abs(pref[i][0]-pref[i][1]);
            min_diff[i].second = i;
        }
        sort(min_diff.begin(),min_diff.end());
        unordered_map<string, bool> forbidden;
        for(int i=0;i<M;i++){
            in>>temp;
            forbidden[temp]=true;
        }
        string min_string;
        int complaints=0;
        for(int i=0;i<P;i++){
            if(pref[i][0]>pref[i][1]){
                min_string+='0';
                complaints+=pref[i][1];
            }
            else{
                min_string+='1';
                complaints+=pref[i][0];
            }
        }
        string ans_string=min_string;

        int index=0;
        while(forbidden.find(ans_string)!=forbidden.end()){
            ans_string=min_string;
            ans_string[min_diff[index].second] = (ans_string[min_diff[index].second]=='0')?'1':'0';
            complaints+=(pref[i][])
        }

    }
    in.close();
    out.close();
    return 0;
}

