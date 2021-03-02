#include "helper.h"
#include <unordered_set>
#include <math.h>

bool isHappy(int n) {
    unordered_set<int> m;
    while (n != 1) {
        if (m.find(n) == m.end()) m.insert(n);
        else return false;
        int sum = 0;
        while (n) {
            sum += pow(n%10, 2);
            n /= 10;
        }
        n = sum;
    }
    return true;
}

void printResult(int n) {
    cout << "Input: n = " << n << endl;
    cout << "Output: " << helper::bool2str(isHappy(n)) << endl << helper::printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(19); // Output: true
    printResult(2); // Output: true

    return 0;
}