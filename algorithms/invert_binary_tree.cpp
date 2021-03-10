#include "helper.h"

using namespace Node;
using namespace helper;


TreeNode* invertTree(TreeNode* root) {
    if (root != NULL) {
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
    }
    return root;
}


int main(int argc, char ** argv) {
    TreeNode* root = createTreeNode(vector<int>{4,2,7,1,3,6,9}); 
    cout << "Input: root = " << printTreeNode(root) << endl;
    root = invertTree(root); // Output: [4,2,7,1,3,6,9]
    cout << "Output: " << printTreeNode(root) << endl << printEnd() << endl; 

    return 0;
}