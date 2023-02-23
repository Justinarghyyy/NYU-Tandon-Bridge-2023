# include <iostream>
using namespace std ;

const int number_of_month = 12 ;
const int leap_year = 4 ;
const int leao_year_cen = 100 ;

void printYearCalender(int year, int startingDay) ;
int printMonthCalender(int numOfDays, int startingDay) ;

int main(){
    int year, startingDay ; 

    cout << "Please enter the year and the day in the week of the date 1/1 of that year." << endl ;
    cin >> year >> startingDay ;

    printYearCalender( year, startingDay) ;

    return 0 ;

}

void printYearCalender(int year, int startingDay) {
    int month, row, numOfDays ;
    
    month = 1 ;
    
    while ( month < number_of_month + 1 ){
        if ( month == 1 || month == 3 || month == 5 || month == 7|| month == 8 || month == 10 || month == 12 ){
            numOfDays = 31 ;
        }
        else {
            if ( month == 2 ){
                if ( year % 4 == 0 && year % 100 != 0 ){
                    numOfDays = 29 ;
                }
                else {
                    numOfDays = 28 ;
                }
            }
            else {
                numOfDays = 30 ;
            }
        }
        switch ( month ){
            case 1 :
                cout << "January" ;
                break ;
            case 2 :
                cout << "Feburary" ;
                break ;
            case 3 :
                cout << "March" ;
                break ;
            case 4 :
                cout << "April" ;
                break ;
            case 5 :
                cout << "May" ;
                break ;
            case 6 :
                cout << "June"  ;
                break ;
            case 7 :
                cout << "July"  ;
                break ;
            case 8 :
                cout << "August"  ;
                break ;
            case 9 :
                cout << "September"  ;
                break ;
            case 10 :
                cout << "October"  ;
                break ;
            case 11 :
                cout << "November"  ;
                break ;
            case 12 :
                cout << "December"  ;
                break ;
        }   
        cout << " " << year << endl ;
        row = printMonthCalender ( numOfDays, startingDay ) ;
        month ++ ;
        startingDay = row + 1 ;
    }
}




int printMonthCalender(int numOfDays, int startingDay) {
    int space, row, date ;
    

    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun " << endl ;
    space = startingDay - 1 ;
    row = 0 ;
    
    date = 1 ;

    while ( row < 8 && date < numOfDays + 1 ){
        
        while ( space > 0 ){
            cout << "\t" ;
            space -- ;
            row ++ ;
        }
    
        while ( row < 7  && date < numOfDays + 1 ){
            cout << date << "\t" ;
            row ++ ;
            date ++ ;
        }
        cout << endl ;
        if ( date < numOfDays + 1 ){
            row = 0 ;
        }
    }
    cout << endl ;
    
    return row ;
}
