#include "helper.h"

using namespace helper;

int trailingZeroes(int n) {
    int res = 0;
    for (int i = 5; n/i > 0; i *= 5) {
        res += n / i;
    }
    return res;
}

void printResult(int n) {
    cout << "Input: n = " << n << endl;
    cout << "Output: " << trailingZeroes(n) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(3); // Output: 0
    printResult(5); // Output: 1
    printResult(0); // Output: 0
    printResult(25); // Output: 0

    return 0;
}