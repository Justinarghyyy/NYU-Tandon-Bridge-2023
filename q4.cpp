# include <iostream>
# include <cmath>
using namespace std ;
void printDivisors( int n );

int main(){

    int n ;
    cout << "Please enter a positive integer >= 2: " << endl ;
    cin >> n ;
    printDivisors( n ) ;
    return 0 ;

}

void printDivisors( int n ) {
    
    int i ;
    
    for ( i = 1 ; i <= sqrt ( n ) ; i ++ ){
        if ( n % i == 0 ){
            cout << i << " " ;
        }
    }
    for ( i = sqrt ( n ) - 1 ; i > 0 ; i -- ){
        if ( n % i == 0 ){
            cout << n/i << " " ;
        }
    }
    
}