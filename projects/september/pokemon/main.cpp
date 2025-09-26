#include <iostream>
#include <vector>
using namespace std;

struct Attack {
    string name;
    int damage;
};

struct Type {
    string name;
    string weakness;
};

struct Character {
    string name;
    int max_hp;
    int hp;
    vector<Attack> attacks;
    int level;
    Type type;
};

enum class Options{
    Explore = 1,
    Battle,
    Heal_Pokemon,
    Exit
};

Type president = {"President", "Prime Minister"};
Type prime_minister = {"Prime Minister", "King"};
Type revolutionary = {"Revolutionary", "General"};
Type general = {"General", "President"};
Type monarch = {"Monarch", "Revolutionary"};

Attack executive_order = {"Executive Order", 15};
Attack rally = {"Rally", 10};
Attack tackle = {"Tackle", 25};
Attack airstrike = {"Air Strike", 35};
Attack naval_invade = {"Naval Invade", 30};
Attack tax = {"Tax", 50};

// Presidents
Character de_gaulle = {"President Charles De Gaulle", 50, 50, {executive_order, rally, tackle}, 0, president};
Character jackson = {"President Andrew Jackson", 1, 1, {executive_order, rally, tackle}, 0, president};

// Prime Minster
Character thatcher = {"Prime Minister Margaret Thatcher", 80, 80, {executive_order, rally, tackle}, 0, prime_minister};
Character churchill = {"Prime Minister Winston Churchill", 70, 70, {executive_order, rally, tackle}, 0, prime_minister};

// Generals
Character isenhower = {"General Dwight D. Isenhower", 100, 100, {rally, airstrike, naval_invade}, 0, general};
Character napolean = {"General Napolean Bonnapart", 25, 25, {rally, airstrike, naval_invade}, 0, general};

// Monarchs
Character henry = {"King Henry VIII", 150, 150, {rally, executive_order, tax}, 0, monarch};
Character wilhelm = {"Kaiser Wilhelm II", 50, 50, {rally, executive_order, tax}, 0, monarch};

vector<Character> wild_character = {de_gaulle, jackson, thatcher, churchill, isenhower, napolean, henry, wilhelm};
vector<Character> party;

bool operator>(const Type& type_1, const Type& type_2)
{
    if (type_1.name == type_2.weakness){
        return true;
    } else{
        return false;
    }
}

int main(){

    bool in_game = true;
    int wild_character_index = 0;

    while (in_game){

        int selected_option;

        cout << "1. Explore \n2. Battle \n3. Heal Characters \n4. Exit \nEnter the number of the option you wish to select: ";
        cin >> selected_option;

        switch (static_cast<Options>(selected_option))
        {
            case Options::Explore:{
                Character wild_character_found = wild_character[wild_character_index];
                string ans;

                cout << "You found a wild " << wild_character_found.name << ". Catch it? (Y/N) ";
                cin >> ans;

                if (ans == "Y" or ans == "y")
                {
                    cout << "\nYou caught a wild " << wild_character_found.name << "!";
                    party.push_back(wild_character_found);
                } else {
                    cout << "You did not catch a wild " << wild_character_found.name << ".";
                }

                wild_character_index += 1;

                if (wild_character_index >= wild_character.size()) {
                    wild_character_index = 0;
                }
                
                break;
            }
            case Options::Battle:{
                break;
            }
            case Options::Heal_Pokemon:{
                break;
            }
            case Options::Exit:{
                in_game = false;
                break;
            }
            default:{
                cout << "{DEBUG} Test";
            }
        }
    }


    return 0;
}