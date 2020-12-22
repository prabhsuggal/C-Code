#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

#define  print_ans(i,a) cout << "Run #" << i <<": "<<a<<"\n"

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n,m;
    int cases=0;
    while(cin >> n && n!=0){
        cases++;
        cin.ignore(1,'\n');
        vector<string> standard(n);
        for(int i=0; i<n; i++){
            getline(cin, standard[i]);
        }
        cin >> m;
        cin.ignore(1,'\n');
        vector<string> team(m);
        for(int i=0; i<m; i++){
            getline(cin, team[i]);
        }
        //cout << "N: "<<n<<" M: "<<m<<endl;
        if(n!=m){
            print_ans(cases, "Wrong Answer");
            continue;
        }
        
        bool presentation_error=false, wrong=false;
        for (size_t i = 0; i < n; i++)
        {
            if(standard[i].size() != team[i].size()){
                presentation_error = true;
            }
            //:cout << "Standard: " << standard[i] << " Team output:" << team[i] << " END" << endl;
            size_t x,y;
            for (x = 0, y=0; x < standard[i].size() && y < team[i].size();) 
            {
                if(standard[i][x] == team[i][y]){
                    x++;y++;
                }
                else if((standard[i][x] >= '0' && standard[i][x] <= '9') && 
                    (team[i][y]>='0' && team[i][y]<='9')){
                    wrong = true;
                    break;
                }
                else if(standard[i][x] >= '0' && standard[i][x] <= '9'){
                    y++;
                }
                else if(team[i][y]>='0' && team[i][y]<='9'){
                    x++;
                }
                else{
                    presentation_error = true;
                    x++;y++;
                }
            }
            if((x < standard[i].size() && standard[i][x] >= '0' && standard[i][x] <= '9') || 
                    (y<team[i].size() && team[i][y]>='0' && team[i][y]<='9')){
                    wrong = true;
            }
            if(wrong)break;
        }
        if(wrong)print_ans(cases, "Wrong Answer");
        else if(presentation_error)print_ans(cases,"Presentation Error");
        else print_ans(cases, "Accepted");
    }

    return 0;
}
