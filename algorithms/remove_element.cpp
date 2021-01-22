#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
 * The length of vector doesn't matter since we only take the first i elements
 */
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (auto & n : nums) {
        if (n != val) {
            nums[i++] = n;
        }
    }
    return i;
}            

void printResult(vector<int> nums, int val) {
    cout << "Input : " << "nums = [" << nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        cout << "," << nums[i];
    }
    cout << "], val = " << val << endl;
    int res = removeElement(nums, val);
    cout << "Output : " << res << ", " << "nums = [" << nums[0];
    for (int j = 1; j < res; ++j) {
        cout << "," << nums[j];
    }
    cout << "]" << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{3,2,2,3}, 3); // Output: 2, nums = [2,2]
    printResult(vector<int>{0,1,2,2,3,0,4,2}, 2); // Output: 5, nums = [0,1,4,0,3]

    return 0;
}