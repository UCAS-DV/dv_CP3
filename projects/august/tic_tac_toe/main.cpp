#include <iostream>
using namespace std;

char board[3][3] = {
    {'-','-','-'},
    {'-','-','-'},
    {'-','-','-'}
};

char numbered_board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

bool take_space(int space, char player){
    // IF space is taken, return false
    if (board[space / 3][space - ((space / 3) * 3)] != '-'){
        return false;
    // ELSE, take space for player and return true
    } else{
        board[space / 3][space - ((space / 3) * 3)] = player;
        return true;
    }
}

void print_board(bool numbered){

    if (numbered = false){
        for (int j = 0; j < 3; j++){
            cout << "|";
            for (int i = 0; i < 3; i++){
                cout << board[j][i] << "|";
            }
            cout << endl;
        }
    } else{
        for (int j = 0; j < 3; j++){
            cout << "|";
            for (int i = 0; i < 3; i++){
                cout << numbered_board[j][i] << "|";
            }
            cout << endl;
        }
    }
}

int check_win(char player){
    char completed_row[] = {player, player, player};

    // CHECK each row. IF row equals completed row, return 1
    for (int i = 0; i < 3; i++){
        char board_row[] = {board[i][0], board[i][1], board[i][2]};

        if (board_row == completed_row)
            return 1;
                    
    }

    for (int i = 0; i < 3; i++){
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == player)
            return 1;    
        }

    if (board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[0][0] == player)
        return 1;
    else if (board[0][2] == board[1][1] and board[1][1] == board[2][0] and board[0][2] == player)
        return 1;

    return 0;
}



int main(){

    string blank_input;
    int turn = -1;
    int game_state = 0;

    cout << "-~-~-~-~-~-~-~-~Tic/Tac/Toe-~-~-~-~-~-~-~-~\n";

    int seconds = time(nullptr);
    srand(seconds);
    int my_num = rand() % 11;

    while (game_state == 0){
        if (turn = -1){
            cout << "If you ever need to be reminded of the space number. Type '-1' to get the numbered board\n";
            print_board(true);

            cout << "If you understand, enter anything. ";
            cin >> blank_input;

            turn = 0;
        }
    
        if (turn % 2 == 0){
            int player_move;

            cout << "What space would you like to take: ";
            cin >> player_move;

            if (player_move == -1){
                print_board(true);
                continue;
            }

            if (take_space(player_move, 'X') == false){
                cout << "Oops! Seems like that space is taken! Please try again.";
                continue;
            } else{
                game_state == check_win('X');
                turn += 1;
            }
        } else {

            int seconds = time(nullptr);
            srand(seconds);
            int rand_int = rand() % 9;

            if (take_space(rand_int,'O') == false)
                continue;
            else {
                game_state = check_win('O');

                turn += 1;
            }
        }

        print_board(false);
    }

    if (game_state == 1)
        cout << "You Won!";
    else if (game_state == 2)
        cout << "CPU Won!";

    return 0;
}