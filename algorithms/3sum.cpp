#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<vector<int>> threeSum(vector<int> & nums) {

    int n = nums.size();
    if (n < 3)
        return {};
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());

    for (int i = 0; i < n-1 && nums[i] <= 0;) {
        int l = i+1, r = n-1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum > 0) {
                r--;
            }
            else if (sum < 0) {
                l++;
            }
            else {
                res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                while (l < r && nums[r] == nums[r-1]) r--;
                while (l < r && nums[l] == nums[l+1]) l++;
                l++; r--;
            }
        }
        i++;
        while((i < nums.size()) && nums[i] == nums[i-1])
            i++;
    }

    return res;
}

void printThreeSum(vector<int> nums) {
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
    vector<vector<int>> result = threeSum(nums);
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

    printThreeSum(vector<int>{-1,0,1,2,-1,-4});
    printThreeSum(vector<int>{});
    printThreeSum(vector<int>{0});

    return 0;
}