#include "helper.h"

using namespace std;
using namespace helper;


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; ++i) {
        res.push_back(vector<int>(i+1, 1));
        for (int j = 1; j < i; ++j) {
            res[i][j] = res[i-1][j] + res[i-1][j-1];
        }
    }
    return res;        
}

void printResult(int n) {
    vector<vector<int>> res = generate(n);
    cout << "Input: numRows = " << n << endl;
    cout << "Output: " << printVectorVector(res) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(5); // Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    printResult(1); // Output: [[1]]

    return 0;
}