// DV Test program :)

#include <iostream>
using namespace std;

int main(){
    float temperature_f;

    cout << "Enter a temperature in fahrenheit: ";
    cin >> temperature_f;
    cout << temperature_f << " degrees fahrenheit is " << (temperature_f - 32) * 5/9 << " degrees celsius.";

    return 0;
}