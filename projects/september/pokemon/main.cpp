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
Type prime_minister = {"Prime Minister", "President"};
Type revolutionary = {"Revolutionary", "Lame-o"};

Attack executive_order = {"Executive Order", 15};
Attack rally = {"Rally", 10};
Attack tackle = {"Tackle", 25};

// Presidents
Character de_gaulle = {"Charles De Gaulle", 50, 50, {executive_order, rally, tackle}, 0, president};
Character jackson = {"Andrew Jackson", 1, 1, {executive_order, rally, tackle}, 0, president};

// Prime Minster
Character thatcher = {"Margaret Thatcher", 50, 50, {executive_order, rally, tackle}, 0, prime_minister};
Character churchill = {"Winston Churchill", 1, 1, {executive_order, rally, tackle}, 0, prime_minister};

// Chancellor


vector<Character> wild_character = {washington};
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