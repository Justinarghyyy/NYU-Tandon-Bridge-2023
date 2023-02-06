#include <iostream> 
#include <cstdlib>
#include <ctime>
const int max_time = 5 ;

using namespace std ;
int main (){
    int random_number, guess, attempt_time, max_time, remain_attempt, right_range, left_range ;
    bool end_symbol ;
    
    srand(time(0));
    random_number = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl ;
    cout << "Range: [1, 100], Number of guesses left: 5" << endl ;

    cin >> guess ;

    attempt_time = 1 ;
    end_symbol = false ;
    remain_attempt = 4 ;
    left_range = 1 ;
    right_range = 100 ;
    
    while ( remain_attempt > 0 && end_symbol == false ) {
        
        if ( guess == random_number ) {
            end_symbol = true ;
        }
        else {
            if ( guess < random_number ) {
                if ( guess > left_range){
                    left_range = guess ;
                }
                else{
                    left_range = left_range ;
                }
                cout << " Wrong! My number is bigger. " << endl << endl ;
                cout << " Range: [" << left_range << " ," << right_range << "], Number of guesses left:" << remain_attempt << endl ;
                cout << " Your guess is: " << endl;
                cin >> guess ;
            }
            else {
                if ( guess < right_range){
                    right_range = guess ;
                }
                else{
                    right_range = right_range ;
                }
                cout << " Wrong! My number is smaller . " << endl << endl ;
                cout << " Range: [" <<left_range << ", " << right_range << "], Number of guesses left:" << remain_attempt << endl ;
                cout << " Your guess is: " << endl;
                cin >> guess ;
            }
            remain_attempt -- ;
            attempt_time ++ ;
        }
        

    }

        if ( end_symbol == true ){
            cout << "Congrats! You guessed my number in " << attempt_time << " guess." << endl ;
        }
        else {
            cout << "Out of guesses! My number is " << random_number << endl ;
        }

        return 0 ;
    }
    





