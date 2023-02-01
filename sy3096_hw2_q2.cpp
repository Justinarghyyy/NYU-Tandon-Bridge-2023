#include <iostream>
using namespace std;
int main()
{
    int num_of_dollars, num_of_cents, total_value, num_of_quarters, num_of_dimes, num_of_nickels, num_of_pennies, remainder1, remainder2;
    
    cout << "Please enter your amount in the format of dollars and cents separated by a space\n";
    cin >> num_of_dollars;
    cin >> num_of_cents;

    total_value = num_of_dollars * 100 + num_of_cents ;

    num_of_quarters = total_value / 25;
    remainder1 = total_value % 25;
    
    num_of_dimes = remainder1 / 10;
    remainder2 = remainder1 % 10;

    num_of_nickels = remainder2 / 5;
    num_of_pennies = remainder2 % 5;

    cout << num_of_dollars << " dollars and " << num_of_cents << " cents are:\n";
    cout << num_of_quarters << " quarters, " << num_of_dimes << " dimes, " << num_of_nickels << " nickels and " << num_of_pennies << " pennies\n";

    return 0;
}