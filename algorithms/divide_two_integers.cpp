#include <iostream>
#include <limits.h>

using namespace std;

/**
 * Use bit left shift: eg. A = 10, B = 3, if A-B>0 we shift B 1 bit to left (B->B*2)
 * until A-B<0. We have 10 - 4*3 = 10 - 12 < 0 so we shifted B 3 bits to left, i.e 1<<3 <=> 2^3 = 8 times
 * so that 10 = 3*3 + 1, return 3
 */
int divide(int dividend, int divisor) {

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    // because int & unsigned for abs cause integer overflow of -INT_MIN, but can compile with long?
    long A = labs(dividend), B = labs(divisor), res = 0;
    while (A - B >= 0) {
        int x = 0;
        while (A - (B << x << 1) >= 0) {
            x++;
        }
        res += 1 << x;
        A -= B << x;
    }
    return (dividend > 0 == divisor > 0) ? res : -res;
}

void printResult(int dividend, int divisor) {

    cout << "Input: dividend = " << dividend << ", divisor = " << divisor << endl;
    int res = divide(dividend, divisor);
    cout << "Output: " << res << endl;
    cout << "=======" << endl;
}

int main(int argc, char ** argv) {
    
    printResult(10, 3); // Output: 3
    printResult(7, -3); // Output: -2
    printResult(0, 1); // Output: 0
    printResult(1, 1); // Output: 1

    return 0;
}