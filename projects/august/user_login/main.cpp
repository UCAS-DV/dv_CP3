#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){

    string usernames[4] = {"ImagineExisting", "Darius", "Cinnamon", "Jerld"};
    string status[4] = {"Admin", "Admin", "User", "User"};

    string username = "";

    cout << "Enter Username: ";
    cin >> username;

    if (find(begin(usernames), end(usernames), username) != end(usernames)){
        cout << "Real!";
    } 
    else {
        cout << "Lets get you signed up " << username << "." << endl;
    }

    return 0;
}