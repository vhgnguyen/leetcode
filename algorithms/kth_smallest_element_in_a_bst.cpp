#include "helper.h"

using namespace helper;
using namespace Node;


void find(TreeNode* root, int& k, vector<int> & klist) {
    if (root->left) find(root->left, k, klist);

    // disable this IF condition if not using this repo
    // because of the implementation of binary tree node in helper
    if (root->val) 
        klist.push_back(root->val);

    if (root->right) find(root->right, k , klist);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> klist;
    find(root, k, klist);
    return klist[k-1];
}

void printResult(vector<int> a, int k) {
    TreeNode* root = createTreeNode(a);
    cout << "Input: root = " << printTreeNode(root) << ", k = " << k << endl;
    cout << kthSmallest(root, k) << endl << printEnd() << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int>{3,1,4,NULL,2}, 1); // Output: 1
    printResult(vector<int>{5,3,6,2,4,NULL,NULL,1}, 3); // Output: 3

    return 0;
}