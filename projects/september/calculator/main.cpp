#include <iostream>
#include <string>

using namespace std;

enum Operator{
    Add = 1,
    Subtract,
    Multiply,
    Divide
};

double add(double operand_1, double operand_2){
    return operand_1 + operand_2;
}

int main(){

    while (true){

        int input;
        int empty;

        cout <<
        "1. Addition\n" <<
        "2. Subtraction\n" <<
        "3. Multiplication\n" <<
        "4. Division\n" <<
        "5. Exit\n" <<
        "Select: ";

        cin >> input;

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

            cout << "Enter first addend: ";
            cin >> minuend;
            cout << "Enter second addend: ";
            cin >> subtrahend;

            cout << minuend << " - " << subtrahend << " = " << minuend - subtrahend << endl;
        }
            
    }

    return 0;
}