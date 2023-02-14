# include <iostream>
using namespace std ;
double eApprox( int n ) ;

int main() {
    cout.precision( 30 );
    for ( int n = 1; n <= 15; n++ ) {
    cout << "n = " << n << '\t' << eApprox(n) << endl ;
    }
    return 0;
}

double eApprox( int n ){
    int iteration ;
    double e, recip, acc_recip ;
    e = 1.0 ;
    acc_recip = 1.0 ;
    for ( iteration = 1 ; iteration <= n ; iteration ++ ){
    recip = 1.0 / iteration ; 
    acc_recip *= recip ;
    e += acc_recip ;   
    }
    return e ;
}

