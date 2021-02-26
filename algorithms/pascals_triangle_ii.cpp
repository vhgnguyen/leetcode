#include "helper.h"

using namespace std;
using namespace helper;


vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex+1, 1);
    for (int i = 0; i < rowIndex; ++i) {
        for (int j = i; j > 0; --j) {
            res[j] += res[j-1];
        }
    }
    return res;
}

void printResult(int n) {
    vector<int> res = getRow(n);
    cout << "Input: rowIndex = " << n << endl;
    cout << "Output: " << v2s(res) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(3); // Output: [1,3,3,1]
    printResult(0); // Output: [1]
    printResult(1); // Output: [1,1]

    return 0;
}