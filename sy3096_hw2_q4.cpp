#include <iostream>
using namespace std;
int main()
{
    int number1, number2, add, minus, multiply, div, mod;
    double divide;
    cout << "Please enter two positive integers, seperated by a space:\n";
    cin >> number1;
    cin >> number2;

    add = number1 + number2;
    minus = number1 - number2;
    multiply = number1 * number2;
    divide = 1.0 * number1 / number2;
    div = number1 / number2;
    mod = number1 % number2;

    cout << number1 << " + " << number2 << " = " << add << endl;
    cout << number1 << " - " << number2 << " = " << minus << endl;
    cout << number1 << " * " << number2 << " = " << multiply << endl;
    cout << number1 << " / " << number2 << " = " << divide << endl;
    cout << number1 << " div " << number2 << " = " << div << endl;
    cout << number1 << " mod " << number2 << " = " << mod << endl;

    return 0;
}