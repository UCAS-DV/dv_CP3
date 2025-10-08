#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <istream>
#include <vector>

using namespace std;

struct Movie {
    string name;
    string director;
    int year;
    string genre1;
    string genre2;
    string rating;
};

enum Options {
    View = 1,
    Add,
    Delete,
    Search
};

int main(){
    ifstream file;
    file.open("movies.csv");
    string line;
    vector<Movie> movies;

    if(file.is_open()){
        
        getline(file,line);

        while (getline(file,line)){
            istringstream iss(line);
            string item;
            Movie movie;

            getline(iss, item, ',');
            movie.name = item;
            getline(iss, item, ',');
            movie.director = item;
            getline(iss, item, ',');
            movie.year = stoi(item);
            getline(iss, item, ',');
            movie.genre1 = item;
            getline(iss, item, '/');
            movie.genre2 = item;
            getline(iss, item, ',');
            movie.rating = item;

            movies.push_back(movie);
        }
    }
    
    file.close();

    bool open = true;

    while (open){
        int selected_option;

        cout << "1. View All Movies\n2. Add Movie\n3. Delete Movie\n4. Search Movies\nEnter the number of the option to select: ";
        cin >> selected_option;

        switch (selected_option){
            case Options::View:{
                for (Movie movie : movies){
                    cout << movie.name << endl;
                }
            }
            case Options::Add:{

            }
            case Options::Delete:{

            }
            case Options::Search:{

            }
        }
    }
    return 0;
}