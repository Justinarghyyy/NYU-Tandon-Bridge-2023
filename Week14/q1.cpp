#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeExtream(vector<int> arr, int right, int left);

int main() {
    char c ;
    int num ;
    vector<int> arr;
    vector<int> arrRes;
    cout << "Please enter your numbers: " << endl ;
    while (cin >> num) {
        arr.push_back(num);

        // check if next input is a space
        if (cin.peek() == ' ') {
            break;
        }
    }

    int left = arr.size() - 1;
    int right = 0;
    arrRes = mergeExtream(arr, right, left);
    cout << "The largest number is " << arrRes[0] << endl;
    cout << "The smallest number is " << arrRes[1] << endl;
    return 0;
}

vector<int> mergeExtream(vector<int> arr, int right, int left) {
    int mid = (right + left) / 2;
    vector<int> arrRes;
    vector<int> arrRes1;
    vector<int> arrRes2;
    if (right == left) {
        arrRes.push_back(arr[right]) ;
        arrRes.push_back(arr[right]) ;
    }
    else {
        arrRes1 = mergeExtream(arr, right, mid);
        arrRes2 = mergeExtream(arr, mid + 1, left);
        
            if (arrRes1[0] > arrRes2[0]) {
                arrRes.push_back(arrRes1[0]);
            }
            else {
                arrRes.push_back(arrRes2[0]);
            }
            if (arrRes1[1] < arrRes2[1]) {
                arrRes.push_back(arrRes1[1]);
            }
            else {
                arrRes.push_back(arrRes2[1]);
            }
        
    }
    return arrRes;
}
