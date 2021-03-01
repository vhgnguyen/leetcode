#include "helper.h"

using namespace helper;

int titleToNumber(string s) {
    long res = 0;
    for (char c : s) {
        res = res * 26 + c - '@';
    }
    return res;
}

void printResult(string s) {
    cout << "Input: " << printString(s) << endl;
    cout << "Output: " << titleToNumber(s) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult("A"); // Output: 1
    printResult("AB"); // Output: 28
    printResult("ZY"); // Output: 701

    return 0;
}