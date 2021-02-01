#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;


void nextPermutation(vector<int>& nums) {

    int i = nums.size() - 1, j = i;
    while (i > 0 && nums[i-1] >= nums[i]) 
        i--;
    if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
    }
    else {
        while (j > i - 1 && nums[j] <= nums[i-1])
            j--;
        swap(nums[i-1], nums[j]);
        reverse(nums.begin() + i, nums.end());
        return;
    }
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
    nextPermutation(nums);
    cout << "Output: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,3}); //Output: [1,3,2]
    printResult(vector<int>{1,3,2}); //Output: [2,1,3]
    printResult(vector<int>{3,2,1}); //Output: [1,2,3]
    printResult(vector<int>{1,1,5}); //Output: [1,5,1]
    printResult(vector<int>{1}); //Output: [1]

    return 0;
}