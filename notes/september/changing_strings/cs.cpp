// DV Changing Strings

#include <iostream>
#include <string>
using namespace std;

string name = "darius vaiaoga";
string sentence = "The quick brown fox jumps over the lazy dog";

int main(){
    auto index = name.find(' ');
    string first_name = name.substr(0,index);
    string last_name = name.substr(index+1);
    first_name[0] = toupper(first_name[0]);
    last_name[0] = toupper(last_name[0]);

    for (int i = 0; i < size(sentence); i++){
        if (isspace(sentence[i])){
            sentence[i] = '_';
        } else if (isupper(sentence[i])){
            sentence[i] = islower(sentence[i]);
        } else {
            sentence[i] = char(((int(sentence[i]) + 5) % 26) + 97);
        }
    }

    cout << sentence;

    return 0;
}