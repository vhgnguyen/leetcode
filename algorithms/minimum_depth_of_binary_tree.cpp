#include "helper.h"

using namespace std;
using namespace Node;
using namespace helper;

int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

void printResult(vector<int> a) {
    TreeNode* root = createTreeNode(a);
    int res = minDepth(root);
    cout << "Input: root = " << printTreeNode(root) << endl;
    cout << "Output: " << res << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{3,9,20,NULL,NULL,15,7}); // Output: 2
    printResult(vector<int>{2,NULL,3,NULL,4,NULL,5,NULL,6}); // Output: 5

    return 0;
}