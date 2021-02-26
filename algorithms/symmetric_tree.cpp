#include "helper.h"

using namespace std;
using namespace Node;
using namespace helper;


bool isMirror(TreeNode* left, TreeNode* right) {
    return (left == NULL || right == NULL) ? (left == right) : (left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left));
};

bool isSymmetric(TreeNode* root) {
    if (!root)
        return true;
    return isMirror(root->left, root->right);
};

void printResult(vector<int> a) {
    TreeNode* root = createTreeNode(a);
    string res = isSymmetric(root) ? "true" : "false";
    cout << "Input: root = " << printTreeNode(root) << endl;
    cout << "Output: " << res << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,2,NULL,3,NULL,3}); // Output: false
    return 0;
}