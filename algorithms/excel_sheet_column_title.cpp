#include "helper.h"

using namespace helper;

string convertToTitle(int n) {
    string res = "";
    while (n--) {
        char c = 'A' + n%26;
        res = c + res;
        n /= 26;
    }
    return res;
}

void printResult(int n) {
    cout << "Input: " << n << endl;
    cout << "Output: " << convertToTitle(n) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(1); // Output: A
    printResult(28); // Output: AB
    printResult(701); // Output: ZY

    return 0;
}