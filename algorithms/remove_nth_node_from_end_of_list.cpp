#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {

    if (head == NULL)
        return head;

    ListNode* t1 = head, *t2 = head;
    
    while (n--) {
        t2 = t2->next;
    }
    if (t2 == NULL)
        return head->next;

    while (t2->next != NULL) {
        t2 = t2->next;
        t1 = t1->next;
    }
    t1->next = t1->next->next;
    
    return head;
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

void printRemoveNthFromEnd(vector<int> v, int n) {

    ListNode* head = createListNode(v);
    cout << "Input: head = [";
    for (auto & i : v) {
        cout << i << ",";
    }
    cout << "], n = " << n << endl;

    ListNode* result = removeNthFromEnd(head, n);
    ListNode* tmp = result;

    cout << "Output: [";
    while (tmp != nullptr) {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << "]" << endl << "=======" << endl;
}


int main(int argc, char ** argv) {

    printRemoveNthFromEnd(vector<int> {1,2,3,4,5}, 2); // Output: [1,2,3,5]
    printRemoveNthFromEnd(vector<int> {1}, 1); // Output: []
    printRemoveNthFromEnd(vector<int> {1,2}, 1); // Output: [1]

    return 0;
}