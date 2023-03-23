#include <iostream> 
using namespace std ;
int bestSolution(int arr[], int arrSize);
int main(){
    int arr[8] = {0, 3, 80, 6, 57, 10, 12,1};
    int n;
    n = bestSolution(arr, 8);
    cout << n<< endl;
    return 0 ;
}

int bestSolution(int arr[], int arrSize){
    int min, move;
    if ( arrSize < 4 ){
        min = arr[arrSize-1];
        return min;
    }
    else{
        if (arr[arrSize-2]>arr[arrSize-3]){
            min = bestSolution( arr, arrSize-2) + arr[arrSize-1] ;
        }
        else{
            min = bestSolution( arr, arrSize-1) + arr[arrSize-1] ;
        }
        return min ;
    }
}

