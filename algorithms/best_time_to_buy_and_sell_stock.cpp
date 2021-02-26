#include "helper.h"
#include <limits.h>

using namespace std;
using namespace helper;


int maxProfit(vector<int>& prices) {
    int mxp = 0, mnp = INT_MAX;
    for (auto & p : prices) {
        mnp = min(mnp, p);
        mxp = max(mxp, p-mnp);
    }
    return mxp;
}

void printResult(vector<int> prices) {
    int res = maxProfit(prices);
    cout << "Input: prices = " << v2s(prices) << endl;
    cout << "Output: " << res << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{7,1,5,3,6,4}); // Output: 5
    printResult(vector<int>{7,6,4,3,1}); // Output: 0

    return 0;
}