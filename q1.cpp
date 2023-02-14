# include <iostream>
using namespace std ;

int fib ( int num ) ;
int main(){
    
    int n, fibresult ;


    cout << "Please enter a positive integer :" << endl ;
    cin >> n ;

    fibresult = fib ( n ) ;

    cout << fibresult << endl ;

    return 0 ;

}

int fib ( int num ){
    
    int numn_1, numn_2, iteration, temp ;
    numn_1 = 1 ;
    numn_2 = 0 ;
   

    for (iteration = 1 ; iteration < num ; iteration ++ ){            
        
        temp = numn_2 ; 
        numn_2 = numn_1 ; 
        numn_1 += temp ;  
        
    }
return numn_1 ;
}