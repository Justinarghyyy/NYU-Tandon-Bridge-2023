
void oddsKeepEvensFlip(int arr[], int arrSize){
    int even, i, temp ;
    vector <int> v ;
    even = 1 ;

    for ( i = 0 ; i < arrSize ; i ++){
        if ( arr[i] % 2 != 0 ){
            v.push_back(arr[i]) ;
        }
    }
    for ( i = arrSize - 1 ; i > -1 ; i --){
        if ( arr[i] % 2 == 0 ){
            v.push_back(arr[i]) ;
        }
    }
    
    for ( i = 0 ; i < arrSize ; i ++){
        cout << v[i] << " " ;     
    }
    cout << endl ;
}