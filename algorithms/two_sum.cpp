/*
 * @Author: Vo Hoang Nguyen 
 * @Date: 2020-12-05 22:56:28 
 * @Last Modified by: Vo Hoang Nguyen
 * @Last Modified time: 2020-12-05 23:20:01
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * One hash map solution
 */
class Solution{
public:
    vector<int> twoSum(vector<int> & nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) == m.end()) {
                m[nums[i]] = i;
            }
            else {
                return {m[target-nums[i]], i};
            }
        }
        return {};
    }
};


int main(int argc, char** argv) {

    int size, input, target;
    vector<int> nums, result;

    cout << "nums.size(): ";
    cin >> size;
    while (size <2) {
        cout << "nums.size() >= 2!" << endl;
        cout << "nums.size(): ";
        cin >> size;
    }
    cout << endl;

    while (nums.size() < size) {
        cout << "nums[" << nums.size() << "]: ";
        cin >> input;
        nums.push_back(input);
    }

    cout << "nums: ";
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl << "target: ";
    cin >> target;
  
    Solution sol;
    result = sol.twoSum(nums, target);
    cout << "Output: ";
    for (auto it = result.begin(); it != result.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}