# include <iostream>
# include <string>
using namespace std;
bool isPalindrome(string str) ;
int main(){
    string word ;
    bool is_palindrome ;
    cout << "Please enter a word:"<< endl ;
    cin >> word ;
    is_palindrome = isPalindrome( word ) ;
    if ( is_palindrome == true ){
        cout << " is a palindrome."<< endl ;
    }
    else {
        cout << " is not a palindrome."<< endl ;
    }

    return 0 ;
}

bool isPalindrome(string word){
    int index_left, index_right ;
    bool is_palindrome ;

    index_left = 0 ;
    index_right = word.length()-1 ;
    is_palindrome = true ;
    while (index_left < index_right ) {
        if ( word[index_left] == word[index_right]){
            index_left ++ ;
            index_right -- ;
        }
        else {
            is_palindrome = false ;
            break ;
        }
    }

    return is_palindrome ;
}