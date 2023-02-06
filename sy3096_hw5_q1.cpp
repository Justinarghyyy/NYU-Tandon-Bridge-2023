#include <iostream>
using namespace std ;
int main ()
{
    int n, line_number, print_number, count ;
    
    cout << "Please enter a positive integer: " << endl ;
    cin >> n ;

    for (line_number = 1 ; line_number <= n ; line_number ++ ){
        print_number = line_number ;
        count = 1 ;
        while ( count <= n ) {
            cout << print_number << "\t" ;
            print_number += line_number ;
            count ++ ;
        }
        cout << endl ;
        }
    
return 0 ;
}