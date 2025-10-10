#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Movie
{
    string title;
    int release_year;
};


int main(){
    Movie new_movie;

    // parsing
    string movie = "Terminator 1,1984";
    
    stringstream fix;
    fix.str(movie);
    getline(fix, new_movie.title, ',');

    string release_year;
    fix >> release_year; 

    new_movie.release_year = stoi(release_year);

    cout << "title: " << new_movie.title << endl << "release_year: " << new_movie.release_year << endl;

    return 0;
}