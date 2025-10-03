#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Attack {
    string name;
    int damage;
};

struct Type {
    string name;
    string weakness;
};

struct Pokemon {
    string name;
    int max_hp;
    int hp;
    vector<Attack> attacks;
    int level;
    Type type;
};

enum Options{
    Explore = 1,
    Battle,
    Heal_Pokemon,
    Exit
};

Type fire = {"Fire", "Water"};
Type grass = {"Grass", "Fire"};
Type water = {"Water", "Electric"};
Type bug = {"Bug", "Fire"};
Type electric = {"Electric", "Ground"};
Type ground = {"Ground", "Water"};

Attack shock = {"Shock", 10};

Pokemon pikachu = {"Pikachu", 50, 50, {shock}, 0, electric};

vector<Pokemon> pokemons_availible = {pikachu};

bool operator>(const Type& type_1, const Type& type_2)
{
    if (type_1.name == type_2.weakness){
        return true;
    } else{
        return false;
    }
}

int main(){

    vector<Pokemon> party;

    bool in_game = true;
    int hiding_pokemon_index = 0;

    while (in_game){

        int selected_option;

        cout << "1. Explore \n2. Battle \n3. Heal Pokemon \n4. Exit \nEnter the number of the option you wish to select: ";
        cin >> selected_option;


        cout << "[DEBUG] You chose option: " << selected_option << endl;

        switch (selected_option)
        {
            case Options::Explore:

                string answer;
                cout << "You have found a wild " << pokemons_availible[hiding_pokemon_index].name << endl << "Do you want to catch it? (Y/N) ";
                cin >> answer;
                if (answer == "Y" || answer == "y"){
                    cout << "You caught a wild " << pokemons_availible[hiding_pokemon_index].name;
                    party.push_back(pokemons_availible[hiding_pokemon_index]);
                    hiding_pokemon_index += 1;
                } 

                break;
            case Options::Battle:
                break;
            case Options::Heal_Pokemon:
                break;
            case Options::Exit:
                in_game = false;
                break;
            default:
                break;
        }
    }


    return 0;
}