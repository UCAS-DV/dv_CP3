#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){

    string admins[2] = {"Washington", "Lincoln"};
    string users[3] = {"Nixon", "Ford", "Carter"};

    string username = "";
    int user_index = 0;

    cout << "Enter Username: ";
    cin >> username;

    // Loops through admins to see whether the username is in admins array
    for (int i = 0; i < 2; i++){
        if (username == admins[i]){
            cout << "Hello Admin " << username;
            return 0;
        }
    }

    // Loops through users to see whether the username is in users array
    for (int i = 0; i < 3; i++){
        if (username == users[i]){
            cout << "Welcome back " << username;
            return 0;
        }
    }

    // IF username not in admins or users, print this:
    cout << "Let's get you signed up " << username;
    return 0;
}