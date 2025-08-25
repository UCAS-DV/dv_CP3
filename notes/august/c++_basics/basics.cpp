// DV Variables, Data Types, Inputs and Outputs

#include <iostream>
using namespace std;

int main(){
    int students = 11;
    short dave_number = 5;
    long years = 2554l;
    float pi = 3.14f; // float will compile to double without f at the end
    bool on = true;
    char clang = 'Clang';

    

    cout << "Tell me your age:";
    int age;
    cin >> age;
    cout << students/dave_number;

    return 0;
}