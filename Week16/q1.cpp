#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std ;

void openFile (ifstream& inFile){
    string fileName ;
    cout << "Enter file name: " << endl ;
    cin >> fileName ;
    inFile.open(fileName) ;
    while ( ! inFile ){
        cout << "Invaid file name! " << endl ;
        cout << "Enter file name: " << endl ;
        cin >> fileName ;
        inFile.clear() ;
        inFile.open(fileName) ;
    }
}

bool checker ( stack<char>& open, string program ) ;

int main () {
    ifstream inFile ;
    openFile ( inFile ) ;

    string program ;
    inFile >> program ;

    stack<char> open;

    bool balanced ;
    balanced = checker ( open, program );
    if (balanced == false){
        cout << "false" << endl ;
    }
    else {
        cout << "true" << endl ;
    }
}

bool checker ( stack<char>& open, string program ) {
    char matching ;
    
    if ( program[0] == 'b' && program[1] == 'e' && program[2] == 'g' && program[3] == 'i' && program[4] == 'n'){
        open.push('b') ;
        }
    else {
        return false ;
    }

    for ( int i = 5 ; i < program.size() - 3 ; i ++ ){
        if ( program[i] == '{' || program[i] == '[' || program[i] == '(' ){
            open.push( program[i] ) ;
        }
        else {
            if ( program[i] == '}' || program[i] == ']' || program[i] == ')' ){
                if ( open.empty() ) {
                    return false ;
                }
                else {
                    matching = open.top() ;
                    open.pop() ;
                    if ( program[i] == '}' && matching != '{'){
                        return false ;
                    }
                    else if ( program[i] == ']' && matching != '[' ){
                        return false ;
                    }
                    else if ( program[i] == ')' && matching != '(' ){
                        return false ;
                    }
                }
            }
        }
    }

    if ( program[program.size() - 3] == 'e' && program[program.size() - 2] == 'n' && program[program.size() - 1] == 'd' ){
        if ( open.empty() ) {
            return false ;
        }
        else {
            matching = open.top() ;
            open.pop() ;
            if ( matching != 'b' ){
                return false ;
            }        
        }
    }
    else {
        return false ;
    }
        
    if ( !open.empty() ){
        return false ;
    }
    return true ;
}
