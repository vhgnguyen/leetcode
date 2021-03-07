#include "helper.h"
#include <algorithm>

using namespace helper;

bool containsDuplicate(vector<int> & nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == nums[i+1]) return true;
    }
    return false;
}

void printResult(vector<int> a) {
    cout << "Input: nums = " << v2s(a) << endl;
    cout << "Output: " << bool2str(containsDuplicate(a)) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,3,1}); // Ouput: true
    printResult(vector<int>{1,2,3,4}); // Ouput: false
    printResult(vector<int>{1,1,1,3,3,4,3,2,4,2}); // Ouput: true

    return 0;
}