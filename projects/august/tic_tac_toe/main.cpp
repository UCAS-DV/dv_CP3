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

int turn = -1;
int game_state = 0;

bool take_space(int space, int player){
    if (board[space / 3][space - ((space / 3) * 3)] != '-'){
        return false;
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

int main(){

    string blank_input;

    cout << "-~-~-~-~-~-~-~-~Tic/Tac/Toe-~-~-~-~-~-~-~-~\n";

    int seconds = time(nullptr);
    srand(seconds);
    int my_num = rand() % 11;

    if (turn = -1){
        cout << "If you ever need to be reminded of the space number. Type '-1' to get the numbered board\n";
        print_board(true);

        cout << "If you understand, enter anything. ";
        cin >> blank_input;
    }

    return 0;
}