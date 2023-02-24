# include <iostream>
# include <cmath>
using namespace std ;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) ;
bool isPerfect(int num) ;

int main(){
    int m, n, outCountDivs, outSumDivs, ami_outCountDivs, ami_outSumDivs ;
    bool perfect ;

    cout << "Please enter a positive integer: " << endl ;
    cin >> m ;

    cout << "All the perfect numbers between 2 and " << m << " are : " << endl ;
    for ( n = 2 ; n <= m ; n ++ ){
        perfect = isPerfect( n ) ;
        if ( perfect == true ){
            cout << n << ", " ;
        }
    }
    cout << endl ;

    cout << " All pairs of amicable numbers that are between 2 and M are : " << endl ;
    for ( n = 2 ; n <= m ; n ++ ){
        outCountDivs = 0 ;
        outSumDivs = 0 ;
        analyzeDividors( n, outCountDivs, outSumDivs ) ;
        ami_outCountDivs = 0 ;
        ami_outSumDivs = 0 ;
        analyzeDividors( outSumDivs , ami_outCountDivs, ami_outSumDivs ) ;
        if ( n == ami_outSumDivs && n != outSumDivs && outSumDivs > ami_outSumDivs ){
            cout << n << " and " << outSumDivs << ";" ;
        }
    }

    return 0 ;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    int i, m ;
    for ( i = 1 ; i <= sqrt( num ) ; i ++){
        if ( num % i == 0 ){
            outCountDivs ++ ;
            outSumDivs += i ;            
        }
    }
    for ( i = sqrt( num ) ; i > 1 ; i --){
        m = num / i ;
        if (num % i == 0 ){
            outCountDivs ++ ;
            outSumDivs += m ;            
        }
    }
}

bool isPerfect(int num) {
    bool perfect ;
    int outSumDivs, outCountDivs ;
    outCountDivs = 0 ;
    outSumDivs = 0 ;
    analyzeDividors( num, outCountDivs, outSumDivs ) ;
    if ( outSumDivs == num ){
        perfect = true ;
    }
    else {
        perfect = false ;
    }
    return perfect ;
}