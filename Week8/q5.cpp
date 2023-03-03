#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std ;

const int rand_number = 10 ;
const int pin_number = 5 ;
const int pin = 12345 ; // the original pin

void random_number( int temp[],int number ) ;
bool check_pin ( int pin, int input_pin, int temp []);

//input[] the five-digit number user inputs.
//temp[] the random pin correspondence
//right_pin[] the correct corresponding pin.

int main (){
    int input[pin_number];
    int temp[pin_number] ;
    int i, input_pin ;
    bool match ;
    cout << "Please	enter your PIN according to the following mapping: " << endl << "PIN:\t" ;
    for (i = 0 ; i < rand_number ; i++){
        cout << i << "\t" ;
    }
    cout << endl;
    cout << "NUM: \t" ;
    random_number( temp, rand_number ) ;
    cin >> input_pin ;
 
    
    match = check_pin ( pin, input_pin ,temp) ;
    if ( match == true ){
        cout << "Your PIN is correct " << endl ;
    }
    else {
        cout << "Your PIN is not correct " << endl ;
    }
    return 0 ;
}

void random_number( int temp[],int number ){
    srand(time(0)); 
    for( int i = 0 ; i < 10 ;i++ ){
        temp[i] = rand() % 3 + 1 ;
        cout << temp[i] << "\t" ;
    }
    cout << endl ;
} 

bool check_pin ( int pin, int input_pin, int temp[]){
    int i ;
    bool match ;
    match = true ;
    for ( i = 0 ; i < pin_number ; i ++ ){
        if ((int)temp[pin%10]== input_pin % 10 ){
            pin /= 10 ;
            input_pin /= 10 ;        
        }
        else {
            match = false ;
            break ;
        }
    }
    return match ;
}

