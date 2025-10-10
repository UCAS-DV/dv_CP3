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
    } else {
        cout << "Could not open movies.csv" << endl;
        cout << "Make sure the file is in the working directory." << endl;
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
                Movie new_movie;
                
                cin.ignore(); // Clear the newline left from the menu selection

                cout << "\nEnter movie title: ";
                getline(cin, new_movie.name);
                
                cout << "Enter director: ";
                getline(cin, new_movie.director);
                
                cout << "Enter release year: ";
                getline(cin, new_movie.year);
                
                cout << "Enter first movie genre: ";
                getline(cin, new_movie.genre1);
                
                cout << "Enter second movie genre: ";
                getline(cin, new_movie.genre2);
                
                cout << "Enter movie rating: ";
                getline(cin, new_movie.rating);

                movies.push_back(new_movie);

                ofstream outfile("C:/Users/Darius Vaiaoga/Desktop/dv_CP3/projects/october/movie_library/movies.csv");

                if (outfile.is_open()){
                    outfile << "Movie Name,Director,Year,Genre,Rating" << endl;

                    for (Movie movie : movies){
                        outfile << movie.name << "," 
                        << movie.director << "," 
                        << movie.year << "," 
                        << movie.genre1 << "/" 
                        << movie.genre2 << "," 
                        << movie.rating << endl;
                    }
                    outfile.close();
                    cout << "\n" << new_movie.name << " has been added to the library!\n" << endl;
                } else {
                    cout << "Error: Could not save to file." << endl;
                }

                break;
            }
            case Options::Delete:{
                string movie_to_delete;

                cin.ignore(); // Clear the newline left from the menu selection

                cout << "\nEnter title of movie to delete: ";
                getline(cin, movie_to_delete);

                for(int i = 0; i < movies.size(); i++){
                    if(movies[i].name == movie_to_delete){
                        movies.erase(movies.begin() + i);
                        break;
                    }
                }

                ofstream outfile("C:/Users/Darius Vaiaoga/Desktop/dv_CP3/projects/october/movie_library/movies.csv");
    
                if (outfile.is_open()){
                    outfile << "Movie Name,Director,Year,Genre,Rating" << endl;
                    
                    for (Movie movie : movies){
                        outfile << movie.name << "," 
                        << movie.director << "," 
                        << movie.year << "," 
                        << movie.genre1 << "/" 
                        << movie.genre2 << "," 
                        << movie.rating << endl;
                    }
                    outfile.close();
                    cout << "\n\"" << movie_to_delete << "\" has been deleted from the library!\n" << endl;
                }

                break;
            }
            case Options::Search:{
                cout << "1. Search by Title\n2. Search by Director\n3. Search by Year\n4. Search by Genre\n5. Search by Rating\nEnter the number of the option to select: ";
                cin >> selected_option;

                string search_term;

                switch (selected_option)
                {
                    case 1:{
                        cout << "Search Title (Make sure to watch out for capitalization and spelling): ";
                        getline(cin, search_term);

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
                        getline(cin, search_term);


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
                        getline(cin, search_term);


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
                        getline(cin, search_term);


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
                        getline(cin, search_term);

                        for (Movie movie : movies){
                            
                            int search_int = movie.rating.find(search_term);
                            if (search_int != string::npos){
                                print_movie(movie);
                            }
                        }

                        break;
                    }
                }

                break;
            }
            case Options::Exit:{
                open = false;
                break;
            }
        }
    }
    return 0;
}