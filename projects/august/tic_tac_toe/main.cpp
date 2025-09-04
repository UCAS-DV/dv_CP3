#include <iostream>
using namespace std;

char board[3][3] = {
    {'-','-','-'},
    {'-','-','-'},
    {'-','-','-'}
};

char numbered_board[3][3] = {
    {'0','1','2'},
    {'3','4','5'},
    {'6','7','8'}
};

bool take_space(int space, char player){

    // IF space is in 0 through 2, place a square in the bottom row
    if (space >= 0 && space <= 2){
        if (board[0][space] != '-')
            return false;
        else {
            board[0][space] = player;
            return true;
        }   
        
    // IF space is in 3 through 5, place a square in the bottom row
    } else if (space >= 3 && space <= 5){
        if (board[1][space - 3] != '-')
            return false;
        else {
            board[1][space - 3] = player;
            return true;
        }            

    // IF space is in 6 through 8, place a square in the bottom row
    } else if (space >= 6 && space <= 8){
        if (board[2][space - 6] != '-')
            return false;
        else {
            board[2][space - 6] = player;
            return true;
        } 
    }

    return false;
}

// Prints board. IF numbered is true, it'll print the numbered board, if not, it'll print the game board.
void print_board(bool numbered){

    if (numbered == false){
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

// Figures out whether a player has won. IF they have, return 1, if not, return 0
int check_win(char player, int return_num){

    bool space_open = false;
    // CHECK each row. IF row equals completed row, return 1
    for (int i = 0; i < 3; i++){

        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return return_num;
                    
    }

    // IF player has column, mark as victory
    for (int i = 0; i < 3; i++){
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == player)
            return return_num;    
        }

    // IF player has a diagonal, mark as victory
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == player)
        return return_num;
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == player)
        return return_num;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == '-'){
                space_open = true;
            }
        }
    }

    if (space_open == true)
        return 0;
    else
        return 3;
}   

int main(){

    string blank_input;
    int turn = -1;
    int game_state = 0;

    cout << "\n-~-~-~-~-~-~-~-~Tic/Tac/Toe-~-~-~-~-~-~-~-~\n";

    int seconds = time(nullptr);
    srand(seconds);
    int my_num = rand() % 11;

    while (game_state == 0){
        
        if (turn == -1){
            cout << "If you ever need to be reminded of the space number. Type '-1' to get the numbered board\n";
            print_board(true);

            cout << "If you understand, enter anything. ";
            cin >> blank_input;

            turn = 0;
            continue;
        }

        // Player Turn
        if (turn % 2 == 0){

            print_board(false);
            int player_move;

            cout << "What space would you like to take: ";
            cin >> player_move;

            if (player_move == -1){
                print_board(true);
                continue;
            }

            if (player_move >= 0 && player_move <= 8){
                if (take_space(player_move, 'X') == false){
                cout << "Oops! Seems like that space is taken! Please try again.\n";
                continue;
                } else{
                    game_state = check_win('X', 1);
                    turn += 1;
                    continue;
                }
            }
            
        } 
        // CPU Turn
        else {
            
            // Set random number
            int seconds = time(nullptr);
            srand(seconds);
            int rand_int = rand() % 9;

            game_state = check_win('O', 2);
            
            if (game_state == 3 || game_state == 2){
                continue;
            }

            if (take_space(rand_int,'O') == false)
                continue;
            else {
                game_state = check_win('O', 2);
                turn += 1;
                continue;
            }
        }
    }

    print_board(false);

    if (game_state == 1)
        cout << "You Won!";
    else if (game_state == 2)
        cout << "CPU Won!";
    else if (game_state == 3)
        cout << "Tie!";

    return 0;
}