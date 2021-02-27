#include "helper.h"

using namespace helper;


vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        if (numbers[l] + numbers[r] > target)
            r--;
        else if (numbers[l] + numbers[r] < target)
            l++;
        else 
            return {l+1, r+1};
    }
    return {};
}

void printResult(vector<int> a, int target) {
    vector<int> res = twoSum(a, target);
    cout << "Input: numbers = " << v2s(a) << ", target = " << target << endl;
    cout << "Output: " << v2s(res) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{2,7,11,15}, 9); // Output: [1, 2]
    printResult(vector<int>{2,3,4}, 6); // Output: [1, 3]
    printResult(vector<int>{-1,0}, -1); // Output: [1, 2]

    return 0;
}