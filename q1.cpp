# include <iostream>
# include <vector>
using namespace std ;

class Money
{
private:
    long all_cents, dollars ;
    int cents ;
 
public: 
    friend Money operator +(const Money& checkAmount1, const Money& checkAmount2) {
        Money sum;
        sum.dollars = checkAmount1.dollars + checkAmount2.dollars;
        sum.cents = checkAmount1.cents + checkAmount2.cents;
        if (sum.cents >= 100) {
            sum.dollars++;
            sum.cents -= 100;
        }
        return sum;
    };
    friend Money operator -(const Money& checkAmount1, const Money& checkAmount2) {
        Money minus;
        minus.dollars = checkAmount1.dollars - checkAmount2.dollars;
        minus.cents = checkAmount1.cents - checkAmount2.cents;
        if (minus.cents < 0 ) {
            minus.dollars--;
            minus.cents += 100;
        }
    return minus;
    } ;
    friend bool operator ==(const Money& amount1, const Money& amount2) {
        return (amount1.all_cents == amount2.all_cents);
    } ;
    friend istream& operator >>(istream& ins, Money& checkAmount) {
        char dollarSign;
        ins >> dollarSign >> checkAmount.dollars >> checkAmount.cents;
        return ins;
    } ;
    friend ostream& operator <<(ostream& outs, const Money& checkAmount) {
        outs << "$" << checkAmount.dollars << "." << checkAmount.cents;
        return outs;
    } ;
    Money(long dollars, int cents){
        this->dollars = dollars;
        this->cents = cents;
    };
    Money(long dollars){
        this->dollars = dollars;
    };
    Money( ){
        this->dollars = 0;
        this->cents = 0;
    };
double get_value( ) const ;
long getDollars() const {
    return dollars;
} ;
int getCents() const {
    return cents;
} ;
}; 

class Check
{
public:
    int checkNumber ; 
    Money checkAmount ;
    bool checkCash ;
};

Money sortCheck() ;
Money computeDeposit() ;
int main(){
    Money totalCashed, totalDeposit ;
    totalCashed = sortCheck() ;
    totalDeposit = computeDeposit() ;

    Money newBalance, oldBalance, newBankBalance, difference ;
    cout << "Enter the old account balance: " ;
    cin >> oldBalance ;
    cout << "Enter the new account balance: " ;
    cin >> newBankBalance ;

    newBalance = oldBalance + totalDeposit - totalCashed ;
    difference = newBankBalance - newBalance ;

    cout << "Total of the checks cashed is: " << totalCashed << endl ;
    cout << "Total of the deposits is: " << totalDeposit << endl ;
    cout << "The new balance is: " << newBalance << endl ;
    cout << "The difference is: " << difference << endl ;
    
    return 0 ;
    
}

Money sortCheck(){
    vector<Check> checkbook ;
    int checkNumber;
    Money checkAmount, totalCashed;
    bool checkCash, end;
    end = false ;
    while (end == false){
        cout << "Enter check number (enter 0 if you haved finished): " ;
        cin >> checkNumber ;
        cout << "Enter check amount: " ;
        cin >> checkAmount ;
        cout << "Is the check already cashed? If yes, type 1, if no, type 0: " ;
        cin >> checkCash ;
        totalCashed = totalCashed + checkAmount ;

        if ( checkNumber == 0 ){
            end = true ;
        }
    }
    return totalCashed ;
}

Money computeDeposit(){
    vector <Money> deposit;
    Money n ;
    Money totalDeposit ;
    cout << "Enter amount of deposites, end with 0 : " ;
    while (true){
        cin >> n ;
        deposit.push_back(n) ;
        totalDeposit = totalDeposit + n ;
    }
    return totalDeposit ;
}