#include "helper.h"

using namespace std;
using namespace Node;
using namespace helper;


TreeNode* build(vector<int>& nums, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode* tree = new TreeNode(nums[mid]);
    tree->left = build(nums, start, mid-1);
    tree->right = build(nums, mid+1, end);
    return tree;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size()-1);
}

void printResult(vector<int> a) {
    TreeNode* res = sortedArrayToBST(a);
    cout << "Input: nums = " << v2s(a) << endl;
    cout << "Output: " << printTreeNode(res) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{-10,-3,0,5,9}); // Output: [0,-3,9,-10,null,5]
    printResult(vector<int>{1,3}); // Output: [1,3] or [3,1]

    return 0;
}