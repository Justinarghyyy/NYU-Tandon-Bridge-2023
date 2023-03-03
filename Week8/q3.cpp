void reverseArray(int arr[], int arrSize){
    int temp , index_left , index_right ;
    index_left = 0 ;
    index_right = arrSize-1 ;
    while (index_left < index_right ) {
        temp = arr[index_left] ;
        arr[index_left] = arr[index_right] ;
        arr[index_right] = temp ;
        index_left ++ ;
        index_right -- ;
    }
}
 
void removeOdd(int arr[], int& arrSize){
    int i, odd ;
    odd = 0 ;
    i = 0 ;
    while ( i < arrSize ){
        if ( arr[i] % 2 != 0 ){
            odd ++;
            arr[i] = arr[i+odd];
        }
        i ++ ;
        arr[i-odd] = arr[i];
    }
    arrSize -= odd ;
}

void splitParity(int arr[], int arrSize){
    int even , i , temp ;
    even = 0 ;
    for ( i = 0 ; i < arrSize ; i++ ){
        while ( arr[i] % 2 == 0 && i + even < arrSize -1 ){
            even ++ ;
            temp = arr[i] ;
            arr[i] = arr[i+even];
            arr[i+even] = temp ;
        }
    }
}