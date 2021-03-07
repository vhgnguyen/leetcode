#include "helper.h"
#include <algorithm>
#include <set>

using namespace helper;


bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k) 
            m.erase(nums[i-k-1]);
        auto it = m.lower_bound(nums[i] - t);
        if (it != m.end() && (*it) <= nums[i] + t)
            return true;
        m.insert(nums[i]);
    }

    return false;
}

void printResult(vector<int> a, int k, int t) {
    cout << "Input: nums = " << v2s(a) << endl;
    cout << "Output: " << bool2str(containsNearbyAlmostDuplicate(a, k, t)) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,3,1}, 3, 0); // Ouput: true
    printResult(vector<int>{1,0,1,1}, 1, 2); // Ouput: true
    printResult(vector<int>{1,5,9,1,5,9}, 2, 3); // Ouput: false

    return 0;
}