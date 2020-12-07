#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r = NULL;
        ListNode* t = NULL;
        ListNode* p = NULL;
        int carry = 0;
        int sum = 0;

        while ((l1 != NULL) || (l2 != NULL)) {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = (sum>=10) ? 1 : 0;
            sum = sum % 10;
            t = new ListNode(sum);
            if (r == NULL) {
                r = t;
            }
            else {
                p->next = t;
            }
            p = t;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) t->next = new ListNode(carry);
        
        return r;
    }
};

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
}

void printListNode(ListNode * a) {
    ListNode* n = a;
    while (n != nullptr) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}


int main(int argc, char** argv) {
    
    vector<int> a{1,4,7};
    vector<int> b{1,7,4};

    ListNode* l1 = createListNode(a);
    ListNode* l2 = createListNode(b);

    cout << "Input 1: ";
    printListNode(l1);
    cout << "Input 2: ";
    printListNode(l2);

    Solution s;
    ListNode* r = s.addTwoNumbers(l1, l2);
    cout << "Output: ";
    printListNode(r);
}