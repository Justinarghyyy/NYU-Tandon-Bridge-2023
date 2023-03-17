#include <iostream>
#include <string>
#include <vector>
using namespace std ;
int* findMissing(int arr[], int n, int& resArrSize) ;
int main(){
    int arr[6] = {3,1,3,0,6,4} ;
    int i ;
    int resArrSize = 0 ;
    int n = 6 ;
    int* resArr = findMissing(arr, n, resArrSize) ;
    for ( i = 0 ; i < resArrSize ; i++){
        cout << resArr[i] ;
    }
    delete[] resArr ;
    return 0 ;
}

int* findMissing(int arr[], int n, int& resArrSize){
    vector <int> vec ;
    int i, ind, arrNew[n+1];
    for ( i = 0 ; i < n + 1 ; i++){
        arrNew[i] = i ;
    }
    for ( i = 0 ; i < n ; i++){
        ind = arr[i] ;
        arrNew[ind] = -1 ;
    }
    resArrSize = 0 ;
    for ( i = 0 ; i < n ; i++){
        if (arrNew[i] != -1) {
            vec.push_back(arrNew[i]) ;
            resArrSize += 1 ;
        }
    }

    int* resArr = new int [resArrSize];
    for (i = 0 ; i < resArrSize ; i++){
        resArr[i] = vec[i] ;
    }

    return resArr ;
}
