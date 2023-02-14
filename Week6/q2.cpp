# include <iostream>
using namespace std ;

void printPineTree(int n, char symbol) ;
void printShiftedTriangle ( int n, int m, char symbol ) ;

int main(){

    int number ;
    char symbol ;

    cout << " Please enter the number of triangles you want and the character you want, seperated by space: " << endl ;
    cin >> number >> symbol ;

    printPineTree( number , symbol ) ;

    return 0 ;
}

void printPineTree(int n, char symbol){
    
    int iteration, m ;
    
    for ( iteration = 1 ; iteration < n + 1 ; iteration ++){
        m = n - iteration ;
        printShiftedTriangle ( iteration + 1 , m , symbol ) ;
             
    }
    cout << endl ;

}

void printShiftedTriangle ( int n, int m, char symbol ) {

    int line, print_time ;
    

    for ( line = 1 ; line <= n ; line ++ ){
        for ( print_time = m + n - line  ; print_time > 0 ; print_time -- ){
            cout << " " ;
        }
        for ( print_time = 2 * line - 1 ; print_time > 0 ; print_time -- ){
            cout << symbol ;
        }
        
        cout << endl ;
    }



}
