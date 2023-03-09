#include <iostream>
#include <string>
using namespace std;
const int letter = 26 - 1 ;
const int upper = 65 ;
const int lower = 97 ;

int* countLetter( string str, int arrSize );
void compareStr (int* ptr1, int* ptr2, int letter, int arrSize1, int arrSize2 );

int main (){
    int arrSize1, arrSize2 ;
    string str1, str2 ;
    int *ptr1, *ptr2 ;

    cout << "Please enter the first string:" << endl ;
    getline (cin, str1) ;
    cout << "Please enter the second string:" << endl ;
    getline (cin, str2) ;

    arrSize1 = str1.length() ;
    arrSize2 = str1.length() ;

    ptr1 = countLetter( str1, arrSize1 ) ;
    ptr2 = countLetter( str2, arrSize2 ) ;

    compareStr ( ptr1, ptr2, letter, arrSize1, arrSize2 ) ;

    return 0 ;
}            

int* countLetter( string str, int arrSize ){
    int i, n;
    static int letterCount[letter] ;
    char temp ;

    for ( i = 0 ; i < letter ; i++){
        letterCount[i] = 0 ;
    }

    for ( i = 0 ; i < arrSize ; i ++ ){         
        if ( (int)str[i] < lower ){
            n = (int)str[i] - upper ;
            letterCount[n] ++ ;
        }
        else {
            n = (int)str[i] - lower ;
            letterCount[n] ++ ;
        }
    }

    return letterCount ;
}

void compareStr (int* ptr1, int* ptr2, int letter, int arrSize1, int arrSize2 ){
    int i ;
    bool ana ;
    ana = true ;

    if (arrSize1 == arrSize2){
        for ( i = 0 ; i < letter ; i++ ){
            if (ptr1[i] != ptr2[i]){
                ana = false ;
                break ;
            }
        }
    }
    else {
        ana = false ;
    }
    
    if ( ana == true ){
        cout << "They are anagrams." << endl ;
    }
    else{
        cout << "They are not anagrams."<< endl ;
    }
}