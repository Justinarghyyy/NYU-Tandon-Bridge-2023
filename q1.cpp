# include <iostream>
using namespace std ;
const int arrSize = 20 ;
int minInArray(int arr[], int arrSize) ;
int main (){
    int arr[arrSize] ;
    int number, index, min ;
    cout << " Please enter 20 integers separated by	a space:" << endl;
    
    for ( index = 0 ; index < arrSize ; index ++ ){
        cin >> number ;
        arr[index] = number ;
    }

    min = minInArray( arr, arrSize ) ;
    cout << "The minimum value is " << min << ", and it is located in the following indices:" ;
    
    for ( index = 0 ; index < arrSize ; index ++ ){
        if (arr[index] == min){
            cout << index << " " ;
        }
    }
    cout << endl ;
}

int minInArray(int arr[], int arrSize){
    int min, index ;
    min = arr[0] ;
    for ( index = 1 ; index < arrSize ; index ++){
        if (arr[index] < min) {
            min = arr[index] ;
        }
    }
    return min ;
}