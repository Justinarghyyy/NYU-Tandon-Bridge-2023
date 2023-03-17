#include <iostream>
#include <string>
#include <vector>
using namespace std ;
string* createWordsArray(string sentence, int& outWordsArrSize) ;
int main(){
    int outWordsArrSize = 0 ;
    string sentence ;
    cout << "Please enter a sentence:" << endl ;
    getline(cin, sentence) ;
    string* newSentence = createWordsArray( sentence, outWordsArrSize) ;
    cout << outWordsArrSize ;
    delete[] newSentence ;
    return 0 ;
}
string* createWordsArray(string sentence, int& outWordsArrSize){
    int ind, letter, i, arrSize, space ;
    vector <string> vec ;
    letter = 0 ;
    ind = 0 ;
    space = 0 ;
    arrSize = sentence.length() ;
    for (i = 0 ; i < arrSize - 1; i ++){
        if ( sentence[i] == ' '){
            vec.push_back(sentence.substr(space, letter)) ;
            space = sentence.find(' ', i);
            outWordsArrSize ++ ;
        }
        else {
            letter ++ ;
        }
    }
    letter += 1 ;
    vec.push_back(sentence.substr(space, letter)) ;
    outWordsArrSize += 1 ;

    string* newSentence = new string[outWordsArrSize];
    for (i = 0 ; i < outWordsArrSize ; i++){
        newSentence[i] = vec[i] ;
    }

    return newSentence ;

}