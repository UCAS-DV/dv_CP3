#include <iostream>
#include <string>

using namespace std;

enum Operator{
    Add = 1,
    Subtract,
    Multiply,
    Divide
};

int main(){

    while (true){

        int input;

        cout <<
        "1. Addition\n" <<
        "2. Subtraction\n" <<
        "3. Multiplication\n" <<
        "4. Division\n" <<
        "5. Exit\n" <<
        "Select: ";
        
        while (!(cin >> input)){
            cin >> input;
        }

        if (input == Operator::Add){
            double addend_1;
            double addend_2;

            cout << "Enter first addend: ";
            cin >> addend_1;
            cout << "Enter second addend: ";
            cin >> addend_2;

            cout << addend_1 << " + " << addend_2 << " = " << addend_1 + addend_2 << endl;
        } else if (input == Operator::Subtract){
            double minuend;
            double subtrahend;

            cout << "Enter the minuend: ";
            cin >> minuend;
            cout << "Enter the subtrahend: ";
            cin >> subtrahend;

            cout << minuend << " - " << subtrahend << " = " << minuend - subtrahend << endl;
        } else if (input == Operator::Multiply){
            double factor_1;
            double factor_2;

            cout << "Enter first factor: ";
            cin >> factor_1;
            cout << "Enter second factor: ";
            cin >> factor_2;

            cout << factor_1 << " * " << factor_2 << " = " << factor_1 * factor_2 << endl;
        } else if (input == Operator::Divide){
            double dividend;
            double divisor;

            cout << "Enter dividend: ";
            cin >> dividend;
            cout << "Enter divisor: ";
            cin >> divisor;

            cout << dividend << " / " << divisor << " = " << dividend / divisor << endl;
        } else if (input == 5) {
            break;
        } else {
            cout << "Not a valid input" << endl;
        }
    }

    return 0;
}