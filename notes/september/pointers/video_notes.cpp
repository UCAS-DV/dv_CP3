#include <iostream>
using namespace std;

int main(){
    string name = "Darius";
    int age = 15;

    string free_pizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};

    string *p_name = &name;
    int *p_age = &age;
    string *p_free_pizzas = free_pizzas;

    cout << *p_name << endl;
    cout << *p_age << endl;

    cout << *p_free_pizzas << endl;
}