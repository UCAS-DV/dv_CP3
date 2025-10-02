#include <iostream>
#include <fstream>

using namespace std;

struct Date {
    int month;
    int day;
    int year;
};

struct Score {
    string player;
    int score;
    Date date;
};

int main(){

    bool open = true;
    int selected_option;

    while (open){
        cout << "Menu: \n1. Add a new high score \n2. Display high scores \n3. Exit \nEnter your choice (1-3): ";
        cin >> selected_option;

        switch (selected_option){
            case 1:{
                Score new_score;
                string date_string;
    
                cout << "Enter player's name: ";
                cin >> new_score.player;
                
                cout << "Enter score: ";
                cin >> new_score.score;

                cout << "Enter date (MM/DD/YYYY): ";
                cin >> date_string;

                new_score.date.year = stoi(date_string.substr(6, 4));
                new_score.date.month = stoi(date_string.substr(0, 2));
                new_score.date.day = stoi(date_string.substr(3, 2));

                ofstream text_file("high_scores.txt", ios::app);

                text_file << new_score.player + "," + to_string(new_score.score) + "," + to_string(new_score.date.month) + "," + to_string(new_score.date.day) + "," + to_string(new_score.date.year) + "\n";
                text_file.close();
            }
            case 2:{
                ifstream text_file("high_scores.txt");
                string line;
                
            }
            case 3:{
                open = false;
                break;
            }
            default:{
                cout << "Invalid Input";
            }
        }

    }


    return 0;
}