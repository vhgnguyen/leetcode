#include "helper.h"

using namespace helper;


int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int n : nums) {
        res ^= n;
    }
    return res;
}

void printResult(vector<int> nums) {
    cout << "Input: nums = " << v2s(nums) << endl;
    cout << "Output: " << singleNumber(nums) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{2,2,1}); // Output: 1
    printResult(vector<int>{4,1,2,1,2}); // Output: 4
    printResult(vector<int>{1}); // Output: 1

    return 0;
}