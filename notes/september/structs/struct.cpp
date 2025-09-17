#include <iostream>
#include <string>

using namespace std;

struct Customer {
    int id;
    string name;
    string email;
};

int main(){
    Customer me;
    me.id = 32;
    me.name = "Darius Vaiaoga";
    me.email = "darius.vaiaoga@ucas-edu.net";
}