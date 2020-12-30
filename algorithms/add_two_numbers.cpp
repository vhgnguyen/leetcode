/*
 * @Author: Vo Hoang Nguyen 
 * @Date: 2020-12-07 02:53:00 
 * @Last Modified by: Vo Hoang Nguyen
 * @Last Modified time: 2020-12-07 02:54:04
 */
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
        ListNode* p = NULL;
        int carry = 0;
        int sum = 0;

        while ((l1 != NULL) || (l2 != NULL)) {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = sum / 10;
            ListNode* t = new ListNode(sum % 10);

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

        if (carry > 0) p->next = new ListNode(carry);
        
        return r;
    }
};


/**
 * TEST FUNCTION
 * @brief Create a List Node object from vector
 * 
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
}

/**
 * TEST FUNCTION
 * @brief Print a List Node
 * 
 * @param a 
 */
void printListNode(ListNode * a) {
    ListNode* n = a;
    while (n != nullptr) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}


int main(int argv, char** argc) {
    
    // Test case
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