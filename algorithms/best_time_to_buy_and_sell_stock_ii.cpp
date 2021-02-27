#include "helper.h"
#include <limits.h>

using namespace std;
using namespace helper;


int maxProfit(vector<int>& prices) {
    int m = 0;
    for (auto it = prices.begin()+1; it < prices.end(); ++it) {
        m += max(0, *it - *(it-1));
    }
    return m;
}

void printResult(vector<int> prices) {
    int res = maxProfit(prices);
    cout << "Input: prices = " << v2s(prices) << endl;
    cout << "Output: " << res << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{7,1,5,3,6,4}); // Output: 7
    printResult(vector<int>{1,2,3,4,5}); // Output: 4
    printResult(vector<int>{7,6,4,3,1}); // Output: 0

    return 0;
}