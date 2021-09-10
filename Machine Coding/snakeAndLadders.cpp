#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE
#define MAX_DICE_VAL 6

#define MAX_DICE_STEP 101

class snakeAndLadder{
private:
    vector<int> board;
    vector<int> player_pos;
public:
    snakeAndLadder(){
        srand(time(0));
        board.resize(MAX_DICE_STEP, -1);
        player_pos.resize(5, 0);
    }

    snakeAndLadder(vector<vector<int>> snake_pos, vector<vector<int> > ladder_pos, int num_players){
        srand(time(0));
        board.resize(MAX_DICE_STEP, -1);
        player_pos.resize(num_players, 0);

        for(auto pos : snake_pos){
            board[pos[0]] = pos[1];
        }

        for(auto pos : ladder_pos){
            board[pos[1]] = pos[0];
        }
    }

    void makeAMove(int player_id){
        int steps;
        int new_pos, old_pos = player_pos[player_id];


        steps = rand()%MAX_DICE_VAL+1;
        new_pos = old_pos + steps;
        if(new_pos < MAX_DICE_STEP)
            player_pos[player_id] = new_pos;

        while(board[player_pos[player_id]] != -1){
            player_pos[player_id] = board[player_pos[player_id]];
        }
    }


    bool hasPlayerWon(int player_id){

        if(player_pos[player_id] == MAX_DICE_STEP-1){
            return true;
        }
        return false;
    }

};

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    // int num_snakes;
    // cin >> num_snakes;
    // vector<vector<int> > snakes_pos;

    // int start, end;
    // for(int i=0; i<num_snakes; i++){
    //     cin >> start >> end;
    //     snakes_pos.push_back({start, end});
    // }

    // int num_ladders;
    // cin >> num_ladders;
    // vector<vector<int>> ladders_pos;

    // for(int i=0; i<num_ladders; i++){
    //     cin >> start >> end;
    //     ladders_pos.push_back({start,end});
    // }

    // int num_players;
    // cin >> num_players;
    // vector<string> players;

    // string player_name;
    // for(int i=0; i<num_players; i++){
    //     cin >> player_name;
    //     players.push_back(player_name);
    // }

    vector<int> count(5, 0);

    for(int i=0; i<1000000; i++){
        snakeAndLadder game;

        int player_id = 0;
        do{
            game.makeAMove(player_id);
            if(game.hasPlayerWon(player_id))
                break;
            player_id = (player_id+1)%5;
        }while(1);

        count[player_id]++;
    }

    for(int i=0; i<count.size(); i++){
        cout << "player_id : " << i << " won " << count[i] << " times\n";
    }

    return 0;
}
