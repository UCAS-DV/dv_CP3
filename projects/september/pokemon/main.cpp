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

    while (in_game){

        int selected_option;

        cout << "1. Explore \n2. Battle \n3. Heal Pokemon \n4. Exit \nEnter the number of the option you wish to select: ";
        cin >> selected_option;


        switch (selected_option)
        {
            case Options::Explore:
                /* code */
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