#include "helper.h"

using namespace std;
using namespace Node;
using namespace helper;

int maxDepth(TreeNode* root) {
    return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

void printResult(vector<int> a) {
    TreeNode* root = createTreeNode(a);
    int res = maxDepth(root);
    cout << "Input: root = " << printTreeNode(root) << endl;
    cout << "Output: " << res << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{3,9,20,NULL,NULL,15,7}); // Output: 3
    printResult(vector<int>{1,NULL,2}); // Output: 2
    printResult(vector<int>{}); // Output: 0
    printResult(vector<int>{0}); // Output: 1

    return 0;
}