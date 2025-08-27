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

    for (int i = 0; i < 2; i++){
        if (username == admins[i]){
            cout << "Hello Admin " << username;
            return 0;
        }
    }

    for (int i = 0; i < 3; i++){
        if (username == users[i]){
            cout << "Welcome back " << username;
            return 0;
        }
    }

    cout << "Let's get you signed up " << username;
    return 0;
}