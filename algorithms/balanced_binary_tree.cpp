#include "helper.h"

using namespace std;
using namespace Node;
using namespace helper;


int maxDepth(TreeNode* root) {
    return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    return root == NULL ? true : abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

void printResult(vector<int> a) {
    TreeNode* root = createTreeNode(a);
    string res = isBalanced(root) ? "true" : "false";
    cout << "Input: root = " << printTreeNode(root) << endl;
    cout << "Output: " << res << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{3,9,20,NULL,NULL,15,7}); // Output: true
    printResult(vector<int>{1,2,2,3,3,NULL,NULL,4,4}); // Output: false
    printResult(vector<int>{}); // Output: true

    return 0;
}