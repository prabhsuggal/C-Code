// Consider a set of movies M1,M2, . . . , Mk. There is a set of customers,
// each one of which indicates the two movies they would like to see this weekend.
// Movies are shown on Saturday evening and Sunday evening. Multiple movies
// may be screened at the same time.
// You must decide which movies should be televised on Saturday and which on
// Sunday, so that every customer gets to see the two movies they desire. Is there a
// schedule where each movie is shown at most once? Design an efficient algorithm
// to find such a schedule if one exists.

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define SATURDAY 1
#define SUNDAY -1
#define NONE 0

bool notPresent(vector<vector<int> > &a, int x, int y){
    int n = a.size();
    if(x >= n){
        cout << "Index is greater than vector size" << endl;
        return false;
    }
    for(int i=0; i<a[x].size(); i++){
        if(a[x][i] == y){
            return false;
        }
    }
    return true;

}

int main(){

    srand(time(0));
    int n = 5;

    cout << "Set of Movies:\n";
    vector<int> movies(n,-1);
    for(int i=0; i<n; i++){
        movies[i] = rand();
        cout << movies[i] << " ";
    }
    cout << "\n";
    vector<vector<int> > choices(n);
    cout << "Customer wishlist:\n";
    int x,y;
    for(int i=0; i<n; ){
        x = rand()%n, y = rand()%n;
        if(x == y){
            continue;
        }
        if(notPresent(choices, x, y)){
            choices[x].push_back(y);
            cout << "C"<<i<<": " << movies[x] << " " << movies[y] << endl;
            i++;
        }
    }

    stack<pair<int, int> > dfs;
    vector<int> Day(n, NONE);

    for(int i=0; i<n; i++){
        if(Day[i] == NONE){
            dfs.push(make_pair(i, SATURDAY));
            Day[i] = SATURDAY;
            while(!dfs.empty()){
                pair<int, int> it = dfs.top();
                int day = it.second;
                dfs.pop();
                for(int i=0; i<choices[it.first].size(); i++){
                    if(Day[choices[it.first][i]] == NONE){
                        Day[choices[it.first][i]] = (day==SATURDAY)?SUNDAY:SATURDAY;
                        dfs.push(make_pair(choices[it.first][i], Day[choices[it.first][i]]));
                    }
                    else{
                        if(Day[choices[it.first][i]] == day){
                            goto fail;
                        }
                    }
                }
            }
        }
    }

    cout << "Movies Which will be played on Saturday:\n";
    for(int i=0; i<n; i++){
        if(Day[i] == SATURDAY){
            cout << movies[i] << " ";
        }
    }
    cout << "\n";
    cout << "Movies Which will be played on Sunday:\n";
    for(int i=0; i<n; i++){
        if(Day[i] == SUNDAY){
            cout << movies[i] << " ";
        }
    }
    cout << "\n";
    return 0;

fail:
    cout << "Not possible to arrange the movies for all viewers\n";
    return 0;
}