#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int threeSumClosest(vector<int>& nums, int target) {

    int n = nums.size();
    sort(nums.begin(),nums.end());
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n-2; ++i) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int l = i+1, r = n-1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (abs(closest-target) > abs(sum-target))
                closest = sum;

            if (sum == target) {
                return closest;
            }
            else if (sum < target) {
                while (l < r && nums[l] == nums[l+1]) l++;
                l++;
            }
            else {
                while (l < r && nums[r] == nums[r-1]) r--;
                r--;
            }
        }
    }

    return closest;
}


void printThreeSumClosest(vector<int> nums, int target) {

    cout << "Input: nums = [" << nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        cout << "," << nums[i];
    }
    cout << "]" << ", target = " << target << endl;
    int result = threeSumClosest(nums, target);
    cout << "Output: " << result << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    /**
     * Input: nums = [-1,2,1,-4], target = 1
     * Output: 2
     */
    printThreeSumClosest(vector<int>{-1,2,1,-4}, 1);

    return 0;
}