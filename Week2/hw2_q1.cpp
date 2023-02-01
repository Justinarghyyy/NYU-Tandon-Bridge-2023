#include <iostream>
using namespace std;
int main()
{
    double num_of_quarters, num_of_dimes, num_of_nickels, num_of_pennies, total_value, dollar, cent;
    cout << "Please enter number of coins:\n# of quarters:\n"; /*0.25*/
    cin >> num_of_quarters;
    cout << "# of dimes:\n"; /*0.1*/
    cin >> num_of_dimes;
    cout << "# of nickels:\n"; /*0.05*/
    cin >> num_of_nickels;
    cout << "# of pennies:\n"; /*0.01*/
    cin >> num_of_pennies;

    total_value = num_of_quarters * 0.25 + num_of_dimes * 0.1 + num_of_nickels * 0.05 + num_of_pennies * 0.01;

    dollar = int(total_value);
    cent = (total_value - dollar) * 100;

    cout << "The total is " << dollar << " dollars and "<< cent << " cents\n";

    return 0;

}
