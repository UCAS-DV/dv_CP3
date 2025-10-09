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
    string year;
    string genre1;
    string genre2;
    string rating;
};

enum Options {
    View = 1,
    Add,
    Delete,
    Search,
    Exit
};

void print_movie(Movie movie){
    cout 
    << "Title: " << movie.name << endl
    << "Director: " << movie.director << endl
    << "Release Year: " << movie.year << endl
    << "Genre: " << movie.genre1 << "/" << movie.genre2 << endl
    << "Rating: " << movie.rating << endl << endl;
}

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
            movie.year = item;
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

        cout << "1. View All Movies\n2. Add Movie\n3. Delete Movie\n4. Search Movies\n5. Exit\nEnter the number of the option to select: ";
        cin >> selected_option;

        switch (selected_option){
            case Options::View:{
                for (Movie movie : movies){
                    cout << movie.name << endl;
                }
                break;
            }
            case Options::Add:{

            }
            case Options::Delete:{

            }
            case Options::Search:{
                cout << "1. Search by Title\n2. Search by Director\n3. Search by Year\n4. Search by Genre\n5. Search by Rating\nEnter the number of the option to select: ";
                cin >> selected_option;

                string search_term;

                switch (selected_option)
                {
                    case 1:{
                        cout << "Search Title (Make sure to watch out for capitalization and spelling): ";
                        cin >> search_term;


                        for (Movie movie : movies){
                            
                            int search_int = movie.name.find(search_term);
                            if (search_int != string::npos){
                                print_movie(movie);
                            }
                        }

                        break;
                    }
                    case 2:{
                        cout << "Search Director (Make sure to watch out for capitalization and spelling): ";
                        cin >> search_term;


                        for (Movie movie : movies){
                            
                            int search_int = movie.director.find(search_term);
                            if (search_int != string::npos){
                                print_movie(movie);
                            }
                        }

                        break;
                    }
                    case 3:{
                        cout << "Search Year: ";
                        cin >> search_term;


                        for (Movie movie : movies){
                            
                            int search_int = movie.year.find(search_term);
                            if (search_int != string::npos){
                                print_movie(movie);
                            }
                        }

                        break;
                    }
                    case 4:{
                        cout << "Search Genre: ";
                        cin >> search_term;


                        for (Movie movie : movies){
                            
                            int search_int = movie.genre1.find(search_term);
                            int search_int2 = movie.genre2.find(search_term);
                            if (search_int != string::npos){
                                print_movie(movie);
                            } else if (search_int2 != string::npos){
                                print_movie(movie);
                            }
                        }

                        break;
                    }
                    case 5:{
                        cout << "Search Rating: ";
                        cin >> search_term;


                        for (Movie movie : movies){
                            
                            int search_int = movie.rating.find(search_term);
                            if (search_int != string::npos){
                                print_movie(movie);
                            }
                        }

                        break;
                    }
                }
            }
            case Options::Exit:{
                open = false;
                break;
            }
        }
    }
    return 0;
}