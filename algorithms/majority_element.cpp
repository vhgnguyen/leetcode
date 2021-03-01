#include "helper.h"

using namespace helper;

int majorityElement(vector<int>& nums) {
    int major, count = 0;
    for (int n : nums) {
        if (count == 0) major = n;
        count += n == major ? 1 : -1;
    }
    return major;
}

void printResult(vector<int> nums) {
    cout << "Input: nums = " << v2s(nums) << endl;
    cout << "Output: " << majorityElement(nums) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{3,2,3}); // Output: 3
    printResult(vector<int>{2,2,1,1,1,2,2}); // Output: 2

    return 0;
}