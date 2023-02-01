#include <iostream>
using namespace std;
int main()
{
    int num_of_days_j, num_of_hours_j, num_of_mins_j, num_of_days_b, num_of_hours_b, num_of_mins_b, total_time_j, total_time_b, total_time, total_days, total_hours, total_mins;

    cout << "Please enter the number of days John has worked:\n";
    cin >> num_of_days_j;
    cout << "Please enter the number of hours John has worked:\n";
    cin >> num_of_hours_j;
    cout << "Please enter the number of minutes John has worked:\n";
    cin >> num_of_mins_j;
    cout << "\n";

    cout << "Please enter the number of days Bill has worked:\n";
    cin >> num_of_days_b;
    cout << "Please enter the number of hours Bill has worked:\n";
    cin >> num_of_hours_b;
    cout << "Please enter the number of minutes Bill has worked:\n";
    cin >> num_of_mins_b;
    cout << "\n";

    total_time_j = num_of_days_j * 1440 + num_of_hours_j *60 + num_of_mins_j;
    total_time_b = num_of_days_b * 1440 + num_of_hours_b *60 + num_of_mins_b;

    total_time = total_time_j + total_time_b;

    total_days = total_time / 1440;
    total_hours = ( total_time % 1440 ) / 60;
    total_mins = ( total_time % 1440 ) % 60;

    cout << "The total time of both of them worked together is： " << total_days << " days, " << total_hours << " hours and " << total_mins << " minutes.\n";

    return 0;
}