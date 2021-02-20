#include <iostream>

using namespace std;

/**
 * Fibonacci number: starting from {1,2}, which are each step could take, then {1,2,3},{1,2,3,5},...
 *  the total way at n-th index is the sum of the ways at index (n-1) and (n-2)
 * We use a, b to represent two previous consecutive index
 */
int climbStairs(int n) {
    int a = 1, b = 1;
    while (--n) {
        a = (b += a) - a; // replace b=a and next a = b
    }
    return b; // return b because it stops at n = 0
}

void printResult(int n) {
    cout << "Input: n = " << n << endl;
    int res = climbStairs(n);
    cout << "Output: " << res << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult(2); // Output: 2
    printResult(3); // Output: 3
    printResult(7); // Output: 21

    return 0;
}