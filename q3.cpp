#include <iostream>
#include <string>
#include <vector>
using namespace std ;
void main1 () ;
void main2 () ;
void resizeArray (int*& arr, int size, int newSize) ;
void printResult (int count , int key, int result[]) ;
int main(){    
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl ;
    cout << "End you input by typing -1." << endl ;

    main2() ;


    return 0 ;
}
    
void main1() {
    int num, key, i, size, count;
    vector <int> vec ;
    vector <int> vec2 ;
    bool endSymbol;
    endSymbol = false ;
    i = 0 ;
    while ( endSymbol == false ){
        cin >> num ;
        if ( num == -1 ){
            endSymbol = true ;
        }
        else {
            vec.push_back(num);
            i ++ ;
        }    
    }
    size = i ;
    cout << "Please enter a number you want to search." << endl ;
    cin >> key ;
    count = 0 ;
    
    for ( i = 0 ; i < size ; i ++){
        if ( key == vec[i] ){
            vec2.push_back(i);
            count ++ ;
        }
    }
    int result[count] ;
    for ( i = 0 ; i < size ; i ++) {
        result[i] = vec2[i] ;
    }
    printResult ( count , key, result ) ;   
}


void main2(){
    int size, newSize, count, i, num, key, countResult ;
    bool endSymbol = false ;
    size = 1 ;
    count = 0 ;
    int *arr = new int [size] ;
    while ( endSymbol == false ){
        cin >> num ;
        if ( num == -1 ){
            endSymbol = true ;
        }
        else{
            count ++ ;
            if (count == size){
                newSize = size * 2 ;
                resizeArray( arr, size, newSize ) ;
            }
            arr[count-1] = num ;
        }    
    }
    cout << "Please enter a number you want to search." << endl ;
    cin >> key ;
    countResult = 0 ;
    size = 1 ;
    newSize = 1 ;
    int *result = new int [size] ;
    for ( i = 0 ; i < count ; i ++ ){
        if ( arr[i] == key ){
            countResult ++ ;
            if (countResult == size){
                newSize = size * 2 ;
                resizeArray( result, size, newSize ) ;
            }
            result[countResult-1] = i ;
        }
    }
    printResult ( countResult , key, result ) ; 
}

void resizeArray (int*& arr, int size, int newSize){
    int i ;
    int* temp = new int [newSize] ;
    for ( i = 0 ; i < size ; i ++ ){
        temp[i] = arr[i] ;
    }
    size = newSize ;
    delete [] arr ;
    arr = temp ;
}

void printResult (int count , int key, int result[]){
    int i ;
    if ( count == 0 ){
        cout << key << " does not show at all in the sequence. " ;
    }
    else {
        if (count >= 2) {
            cout << key << " shows in lines " ;
        }
        else {
            cout << key << " shows in line " ;
        }
        for ( i = 0 ; i < count -1 ; i++ ){
            cout << result[i]+1 << ", " ;
        }
        cout << result[count-1]+1 << "." ;
    }
    cout << endl ;
}