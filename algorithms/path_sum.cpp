#include "helper.h"

using namespace std;
using namespace Node;
using namespace helper;


bool hasPathSum(TreeNode* root, int targetSum) {
    return root != NULL && (root->left == NULL && root->right == NULL && root->val == targetSum || hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val));
}

void printResult(vector<int> a, int target) {
    TreeNode* root = createTreeNode(a);
    string res = hasPathSum(root, target) ? "true" : "false";
    cout << "Input: root = " << printTreeNode(root) << endl;
    cout << "Output: " << res << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1}, 22); // Output: true
    printResult(vector<int>{1,2,3}, 5); // Output: false
    printResult(vector<int>{1,2}, 0); // Output: false

    return 0;
}