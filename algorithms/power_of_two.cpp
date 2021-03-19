#include "helper.h"

bool isPowerOfTwo(int n) {
    return n > 0 && !(n & n-1);
}

void printResult(int n) {
    cout << "Input: n = " << n << endl;
    cout << "Output: " << helper::bool2str(isPowerOfTwo(n)) << endl << helper::printEnd() << endl;
} 


int main(int argc, char ** argv) {

    printResult(1); // Output: true
    printResult(16); // Output: true
    printResult(3); // Output: false
    printResult(4); // Output: true
    printResult(5); // Output: false

    return 0;
}