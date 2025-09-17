#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User{
    string name;
    string password;
    string admin_status;
};

bool operator==(const User& first, const User& second){
    return (first.name == second.name && 
    first.password == second.password && 
    first.admin_status == second.admin_status);
}

vector<User> users;

User darius = {"Darius", "password", "Admin"};
User cecily = {"Cecily", "1234", "Admin"};
User michael = {"Michael", "Hoi", "Admin"};
User nick = {"Nick", "ABCDE", "User"};
User nyx = {"Nyx", "Hi", "User"};
User tate = {"Tate", "undertale", "User"};
User hasan = {"Hasan", "ZYXWV", "User"};
User al = {"Al", "Bye", "User"};
User briggs = {"Briggs", "politics", "User"};
User obama = {"Barack Obama", "president-44", "User"};

int main(){

    // Puts all users in users
    users.push_back(darius);
    users.push_back(cecily);
    users.push_back(michael);
    users.push_back(nick);
    users.push_back(nyx);
    users.push_back(tate);
    users.push_back(hasan);
    users.push_back(al);
    users.push_back(briggs);
    users.push_back(obama);

    string username;
    string password;
    string admin_status;

    // Asks for username, password, admin status
    cout << "Enter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    cin >> password;
    cout << "\nEnter admin status: ";
    cin >> admin_status;

    User entered_user = {username, password, admin_status};
    bool user_exists = false;


    // FOR user in user
    for (User user: users){

        // IF user exists, say so
        if (user == entered_user){
            cout << admin_status << ": " << username << "\nAlready exists.";
            user_exists = true;
            break;
        }
    }

    // IF user doesn't exist, say so
    if (user_exists == false){
        cout << "Welcome\n" << admin_status << ": " << username;
    }

    return 0;
}