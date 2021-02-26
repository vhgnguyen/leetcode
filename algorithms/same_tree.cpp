#include "helper.h"

using namespace std;
using namespace Node;
using namespace helper;

bool isSameTree(TreeNode* p, TreeNode* q) {
    return ((p == NULL || q == NULL) ? p == q : (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)));
}

void printResult(vector<int> a, vector<int> b) {
    TreeNode* p = createTreeNode(a);
    TreeNode* q = createTreeNode(b);
    bool res = isSameTree(p, q);
    cout << "Input: p = " << printTreeNode(p) << ", q = " << printTreeNode(q) << endl;
    string s = res ? "true" : "false";
    cout << "Output: " << s << endl << printEnd() << endl;
}

int main(int argc, char ** argv) {

    printResult(vector<int>{1,2,3}, vector<int>{1,2,3}); // Output: true
    printResult(vector<int>{1,2}, vector<int>{1,NULL,2}); // Output: false
    printResult(vector<int>{1,2,1}, vector<int>{1,1,2}); // Output: false

    return 0;
}