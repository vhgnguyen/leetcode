#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

namespace Node {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    /**
     * TEST FUNCTION
     * @brief Create a List Node object from vector
     * @param a 
     * @return ListNode* 
     */
    ListNode* createListNode(vector<int> & a) {

        ListNode* r = NULL;
        ListNode* t = NULL;
        ListNode* p = NULL;

        for (int i = 0; i < a.size(); i++) {
            t = new ListNode(a[i]);
            if (i == 0) {
                r = t;
            }
            else {
                p->next = t;
            }
            p = t;
        }
        return r;
    };

    string printListNode(ListNode* l) {

        string s = "[";
        while (l != nullptr) {
             s += to_string(l->val);
            if (l->next != NULL) s += ",";
            l = l->next;
        }
        return s + "]";
    };

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    /**
     * TEST FUNCTION
     * @brief Create a Binary Tree Node object from vector
     * @param a 
     * @return TreeNode* 
     */
    TreeNode* insertValue(TreeNode* root, int value, queue<TreeNode *> & q)
    {   
        TreeNode* node = new TreeNode(value);
        if (root == NULL)
            root = node;
    
        // The left child of the current Node is
        // used if it is available.
        else if (q.front()->left == NULL)
            q.front()->left = node;
    
        // The right child of the current Node is used
        // if it is available. Since the left child of this
        // node has already been used, the Node is popped
        // from the queue after using its right child.
        else {
            q.front()->right = node;
            q.pop();
        }
    
        // Whenever a new Node is added to the tree, its
        // address is pushed into the queue.
        // So that its children Nodes can be used later.
        q.push(node);
        return root;
    }
 
    TreeNode* createTreeNode(vector<int> a)
    {
        TreeNode* root = NULL;
        queue<TreeNode*> q;
        for (int i = 0; i < a.size(); i++)
            root = insertValue(root, a[i], q);
        return root;
    }

    string printTreeNode(TreeNode* root) {
        string s = "[";
        if (root == NULL) return "[]";  
    
        // Create an empty queue for level order tarversal  
        queue<TreeNode *> q;  
    
        // Enqueue Root and initialize height  
        q.push(root);  
    
        while (q.empty() == false)  
        {  
            // nodeCount (queue size) indicates number 
            // of nodes at current lelvel.  
            int nodeCount = q.size();  
    
            // Dequeue all nodes of current level and  
            // Enqueue all nodes of next level  
            while (nodeCount > 0) 
            {  
                TreeNode *node = q.front(); 
                if (node->val != 0)
                    s += to_string(node->val) + ",";  
                else
                    s += "null,";
                q.pop();  
                if (node->left != NULL)  
                    q.push(node->left);  
                if (node->right != NULL)  
                    q.push(node->right);  
                nodeCount--;  
            }  
        }
        s.pop_back();
        s += "]";
        return s;
    };


} // namespace Node

namespace helper {
    string v2s(const vector<int> & v) {
        string s = "[";
        for (int i = 0; i < v.size(); ++i) {
            s += to_string(v[i]);
            if (i != v.size() - 1) {
                s += ",";
            }
        }
        return s + "]";
    }

    string printVectorVector(const vector<vector<int>> & v) {
        string s = "[";
        for (int i = 0; i < v.size(); ++i) {
            s += v2s(v[i]);
            if (i != v.size() - 1) {
                s += ",";
            }
        }
        return s + "]";
    }

    string bool2str(bool b) {
        return b ? "true" : "false";
    }

    string printString(const string & s) {
        return "\"" + s + "\"";
    }

    string printEnd() {
        return "=======";
    }
} // namespace helper
