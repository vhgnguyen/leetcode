#include <iostream>
#include <vector>
#include <string>

using namespace std;


int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (auto & n : nums) {
        if (i == 0 || n > nums[i-1]) {
            nums[i++] = n;
        }
    }
    return i;
}            

void printResult(vector<int> nums) {
    cout << "Input : " << "nums = [" << nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        cout << "," << nums[i];
    }
    cout << "]" << endl;
    int res = removeDuplicates(nums);
    cout << "Output : " << res << ", " << "nums = [" << nums[0];
    for (int j = 1; j < res; ++j) {
        cout << "," << nums[j];
    }
    cout << "]" << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,1,2}); // Output: 2, nums = [1,2]
    printResult(vector<int>{0,0,1,1,1,2,2,3,3,4}); // Output: 5, nums = [0,1,2,3,4]

    return 0;
}