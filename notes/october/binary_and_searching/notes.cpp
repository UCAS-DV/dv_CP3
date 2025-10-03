#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

string u_to_string(double number, int precision){
    stringstream stream;
    stream << fixed << setprecision(precision) << number;
    return stream.str();
}

int main(){
    double number = 3.14;
    cout << u_to_string(number, 2) << endl;

    // parsing
    string users = "10 20";
    stringstream fix;
    fix.str(users);
    int first; 
    fix >> first;

    int second;
    fix >> second;

    cout << "first: " << first << endl << "second: " << second << endl;

    fstream file;
    file.open("file.txt", ios::in | ios::out | ios::app);

    if(file.is_open()){


        file.close();
    }


    return 0;
}