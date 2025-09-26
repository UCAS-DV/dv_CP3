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

    int heal(){
        hp = max_hp;
        return hp;
    }
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
Attack overthrow {"Overthrow", 40};
Attack protest = {"Protest", 20};

// Presidents
Character de_gaulle = {"President Charles De Gaulle", 50, 50, {executive_order, rally, tackle}, 0, president};
Character jackson = {"President Andrew Jackson", 1, 1, {executive_order, rally, tackle}, 0, president};

// Prime Minster
Character thatcher = {"Prime Minister Margaret Thatcher", 80, 80, {executive_order, rally, tackle}, 0, prime_minister};
Character churchill = {"Prime Minister Winston Churchill", 70, 70, {executive_order, rally, tackle}, 0, prime_minister};

// Generals
Character eisenhower = {"General Dwight D. Eisenhower", 100, 100, {rally, airstrike, naval_invade}, 0, general};
Character napolean = {"General Napolean Bonnapart", 25, 25, {rally, airstrike, naval_invade}, 0, general};

// Revolutionaries
Character robespierre = {"Revolutionary Maximilien Robespierre", 50, 50, {rally, overthrow, protest}, 0, revolutionary};
Character lenin = {"Revolutionary Vladimir Lenin", 75, 75, {rally, overthrow, protest}, 0, revolutionary};

// Monarchs
Character henry = {"King Henry VIII", 150, 150, {rally, executive_order, tax}, 0, monarch};
Character wilhelm = {"Kaiser Wilhelm II", 50, 50, {rally, executive_order, tax}, 0, monarch};

vector<Character> wild_characters = {de_gaulle, jackson, thatcher, churchill, robespierre, lenin, eisenhower, napolean, henry, wilhelm};
vector<Character> party;

bool operator>(const Type& type_1, const Type& type_2)
{
    if (type_1.name == type_2.weakness){
        return true;
    } else{
        return false;
    }
}

bool operator==(const Character& char_1, const Character& char_2)
{
    if (char_1.name == char_2.name){
        return true;
    } else{
        return false;
    }
}

int explore(int wild_character_index){
    Character wild_character_found = wild_characters[wild_character_index];
    string ans;

    for (Character member : party){
        if (member == wild_character_found){
            cout << "You did not find anything.";
            return wild_character_index;
        }
    }

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

    if (wild_character_index >= wild_characters.size()) {
        wild_character_index = 0;
    }

    return wild_character_index;
                
}

void battle(Character player_character, Character enemy_character){
    int turn = 0;
    bool battle_done = false;
    while (battle_done == false){

        if (player_character.hp <= 0) {
            cout << "\nYour " << player_character.name << " has fainted! You lost the battle.";
            battle_done = true;
            break;
        } else if (enemy_character.hp <= 0){
            cout << endl << enemy_character.name << " has fainted! You won the battle!";
            battle_done = true;

            player_character.level += 1;
            player_character.max_hp += player_character.level * 10;

            cout << endl << player_character.name << " leveled up to level " << player_character.level << " and now has a max HP of " << player_character.max_hp << "!";

            break;
        }

        if (turn % 2 == 0){

            int selected_option;

            cout << "\n1. " << player_character.attacks[0].name << "\n2. " << player_character.attacks[1].name << "\n3. " << player_character.attacks[2].name <<  "\nEnter the number of the option you wish to select: ";
            cin >> selected_option; 

            if (selected_option < 1 or selected_option > 3) {
                cout << "Invalid Number";
                continue;
            }

            Attack selected_attack = player_character.attacks[selected_option - 1];

            if (player_character.type > enemy_character.type){
                enemy_character.hp -= selected_attack.damage * 2;
                cout << "Your " << player_character.name << " used " << selected_attack.name << " and it's super effective! " << enemy_character.name << " now has " << enemy_character.hp << " HP left after losing " << selected_attack.damage * 2 << " HP.";
            } else {
                enemy_character.hp -= selected_attack.damage;
                cout << "Your " << player_character.name << " used " << selected_attack.name << "! " << enemy_character.name << " now has " << enemy_character.hp << " HP left after losing " << selected_attack.damage << " HP.";
            }

            turn += 1;
            
        } else {
            int seconds = time(nullptr);
            srand(seconds);
            int enemy_attack_index = rand() % enemy_character.attacks.size();
            Attack enemy_attack = enemy_character.attacks[enemy_attack_index];

            if (enemy_character.type > player_character.type){
                player_character.hp -= enemy_attack.damage * 2;
                cout << "\nThe " << enemy_character.name << " used " << enemy_attack.name << " and it's super effective! Your " << player_character.name << " now has " << player_character.hp << " HP left after losing " << enemy_attack.damage * 2 << " HP.";
            } else {
                player_character.hp -= enemy_attack.damage;
                cout << "\nThe " << enemy_character.name << " used " << enemy_attack.name << "! Your " << player_character.name << " now has " << player_character.hp << " HP left after losing " << enemy_attack.damage << " HP.";
            }

            turn += 1;
        }
        
    }
}

int main(){

    bool in_game = true;

    while (in_game){

        int seconds = time(nullptr);
        srand(seconds);

        int selected_option;

        cout << "\n1. Explore \n2. Battle \n3. Heal Characters \n4. Exit \nEnter the number of the option you wish to select: ";
        cin >> selected_option;

        switch (static_cast<Options>(selected_option))
        {
            case Options::Explore:{
                int wild_character_index = rand() % wild_characters.size();
                wild_character_index = explore(wild_character_index);
                break;
            }
            case Options::Battle:{
                if (party.size() == 0){
                    cout << "\nYou have no characters in your party to battle with!";
                    break;
                } else {
                    int player_character_index = rand() % party.size();
                    srand(seconds + 1);
                    int enemy_index = rand() % wild_characters.size();

                    battle(party[player_character_index], wild_characters[enemy_index]);

                    wild_characters[enemy_index].hp = wild_characters[enemy_index].max_hp;
                }
                break;
            }
            case Options::Heal_Pokemon:{
                for (Character member : party){
                    member.heal();
                    cout << "\n" << member.name << " healed to full health and is now at " << member.hp << " HP.";
                }
                break;
            }
            case Options::Exit:{
                in_game = false;
                break;
            }
            default:{
                cout << "Invalid Number";
            }
        }
    }


    return 0;
}