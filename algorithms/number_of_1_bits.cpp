#include "helper.h"
#include <bitset>

using namespace helper;


int hammingWeight(uint32_t n) {
    int c = n ? 1 : 0;
    while (n &= n-1) c++;
    return c;
}

void printResult(string s) {
    cout << "Input: n = " << bitset<32>(stoi(s, 0, 2)) << endl;
    cout << "Output: " << hammingWeight(stoi(s, 0, 2)) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult("00000000000000000000000000001011"); // Output: 3
    printResult("00000000000000000000000010000000"); // Output: 1

    return 0;
}