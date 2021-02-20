#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int searchInsert(vector<int> & nums, int target) {
    return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
}

void printResult(vector<int> nums, int target) {
    cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "], target = " << target << endl;
    int res = searchInsert(nums, target);
    cout << "Output: " << res << endl;;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,3,5,6}, 5); //Output: 2
    printResult(vector<int>{1,3,5,6}, 2); //Output: 1
    printResult(vector<int>{1,3,5,6}, 7); //Output: 4
    printResult(vector<int>{1,3,5,6}, 0); //Output: 0
    printResult(vector<int>{1}, 0); //Output: 0

    return 0;
}