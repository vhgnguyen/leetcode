#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int res = nums[0], curr = 0;
    for (int n : nums) {
        curr = max(n, curr + n);
        res = max(res, curr);
    }
    return res;
}

void printResult(vector<int> nums) {
    cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    int res = maxSubArray(nums);
    cout << "Output: " << res << endl;;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{-2,1,-3,4,-1,2,1,-5,4}); //Output: 6
    printResult(vector<int>{1}); //Output: 1
    printResult(vector<int>{0}); //Output: 0
    printResult(vector<int>{-1}); //Output: -1
    printResult(vector<int>{-100000}); //Output: -100000

    return 0;
}