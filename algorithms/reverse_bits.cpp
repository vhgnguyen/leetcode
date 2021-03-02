#include "helper.h"
#include <bitset>

using namespace helper;


uint32_t reverseBits(uint32_t n) {
    n = ((n >> 16) | (n << 16));
    n = ((n &  0xFF00FF00) >> 8) | ((n &  0x00FF00FF) << 8); 
    n = ((n &  0xF0F0F0F0) >> 4) | ((n &  0x0F0F0F0F) << 4); 
    n = ((n &  0xCCCCCCCC) >> 2) | ((n &  0x33333333) << 2); 
    n = ((n &  0xAAAAAAAA) >> 1) | ((n &  0x55555555) << 1); 
    return n;
}

void printResult(uint32_t n) {
    cout << "Input: n = " << n << "(" << bitset<32>(n) << ")" << endl;
    cout << "Output: " << reverseBits(n) << "(" << bitset<32>(reverseBits(n)) << ")" << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult((uint32_t)43261596); // Output: 964176192
    printResult((uint32_t)4294967293); // Output: 3221225471

    return 0;
}