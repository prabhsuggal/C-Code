#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

void print_tictac(char a[][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<a[i][j]<<" | ";
        }
        cout <<"\n";
        for(int j=0; j< 12; j++){
            cout << "-";
        }
        cout <<"\n";
    }
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    char tictactoe[3][3] = {
                            {' ', ' ', ' '},
                            {' ', ' ', ' '},
                            {' ', ' ', ' '}
                            };
    uint32_t x,y;
    uint8_t turn=0;
    cout << " First Turn: ";
    while(true){
        cin >> x >> y;
        if(x > 2 || y > 2){
            cout<< "Please give correct coordinates x:[0-2] y:[0-2]\n" << x <<" " << y << "\n";
            continue;
        }
        tictactoe[x][y] = ((turn++)%2==0)?'X':'O';
        print_tictac(tictactoe);
        cout << "Next Turn: ";
    }

    return 0;
}
