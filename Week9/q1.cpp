#include <iostream>
#include <string>
using namespace std;
const int letter = 26 ;
const int upper = 65 ;
const int lower = 97 ;
void countLetter(string str, int arrSize , int wordNumber );
int main(){
    int i, n, arrSize, wordNumber;
    char temp ;
    string str ;
    
    cout << "Please enter a line of text: " << endl;
    getline ( cin , str ) ;
    arrSize = str.length() ;
    wordNumber = 1 ;
    
    countLetter ( str, arrSize, wordNumber);

    return 0 ;
}

void countLetter(string str, int arrSize, int wordNumber){
    int i, n, letterCount[letter] ;
    char temp ;

    for ( i = 0 ; i < letter ; i++){
        letterCount[i] = 0 ;
    }

    for ( i = 0 ; i < arrSize ; i ++ ){
        if ( (int)str[i] < upper ){
            wordNumber ++ ;
        }
        else {          
            if ( (int)str[i] < lower ){
                n = (int)str[i] - upper ;
                letterCount[n] ++ ;
            }
            else {
                n = (int)str[i] - lower ;
                letterCount[n] ++ ;
            }
        }
    }
    
    if ( str[arrSize] != ' ' ){
        wordNumber = wordNumber - 1 ;
    }

    cout << wordNumber << "\tWords" << endl;
    for ( i = 0 ; i < letter ; i ++ ){
        n = letterCount[i];
        if ( n != 0 ){
            temp = char( i + lower ) ;
            cout << n << "\t" << temp << endl ; 
        }
    }
}

