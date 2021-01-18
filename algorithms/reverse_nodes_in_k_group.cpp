#include <iostream>
#include <vector>
#include <string> 

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || k == 1)
        return head;
    ListNode res(-1);
    res.next = head;
    ListNode *cur =  &res, *nex, *pre = &res;
    int n = 0;
    while (cur = cur->next)
        n++;
    while (n >= k) {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; ++i) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        n -= k;
    }
    return res.next;
}

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
}

void printResult(vector<int> v, int k) {

    ListNode* head = createListNode(v);
    cout << "Input: head = [";
    for (auto & i : v) {
        cout << i << ",";
    }
    cout << "], k = " << k << endl;

    ListNode* result = reverseKGroup(head, k);
    ListNode* tmp = result;

    cout << "Output: [";
    while (tmp != nullptr) {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << "]" << endl << "=======" << endl;
}


int main(int argc, char ** argv) {

    printResult(vector<int> {1,2,3,4,5}, 2); // Output: [2,1,4,3,5]
    printResult(vector<int> {1,2,3,4,5}, 3); // Output: [3,2,1,4,5]
    printResult(vector<int> {1,2,3,4,5}, 1); // Output: [1,2,3,4,5]
    printResult(vector<int> {1}, 1); // Output: [1]

    return 0;
}