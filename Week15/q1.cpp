#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std ;

struct Bill {
    double amountPaid ;
    string name ;
    double amountOwed ;
};

void splitBill ( vector <Bill> & vec , int numberPeople ) ;
void openFile (ifstream& inFile) ;

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

void splitBill ( vector <Bill> & vec , int numberPeople ){
    double totalAmount = 0 ;
    int n ;
    double average ;
    for ( Bill b : vec ){
        totalAmount += b.amountPaid ;
    }
    average = totalAmount / numberPeople ;
    for ( Bill b : vec ){
        b.amountOwed = average - b.amountPaid ;
    }
    cout << "here" << endl ;
    for ( int i = 0 ; i < numberPeople ; i ++ ){
        cout << "here" << endl ;
        if ( vec[i].amountOwed < 0 ){
            cout << vec[i].name << " you don't need to do anything. " << endl ;
        }
        else {
            for (n = 0 ; n < i ; n ++ ){
                while ( vec[i].amountOwed != 0 ){
                    if (vec[n].amountOwed < 0 ){
                        if ( -vec[n].amountOwed > vec[i].amountOwed ){
                            cout << vec[i].name << " you need to give " << vec[n].name << vec[i].amountOwed << endl ;
                            vec[n].amountOwed += vec[i].amountOwed ;
                            vec[i].amountOwed = 0 ;
                        }
                        else if ( -vec[n].amountOwed < vec[i].amountOwed ){
                            cout << vec[i].name << " you need to give " << vec[n].name << vec[i].amountOwed << endl ;
                            vec[i].amountOwed += vec[n].amountOwed ;
                            vec[n].amountOwed = 0 ;
                        }
                    }
                }
            }
            for (n = i + 1 ; n < numberPeople ; n ++ ){
                while ( vec[i].amountOwed != 0 ){
                    if (vec[n].amountOwed < 0 ){
                        if ( -vec[n].amountOwed > vec[i].amountOwed ){
                            cout << vec[i].name << " you need to give " << vec[n].name << vec[i].amountOwed << endl ;
                            vec[n].amountOwed += vec[i].amountOwed ;
                            vec[i].amountOwed = 0 ;
                        }
                        else if ( -vec[n].amountOwed < vec[i].amountOwed ){
                            cout << vec[i].name << " you need to give " << vec[n].name << vec[i].amountOwed << endl ;
                            vec[i].amountOwed += vec[n].amountOwed ;
                            vec[n].amountOwed = 0 ;
                        }
                    }
                }
            }
        }
    }

}

int main(){
    ifstream inFile ;
    openFile ( inFile ) ;
    vector <Bill> vec ;
    Bill temp ;
    int numberPeople = 0 ;
    while ( inFile >> temp.amountPaid ){
        cout << temp.amountPaid << endl ;
        inFile.ignore( 9999, '\t' ) ;
        getline( inFile, temp.name ) ;
        cout << temp.name << endl ;
        vec.push_back( temp ) ;
        numberPeople ++ ;
    } 
    for (int i = 0 ; i < numberPeople; i++){
        if (vec[i].amountPaid > 0){
            cout << vec[i].name << endl;
    }
    }
    splitBill ( vec , numberPeople ) ;

    
    return 0 ;
}
