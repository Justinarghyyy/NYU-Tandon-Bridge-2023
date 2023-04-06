# include <iostream>
# include <vector>
using namespace std ;

class Money
{
private:
    long all_cents;
 
public: 
    friend Money operator +(const Money& checkAmount1, const Money& checkAmount2) {
        Money sum;
        sum.all_cents = checkAmount1.all_cents + checkAmount2.all_cents;
        return sum;
    };
    friend Money operator -(const Money& checkAmount1, const Money& checkAmount2) {
        Money minus;
        minus.all_cents = checkAmount1.all_cents - checkAmount2.all_cents;
        return minus;
    } ;
    friend istream& operator >>(istream& ins, Money& checkAmount) {
        char period;
        long dollars; 
        int cents ;
        ins >> dollars >> period >> cents;
        checkAmount.all_cents = dollars * 100 + cents;
        return ins;
    } ;
    friend ostream& operator <<(ostream& outs, const Money& checkAmount) {
        outs << "$" << checkAmount.getDollars() << "." << checkAmount.getCents();
        return outs;
    } ;
    Money(long dollars = 0 , int cents = 0){
        this->all_cents = dollars * 100 + cents;
    };

double get_value( ) const {
    return all_cents / 100.0;
};
long getDollars() const {
    return all_cents / 100;
} ;
int getCents() const {
    return all_cents % 100;
} ;
}; 

class Check
{
public:
    int checkNumber ; 
    Money checkAmount ;
    bool checkCash ;

    int getCheckNumber() const {
    return checkNumber;
    };
    Money getCheckAmount() const {
    return checkAmount;
    };
    bool getCheckCash() const {
    return checkCash;
    };
};

void calCheck(Money& totalCashed, Money& totalUncashed) ;
Money calDeposit() ;
void clearCheck (int status) ;
vector<Check> checkbook ;
int main(){
    Money totalCashed(0,0) ;
    Money totalUncashed(0,0) ;
    Money totalDeposit(0,0);
    calCheck( totalCashed, totalUncashed) ;
    cout << "The sum of the cashed check is: " << "\n" << totalCashed << endl ;
    cout << "The sum of the uncashed check is: " << "\n" << totalUncashed << endl ;
    totalDeposit = calDeposit() ;
    cout << "The sum of the deposits is: " << "\n" << totalDeposit << endl ;

    Money newBalance, oldBalance, newBankBalance, difference ;
    cout << "Enter the prior account balance: " ;
    cin >> oldBalance ;
    cout << "Enter the new balance amount according to the account holder: " ;
    cin >> newBalance ;

    newBankBalance = oldBalance + totalDeposit - totalCashed ;
    difference = newBankBalance - newBalance ;

    cout << "The balance according to the bank which includes only cleared checks is: " << newBankBalance << endl ;
    cout << "The difference between the account holders balance of " << newBalance << " and bank balance of " << newBankBalance << " is: " << difference << endl ;
    
    cout << endl ;
    cout << "The cashed checks are: " << endl ;
    clearCheck(1) ;
    cout << "The uncashed checks are: " << endl ;
    clearCheck(0) ;
    return 0 ;
    
}

void calCheck(Money& totalCashed, Money &totalUncashed){
    int checkNumber;
    Money checkAmount ;
    bool checkCash, end;
    end = false ;
    cout << "Enter check number, amount on check [exclude the dollar sign] and whether the check has already been cashed? If yes, type 1, if no, type 0 " << endl;
    while (end == false){
        cin >> checkNumber >> checkAmount >> checkCash ;
        if (checkCash != 0){
            totalCashed = totalCashed + checkAmount ;
        }
        else {
            totalUncashed = totalUncashed + checkAmount ;
        }
        Check newCheck = {checkNumber, checkAmount, checkCash} ;
        checkbook.push_back(newCheck) ;
        if (checkNumber == 0){
            end = true ;
        }
    }

}

Money calDeposit(){
    vector <Money> deposit;
    double n ;
    Money totalDeposit ;
    cout << "Enter amount of deposites, end with 0 : " ;
    while ( cin >> n ){
        if ( n == 0){
            break ;
        }
        else {
            deposit.push_back(n) ;
            totalDeposit = totalDeposit + n ;
        }
    }
    return totalDeposit ;
}

void clearCheck (int status){
    int i = 0 ;
    for ( i = 0 ; i < checkbook.size()-1 ; i ++ ){
        if (checkbook[i].getCheckCash() == status){
            cout << "check number: " << checkbook[i].getCheckNumber() << " with amount: " << checkbook[i].getCheckAmount() << endl ;
        }
    }
}
