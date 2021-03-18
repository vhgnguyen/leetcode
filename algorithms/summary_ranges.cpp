#include "helper.h"

using namespace helper;


vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int i = 0, j;
    while (i < nums.size()) {
        j = i + 1;
        while (j < nums.size() && nums[j-1] + 1 == nums[j]) j++;
        string s = to_string(nums[i]) + (j-i-1 > 0 ? "->" + to_string(nums[j-1]) : "");
        res.push_back(s);
        i = j;
    }
    return res;
}

void printResult(vector<int> nums) {
    cout << "Input: nums = " << v2s(nums) << endl;
    vector<string> res = summaryRanges(nums);
    cout << "Output: " << v2s(res) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{0,1,2,4,5,7}); // Output: ["0->2","4->5","7"]
    printResult(vector<int>{0,2,3,4,6,8,9}); // Output: ["0","2->4","6","8->9"]
    printResult(vector<int>{}); // Output: []
    printResult(vector<int>{-1}); // Output: ["-1"]
    printResult(vector<int>{0}); // Output: ["0"]

    return 0;
}