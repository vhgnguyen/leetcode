#include "helper.h"
#include <algorithm>
#include <unordered_set>

using namespace helper;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k)
            s.erase(nums[i-k-1]);
        if (s.insert(nums[i]).second == false)
            return true;
    }
    return false;
}

void printResult(vector<int> a, int k) {
    cout << "Input: nums = " << v2s(a) << endl;
    cout << "Output: " << bool2str(containsNearbyDuplicate(a, k)) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,3,1}, 3); // Ouput: true
    printResult(vector<int>{1,0,1,1}, 1); // Ouput: true
    printResult(vector<int>{1,2,3,1,2,3}, 2); // Ouput: false

    return 0;
}