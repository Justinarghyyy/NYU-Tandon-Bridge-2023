# include <iostream> 
# include <cmath>
using namespace std ;
int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
int main(){
    bool r ;
    int arr[4]={2,2,3,10};
    r = isSorted(arr,4);
    cout << r << endl;
    return 0 ;
}

int sumOfSquares(int arr[], int arrSize){
    int sqr, sumSqr ;
    if ( arrSize == 1 ){
        sqr = pow(arr[0] , 2);
        return sqr ;
    }
    else{
        
        sumSqr = sumOfSquares (arr, arrSize-1) + pow(arr[arrSize-1] , 2);
        return sumSqr ;
    }
}

bool isSorted(int arr[], int arrSize){
    bool sort = true ;
    if ( arrSize == 1 ){
        sort = true ;
        return sort ;
    }
    else{
        sort = isSorted(arr, arrSize-1);
        if (sort == true){
            return (arr[arrSize-1]>arr[arrSize-2]);
        }
        else{
            return false;
        }
    }
}
