#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Use 3sum approach for pointers on 4sum
 */
vector<vector<int>> fourSum(vector<int>& nums, int target) {

    int n = nums.size();
    if (n < 4)
        return {};

    vector<vector<int>> res;
    sort(nums.begin(),nums.end());

    for (int i = 0; i < n-3; ++i) {
        if (target <= 0 && nums[i] > 0) break;
        if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
        if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < target) continue;
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        for (int j = i + 1; j < n-2; ++j) {
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
            if(nums[i]+nums[j]+nums[n-2]+nums[n-1] < target) continue;
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            
            int l = j + 1, r = n - 1;
            
            while (l < r) { 
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target) {
                    res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                    do r--; while (l < r && nums[r] == nums[r+1]);
                    do l++; while (l < r && nums[l] == nums[l-1]);
                }
                else if (sum > target) {
                    r--;
                }
                else if (sum < target) {
                    l++;
                }
            }
        }
    }

    return res;
}

void printFourSum(vector<int> nums, int target) {
    
    if (nums.empty()) {
        cout << "Input: nums = [";
    }
    else {
        cout << "Input: nums = [" << nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            cout << "," << nums[i];
        }
    }
    cout << "]" << endl;
    vector<vector<int>> result = fourSum(nums, target);
    cout << endl << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "=======" << endl;
}


int main(int argc, char ** argv) {

    // Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    printFourSum(vector<int>{1,0,-1,0,-2,2}, 0);
    // Output: []
    printFourSum(vector<int>{}, 0);

    return 0;
}