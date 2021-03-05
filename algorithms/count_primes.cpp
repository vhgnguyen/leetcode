#include "helper.h"
#include "math.h"

int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> notPrime(n, false);
    int count = 1, sqrtn = sqrt(n);
    for (int i = 3; i < n; i += 2) {
        if (notPrime[i] == false) {
            count ++;
            if (i > sqrtn) continue;
            for (int j = i*i; j < n; j += i) {
                notPrime[j] = true;
            }
        }
    }
    return count;
}

void printResult(int n) {
    cout << "Input: n = " << n << endl;
    cout << "Output: " << countPrimes(n) << endl << helper::printEnd() << endl;
}


int main(int argc, char ** argv) {
    
    printResult(10); // Output: 4
    printResult(0); // Output: 0
    printResult(1); // Output: 0

    return 0;
}