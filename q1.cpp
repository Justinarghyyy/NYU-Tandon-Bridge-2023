#include <iostream> 
using namespace std ;
void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);
void printAst(int n);
void printMark(int n);
int main(){
    int n = 5 ;
    printRuler(n);
    return 0 ;

}

void printTriangle(int n){
    if ( n == 1 ){
        cout << "-" << endl;
    }
    else{
        printTriangle (n - 1);
        printAst(n);
        cout << endl;
    }
}

void printOpositeTriangles(int n){
    if ( n == 1 ){
        cout << "*" << endl;
    }
    else{
        printAst(n);
        cout << endl;
        printOpositeTriangles (n - 1);
        printAst(n);
        cout << endl;
    }
}

void printAst(int n){
    if (n == 1){
        cout << "*" ;
    }
    else{
        cout << "*" ;
        printAst(n-1);
    }
}

void printRuler(int n){
    if ( n == 1 ){
        cout << "-" ;
    }
    else{
        printRuler(n-1);
        cout << endl ;
        printMark(n);
        cout << endl ;
        printRuler(n-1);
    }
}

void printMark(int n){
    if (n == 1){
        cout << "-" ;
    }
    else{
        cout << "-" ;
        printMark(n-1);
    }
}