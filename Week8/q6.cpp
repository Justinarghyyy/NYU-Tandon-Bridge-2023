# include <iostream>
# include <string>
using namespace std ;

int const space = 32 ;
int const number = 48 ;
int const letter = 65 ;

void encrypt(string& sentence, int length) ;

int main(){
    int length, i , ind, start, count, m ;
    string sentence ;
    cout << "Please enter a line of text: "<< endl ;
    getline (cin , sentence) ;
    length = sentence.length(); 
    encrypt(sentence, length) ;
    
    return 0 ;
}

void encrypt(string& sentence, int length){
    int i, m ,ind, start, count;
    start = 1 ;
    count = 0 ;
    for ( i = 0 ; i < length - 1 ; i ++ ){
        ind = (int)sentence[ i ] ;
        if ( ind == space ){
            start ++ ;
            if ( start == 2 && count >0 ){
                for ( m = count ; m > 0 ; m --){
                    sentence[i-m ] = '*' ;
                }
                start = 1 ;
                count = 0 ;
            }
        }
        else if ( ind > space && ind < letter ){
            count ++ ;
        }
        else {
            start = 0 ;
            count = 0 ;
        }   
    }

    ind = (int)sentence[ length -1 ] ;
    if (ind < 65){
        count ++ ;
        if ( start == 1){
            for ( m = count ; m > -1 ; m --){
                    sentence[length-m] = '*' ;
            }
        }
    }
    cout << sentence << endl ;
}