#include "helper.h"

using namespace helper;


vector<int> majorityElement(vector<int>& nums) {
    int c1, c2, vote1 = 0, vote2 = 0, major = nums.size() / 3;
    for (int n : nums) {
        if (n == c1) vote1++;
        else if (n == c2) vote2++;
        else if (!vote1) {
            c1 = n;
            vote1++;
        }
        else if (!vote2) {
            c2 = n;
            vote2++;
        }
        else {
            vote1--;
            vote2--;
        }
    }
    vote1 = vote2 = 0;
    for (int m : nums) {
        if (m == c1) vote1++;
        if (m == c2) vote2++;
    }
    vector<int> res;
    if (vote1 > major) res.push_back(c1);
    if (vote2 > major) res.push_back(c2);
    return res;
}

void printResult(vector<int> nums) {
    cout << "Input: nums = " << v2s(nums) << endl;
    cout << "Output: " << v2s(majorityElement(nums)) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{3,2,3}); // Output: [3]
    printResult(vector<int>{1}); // Output: [1]
    printResult(vector<int>{1,2}); // Output: [1,2]

    return 0;
}