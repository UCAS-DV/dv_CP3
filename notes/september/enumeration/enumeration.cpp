#include <iostream>

using namespace std;

enum Action{
    List = 1,
    Add = 2,
    Update = 3
};

int main(){
    int input;

    cout <<
    "1: List Invoices" << endl <<
    "2: Add Invoices" << endl <<
    "3: Update Invoices" << endl <<
    "Select: ";

    cin >> input;

    if (input == Action::List){
        cout << "List Invoices" << endl;
    } else if (input == Action::Add){
        cout <<  "I haven't built this yet" << endl;
    } else if (input == Action::Update){
        cout <<  "Surpringly I haven't built this either" << endl;
    } else {
        cout << "Womp womp. Not an option." << endl;
    }

    return 0;
}