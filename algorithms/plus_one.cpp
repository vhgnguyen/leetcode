#include <iostream>
#include <vector>

using namespace std;;


vector<int> plusOne(vector<int> & digits) {
    for (int i = digits.size(); i--; digits[i] = 0) {
        if (digits[i]++ < 9) {
            return digits;
        }
    }
    digits[0] = 1;
    digits.push_back(0);
    return digits;
}

void printResult(vector<int> digits) {
    cout << "Input : " << "digits = [" << digits[0];
    for (int i = 1; i < digits.size(); ++i) {
        cout << "," << digits[i];
    }
    cout << "]" << endl;
    vector<int> res = plusOne(digits);
    cout << "Output: [";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,3}); // Output: [1,2,4]
    printResult(vector<int>{4,3,2,1}); // Output: [4,3,2,2]
    printResult(vector<int>{0}); // Output: [1]
    printResult(vector<int>{9,9,9}); // Output: [1,0,0,0]
    printResult(vector<int>{9,0,9}); // Output: [9,1,0]

    return 0;
}